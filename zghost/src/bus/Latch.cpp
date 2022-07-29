#include <zghost/bus/Latch.hpp>

bool Latch::write(const uint16_t& address, const uint8_t& value) {
    if ((!readOnly) && valid(address)) {
        this->value = value;
        this->changed = true;
        return true;
    }
    return false;
}

bool Latch::read(const uint16_t& address, uint8_t& valueRet) {
    if (valid(address)) {
        this->changed = false;
        valueRet = this->value;
        return true;
    }
    return false;
}

bool Latch::readDirect(uint8_t& valueRet) {
    if (enable) {
        this->changed = false;
        valueRet = this->value;
        return true;
    }

    return false;
}

bool Latch::writeDirect(const uint8_t& value) {
    if ((!readOnly) && enable) {
        this->changed = true;
        this->value = value;
        return true;
    }

    return false;
}