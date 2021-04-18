#include <zghost/bus/Latch.hpp>

Latch::Latch(const uint16_t& address) {
    this->address = address;
    this->value = 0x0;
}

Latch::~Latch() {}

std::tuple<uint8_t, bool> Latch::read(const uint8_t& address) {
    if (this->address == address) {
        return std::make_tuple(this->value, true);
    }
    return std::make_tuple(0x0, false);
}

bool Latch::write(const uint16_t& address, const uint8_t& value) {
    if (this->address == address) {
        this->value = value;
        return true;
    }
    return false;
}

bool Latch::valid(const uint16_t& address) { return (this->address == address); }
