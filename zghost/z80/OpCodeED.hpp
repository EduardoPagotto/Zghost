#ifndef __OPCODEED_H__
#define __OPCODEED_H__

#include <zghost/z80/Z80.hpp>

void initOpCodeED();
void opcodeEDStep(Z80* z, const uint8_t opcode);

#endif // __OPCODEED_H__