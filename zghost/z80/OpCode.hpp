#ifndef __OPCODE_HPP
#define __OPCODE_HPP

#include <zghost/z80/Z80.hpp>

class OpCode {
  public:
    OpCode();
    virtual ~OpCode();
    void step(Z80* z);

  private:
    void (*opcodemap[256])(Z80*, uint8_t);
    void (*opcodeCBMap[256])(Z80*, uint8_t);
    void (*opcodeDDMap[256])(Z80*, uint8_t);
    void (*opcodeDDCBMap[256])(Z80*, uint8_t, uint16_t);
    void (*opcodeEDMap[256])(Z80*, uint8_t);
    void (*opcodeDFMap[256])(Z80*, uint8_t);
};

#endif