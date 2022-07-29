#include <zghost/bus/Latch.hpp>

void Latch::write(const uint16_t& address, const uint8_t& value) {
    this->value = value;
    this->changed = true;
}

const uint8_t& Latch::read(const uint16_t& address) {
    this->changed = false;
    return this->value;
}

const uint8_t& Latch::readDirect() {
    this->changed = false;
    return this->value;
}

void Latch::writeDirect(const uint8_t& value) {
    this->changed = true;
    this->value = value;
}