#include <zghost/z80/OpCode.hpp>
#include <zghost/z80/Z80.hpp>

const uint8_t Z80::halfcarryAddTable[] = {0, FLAG_H, FLAG_H, FLAG_H, 0, 0, 0, FLAG_H};
const uint8_t Z80::halfcarrySubTable[] = {0, 0, FLAG_H, 0, FLAG_H, 0, FLAG_H, FLAG_H};
const uint8_t Z80::overflowAddTable[] = {0, 0, 0, FLAG_V, FLAG_V, 0, 0, 0};
const uint8_t Z80::overflowSubTable[] = {0, FLAG_V, 0, 0, 0, 0, FLAG_V, 0};

Z80::Z80(Bus* pBus) : bus(pBus), A(0xff), sp(0xffff), pc(0x0000) {

    F = B = C = D = E = H = L = 0;
    A_ = F_ = B_ = C_ = D_ = E_ = H_ = L_ = 0;
    IXH = IXL = IYH = IYL = 0;
    I = IFF1 = IFF2 = IM = 0;
    R = R7 = 0;

    AF.setPtr(&A, &F);
    BC.setPtr(&B, &C);
    DE.setPtr(&D, &E);
    HL.setPtr(&H, &L);
    IX.setPtr(&IXH, &IXL);
    IY.setPtr(&IYH, &IYL);
    AF_.setPtr(&A_, &F_);
    BC_.setPtr(&B_, &C_);
    DE_.setPtr(&D_, &E_);
    HL_.setPtr(&H_, &L_);

    this->init_table_sz53();
    initOpCode();
}

Z80::~Z80() {}

void Z80::init_table_sz53() {
    uint16_t i;
    uint8_t j, k;
    uint8_t parity;

    for (i = 0; i < 0x100; i++) {
        sz53Table[i] = static_cast<uint8_t>(i) & (0x08 | 0x20 | 0x80);
        j = static_cast<uint8_t>(i);
        parity = 0;
        for (k = 0; k < 8; k++) {
            parity ^= j & 1;
            j >>= 1;
        }
        parityTable[i] = (parity != 0) ? 0 : 0x04; // ternOpB(parity != 0, 0, 0x04);
        sz53pTable[i] = sz53Table[i] | parityTable[i];
    }

    sz53Table[0] |= 0x40;
    sz53pTable[0] |= 0x40;
}

void Z80::reset() {
    I = R = R7 = pc = IFF1 = IFF2 = IM = 0;
    Tstates += 3;
    Halted = false;
    interruptsEnabledAt = 0;
}

void Z80::step() {

    if (this->Halted == false) {
        uint8_t opcode = this->bus->readMemory(this->pc);
        this->R = (this->R + 1) & 0x7f;
        this->pc++;
        opcodeStep(this, opcode);
    } else {
        this->Tstates += 4;
        this->R = (this->R + 1) & 0x7f;
    }
}

void Z80::interrupt() {
    if (this->IFF1 != 0) {

        if (this->interruptsEnabledAt + 24 > int(this->Tstates)) {
            return;
        }

        if (this->Halted) {
            // this->pc++
            this->Halted = false;
        }

        this->Tstates += 7;

        this->R = (this->R + 1) & 0x7f;
        this->IFF1 = this->IFF2 = 0;

        // push PC
        this->push(this->pc);
        switch (this->IM) {
            case 0:
            case 1:
                this->pc = 0x0038;
                break;
            case 2: {
                uint16_t inttemp = static_cast<uint16_t>((this->I << 8) | 0xff);
                uint8_t pcl = this->bus->readMemory(inttemp);
                inttemp++;
                uint8_t pch = this->bus->readMemory(inttemp);
                this->pc = R16::joinBytes(pch, pcl);
            } break;
            default:
                // throw std::exception(std::string("Unknown interrupt mode"));
                break;
        }
    }
}

