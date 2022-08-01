#include <zghost/bus/Latch.hpp>

bool Latch::readDirect(uint8_t& valueRet) {
    if (status & DSTAT_ENABLED) {
        status &= (~DSTAT_CHANGED);
        valueRet = mem[0];
        return true;
    }
    return false;
}

bool Latch::writeDirect(const uint8_t& value) {
    if (status &= (DSTAT_READWRITE | DSTAT_ENABLED)) {
        status |= DSTAT_CHANGED;
        mem[0] = value;
        return true;
    }
    return false;
}