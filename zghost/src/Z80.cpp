#include <zghost/z80/OpCode.hpp>
#include <zghost/z80/Z80.hpp>

Z80::Z80(Bus* pBus) {
    A, F, B, C, D, E, H, L = 0;
    A_, F_, B_, C_, D_, E_, H_, L_ = 0;
    IXH, IXL, IYH, IYL = 0;
    I, IFF1, IFF2, IM = 0;

    R7 = 0;
    R = 0;
    pc = 0;
    sp = 0xffff;

    AF = new R16(&A, &F);
    BC = new R16(&B, &C);
    DE = new R16(&D, &E);
    HL = new R16(&H, &L);
    IX = new R16(&IXH, &IXL);
    IY = new R16(&IYH, &IYH);
    AF_ = new R16(&A_, &F_);
    BC_ = new R16(&B_, &C_);
    DE_ = new R16(&D_, &E_);
    HL_ = new R16(&H_, &L_);

    bus = pBus;
}

Z80::~Z80() {}

void Z80::reset() {
    A = 0xff;
    F, B, C, D, E, H, L = 0;
    A_, F_, B_, C_, D_, E_, H_, L_ = 0;
    IXH, IXL, IYH, IYL = 0;
    sp, I, R, R7, pc, IFF1, IFF2, IM = 0;
    Tstates = 0;
    Halted = false;
    interruptsEnabledAt = 0;

    initOpCode();
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
        ;
    }
}

void Z80::interrupt() {
    if (this->IFF1 != 0) {
        if (this->Halted) {
            // this->pc++
            this->Halted = false;
        }

        if (this->interruptsEnabledAt + 24 > int(this->Tstates)) {
            return;
        }

        this->Tstates += 7;

        this->R = (this->R + 1) & 0x7f;
        this->IFF1, this->IFF2 = 0, 0;

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

/*
Salve registro no stack
*/
void Z80::pushR(R16* pReg) {
    this->sp--;
    this->bus->writeMemory(this->sp, pReg->getHi());
    this->sp--;
    this->bus->writeMemory(this->sp, pReg->getLo());
}

/*
Carrgado registro do stack
*/
void Z80::popR(R16* pReg) {
    pReg->setLo(this->bus->readMemory(this->sp));
    this->sp++;
    pReg->setHi(this->bus->readMemory(this->sp));
    this->sp++;
}

/*
Salva uint16 no stack
*/
void Z80::push(const uint16_t& value) {

    uint8_t high, low;
    std::tie(high, low) = R16::splitword(value);

    this->sp--;
    this->bus->writeMemory(this->sp, high);
    this->sp--;
    this->bus->writeMemory(this->sp, low);
}

/*
Carrega uint16 do stack
*/
uint16_t Z80::pop() {
    uint8_t valLo = this->bus->readMemory(this->sp);
    this->sp++;
    uint8_t valHi = this->bus->readMemory(this->sp);
    this->sp++;
    return R16::joinBytes(valHi, valLo);
}

void Z80::loadR(R16* pReg) {
    pReg->setLo(this->bus->readMemory(this->pc));
    this->pc++;
    pReg->setHi(this->bus->readMemory(this->pc));
    this->pc++;
}

/*
Carrega uint16 seguinte do PC em LittleEndian
*/
uint16_t Z80::load16() {
    uint16_t ldtemp = static_cast<uint16_t>(this->bus->readMemory(this->pc));
    this->pc++;
    ldtemp |= static_cast<uint16_t>(this->bus->readMemory(this->pc) << 8);
    this->pc++;
    return ldtemp;
}

/*
Carrega byte seguinte do PC
*/
uint8_t Z80::load8() {
    uint8_t val = this->bus->readMemory(this->pc);
    this->pc++;
    return val;
}

/*
Carrega conteudo apontado pelo PC, PC+1 no ponteido do Register16
*/
void Z80::loadIndexR(R16* pReg) {
    uint16_t ldtemp = this->load16();
    pReg->setLo(this->bus->readMemory(ldtemp));
    ldtemp++;
    pReg->setHi(this->bus->readMemory(ldtemp));
}

/*
Armazena o conteudo do Register16 no endereco apontado por PC, PC+1
*/
void Z80::storeIndexR(R16* pReg) {
    uint16_t ldtemp = this->load16();
    this->bus->writeMemory(ldtemp, pReg->getLo());
    ldtemp++;
    this->bus->writeMemory(ldtemp, pReg->getHi());
}

/*
Carrega ponteiro de byte na posicao indexada pelo PC, PC+1
*/
void Z80::loadIndex8(uint8_t* pValue) {
    uint16_t ldtemp = this->load16();
    *pValue = this->bus->readMemory(ldtemp);
}

/*
Armazena bute na posicao indexada pelo PC, PC+1
*/
void Z80::storeIndex8(const uint8_t& value) {
    uint16_t addr = this->load16();
    this->bus->writeMemory(addr, value);
}
