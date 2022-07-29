#pragma once
#include <zghost/z80/Z80.hpp>

void initOpCodeED();
void opcodeEDStep(Z80* z, const uint8_t opcode);