// Process a Z80 non-maskable interrupt.
void Z80::nonMaskableInterrupt() {
    if (this->Halted) {
        // this->pc++
        this->Halted = false;
    }

    this->Tstates += 7;

    this->R = (this->R + 1) & 0x7f;
    this->IFF1 = this->IFF2 = 0;

    // push PC
    this->push(this->pc);
    this->pc = 0x0066;
}

// // -- Memory
// Stack
void Z80::pushR16(R16& reg16) {
    this->sp--;
    this->bus->writeMemory(this->sp, reg16.getHi());
    this->sp--;
    this->bus->writeMemory(this->sp, reg16.getLo());
}

void Z80::popR16(R16& reg16) {
    reg16.setLo(this->bus->readMemory(this->sp));
    this->sp++;
    reg16.setHi(this->bus->readMemory(this->sp));
    this->sp++;
}

void Z80::push(const uint16_t& value) {

    uint8_t high, low;
    std::tie(high, low) = R16::splitword(value);

    this->sp--;
    this->bus->writeMemory(this->sp, high);
    this->sp--;
    this->bus->writeMemory(this->sp, low);
}

uint16_t Z80::pop() {
    uint8_t valLo = this->bus->readMemory(this->sp);
    this->sp++;
    uint8_t valHi = this->bus->readMemory(this->sp);
    this->sp++;
    return R16::joinBytes(valHi, valLo);
}

// PC
uint8_t Z80::load8() {
    uint8_t val = this->bus->readMemory(this->pc);
    this->pc++;
    return val;
}

uint16_t Z80::load16() {
    uint16_t ldtemp = static_cast<uint16_t>(this->bus->readMemory(this->pc));
    this->pc++;
    ldtemp |= static_cast<uint16_t>(this->bus->readMemory(this->pc) << 8);
    this->pc++;
    return ldtemp;
}

void Z80::loadR16(R16& reg16) {
    reg16.setLo(this->bus->readMemory(this->pc));
    this->pc++;
    reg16.setHi(this->bus->readMemory(this->pc));
    this->pc++;
}

void Z80::loadIndexR16(R16& reg16) {
    uint16_t ldtemp = this->load16();
    reg16.setLo(this->bus->readMemory(ldtemp));
    ldtemp++;
    reg16.setHi(this->bus->readMemory(ldtemp));
}

void Z80::storeIndexR16(R16& reg16) {
    uint16_t ldtemp = this->load16();
    this->bus->writeMemory(ldtemp, reg16.getLo());
    ldtemp++;
    this->bus->writeMemory(ldtemp, reg16.getHi());
}

uint8_t Z80::readMem(const uint16_t& address) { return this->bus->readMemory(address); }

void Z80::writeMem(const uint16_t& address, const uint8_t& value) { this->bus->writeMemory(address, value); }

// int Z80::sltTrap(const uint16_t& int16, const uint8_t& level) {
//     // Dummy implementation
//     return 0;
// }

void Z80::call() {
    this->Tstates += 17;
    uint16_t newpc = this->load16();
    this->push(this->pc);
    this->pc = newpc;
}

void Z80::jr() {
    this->Tstates += 12;
    int16_t jrtemp = R16::signExtend(this->bus->readMemory(this->pc));
    this->pc += jrtemp;
    this->pc++;
}

void Z80::rst(const uint8_t& value) {
    this->push(this->pc);
    this->pc = static_cast<uint16_t>(value); // uint16(value);
}

//-- Logic----------------------------------------------------

void Z80::oppAnd(const uint8_t& value) {
    this->A &= value;
    this->F = FLAG_H | sz53pTable[this->A];
}

void Z80::oppXor(const uint8_t& value) {
    this->A ^= value;
    this->F = sz53pTable[this->A];
}

void Z80::oppOr(const uint8_t& value) {
    this->A |= value;
    this->F = sz53pTable[this->A];
}

