#include <zghost/bus/PPI8255.hpp>

// verificar: https://github.com/bibekdahal/8085-simulator/blob/master/PPI.py

PPI8255::PPI8255(const uint16_t& address, const uint8_t& status) : Memory(address, 4, DEV_OPENED) {

    mem[0] = 0; // A
    mem[1] = 0; // B
    mem[2] = 0; // C
    mem[3] = 0; // Control
}

PPI8255::~PPI8255() {}

bool PPI8255::read(const uint32_t& address, const uint32_t& size, uint8_t* valueRet) { // FIXME: NAO FUNCIONA!!!

    *valueRet = 0xff;
    if (!validRange(address, size))
        return false;

    if ((mem[3] & 0x80) != 0x80)
        return false;

    uint16_t t = address - start;

    if (t == 0x03) {
        return false;

    } else if (t == 0x00) {
        *valueRet = this->inA();

    } else if (t == 0x01) {
        *valueRet = this->inB();

    } else if (t == 0x02)
        *valueRet = this->inC();

    return true;
}

bool PPI8255::write(const uint32_t& address, const uint32_t& size, uint8_t* value) {

    if (!validWrite(address, size))
        return false;

    uint16_t t = address - start;
    if (t == 0x03) { // Control
        mem[3] = *value;
        if ((mem[3] & 0x80) != 0x80) {
            this->bsr();
        }

    } else if ((mem[3] & 0x80) != 80) {
        return false;

    } else if (t == 0x0) {
        this->outA(*value);

    } else if (t == 0x1) {
        this->outB(*value);

    } else if (t == 0x2) {
        this->outC(*value);
    }

    return true;
}

uint8_t PPI8255::inA() {

    if ((mem[3] & 0x10) == 0x00)
        return 0;

    return mem[0];
}

uint8_t PPI8255::inB() {

    if ((mem[3] & 0x02) == 0x00)
        return 0;

    return mem[1];
}

uint8_t PPI8255::inC() {

    uint8_t defaultC = 0x0;
    if ((mem[3] & 0x08) == 0x08) {
        defaultC |= mem[2] & 0xf0;
    }

    if ((mem[3] & 0x01) == 0x01) {
        defaultC |= mem[2] & 0x0f;
    }

    return defaultC;
}

void PPI8255::outA(const uint8_t& value) {

    if (((mem[3] & 0x10) == 0x10) && ((mem[3] & 0x60) != 0x60))
        return;

    mem[0] = value;
    this->change();
}

void PPI8255::outB(const uint8_t& value) {

    if ((mem[3] & 0x02) == 0x02)
        return;

    this->mem[2] = value;
    this->change();
}

void PPI8255::outC(const uint8_t& value) {

    if ((mem[3] & 0x08) == 0x00)
        mem[2] = (value & 0xF0) | (mem[2] & 0x0F);
    if ((mem[3] & 0x01) == 0x00)
        mem[2] = (mem[2] & 0xF0) | (value & 0x0F);

    this->change();
}

void PPI8255::bsr() {

    uint8_t bit = mem[3] & 0x0E;
    bit = bit >> 1;
    uint8_t data = mem[3] & 0x01;
    data = data << bit;
    mem[2] = (mem[2] & ~data) | data;
    this->change();
}

void PPI8255::change() {
    // TODO
    // if (this->changedHandler)
    //     this->changedHandler();
}

void PPI8255::SetInterruptCallPA(void* call) { this->interruptA = call; }
void PPI8255::SetInterruptCallPB(void* call) { this->interruptB = call; }

void PPI8255::strobeA() {
    // TODO
    // if (((mem[3] & 0x20) == 0x20) && (this->interruptA != nullptr))
    //     this->interruptA();
}

void PPI8255::strobeB() {
    // TODO
    // if (((mem[3] & 0x04) == 0x04) && (this->interruptB != nullptr))
    //     this->interruptB();
}