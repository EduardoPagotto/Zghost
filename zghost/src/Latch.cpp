#include <zghost/bus/Latch.hpp>

Latch::Latch(const uint16_t& address) {
    this->address = address;
    this->value = 0x0;
    has_value = false;
}

Latch::~Latch() {}

std::tuple<uint8_t, bool> Latch::read(const uint8_t& address) {
    if (this->address == address) {
        has_value = false;
        return std::make_tuple(this->value, true);
    }
    return std::make_tuple(0x0, false);
}

bool Latch::write(const uint16_t& address, const uint8_t& value) {
    if (this->address == address) {
        this->value = value;
        this->has_value = true;
        return true;
    }
    return false;
}

bool Latch::valid(const uint16_t& address) { return (this->address == address); }

std::tuple<uint8_t, bool> Latch::readDirect() {
    if (this->has_value) {
        this->has_value = false;
        return std::make_tuple(this->value, true);
    }

    return std::make_tuple(0xff, false);
}

void Latch::writeDirect(const uint8_t& value) {
    this->has_value = true;
    this->value = value;
}