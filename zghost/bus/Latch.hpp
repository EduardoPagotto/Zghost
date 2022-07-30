#pragma once
#include "Memory.hpp"

class Latch : public Memory {
  public:
    Latch(const uint16_t& address, const uint8_t& status) : Memory(address, 1, status) {}
    virtual ~Latch() = default;
    //
    bool readDirect(uint8_t& valueRet);
    bool writeDirect(const uint8_t& value);
};
