#pragma once
#include <zghost/z80/Z80.hpp>

class Console {
  public:
    Console();
    virtual ~Console();
    void exec();

  private:
    Z80 z80;
    Bus bus;
};
