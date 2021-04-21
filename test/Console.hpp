#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <zghost/bus/Bus.hpp>
#include <zghost/bus/Latch.hpp>
#include <zghost/bus/Memory.hpp>
#include <zghost/z80/Z80.hpp>

class Console {
  public:
    Console();
    virtual ~Console();
    void exec();

  private:
    Bus bus;
    Z80* z80;
    Memory* ram;
    Memory* rom;
    Latch* portA;
    Latch* portB;
};

#endif // __CONSOLE_H__