#include <fstream>
#include <zghost/bus/Memory.hpp>

Memory::Memory(const uint16_t& start, const uint16_t& size) {
    this->start = start;
    this->top = start + size;

    for (int i = 0; i < size; i++)
        this->mem.push_back(0x0);
}

Memory::~Memory() { this->mem.clear(); }

std::tuple<uint8_t, bool> Memory::read(const uint8_t& address) {
    if ((address >= this->start) && (address < this->top)) {
        uint16_t addrFinal = address - this->start;
        return std::make_tuple(this->mem[addrFinal], true);
    }
    return std::make_tuple(0x0, false);
}

bool Memory::write(const uint16_t& address, const uint8_t& value) {
    if ((address >= this->start) && (address < this->top)) {

        uint16_t addrFinal = address - this->start;
        this->mem[addrFinal] = value;
        return true;
    }
    return false;
}

bool Memory::valid(const uint16_t& address) { return ((address >= this->start) && (address < this->top)); }

void Memory::load(const std::string& file_path) {

    std::ifstream instream(file_path, std::ios::in | std::ios::binary);

    std::vector<uint8_t> data((std::istreambuf_iterator<char>(instream)), std::istreambuf_iterator<char>());

    for (int i = 0; i < data.size(); i++) {
        this->mem[i] = data[i];
    }

    // return data;
}