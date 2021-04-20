#include <zghost/z80/OpCode.hpp>

void instr__NOP(Z80* z, uint8_t opcode) { z->Tstates += 4; }

void (*opcodemap[256])(Z80*, uint8_t);

void initOpCode() { opcodemap[0x0] = instr__NOP; }
void opcodeStep(Z80* z, const uint8_t opcode) { opcodemap[opcode](z, opcode); }