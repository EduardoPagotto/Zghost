#include <zghost/z80/OpCode.hpp>
#include <zghost/z80/OpCodeCB.hpp>
#include <zghost/z80/OpCodeDD.hpp>
#include <zghost/z80/OpCodeED.hpp>

void instr__NOP(Z80* z, const uint8_t& opcode) { z->Tstates += 4; }

void instr__LD_BC_NNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    z->loadR(z->BC);
}

void instr__LD_iBC_A(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->bus->writeMemory(z->BC->get(), z->A);
}

void instr__INC_BC(Z80* z, const uint8_t& opcode) {
    z->Tstates += 6;
    z->BC->inc();
}

void instr__INC_B(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    uint8_t* pReg = z->getPrtRegisterValByte(0);
    z->inc(pReg);
}

void instr__DEC_B(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    uint8_t* pReg = z->getPrtRegisterValByte(0);
    z->dec(pReg);
}

void instr__LD_B_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->B = z->load8();
}

void instr__RLCA(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    z->A = (z->A << 1) | (z->A >> 7);
    z->F = (z->F & (FLAG_P | FLAG_Z | FLAG_S)) | (z->A & (FLAG_C | FLAG_3 | FLAG_5));
}

/* EX AF,AF' */
void instr__EX_AF_AF(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;

    uint8_t olda = z->A;
    uint8_t oldf = z->F;

    z->A = z->A_;
    z->F = z->F_;
    z->A_ = olda;
    z->F_ = oldf;
}

/* ADD HL,BC */
void instr__ADD_HL_BC(Z80* z, const uint8_t& opcode) {
    z->Tstates += 11;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->add16(z->HL, z->BC->get());
}

/* LD A,(BC) */
void instr__LD_A_iBC(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->A = z->bus->readMemory(z->BC->get());
}

/* DEC BC */
void instr__DEC_BC(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 2)
    z->Tstates += 6;
    z->BC->dec();
}

/* INC C */
void instr__INC_C(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    uint8_t* pReg = z->getPrtRegisterValByte(1);
    z->inc(pReg);
}

/* DEC C */
void instr__DEC_C(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    uint8_t* pReg = z->getPrtRegisterValByte(1);
    z->dec(pReg);
}

// /* LD C,nn */
void instr__LD_C_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->C = z->load8();
}

/* RRCA */
void instr__RRCA(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    z->F = (z->F & (FLAG_P | FLAG_Z | FLAG_S)) | (z->A & FLAG_C);
    z->A = (z->A >> 1) | (z->A << 7);
    z->F |= (z->A & (FLAG_3 | FLAG_5));
}

/* DJNZ offset */
void instr__DJNZ_OFFSET(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    z->B--;
    if (z->B != 0) {
        z->Tstates += 1;
        z->jr();
    } else {
        // z->Memory.ContendRead(z->PC(), 3)
        z->Tstates += 8;
        z->pc++;
    }
    // z->IncPC(1) // TESTAR!!!!!!
}

/* LD DE,nnnn */
void instr__LD_DE_NNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    z->loadR(z->DE);
}

/* LD (DE),A */
void instr__LD_iDE_A(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->bus->writeMemory(z->DE->get(), z->A);
}

/* INC DE */
void instr__INC_DE(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 2)
    z->Tstates += 6;
    z->DE->inc();
}

/* INC D */
void instr__INC_D(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    uint8_t* pReg = z->getPrtRegisterValByte(2);
    z->inc(pReg);
}

/* DEC D */
void instr__DEC_D(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    uint8_t* pReg = z->getPrtRegisterValByte(2);
    z->dec(pReg);
}

// /* LD D,nn */
void instr__LD_D_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->D = z->load8();
}

/* RLA */
void instr__RLA(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    uint8_t bytetemp = z->A;
    z->A = (z->A << 1) | (z->F & FLAG_C);
    z->F = (z->F & (FLAG_P | FLAG_Z | FLAG_S)) | (z->A & (FLAG_3 | FLAG_5)) | (bytetemp >> 7);
}

/* JR offset */
void instr__JR_OFFSET(Z80* z, const uint8_t& opcode) { z->jr(); }

/* ADD HL,DE */
void instr__ADD_HL_DE(Z80* z, const uint8_t& opcode) {
    z->Tstates += 11;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->add16(z->HL, z->DE->get());
}

/* LD A,(DE) */
void instr__LD_A_iDE(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->A = z->bus->readMemory(z->DE->get());
}

/* DEC DE */
void instr__DEC_DE(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 2)
    z->Tstates += 6;
    z->DE->dec();
}

/* INC E */
void instr__INC_E(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    uint8_t* pReg = z->getPrtRegisterValByte(3);
    z->inc(pReg);
}

/* DEC E */
void instr__DEC_E(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    uint8_t* pReg = z->getPrtRegisterValByte(3);
    z->dec(pReg);
}

// /* LD E,nn */
void instr__LD_E_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->E = z->load8();
}

/* RRA */
void instr__RRA(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    uint8_t bytetemp = z->A;
    z->A = (z->A >> 1) | (z->F << 7);
    z->F = (z->F & (FLAG_P | FLAG_Z | FLAG_S)) | (z->A & (FLAG_3 | FLAG_5)) | (bytetemp & FLAG_C);
}

/* JR NZ,offset */
void instr__JR_NZ_OFFSET(Z80* z, const uint8_t& opcode) {
    if ((z->F & FLAG_Z) == 0) {
        z->jr();
    } else {
        z->Tstates += 7;
        // z->Memory.ContendRead(z->PC(), 3)
        z->pc++;
    }
}

