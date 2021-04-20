#include <zghost/z80/OpCodeDD.hpp>

void (*opcodemapdd[256])(Z80*, const uint8_t&);

void initOpCodeDD() {}

void opcodeDDStep(Z80* z, const uint8_t opcode) {
    // z->Tstates += 4
    uint8_t opcode2 = z->load8();
    z->R++;
    opcodemapdd[opcode2](z, opcode2); // FIXME: verificar!!!!!
}