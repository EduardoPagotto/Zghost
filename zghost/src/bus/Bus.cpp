#include <zghost/bus/Bus.hpp>

uint8_t Bus::readMemory(const uint16_t& address) {
    for (auto it = mem.begin(); it != mem.end(); it++) {

        std::string name = it->first;
        Device* pDev = it->second;
        if (pDev->valid(address) == true)
            return pDev->read(address);
    }
    return 0xff;
}

void Bus::writeMemory(const uint16_t& address, const uint8_t& value) {
    for (auto it = mem.begin(); it != mem.end(); it++) {

        std::string name = it->first;
        Device* pDev = it->second;
        if (pDev->valid(address) == true)
            pDev->write(address, value);
    }
}

uint8_t Bus::readIo(const uint16_t& address) {
    using namespace std;
    for (auto it = io.begin(); it != io.end(); it++) {

        string name = it->first;
        Device* pDev = it->second;
        if (pDev->valid(address) == true)
            return pDev->read(address);
    }

    return 0xff;
}

void Bus::writeIo(const uint16_t& address, const uint8_t& value) {
    using namespace std;
    for (auto it = io.begin(); it != io.end(); it++) {

        string name = it->first;
        Device* pDev = it->second;
        if (pDev->valid(address) == true)
            pDev->write(address, value);
    }
}