void Z80::oppCp(const uint8_t& value) {
    uint16_t cptemp = static_cast<uint16_t>(this->A) - static_cast<uint16_t>(value);
    uint8_t lookup = ((this->A & 0x88) >> 3) |                   //
                     ((value & 0x88) >> 2) |                     //
                     static_cast<uint8_t>((cptemp & 0x88) >> 1); //

    this->F = (((cptemp & 0x100) != 0) ? FLAG_C : ((cptemp != 0) ? 0 : FLAG_Z)) | FLAG_N | halfcarrySubTable[lookup & 0x07] |
              overflowSubTable[lookup >> 4] | (value & (FLAG_3 | FLAG_5)) | static_cast<uint8_t>(cptemp & FLAG_S);
}

// //-- aritmetric

void Z80::add(const uint8_t& value) {
    uint addtemp = uint(this->A) + uint(value);

    uint8_t lookup = ((this->A & 0x88) >> 3) | ((value & 0x88) >> 2) | static_cast<uint8_t>((addtemp & 0x88) >> 1);

    this->A = static_cast<uint8_t>(addtemp);

    this->F = (((addtemp & 0x100) != 0) ? FLAG_C : 0) | // flag c
              halfcarryAddTable[lookup & 0x07] |        // tbl1
              overflowAddTable[lookup >> 4] |           // tbl2
              sz53Table[this->A];
}

void Z80::addR16(R16& value1, const uint16_t& value2) {
    uint add16temp = uint(value1.get()) + uint(value2);

    uint8_t lookup = static_cast<uint8_t>(((value1.get() & 0x0800) >> 11) |                  //
                                          ((value2 & 0x0800) >> 10) |                        //
                                          (static_cast<uint16_t>(add16temp) & 0x0800) >> 9); //

    value1.set(static_cast<uint16_t>(add16temp));

    this->F = (this->F & (FLAG_V | FLAG_Z | FLAG_S)) |                     //
              ((add16temp & 0x10000) != 0 ? FLAG_C : 0) |                  //
              (static_cast<uint8_t>(add16temp >> 8) & (FLAG_3 | FLAG_5)) | //
              halfcarryAddTable[lookup];
}

void Z80::adc(const uint8_t& value) {
    uint16_t adctemp = static_cast<uint16_t>(this->A) + static_cast<uint16_t>(value) + (static_cast<uint16_t>(this->F) & FLAG_C);

    uint8_t lookup = static_cast<uint8_t>(((static_cast<uint16_t>(this->A) & 0x88) >> 3) | //
                                          ((static_cast<uint16_t>(value) & 0x88) >> 2) |   //
                                          ((static_cast<uint16_t>(adctemp) & 0x88) >> 1)); //

    this->A = static_cast<uint8_t>(adctemp);

    this->F = ((adctemp & 0x100) != 0 ? FLAG_C : 0) | //
              halfcarryAddTable[lookup & 0x07] |      //
              overflowAddTable[lookup >> 4] |         //
              sz53Table[this->A];                     //
}

void Z80::adc16(const uint16_t& value) {
    uint add16temp = uint(this->HL.get()) + uint(value) + (uint(this->F) & FLAG_C);

    uint8_t lookup = static_cast<uint8_t>(((uint(this->HL.get()) & 0x8800) >> 11) | //
                                          ((uint(value) & 0x8800) >> 10) |          //
                                          (add16temp & 0x8800) >> 9);               //

    this->HL.set(static_cast<uint16_t>(add16temp));

    this->F = ((uint(add16temp) & 0x10000) != 0 ? FLAG_C : 0) | //
              overflowAddTable[lookup >> 4] |                   //
              (this->H & (FLAG_3 | FLAG_5 | FLAG_S)) |          //
              halfcarryAddTable[lookup & 0x07] |                //
              (this->HL.get() != 0 ? 0 : FLAG_Z);               //
}