/* LD HL,nnnn */
void instr__LD_HL_NNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    z->loadR(z->HL);
}

/* LD (nnnn),HL */
void instr__LD_iNNNN_HL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 16;
    z->storeIndexR(z->HL);
}

/* INC HL */
void instr__INC_HL(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 2)
    z->Tstates += 6;
    z->HL->inc();
}

/* INC H */
void instr__INC_H(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    uint8_t* pReg = z->getPrtRegisterValByte(4);
    z->inc(pReg);
}

/* DEC H */
void instr__DEC_H(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    uint8_t* pReg = z->getPrtRegisterValByte(4);
    z->dec(pReg);
}

// /* LD H,nn */
void instr__LD_H_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->H = z->load8();
}

/* DAA */
// void instr__DAA(Z80* z, const uint8_t& opcode) {
// 	z->Tstates += 4;

//     uint8_t add = 0;
//     uint8_t carry = (z->F & FLAG_C);

// 	if (((z->F & FLAG_H) != 0) || ((z->A & 0x0f) > 9)) {
// 		add = 6;
// 	}
// 	if ((carry != 0) || (z->A > 0x99)) {
// 		add |= 0x60;
// 	}
// 	if (z->A > 0x99) {
// 		carry = FLAG_C;
// 	}
// 	if ((z->F & FLAG_N) != 0) {
// 		z->sub(add);
// 	} else {
// 		z->add(add);
// 	}
// 	uint8_t temp = static_cast<uint8_t>(int(z->F) & ^(FLAG_C|FLAG_P)) | carry | parityTable[z->A]; //FIXME: questao do XOR!!!
// 	z->F = temp;
// }

/* JR Z,offset */
void instr__JR_Z_OFFSET(Z80* z, const uint8_t& opcode) {
    if ((z->F & FLAG_Z) != 0) {
        z->jr();
    } else {
        z->Tstates += 7;
        // z->Memory.ContendRead(z->PC(), 3)
        z->pc++;
    }
}

/* ADD HL,HL */
void instr__ADD_HL_HL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 11;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->add16(z->HL, z->HL->get());
}

/* LD HL,(nnnn) */
void instr__LD_HL_iNNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 16;
    z->loadIndexR(z->HL);
}

/* DEC HL */
void instr__DEC_HL(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 2)
    z->Tstates += 6;
    z->HL->dec();
}

/* INC L */
void instr__INC_L(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    uint8_t* pReg = z->getPrtRegisterValByte(5);
    z->inc(pReg);
}

/* DEC L */
void instr__DEC_L(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    uint8_t* pReg = z->getPrtRegisterValByte(5);
    z->dec(pReg);
}

// /* LD L,nn */
void instr__LD_L_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->L = z->load8();
}

/* CPL */
void instr__CPL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    z->A ^= 0xff;
    z->F = (z->F & (FLAG_C | FLAG_P | FLAG_Z | FLAG_S)) | (z->A & (FLAG_3 | FLAG_5)) | (FLAG_N | FLAG_H);
}

/* JR NC,offset */
void instr__JR_NC_OFFSET(Z80* z, const uint8_t& opcode) {
    if ((z->F & FLAG_C) == 0) {
        z->jr();
    } else {
        z->Tstates += 7;
        // z->Memory.ContendRead(z->PC(), 3)
        z->pc++;
    }
}

// /* LD SP,nnnn */
void instr__LD_SP_NNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    z->sp = z->load16();
}

// /* LD (nnnn),A */
void instr__LD_iNNNN_A(Z80* z, const uint8_t& opcode) {
    z->Tstates += 13;
    z->storeIndex8(z->A);
}

/* INC SP */
void instr__INC_SP(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 2)
    z->Tstates += 6;
    z->sp++;
}

/* INC (HL) */
void instr__INC_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 11;
    uint8_t bytetemp = z->bus->readMemory(z->HL->get());
    // z->Memory.ContendReadNoMreq(z->HL(), 1)
    z->inc(&bytetemp);
    z->bus->writeMemory(z->HL->get(), bytetemp);
}

/* DEC (HL) */
void instr__DEC_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 11;
    uint8_t bytetemp = z->bus->readMemory(z->HL->get());
    // z->Memory.ContendReadNoMreq(z->HL(), 1)
    z->dec(&bytetemp);
    z->bus->writeMemory(z->HL->get(), bytetemp);
}

/* LD (HL),nn */
void instr__LD_iHL_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    z->bus->writeMemory(z->HL->get(), z->load8());
}

/* SCF */
void instr__SCF(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    z->F = (z->F & (FLAG_P | FLAG_Z | FLAG_S)) | (z->A & (FLAG_3 | FLAG_5)) | FLAG_C;
}

/* JR C,offset */
void instr__JR_C_OFFSET(Z80* z, const uint8_t& opcode) {
    if ((z->F & FLAG_C) != 0) {
        z->jr();
    } else {
        z->Tstates += 7;
        // z->Memory.ContendRead(z->PC(), 3)
        z->pc++;
    }
}

/* ADD HL,SP */
void instr__ADD_HL_SP(Z80* z, const uint8_t& opcode) {
    z->Tstates += 11;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->add16(z->HL, z->sp);
}

/* LD A,(nnnn) */
void instr__LD_A_iNNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 13;
    z->loadIndex8(&z->A);
}

/* DEC SP */
void instr__DEC_SP(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 2)
    z->Tstates += 6;
    z->sp--;
}

/* INC A */
void instr__INC_A(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    uint8_t* pReg = z->getPrtRegisterValByte(7);
    z->inc(pReg);
}

/* DEC A */
void instr__DEC_A(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    uint8_t* pReg = z->getPrtRegisterValByte(7);
    z->dec(pReg);
}

