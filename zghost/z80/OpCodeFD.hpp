#pragma once
#include <zghost/z80/Z80.hpp>

void initOpCodeFD();
void opcodeFDStep(Z80* z, const uint8_t opcode);
