#include <zghost/bus/Memory.hpp>

Memory::Memory(const uint16_t& start, const uint16_t& size, const bool& readOnly) : Device(true, false, readOnly), start(start) {
    this->top = start + size;
    this->mem.reserve(size + 10);
    for (int i = 0; i < size; i++)
        this->mem.push_back(0xFC);
}

Memory::~Memory() { this->mem.clear(); }

const uint8_t& Memory::read(const uint16_t& address) {
    changed = false;
    uint16_t addrFinal = address - start;
    return this->mem[addrFinal];
}

void Memory::write(const uint16_t& address, const uint8_t& value) {
    if (!readOnly) {
        uint16_t addrFinal = address - start;
        this->mem[addrFinal] = value;
        changed = true;
    }
}
