#ifndef __OPCODEFD_H__
#define __OPCODEFD_H__

#include <zghost/z80/Z80.hpp>

void initOpCodeFD();
void opcodeFDStep(Z80* z, const uint8_t opcode);

#endif // __OPCODEFD_H__