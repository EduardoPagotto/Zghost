#include <zghost/bus/Bus.hpp>

uint8_t Bus::readMemory(const uint16_t& address) {
    using namespace std;
    for (auto it = mem.begin(); it != mem.end(); it++) {

        string name = it->first;
        Device* pDev = it->second;

        uint8_t val;
        bool ok;

        tie(val, ok) = pDev->read(address);
        if (ok) {
            return val;
        }
    }

    return 0xff;
}

void Bus::writeMemory(const uint16_t& address, const uint8_t& value) {

    using namespace std;
    for (auto it = mem.begin(); it != mem.end(); it++) {

        string name = it->first;
        Device* pDev = it->second;

        if (pDev->write(address, value))
            return;
    }
}

uint8_t Bus::readIo(const uint16_t& address) {
    using namespace std;
    for (auto it = io.begin(); it != io.end(); it++) {

        string name = it->first;
        Device* pDev = it->second;

        uint8_t val;
        bool ok;

        tie(val, ok) = pDev->read(address);
        if (ok) {
            return val;
        }
    }

    return 0xff;
}

void Bus::writeIo(const uint16_t& address, const uint8_t& value) {
    using namespace std;
    for (auto it = mem.begin(); it != mem.end(); it++) {

        string name = it->first;
        Device* pDev = it->second;

        if (pDev->write(address, value))
            return;
    }
}