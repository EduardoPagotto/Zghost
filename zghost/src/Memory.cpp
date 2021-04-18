#include <zghost/bus/Memory.hpp>

Memory::Memory(const uint16_t& start, const uint16_t& size) {
    this->start = start;
    this->top = start + size;

    this->mem = new uint8_t[size];
    for (uint16_t i = 0; i < size; i++)
        this->mem[i] = 0x0;
}

Memory::~Memory() { delete[] this->mem; }

std::tuple<uint8_t, bool> Memory::read(const uint8_t& address) {
    if ((address >= this->start) && (address < this->top)) {
        uint16_t addrFinal = address - this->start;
        return std::make_tuple(this->mem[address], true);
    }
    return std::make_tuple(0x0, false);
}

bool Memory::write(const uint16_t& address, const uint8_t& value) {
    if ((address >= this->start) && (address < this->top)) {

        uint16_t addrFinal = address - this->start;
        this->mem[address] = value;
        return true;
    }
    return false;
}

bool Memory::valid(const uint16_t& address) { return ((address >= this->start) && (address < this->top)); }
