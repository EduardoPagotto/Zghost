#pragma once
#include <zghost/z80/Z80.hpp>

void initOpCode();
void opcodeStep(Z80* z, const uint8_t opcode);
