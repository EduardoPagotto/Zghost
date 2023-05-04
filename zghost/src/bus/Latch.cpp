#include <zghost/bus/Latch.hpp>

bool Latch::readDirect(uint8_t& valueRet) {
    if (status & DEV_OPENED) {
        status &= (~DEV_CHANGED);
        valueRet = mem[0];
        return true;
    }
    return false;
}

bool Latch::writeDirect(const uint8_t& value) {
    if (status &= (DEV_RW | DEV_OPENED)) {
        status |= DEV_CHANGED;
        mem[0] = value;
        return true;
    }
    return false;
}