void Z80::sub(const uint8_t& value) {
    uint16_t subtemp = static_cast<uint16_t>(this->A) - static_cast<uint16_t>(value);

    uint8_t lookup = ((this->A & 0x88) >> 3) | ((value & 0x88) >> 2) | static_cast<uint8_t>((subtemp & 0x88) >> 1);

    this->A = static_cast<uint8_t>(subtemp);

    this->F = ((subtemp & 0x100) != 0 ? FLAG_C : 0) | //
              FLAG_N |                                //
              halfcarrySubTable[lookup & 0x07] |      //
              overflowSubTable[lookup >> 4] |         //
              sz53Table[this->A];
}

void Z80::sbc(const uint8_t& value) {
    uint16_t sbctemp = static_cast<uint16_t>(this->A) - static_cast<uint16_t>(value) - (static_cast<uint16_t>(this->F) & FLAG_C);

    uint8_t lookup = ((this->A & 0x88) >> 3) |                    //
                     ((value & 0x88) >> 2) |                      //
                     static_cast<uint8_t>((sbctemp & 0x88) >> 1); //

    this->A = static_cast<uint8_t>(sbctemp);

    this->F = ((sbctemp & 0x100) != 0 ? FLAG_C : 0) | //
              FLAG_N |                                //
              halfcarrySubTable[lookup & 0x07] |      //
              overflowSubTable[lookup >> 4] |         //
              sz53Table[this->A];                     //
}

void Z80::sbc16(const uint16_t& value) { // ??
    uint sub16temp = uint(this->HL.get()) - uint(value) - (uint(this->F) & FLAG_C);

    uint8_t lookup = static_cast<uint8_t>(((this->HL.get() & 0x8800) >> 11) |                  //
                                          ((static_cast<uint16_t>(value) & 0x8800) >> 10) |    //
                                          ((static_cast<uint16_t>(sub16temp) & 0x8800) >> 9)); //

    this->HL.set(static_cast<uint16_t>(sub16temp));

    this->F = ((sub16temp & 0x10000) != 0 ? FLAG_C : 0) | //
              FLAG_N |                                    //
              overflowSubTable[lookup >> 4] |             //
              (this->H & (FLAG_3 | FLAG_5 | FLAG_S)) |    //
              halfcarrySubTable[lookup & 0x07] |          //
              (this->HL.get() != 0 ? 0 : FLAG_Z);
}

/*
Incrementa o conteudo do ponteiro referente ao registro
*/
void Z80::inc(uint8_t* ptrValue) { // TODO merge com IncR
    (*ptrValue)++;
    this->F = (this->F & FLAG_C) |                     //
              ((*ptrValue) == 0x80 ? FLAG_V : 0) |     //
              ((*ptrValue & 0x0f) != 0 ? 0 : FLAG_H) | //
              sz53Table[(*ptrValue)];                  //
}

/*
Decrementa o conteudo do ponteiro referente ao registro
*/
void Z80::dec(uint8_t* ptrValue) { // TODO merge com DecR

    this->F = (this->F & FLAG_C) |                       //
              (((*ptrValue) & 0x0f) != 0 ? 0 : FLAG_H) | //
              FLAG_N;                                    //

    (*ptrValue)--;

    this->F |= ((*ptrValue) == 0x7f ? FLAG_V : 0) | //
               sz53Table[(*ptrValue)];
}

// //-- bit shift

uint8_t Z80::rlc(const uint8_t& val) {
    uint8_t value = (val << 1) | (val >> 7);
    this->F = (value & FLAG_C) | sz53pTable[value];
    return value;
}

uint8_t Z80::rrc(const uint8_t& val) {
    this->F = val & FLAG_C;
    uint8_t value = (val >> 1) | (val << 7);
    this->F |= sz53pTable[value];
    return value;
}

uint8_t Z80::rr(const uint8_t& val) {
    uint8_t rrtemp = val;
    uint8_t value = (val >> 1) | (this->F << 7);
    this->F = (rrtemp & FLAG_C) | sz53pTable[value];
    return value;
}

