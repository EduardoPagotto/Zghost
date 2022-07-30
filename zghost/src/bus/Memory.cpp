#include <zghost/bus/Memory.hpp>

Memory::Memory(const uint16_t& start, const uint16_t& size, const uint8_t& status) : Device(status), start(start) {
    this->top = start + size;
    this->mem.reserve(size + 10);
    for (int i = 0; i < size; i++)
        this->mem.push_back(0xFC);
}

Memory::~Memory() { this->mem.clear(); }

bool Memory::read(const uint16_t& address, uint8_t& valueRet) {
    if (valid(address)) {
        status &= !DSTAT_CHANGED; // limpa so o change
        uint16_t addrFinal = address - start;
        valueRet = this->mem[addrFinal];
        return true;
    }
    return false;
}

bool Memory::write(const uint16_t& address, const uint8_t& value) {

    if ((!(status & DSTAT_READONLY)) && valid(address)) {
        uint16_t addrFinal = address - start;
        this->mem[addrFinal] = value;
        status |= DSTAT_CHANGED; // ativa so o changed
        return true;
    }
    return false;
}
