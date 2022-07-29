#pragma once
#include <zghost/z80/Z80.hpp>

void initOpCodeCB();
void opcodeCBStep(Z80* z, const uint8_t opcode);