uint8_t Z80::rl(const uint8_t& val) {
    uint8_t rltemp = val;
    uint8_t value = (val << 1) | (this->F & FLAG_C);
    this->F = (rltemp >> 7) | sz53pTable[value];
    return value;
}

uint8_t Z80::sla(const uint8_t& val) {
    uint8_t value = val;
    this->F = value >> 7;
    value <<= 1;
    this->F |= sz53pTable[value];
    return value;
}

uint8_t Z80::sll(const uint8_t& val) {
    uint8_t value = val;
    this->F = value >> 7;
    value = (value << 1) | 0x01;
    this->F |= sz53pTable[(value)];
    return value;
}

uint8_t Z80::sra(const uint8_t& val) {
    this->F = val & FLAG_C;
    uint8_t value = (val & 0x80) | (val >> 1);
    this->F |= sz53pTable[value];
    return value;
}

uint8_t Z80::srl(const uint8_t& val) {
    uint8_t value = val;
    this->F = value & FLAG_C;
    value >>= 1;
    this->F |= sz53pTable[value];
    return value;
}

void Z80::bit(const uint8_t& bit, const uint8_t& value) {

    this->F = (this->F & FLAG_C) | FLAG_H | (value & (FLAG_3 | FLAG_5));
    if ((value & (0x01 << bit)) == 0) {
        this->F |= FLAG_P | FLAG_Z;
    }

    if (bit == 7 && (value & 0x80) != 0) {
        this->F |= FLAG_S;
    }
}

void Z80::biti(const uint8_t& bit, const uint8_t& value, const uint16_t& address) {
    this->F = (this->F & FLAG_C) | FLAG_H | (static_cast<uint8_t>(address >> 8) & (FLAG_3 | FLAG_5));
    if ((value & (0x01 << bit)) == 0) {
        this->F |= FLAG_P | FLAG_Z;
    }
    if ((bit == 7) && (value & 0x80) != 0) {
        this->F |= FLAG_S;
    }
}

// //--- IO

void Z80::in(uint8_t* reg, const uint16_t& address) {
    *reg = this->bus->readIo(address);
    this->F = (this->F & FLAG_C) | sz53pTable[*reg];
}

uint8_t Z80::readPort(const uint16_t& address) { return this->bus->readIo(address); }
void Z80::writePort(const uint16_t& address, const uint8_t& b) { this->bus->writeIo(address, b); }

const uint8_t Z80::getRegisterValByte(const uint8_t& opcode) {
    uint8_t r = opcode & 0x07;
    switch (r) {
        case 0:
            return this->B;
            break;
        case 1:
            return this->C;
            break;
        case 2:
            return this->D;
            break;
        case 3:
            return this->E;
            break;
        case 4:
            return this->H;
            break;
        case 5:
            return this->L;
            break;
        case 7:
            return this->A;
            break;
    }

    return 0;
}

uint8_t* Z80::getPrtRegisterValByte(const uint8_t& opcode) {
    uint8_t r = opcode & 0x07;
    switch (r) {
        case 0:
            return &this->B;
        case 1:
            return &this->C;
        case 2:
            return &this->D;
        case 3:
            return &this->E;
        case 4:
            return &this->H;
        case 5:
            return &this->L;
        case 7:
            return &this->A;
    }

    return nullptr;
}

uint8_t Z80::getMaskBitReset(const uint8_t& opcode) {
    uint8_t r = opcode & 0x07;
    switch (r) {
        case 0:
            return 0xfe;
            break;
        case 1:
            return 0xfd;
            break;
        case 2:
            return 0xfb;
            break;
        case 3:
            return 0xf7;
            break;
        case 4:
            return 0xef;
            break;
        case 5:
            return 0xdf;
            break;
        case 6:
            return 0xbf;
            break;
        case 7:
            return 0x7f;
            break;
    }

    return 0x0;
}