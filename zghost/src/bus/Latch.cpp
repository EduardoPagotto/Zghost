#include <zghost/bus/Latch.hpp>

void Latch::write(const uint16_t& address, const uint8_t& value) {
    this->value = value;
    this->hasVal = true;
}

uint8_t& Latch::read(const uint16_t& address) {
    this->hasVal = false;
    return this->value;
}

uint8_t Latch::readDirect() {
    if (this->hasVal) {
        this->hasVal = false;
        return this->value;
    }
    return 0xff;
}

void Latch::writeDirect(const uint8_t& value) {
    this->hasVal = true;
    this->value = value;
}