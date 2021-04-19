#include <zghost/z80/OpCode.hpp>

void instr__NOP(Z80* z, uint8_t opcode) { z->Tstates += 4; }

OpCode::OpCode() { opcodemap[0x0] = instr__NOP; }

OpCode::~OpCode() {}

void OpCode::step(Z80* z) {

    if (z->Halted == false) {
        uint8_t opcode = z->bus->readMemory(z->pc);
        z->R = (z->R + 1) & 0x7f;
        z->pc++;
        opcodemap[opcode](z, opcode);
    } else {
        z->Tstates += 4;
        z->R = (z->R + 1) & 0x7f;
        ;
    }
}