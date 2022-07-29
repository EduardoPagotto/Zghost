#include <zghost/bus/PPI8255.hpp>

// verificar: https://github.com/bibekdahal/8085-simulator/blob/master/PPI.py

PPI8255::PPI8255(const uint16_t& address) {
    this->addressBase = address;
    this->control = 0;
    this->portA = 0;
    this->portB = 0;
    this->portC = 0;

    // this->interruptA = nullptr;
    // this->interruptB = nullptr;
    // this->changedHandler = nullptr
}

PPI8255::~PPI8255() {}

std::tuple<uint8_t, bool> PPI8255::read(const uint16_t& address) {

    uint16_t t = address - this->addressBase;

    if ((this->control & 0x80) != 0x80) {
        return std::make_tuple(0xff, false);
    }

    if (t == 0x0)
        return this->inA();
    else if (t == 0x1)
        return this->inB();
    else if (t == 0x2)
        return this->inC();

    return std::make_tuple(0xff, false);
}

bool PPI8255::write(const uint16_t& address, const uint8_t& value) {

    uint16_t t = address - this->addressBase;

    if (t == 0x3)
        this->control = value;
    if ((this->control & 0x80) != 0x80) {
        this->bsr();
    } else if ((this->control & 0x80) != 80) {
        return false;
    } else if (t == 0x0) {
        return this->outA(value);
    } else if (t == 0x1) {
        return this->outB(value);
    } else if (t == 0x2) {
        return this->outC(value);
    }

    return false;
}

bool PPI8255::valid(const uint16_t& address) {
    uint16_t t = address - this->addressBase;
    if (t <= 3)
        return true;

    return false;
}

std::tuple<uint8_t, bool> PPI8255::inA() {
    if ((this->control & 0x10) == 0x00) {
        return std::make_tuple(false, 0xff);
    }
    return std::make_tuple(true, this->portA);
}

std::tuple<uint8_t, bool> PPI8255::inB() {
    if ((this->control & 0x02) == 0x00) {
        return std::make_tuple(false, 0xff);
    }
    return std::make_tuple(true, this->portB);
}

std::tuple<uint8_t, bool> PPI8255::inC() {

    uint8_t value = 0x0;
    if ((this->control & 0x08) == 0x08) {
        value |= this->portC & 0xf0;
    }

    if ((this->control & 0x01) == 0x01) {
        value |= this->portC & 0x0f;
    }

    return std::make_tuple(true, value);
}

bool PPI8255::outA(const uint8_t& value) {

    if (((this->control & 0x10) == 0x10) && ((this->control & 0x60) != 0x60)) {
        return false;
    }
    this->portA = value;
    return true;
}

bool PPI8255::outB(const uint8_t& value) {

    if ((this->control & 0x02) == 0x02)
        return false;

    this->portB = value;

    this->change();

    return true;
}

bool PPI8255::outC(const uint8_t& value) {

    if ((this->control & 0x08) == 0x00)
        this->portC = (value & 0xF0) | (this->portC & 0x0F);
    if ((this->control & 0x01) == 0x00)
        this->portC = (this->portC & 0xF0) | (value & 0x0F);

    this->change();

    return true;
}

void PPI8255::bsr() {

    uint8_t bit = this->control & 0x0E;
    bit = bit >> 1;
    uint8_t data = this->control & 0x01;
    data = data << bit;
    this->portC = (this->portC & ~data) | data;
    this->change();
}

void PPI8255::change() {
    // // TODO
    // if (this->changedHandler)
    //     this->changedHandler();
}

// void SetInterruptCallPA(void* call) { this->interruptA = call; }

// void SetInterruptCallPB(void* call) { void->interruptB = call; }

// void strobeA() {
//     if (((this->crontrol & 0x20) == 0x20) && (this->interruptA != nullptr))
//         this->interruptA();
// }

// void strobeB() {
//     if (((this->crontrol & 0x04) == 0x04) && (this->interruptB != nullptr))
//         this->interruptB();
// }