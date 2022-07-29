#include <fstream>
#include <zghost/bus/Memory.hpp>

Memory::Memory(const uint16_t& start, const uint16_t& size) {
    this->start = start;
    this->top = start + size;

    this->mem.reserve(size + 10);
    for (int i = 0; i < size; i++)
        this->mem.push_back(0xFC);
}

Memory::~Memory() { this->mem.clear(); }

const uint8_t& Memory::read(const uint16_t& address) {
    uint16_t addrFinal = address - start;
    return this->mem[addrFinal];
}

void Memory::write(const uint16_t& address, const uint8_t& value) {
    uint16_t addrFinal = address - start;
    this->mem[addrFinal] = value;
}

void Memory::load(const std::string& file_path) {

    std::ifstream instream(file_path, std::ios::in | std::ios::binary);
    std::vector<uint8_t> data((std::istreambuf_iterator<char>(instream)), std::istreambuf_iterator<char>());
    for (int i = 0; i < data.size(); i++)
        this->mem[i] = data[i];
}