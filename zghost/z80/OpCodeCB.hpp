#ifndef __OPCODECB_H__
#define __OPCODECB_H__

#include <zghost/z80/Z80.hpp>

void initOpCodeCB();
void opcodeCBStep(Z80* z, const uint8_t opcode);

#endif // __OPCODECB_H__