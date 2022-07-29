#include <zghost/bus/Bus.hpp>

uint8_t Bus::read(const uint16_t& address) {
    for (auto it = dev.begin(); it != dev.end(); it++) {

        std::string name = it->first;
        Device* pDev = it->second;
        if (pDev->valid(address) == true)
            return pDev->read(address);
    }
    return 0xff;
}

void Bus::write(const uint16_t& address, const uint8_t& value) {
    for (auto it = dev.begin(); it != dev.end(); it++) {

        std::string name = it->first;
        Device* pDev = it->second;
        if (pDev->valid(address) == true)
            pDev->write(address, value);
    }
}