/* LD A,nn */
void instr__LD_A_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->A = z->load8();
}

/* CCF */
void instr__CCF(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    z->F = (z->F & (FLAG_P | FLAG_Z | FLAG_S)) | ((z->F & FLAG_C) != 0 ? FLAG_H : FLAG_C) | (z->A & (FLAG_3 | FLAG_5));
}

/* LD B,r */
void instr__LD_B_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->B = z->getRegisterValByte(opcode);
}

/* LD B,(HL) */
void instr__LD_B_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->B = z->bus->readMemory(z->HL->get());
}

/* LD C,r */
void instr__LD_C_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->C = z->getRegisterValByte(opcode);
}

/* LD C,(HL) */
void instr__LD_C_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->C = z->bus->readMemory(z->HL->get());
}

/* LD D,r */
void instr__LD_D_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->D = z->getRegisterValByte(opcode);
}

/* LD D,(HL) */
void instr__LD_D_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->D = z->bus->readMemory(z->HL->get());
}

/* LD E,r */
void instr__LD_E_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->E = z->getRegisterValByte(opcode);
}

/* LD E,(HL) */
void instr__LD_E_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->E = z->bus->readMemory(z->HL->get());
}

/* LD H,r */
void instr__LD_H_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->H = z->getRegisterValByte(opcode);
}

/* LD H,(HL) */
void instr__LD_H_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->H = z->bus->readMemory(z->HL->get());
}

/* LD L,r */
void instr__LD_L_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->L = z->getRegisterValByte(opcode);
}

/* LD L,(HL) */
void instr__LD_L_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->L = z->bus->readMemory(z->HL->get());
}

/* LD (HL),r */
void instr__LD_iHL_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->bus->writeMemory(z->HL->get(), z->getRegisterValByte(opcode));
}

/* HALT */
void instr__HALT(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    z->Halted = true;
    // z->pc++
}

// /* LD A,r */
void instr__LD_A_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    z->A = z->getRegisterValByte(opcode);
}

/* LD A,(HL) */
void instr__LD_A_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->A = z->bus->readMemory(z->HL->get());
}

/* ADD A,r */
void instr__ADD_A_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    z->add(z->getRegisterValByte(opcode));
}

/* ADD A,(HL) */
void instr__ADD_A_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->add(z->bus->readMemory(z->HL->get()));
}

/* ADC A,r */
void instr__ADC_A_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    z->adc(z->getRegisterValByte(opcode));
}

/* ADC A,(HL) */
void instr__ADC_A_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    z->adc(z->bus->readMemory(z->HL->get()));
}

/* SUB A,r */
void instr__SUB_A_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    z->sub(z->getRegisterValByte(opcode));
}

/* SUB A,(HL) */
void instr__SUB_A_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->sub(z->bus->readMemory(z->HL->get()));
}

/* SBC A,r */
void instr__SBC_A_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    z->sbc(z->getRegisterValByte(opcode));
}

/* SBC A,(HL) */
void instr__SBC_A_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->sbc(z->bus->readMemory(z->HL->get()));
}

/* AND A,r */
void instr__AND_A_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    z->oppAnd(z->getRegisterValByte(opcode));
}

/* AND A,(HL) */
void instr__AND_A_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->oppAnd(z->bus->readMemory(z->HL->get()));
}

/* XOR A,r */
void instr__XOR_A_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    z->oppXor(z->getRegisterValByte(opcode));
}

/* XOR A,(HL) */
void instr__XOR_A_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->oppXor(z->bus->readMemory(z->HL->get()));
}

/* OR A,r */
void instr__OR_A_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    z->oppOr(z->getRegisterValByte(opcode));
}

/* OR A,(HL) */
void instr__OR_A_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->oppOr(z->bus->readMemory(z->HL->get()));
}

/* CP r */
void instr__CP_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    z->oppCp(z->getRegisterValByte(opcode));
}

/* CP (HL) */
void instr__CP_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->oppCp(z->bus->readMemory(z->HL->get()));
}

/* RET NZ */
void instr__RET_NZ(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    if (!((z->F & FLAG_Z) != 0)) {
        z->Tstates += 11;
        z->pc = z->pop();
    } else {
        z->Tstates += 5;
    }
}

/* POP BC */
void instr__POP_BC(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    z->popR(z->BC);
}

/* JP NZ,nnnn */
void instr__JP_NZ_NNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    if ((z->F & FLAG_Z) == 0) {
        z->pc = z->load16();
    } else {
        // z->Memory.ContendRead(z->PC(), 3)
        // z->Memory.ContendRead(z->PC()+1, 3)
        z->pc += 2;
    }
}

/* JP nnnn */
void instr__JP_NNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    z->pc = z->load16();
}

/* CALL NZ,nnnn */
void instr__CALL_NZ_NNNN(Z80* z, const uint8_t& opcode) {
    if ((z->F & FLAG_Z) == 0) {
        z->call();
    } else {
        // z->Memory.ContendRead(z->PC(), 3)
        // z->Memory.ContendRead(z->PC()+1, 3)
        z->Tstates += 10;
        z->pc += 2;
    }
}

/* PUSH BC */
void instr__PUSH_BC(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    z->Tstates += 11;
    z->pushR(z->BC);
}

/* ADD A,nn */
void instr__ADD_A_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->add(z->load8());
}

/* RST 00 */
void instr__RST_00(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    z->Tstates += 11;
    z->rst(0x00);
}

/* RET Z */
void instr__RET_Z(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    if ((z->F & FLAG_Z) != 0) {
        z->Tstates += 11;
        z->pc = z->pop();
    } else {
        z->Tstates += 5;
    }
}

