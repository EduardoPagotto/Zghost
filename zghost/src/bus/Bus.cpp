#include <zghost/bus/Bus.hpp>

uint8_t Bus::read(const uint16_t& address) {
    uint8_t ret = 0xff;
    for (auto it = dev.begin(); it != dev.end(); it++) {
        Device* pDev = it->second;
        if (pDev->read(address, ret))
            return ret;
    }
    return ret;
}

void Bus::write(const uint16_t& address, const uint8_t& value) {
    for (auto it = dev.begin(); it != dev.end(); it++) {
        Device* pDev = it->second;
        if (pDev->write(address, value))
            return;
    }
}
