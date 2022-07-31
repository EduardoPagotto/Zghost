#pragma once
#include <zghost/z80/Z80.hpp>

class Console {
  public:
    Console();
    virtual ~Console();
    void exec();

  private:
    uint16_t idRom;
    uint16_t idRam;
    uint16_t idPortA;
    uint16_t idPortB;
    Z80 z80;
    Bus bus;
};