// /* RET */
void instr__RET(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    z->pc = z->pop();
}

/* JP Z,nnnn */
void instr__JP_Z_NNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    if ((z->F & FLAG_Z) != 0) {
        z->pc = z->load16();
    } else {
        // z->Memory.ContendRead(z->PC(), 3)
        // z->Memory.ContendRead(z->PC()+1, 3)
        z->pc += 2; // z->IncPC(2)
    }
}

/* shift CB */
void instr__SHIFT_CB(Z80* z, const uint8_t& opcode) { opcodeCBStep(z, opcode); }

/* CALL Z,nnnn */
void instr__CALL_Z_NNNN(Z80* z, const uint8_t& opcode) {
    if ((z->F & FLAG_Z) != 0) {
        z->call();
    } else {
        // z->Memory.ContendRead(z->PC(), 3)
        // z->Memory.ContendRead(z->PC()+1, 3)
        z->Tstates += 10;
        z->pc += 2;
    }
}

// /* CALL nnnn */
void instr__CALL_NNNN(Z80* z, const uint8_t& opcode) {
    z->call(); // z->Tstate incluido
}

/* ADC A,nn */
void instr__ADC_A_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    uint8_t bytetemp = z->load8();
    z->adc(bytetemp);
}

// /* RST 8 */
void instr__RST_8(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    z->Tstates += 11;
    z->rst(0x08);
}

/* RET NC */
void instr__RET_NC(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    if (!((z->F & FLAG_C) != 0)) {
        z->Tstates += 11;
        z->pc = z->pop();
    } else {
        z->Tstates += 5;
    }
}

/* POP DE */
void instr__POP_DE(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    z->popR(z->DE);
}

/* JP NC,nnnn */
void instr__JP_NC_NNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    if ((z->F & FLAG_C) == 0) {
        z->pc = z->load16();
    } else {
        // z->Memory.ContendRead(z->PC(), 3)
        // z->Memory.ContendRead(z->PC()+1, 3)
        z->pc += 2;
    }
}

/* OUT (nn),A */
void instr__OUT_iNN_A(Z80* z, const uint8_t& opcode) {
    z->Tstates += 11;
    uint16_t addrOut = static_cast<int16_t>(z->load8()) + (static_cast<int16_t>(z->A) << 8);
    z->writePort(addrOut, z->A);
}

/* CALL NC,nnnn */
void instr__CALL_NC_NNNN(Z80* z, const uint8_t& opcode) {
    if ((z->F & FLAG_C) == 0) {
        z->call();
    } else {
        // z->Memory.ContendRead(z->PC(), 3)
        // z->Memory.ContendRead(z->PC()+1, 3)
        z->Tstates += 10;
        z->pc += 2;
    }
}

/* PUSH DE */
void instr__PUSH_DE(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    z->Tstates += 11;
    z->pushR(z->DE);
}

/* SUB nn */
void instr__SUB_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    uint8_t bytetemp = z->load8();
    z->sub(bytetemp);
}

/* RST 10 */
void instr__RST_10(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    z->Tstates += 11;
    z->rst(0x10);
}

/* RET C */
void instr__RET_C(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    if ((z->F & FLAG_C) != 0) {
        z->Tstates += 11;
        z->pc = z->pop();
    } else {
        z->Tstates += 5;
    }
}

/* EXX */
void instr__EXX(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    uint16_t wordtemp = z->BC->get();
    z->BC->set(z->BC_->get());
    z->BC_->set(wordtemp);

    wordtemp = z->DE->get();
    z->DE->set(z->DE_->get());
    z->DE_->set(wordtemp);

    wordtemp = z->HL->get();
    z->HL->set(z->HL_->get());
    z->HL_->set(wordtemp);
}

/* JP C,nnnn */
void instr__JP_C_NNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    if ((z->F & FLAG_C) != 0) {
        z->pc = z->load16();
    } else {
        // z->Memory.ContendRead(z->PC(), 3)
        // z->Memory.ContendRead(z->PC()+1, 3)
        z->pc += 2;
    }
}

/* IN A,(nn) */
void instr__IN_A_iNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 11;
    uint16_t intemp = static_cast<int16_t>(z->load8()) + (static_cast<int16_t>(z->A) << 8); // FIXME: preciso deslocar ????
    z->A = z->readPort(intemp);
}

/* CALL C,nnnn */
void instr__CALL_C_NNNN(Z80* z, const uint8_t& opcode) {
    if ((z->F & FLAG_C) != 0) {
        z->call();
    } else {
        // z->Memory.ContendRead(z->PC(), 3)
        // z->Memory.ContendRead(z->PC()+1, 3)
        z->Tstates += 10;
        z->pc += 2;
    }
}

/* shift DD */
void instr__SHIFT_DD(Z80* z, const uint8_t& opcode) { opcodeDDStep(z, opcode); }

/* SBC A,nn */
void instr__SBC_A_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    uint8_t bytetemp = z->load8();
    z->sbc(bytetemp);
}

/* RST 18 */
void instr__RST_18(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    z->Tstates += 11;
    z->rst(0x18);
}

/* RET PO */
void instr__RET_PO(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    if (!((z->F & FLAG_P) != 0)) {
        z->Tstates += 11;
        z->pc = z->pop();
    } else {
        z->Tstates += 5;
    }
}

// /* POP HL */
void instr__POP_HL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    z->popR(z->HL);
}

/* JP PO,nnnn */
void instr__JP_PO_NNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    if ((z->F & FLAG_P) == 0) {
        z->pc = z->load16();
    } else {
        // z->Memory.ContendRead(z->PC(), 3)
        // z->Memory.ContendRead(z->PC()+1, 3)
        z->pc += 2;
    }
}

/* EX (SP),HL */
void instr__EX_iSP_HL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint16_t bytetempl = z->bus->readMemory(z->sp);
    uint16_t bytetemph = z->bus->readMemory(z->sp + 1);
    // z->Memory.ContendReadNoMreq(z->SP()+1, 1)
    z->bus->writeMemory(z->sp + 1, z->H);
    z->bus->writeMemory(z->sp, z->L);
    // z->Memory.ContendWriteNoMreq_loop(z->SP(), 1, 2)
    z->L = bytetempl;
    z->H = bytetemph;
}

/* CALL PO,nnnn */
void instr__CALL_PO_NNNN(Z80* z, const uint8_t& opcode) {
    if ((z->F & FLAG_P) == 0) {
        z->call();
    } else {
        // z->Memory.ContendRead(z->PC(), 3)
        // z->Memory.ContendRead(z->PC()+1, 3)
        z->Tstates += 10;
        z->pc += 2;
    }
}

/* PUSH HL */
void instr__PUSH_HL(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    z->Tstates += 11;
    z->pushR(z->HL);
}

/* AND nn */
void instr__AND_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->oppAnd(z->load8());
}

/* RST 20 */
void instr__RST_20(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    z->Tstates += 11;
    z->rst(0x20);
}

/* RET PE */
void instr__RET_PE(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    if ((z->F & FLAG_P) != 0) {
        z->Tstates += 11;
        z->pc = z->pop();
    } else {
        z->Tstates += 5;
    }
}

/* JP HL */
void instr__JP_HL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4; // NÃoO É INDIRETO!!!
    z->pc = z->HL->get();
}

/* JP PE,nnnn */
void instr__JP_PE_NNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    if ((z->F & FLAG_P) != 0) {
        z->pc = z->load16();
    } else {
        // z->Memory.ContendRead(z->PC(), 3)
        // z->Memory.ContendRead(z->PC()+1, 3)
        z->pc += 2;
    }
}

/* EX DE,HL */
void instr__EX_DE_HL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    uint8_t d = z->D;
    uint8_t e = z->E;
    z->D = z->H;
    z->E = z->L;
    z->H = d;
    z->L = e;
}

/* CALL PE,nnnn */
void instr__CALL_PE_NNNN(Z80* z, const uint8_t& opcode) {
    if ((z->F & FLAG_P) != 0) {
        z->call();
    } else {
        // z->Memory.ContendRead(z->PC(), 3)
        // z->Memory.ContendRead(z->PC()+1, 3)
        z->Tstates += 10;
        z->pc += 2;
    }
}

/* shift ED */
void instr__SHIFT_ED(Z80* z, const uint8_t& opcode) { opcodeEDStep(z, opcode); }

/* XOR A,nn */
void instr__XOR_A_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->oppXor(z->load8());
}

/* RST 28 */
void instr__RST_28(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    z->Tstates += 11;
    z->rst(0x28);
}

/* RET P */
void instr__RET_P(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    if (!((z->F & FLAG_S) != 0)) {
        z->Tstates += 11;
        z->pc = z->pop();
    } else {
        z->Tstates += 5;
    }
}

/* POP AF */
void instr__POP_AF(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    z->popR(z->AF);
}

/* JP P,nnnn */
void instr__JP_P_NNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    if ((z->F & FLAG_S) == 0) {
        z->pc = z->load16();
    } else {
        // z->Memory.ContendRead(z->PC(), 3)
        // z->Memory.ContendRead(z->PC()+1, 3)
        z->pc += 2;
    }
}

/* DI */
void instr__DI(Z80* z, const uint8_t& opcode) {
    z->Tstates += 4;
    z->IFF1 = 0;
    z->IFF2 = 0;
}

/* CALL P,nnnn */
void instr__CALL_P_NNNN(Z80* z, const uint8_t& opcode) {
    if ((z->F & FLAG_S) == 0) {
        z->call();
    } else {
        // z->Memory.ContendRead(z->PC(), 3)
        // z->Memory.ContendRead(z->PC()+1, 3)
        z->Tstates += 10;
        z->pc += 2;
    }
}

/* PUSH AF */
void instr__PUSH_AF(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    z->Tstates += 11;
    z->pushR(z->AF);
}

/* OR nn */
void instr__OR_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->oppOr(z->load8());
}

/* RST 30 */
void instr__RST_30(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    z->Tstates += 11;
    z->rst(0x30);
}

/* RET M */
void instr__RET_M(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    if ((z->F & FLAG_S) != 0) {
        z->Tstates += 11;
        z->pc = z->pop();
    } else {
        z->Tstates += 5;
    }
}

/* LD SP,HL */
void instr__LD_SP_HL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 6;
    z->sp = z->HL->get();
}

/* JP M,nnnn */
void instr__JP_M_NNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    if ((z->F & FLAG_S) != 0) {
        z->pc = z->load16();
    } else {
        // z->Memory.ContendRead(z->PC(), 3)
        // z->Memory.ContendRead(z->PC()+1, 3)
        z->pc += 2;
    }
}

/* EI */
void instr__EI(Z80* z, const uint8_t& opcode) {
    /* Interrupts are not accepted immediately after an EI, but are
       accepted after the next instruction */
    z->Tstates += 4;
    z->IFF1 = 1;
    z->IFF2 = 1;
    z->interruptsEnabledAt = z->Tstates;
    // eventAdd(z->Tstates + 1, z80InterruptEvent)
}

/* CALL M,nnnn */
void instr__CALL_M_NNNN(Z80* z, const uint8_t& opcode) {
    if ((z->F & FLAG_S) != 0) {
        z->call();
    } else {
        // z->Memory.ContendRead(z->PC(), 3)
        // z->Memory.ContendRead(z->PC()+1, 3)
        z->Tstates += 10;
        z->pc += 2;
    }
}

// /* shift FD */
// void instr__SHIFT_FD(Z80* z, const uint8_t& opcode) {
// 	//z->Tstates += 4
// 	uint8_t opcode2 = z->load8();
// 	z->R++;
// 	if f := OpcodeDFMap[opcode2]; f != nil {
// 		f(z, opcode)
// 	} else {
// 		/* Instruction did not involve H or L */
// 		OpcodeMap[opcode2](z, opcode2) // FIXME: verificar se é isto mesmo!!!
// 	}
// }

/* CP nn */
void instr__CP_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 7;
    z->oppCp(z->load8());
}

/* RST 38 */
void instr__RST_38(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    z->Tstates += 11;
    z->rst(0x38);
}

void (*opcodemap[256])(Z80*, const uint8_t&);

void initOpCode() {
    opcodemap[0x0] = instr__NOP;
    opcodemap[0x01] = instr__LD_BC_NNNN;
    opcodemap[0x02] = instr__LD_iBC_A;
    opcodemap[0x03] = instr__INC_BC;
    opcodemap[0x04] = instr__INC_B;
    opcodemap[0x05] = instr__DEC_B;
    opcodemap[0x06] = instr__LD_B_NN;
    opcodemap[0x07] = instr__RLCA;
    opcodemap[0x08] = instr__EX_AF_AF;
    opcodemap[0x09] = instr__ADD_HL_BC;
    opcodemap[0x0a] = instr__LD_A_iBC;
    opcodemap[0x0b] = instr__DEC_BC;
    opcodemap[0x0c] = instr__INC_C;
    opcodemap[0x0d] = instr__DEC_C;
    opcodemap[0x0e] = instr__LD_C_NN;
    opcodemap[0x0f] = instr__RRCA;
    opcodemap[0x10] = instr__DJNZ_OFFSET;
    opcodemap[0x11] = instr__LD_DE_NNNN;
    opcodemap[0x12] = instr__LD_iDE_A;
    opcodemap[0x13] = instr__INC_DE;
    opcodemap[0x14] = instr__INC_D;
    opcodemap[0x15] = instr__DEC_D;
    opcodemap[0x16] = instr__LD_D_NN;
    opcodemap[0x17] = instr__RLA;
    opcodemap[0x18] = instr__JR_OFFSET;
    opcodemap[0x19] = instr__ADD_HL_DE;
    opcodemap[0x1a] = instr__LD_A_iDE;
    opcodemap[0x1b] = instr__DEC_DE;
    opcodemap[0x1c] = instr__INC_E;
    opcodemap[0x1d] = instr__DEC_E;
    opcodemap[0x1e] = instr__LD_E_NN;
    opcodemap[0x1f] = instr__RRA;
    opcodemap[0x20] = instr__JR_NZ_OFFSET;
    opcodemap[0x21] = instr__LD_HL_NNNN;
    opcodemap[0x22] = instr__LD_iNNNN_HL;
    opcodemap[0x23] = instr__INC_HL;
    opcodemap[0x24] = instr__INC_H;
    opcodemap[0x25] = instr__DEC_H;
    opcodemap[0x26] = instr__LD_H_NN;
    // opcodemap[0x27] = instr__DAA;
    opcodemap[0x28] = instr__JR_Z_OFFSET;
    opcodemap[0x29] = instr__ADD_HL_HL;
    opcodemap[0x2a] = instr__LD_HL_iNNNN;
    opcodemap[0x2b] = instr__DEC_HL;
    opcodemap[0x2c] = instr__INC_L;
    opcodemap[0x2d] = instr__DEC_L;
    opcodemap[0x2e] = instr__LD_L_NN;
    opcodemap[0x2f] = instr__CPL;
    opcodemap[0x30] = instr__JR_NC_OFFSET;
    opcodemap[0x31] = instr__LD_SP_NNNN;
    opcodemap[0x32] = instr__LD_iNNNN_A;
    opcodemap[0x33] = instr__INC_SP;
    opcodemap[0x34] = instr__INC_iHL;
    opcodemap[0x35] = instr__DEC_iHL;
    opcodemap[0x36] = instr__LD_iHL_NN;
    opcodemap[0x37] = instr__SCF;
    opcodemap[0x38] = instr__JR_C_OFFSET;
    opcodemap[0x39] = instr__ADD_HL_SP;
    opcodemap[0x3a] = instr__LD_A_iNNNN;
    opcodemap[0x3b] = instr__DEC_SP;
    opcodemap[0x3c] = instr__INC_A;
    opcodemap[0x3d] = instr__DEC_A;
    opcodemap[0x3e] = instr__LD_A_NN;
    opcodemap[0x3f] = instr__CCF;
    opcodemap[0x40] = instr__LD_B_r;
    opcodemap[0x41] = instr__LD_B_r;
    opcodemap[0x42] = instr__LD_B_r;
    opcodemap[0x43] = instr__LD_B_r;
    opcodemap[0x44] = instr__LD_B_r;
    opcodemap[0x45] = instr__LD_B_r;
    opcodemap[0x46] = instr__LD_B_iHL;
    opcodemap[0x47] = instr__LD_B_r;
    opcodemap[0x48] = instr__LD_C_r;
    opcodemap[0x49] = instr__LD_C_r;
    opcodemap[0x4a] = instr__LD_C_r;
    opcodemap[0x4b] = instr__LD_C_r;
    opcodemap[0x4c] = instr__LD_C_r;
    opcodemap[0x4d] = instr__LD_C_r;
    opcodemap[0x4e] = instr__LD_C_iHL;
    opcodemap[0x4f] = instr__LD_C_r;
    opcodemap[0x50] = instr__LD_D_r;
    opcodemap[0x51] = instr__LD_D_r;
    opcodemap[0x52] = instr__LD_D_r;
    opcodemap[0x53] = instr__LD_D_r;
    opcodemap[0x54] = instr__LD_D_r;
    opcodemap[0x55] = instr__LD_D_r;
    opcodemap[0x56] = instr__LD_D_iHL;
    opcodemap[0x57] = instr__LD_D_r;
    opcodemap[0x58] = instr__LD_E_r;
    opcodemap[0x59] = instr__LD_E_r;
    opcodemap[0x5a] = instr__LD_E_r;
    opcodemap[0x5b] = instr__LD_E_r;
    opcodemap[0x5c] = instr__LD_E_r;
    opcodemap[0x5d] = instr__LD_E_r;
    opcodemap[0x5e] = instr__LD_E_iHL;
    opcodemap[0x5f] = instr__LD_E_r;
    opcodemap[0x60] = instr__LD_H_r;
    opcodemap[0x61] = instr__LD_H_r;
    opcodemap[0x62] = instr__LD_H_r;
    opcodemap[0x63] = instr__LD_H_r;
    opcodemap[0x64] = instr__LD_H_r;
    opcodemap[0x65] = instr__LD_H_r;
    opcodemap[0x66] = instr__LD_H_iHL;
    opcodemap[0x67] = instr__LD_H_r;
    opcodemap[0x68] = instr__LD_L_r;
    opcodemap[0x69] = instr__LD_L_r;
    opcodemap[0x6a] = instr__LD_L_r;
    opcodemap[0x6b] = instr__LD_L_r;
    opcodemap[0x6c] = instr__LD_L_r;
    opcodemap[0x6d] = instr__LD_L_r;
    opcodemap[0x6e] = instr__LD_L_iHL;
    opcodemap[0x6f] = instr__LD_L_r;
    opcodemap[0x70] = instr__LD_iHL_r;
    opcodemap[0x71] = instr__LD_iHL_r;
    opcodemap[0x72] = instr__LD_iHL_r;
    opcodemap[0x73] = instr__LD_iHL_r;
    opcodemap[0x74] = instr__LD_iHL_r;
    opcodemap[0x75] = instr__LD_iHL_r;
    opcodemap[0x76] = instr__HALT;
    opcodemap[0x77] = instr__LD_iHL_r;
    opcodemap[0x78] = instr__LD_A_r;
    opcodemap[0x79] = instr__LD_A_r;
    opcodemap[0x7a] = instr__LD_A_r;
    opcodemap[0x7b] = instr__LD_A_r;
    opcodemap[0x7c] = instr__LD_A_r;
    opcodemap[0x7d] = instr__LD_A_r;
    opcodemap[0x7e] = instr__LD_A_iHL;
    opcodemap[0x7f] = instr__LD_A_r;
    opcodemap[0x80] = instr__ADD_A_r;
    opcodemap[0x81] = instr__ADD_A_r;
    opcodemap[0x82] = instr__ADD_A_r;
    opcodemap[0x83] = instr__ADD_A_r;
    opcodemap[0x84] = instr__ADD_A_r;
    opcodemap[0x85] = instr__ADD_A_r;
    opcodemap[0x86] = instr__ADD_A_iHL;
    opcodemap[0x87] = instr__ADD_A_r;
    opcodemap[0x88] = instr__ADC_A_r;
    opcodemap[0x89] = instr__ADC_A_r;
    opcodemap[0x8a] = instr__ADC_A_r;
    opcodemap[0x8b] = instr__ADC_A_r;
    opcodemap[0x8c] = instr__ADC_A_r;
    opcodemap[0x8d] = instr__ADC_A_r;
    opcodemap[0x8e] = instr__ADC_A_iHL;
    opcodemap[0x8f] = instr__ADC_A_r;
    opcodemap[0x90] = instr__SUB_A_r;
    opcodemap[0x91] = instr__SUB_A_r;
    opcodemap[0x92] = instr__SUB_A_r;
    opcodemap[0x93] = instr__SUB_A_r;
    opcodemap[0x94] = instr__SUB_A_r;
    opcodemap[0x95] = instr__SUB_A_r;
    opcodemap[0x96] = instr__SUB_A_iHL;
    opcodemap[0x97] = instr__SUB_A_r;
    opcodemap[0x98] = instr__SBC_A_r;
    opcodemap[0x99] = instr__SBC_A_r;
    opcodemap[0x9a] = instr__SBC_A_r;
    opcodemap[0x9b] = instr__SBC_A_r;
    opcodemap[0x9c] = instr__SBC_A_r;
    opcodemap[0x9d] = instr__SBC_A_r;
    opcodemap[0x9e] = instr__SBC_A_iHL;
    opcodemap[0x9f] = instr__SBC_A_r;
    opcodemap[0xa0] = instr__AND_A_r;
    opcodemap[0xa1] = instr__AND_A_r;
    opcodemap[0xa2] = instr__AND_A_r;
    opcodemap[0xa3] = instr__AND_A_r;
    opcodemap[0xa4] = instr__AND_A_r;
    opcodemap[0xa5] = instr__AND_A_r;
    opcodemap[0xa6] = instr__AND_A_iHL;
    opcodemap[0xa7] = instr__AND_A_r;
    opcodemap[0xa8] = instr__XOR_A_r;
    opcodemap[0xa9] = instr__XOR_A_r;
    opcodemap[0xaa] = instr__XOR_A_r;
    opcodemap[0xab] = instr__XOR_A_r;
    opcodemap[0xac] = instr__XOR_A_r;
    opcodemap[0xad] = instr__XOR_A_r;
    opcodemap[0xae] = instr__XOR_A_iHL;
    opcodemap[0xaf] = instr__XOR_A_r;
    opcodemap[0xb0] = instr__OR_A_r;
    opcodemap[0xb1] = instr__OR_A_r;
    opcodemap[0xb2] = instr__OR_A_r;
    opcodemap[0xb3] = instr__OR_A_r;
    opcodemap[0xb4] = instr__OR_A_r;
    opcodemap[0xb5] = instr__OR_A_r;
    opcodemap[0xb6] = instr__OR_A_iHL;
    opcodemap[0xb7] = instr__OR_A_r;
    opcodemap[0xb8] = instr__CP_r;
    opcodemap[0xb9] = instr__CP_r;
    opcodemap[0xba] = instr__CP_r;
    opcodemap[0xbb] = instr__CP_r;
    opcodemap[0xbc] = instr__CP_r;
    opcodemap[0xbd] = instr__CP_r;
    opcodemap[0xbe] = instr__CP_iHL;
    opcodemap[0xbf] = instr__CP_r;
    opcodemap[0xc0] = instr__RET_NZ;
    opcodemap[0xc1] = instr__POP_BC;
    opcodemap[0xc2] = instr__JP_NZ_NNNN;
    opcodemap[0xc3] = instr__JP_NNNN;
    opcodemap[0xc4] = instr__CALL_NZ_NNNN;
    opcodemap[0xc5] = instr__PUSH_BC;
    opcodemap[0xc6] = instr__ADD_A_NN;
    opcodemap[0xc7] = instr__RST_00;
    opcodemap[0xc8] = instr__RET_Z;
    opcodemap[0xc9] = instr__RET;
    opcodemap[0xca] = instr__JP_Z_NNNN;
    // opcodemap[0xcb] = instr__SHIFT_CB;
    opcodemap[0xcc] = instr__CALL_Z_NNNN;
    opcodemap[0xcd] = instr__CALL_NNNN;
    opcodemap[0xce] = instr__ADC_A_NN;
    opcodemap[0xcf] = instr__RST_8;
    opcodemap[0xd0] = instr__RET_NC;
    opcodemap[0xd1] = instr__POP_DE;
    opcodemap[0xd2] = instr__JP_NC_NNNN;
    opcodemap[0xd3] = instr__OUT_iNN_A;
    opcodemap[0xd4] = instr__CALL_NC_NNNN;
    opcodemap[0xd5] = instr__PUSH_DE;
    opcodemap[0xd6] = instr__SUB_NN;
    opcodemap[0xd7] = instr__RST_10;
    opcodemap[0xd8] = instr__RET_C;
    opcodemap[0xd9] = instr__EXX;
    opcodemap[0xda] = instr__JP_C_NNNN;
    opcodemap[0xdb] = instr__IN_A_iNN;
    opcodemap[0xdc] = instr__CALL_C_NNNN;
    // opcodemap[0xdd] = instr__SHIFT_DD;
    opcodemap[0xde] = instr__SBC_A_NN;
    opcodemap[0xdf] = instr__RST_18;
    opcodemap[0xe0] = instr__RET_PO;
    opcodemap[0xe1] = instr__POP_HL;
    opcodemap[0xe2] = instr__JP_PO_NNNN;
    opcodemap[0xe3] = instr__EX_iSP_HL;
    opcodemap[0xe4] = instr__CALL_PO_NNNN;
    opcodemap[0xe5] = instr__PUSH_HL;
    opcodemap[0xe6] = instr__AND_NN;
    opcodemap[0xe7] = instr__RST_20;
    opcodemap[0xe8] = instr__RET_PE;
    opcodemap[0xe9] = instr__JP_HL;
    opcodemap[0xea] = instr__JP_PE_NNNN;
    opcodemap[0xeb] = instr__EX_DE_HL;
    opcodemap[0xec] = instr__CALL_PE_NNNN;
    // opcodemap[0xed] = instr__SHIFT_ED;
    opcodemap[0xee] = instr__XOR_A_NN;
    opcodemap[0xef] = instr__RST_28;
    opcodemap[0xf0] = instr__RET_P;
    opcodemap[0xf1] = instr__POP_AF;
    opcodemap[0xf2] = instr__JP_P_NNNN;
    opcodemap[0xf3] = instr__DI;
    opcodemap[0xf4] = instr__CALL_P_NNNN;
    opcodemap[0xf5] = instr__PUSH_AF;
    opcodemap[0xf6] = instr__OR_NN;
    opcodemap[0xf7] = instr__RST_30;
    opcodemap[0xf8] = instr__RET_M;
    opcodemap[0xf9] = instr__LD_SP_HL;
    opcodemap[0xfa] = instr__JP_M_NNNN;
    opcodemap[0xfb] = instr__EI;
    opcodemap[0xfc] = instr__CALL_M_NNNN;
    // opcodemap[0xfd] = instr__SHIFT_FD;
    opcodemap[0xfe] = instr__CP_NN;
    opcodemap[0xff] = instr__RST_38;

    initOpCodeCB();
    initOpCodeED();
    initOpCodeDD();
}

void opcodeStep(Z80* z, const uint8_t opcode) { opcodemap[opcode](z, opcode); }
