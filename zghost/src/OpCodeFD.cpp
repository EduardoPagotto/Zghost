#include <zghost/z80/OpCodeDDCBFDCB.hpp>
#include <zghost/z80/OpCodeFD.hpp>

/* ADD iy,BC */
void instrFD__ADD_REG_BC(Z80* z, const uint8_t& opcode) {
    z->Tstates += 15;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->add16(z->IY, z->BC->get());
}

/* ADD iy,DE */
void instrFD__ADD_REG_DE(Z80* z, const uint8_t& opcode) {
    z->Tstates += 15;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->add16(z->IY, z->DE->get());
}

/* LD iy,nnnn */
void instrFD__LD_REG_NNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 14;
    z->loadR(z->IY);
}

/* LD (nnnn),iy */
void instrFD__LD_iNNNN_REG(Z80* z, const uint8_t& opcode) {
    z->Tstates += 20;
    z->storeIndexR(z->IY);
}

/* INC iy */
void instrFD__INC_REG(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 2)
    z->IY->inc(); // z->IncIY()
}

/* INC IYH */
void instrFD__INC_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->inc(&z->IYH);
}

/* DEC IYH */
void instrFD__DEC_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->dec(&z->IYH); // decIYH()
}

/* LD IYH,nn */
void instrFD__LD_REGH_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IYH = z->load8();
}

/* ADD iy,iy */
void instrFD__ADD_REG_REG(Z80* z, const uint8_t& opcode) {
    z->Tstates += 15;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->add16(z->IY, z->IY->get());
}

/* LD iy,(nnnn) */
void instrFD__LD_REG_iNNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 20;
    z->loadIndexR(z->IY);
}

/* DEC iy */
void instrFD__DEC_REG(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 2)
    z->IY->dec();
}

/* INC IYL */
void instrFD__INC_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->inc(&z->IYL); // incIYL()
}

/* DEC IYL */
void instrFD__DEC_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->dec(&z->IYL); // decIYL()
}

/* LD IYL,nn */
void instrFD__LD_REGL_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IYL = z->load8();
}

/* INC (iy+dd) */
void instrFD__INC_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 23;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint16_t wordtemp = z->IY->get() + static_cast<uint16_t>(R16::signExtend(offset));
    uint8_t bytetemp = z->bus->readMemory(wordtemp);
    // z->Memory.ContendReadNoMreq(wordtemp, 1)
    z->inc(&bytetemp);
    z->bus->writeMemory(wordtemp, bytetemp);
}

/* DEC (iy+dd) */
void instrFD__DEC_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 23;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint16_t wordtemp = z->IY->get() + static_cast<uint16_t>(R16::signExtend(offset));
    uint8_t bytetemp = z->bus->readMemory(wordtemp);
    // z->Memory.ContendReadNoMreq(wordtemp, 1)
    z->dec(&bytetemp);
    z->bus->writeMemory(wordtemp, bytetemp);
}

/* LD (iy+dd),nn */
void instrFD__LD_iREGpDD_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    uint8_t value = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 2)
    z->bus->writeMemory(z->IY->get() + static_cast<uint16_t>(R16::signExtend(offset)), value);
}

/* ADD iy,SP */
void instrFD__ADD_REG_SP(Z80* z, const uint8_t& opcode) {
    z->Tstates += 15;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->add16(z->IY, z->sp);
}

/* LD B,IYH */
void instrFD__LD_B_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->B = z->IYH;
}

/* LD B,IYL */
void instrFD__LD_B_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->B = z->IYL;
}

/* LD B,(iy+dd) */
void instrFD__LD_B_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    z->B = z->bus->readMemory(z->IY->get() + static_cast<uint16_t>(R16::signExtend(offset)));
}

/* LD C,IYH */
void instrFD__LD_C_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->C = z->IYH;
}

/* LD C,IYL */
void instrFD__LD_C_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->C = z->IYL;
}

/* LD C,(iy+dd) */
void instrFD__LD_C_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    z->C = z->bus->readMemory(z->IY->get() + static_cast<uint16_t>(R16::signExtend(offset)));
}

/* LD D,IYH */
void instrFD__LD_D_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->D = z->IYH;
}

/* LD D,IYL */
void instrFD__LD_D_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->D = z->IYL;
}

/* LD D,(iy+dd) */
void instrFD__LD_D_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    z->D = z->bus->readMemory(z->IY->get() + static_cast<uint16_t>(R16::signExtend(offset)));
}

/* LD E,IYH */
void instrFD__LD_E_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->E = z->IYH;
}

/* LD E,IYL */
void instrFD__LD_E_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->E = z->IYL;
}

/* LD E,(iy+dd) */
void instrFD__LD_E_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    z->E = z->bus->readMemory(z->IY->get() + static_cast<uint16_t>(R16::signExtend(offset)));
}

/* LD IYH,B */
void instrFD__LD_REGH_B(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IYH = z->B;
}

/* LD IYH,C */
void instrFD__LD_REGH_C(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IYH = z->C;
}

/* LD IYH,D */
void instrFD__LD_REGH_D(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IYH = z->D;
}

/* LD IYH,E */
void instrFD__LD_REGH_E(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IYH = z->E;
}

/* LD IYH,IYH */
void instrFD__LD_REGH_REGH(Z80* z, const uint8_t& opcode) { z->Tstates += 8; }

/* LD IYH,IYL */
void instrFD__LD_REGH_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IYH = z->IYL;
}

/* LD H,(iy+dd) */
void instrFD__LD_H_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    z->H = z->bus->readMemory(z->IY->get() + static_cast<uint16_t>(R16::signExtend(offset)));
}

/* LD IYH,A */
void instrFD__LD_REGH_A(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IYH = z->A;
}

/* LD IYL,B */
void instrFD__LD_REGL_B(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IYL = z->B;
}

/* LD IYL,C */
void instrFD__LD_REGL_C(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IYL = z->C;
}

/* LD IYL,D */
void instrFD__LD_REGL_D(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IYL = z->D;
}

/* LD IYL,E */
void instrFD__LD_REGL_E(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IYL = z->E;
}

/* LD IYL,IYH */
void instrFD__LD_REGL_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IYL = z->IYH;
}

/* LD IYL,IYL */
void instrFD__LD_REGL_REGL(Z80* z, const uint8_t& opcode) { z->Tstates += 8; }

/* LD L,(iy+dd) */
void instrFD__LD_L_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    z->L = z->bus->readMemory(z->IY->get() + static_cast<uint16_t>(R16::signExtend(offset)));
}

/* LD IYL,A */
void instrFD__LD_REGL_A(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IYL = z->A;
}

/* LD (iy+dd),r */
void instrFD__LD_iREGpDD_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint8_t* reg = z->getPrtRegisterValByte(opcode);
    z->bus->writeMemory(z->IY->get() + static_cast<uint16_t>(R16::signExtend(offset)), *reg);
}

/* LD A,IYH */
void instrFD__LD_A_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->A = z->IYH;
}

/* LD A,IYL */
void instrFD__LD_A_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->A = z->IYL;
}

/* LD A,(iy+dd) */
void instrFD__LD_A_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    z->A = z->bus->readMemory(z->IY->get() + static_cast<uint16_t>(R16::signExtend(offset)));
}

/* ADD A,IYH */
void instrFD__ADD_A_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->add(z->IYH);
}

/* ADD A,IYL */
void instrFD__ADD_A_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->add(z->IYL);
}

/* ADD A,(iy+dd) */
void instrFD__ADD_A_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint8_t bytetemp = z->bus->readMemory(z->IY->get() + static_cast<uint16_t>(R16::signExtend(offset)));
    z->add(bytetemp);
}

/* ADC A,IYH */
void instrFD__ADC_A_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->adc(z->IYH);
}

/* ADC A,IYL */
void instrFD__ADC_A_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->adc(z->IYL);
}

/* ADC A,(iy+dd) */
void instrFD__ADC_A_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint8_t bytetemp = z->bus->readMemory(z->IY->get() + static_cast<uint16_t>(R16::signExtend(offset)));
    z->adc(bytetemp);
}

/* SUB A,IYH */
void instrFD__SUB_A_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->sub(z->IYH);
}

/* SUB A,IYL */
void instrFD__SUB_A_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->sub(z->IYL);
}

/* SUB A,(iy+dd) */
void instrFD__SUB_A_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint8_t bytetemp = z->bus->readMemory(z->IY->get() + static_cast<uint16_t>(R16::signExtend(offset)));
    z->sub(bytetemp);
}

/* SBC A,IYH */
void instrFD__SBC_A_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->sbc(z->IYH);
}

/* SBC A,IYL */
void instrFD__SBC_A_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->sbc(z->IYL);
}

/* SBC A,(iy+dd) */
void instrFD__SBC_A_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 18;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint8_t bytetemp = z->bus->readMemory(z->IY->get() + static_cast<uint16_t>(R16::signExtend(offset)));
    z->sbc(bytetemp);
}

/* AND A,IYH */
void instrFD__AND_A_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->oppAnd(z->IYH);
}

/* AND A,IYL */
void instrFD__AND_A_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->oppAnd(z->IYL);
}

/* AND A,(iy+dd) */
void instrFD__AND_A_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint8_t bytetemp = z->bus->readMemory(z->IY->get() + static_cast<uint16_t>(R16::signExtend(offset)));
    z->oppAnd(bytetemp);
}

/* XOR A,IYH */
void instrFD__XOR_A_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->oppXor(z->IYH);
}

/* XOR A,IYL */
void instrFD__XOR_A_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->oppXor(z->IYL);
}

/* XOR A,(iy+dd) */
void instrFD__XOR_A_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint8_t bytetemp = z->bus->readMemory(z->IY->get() + static_cast<uint16_t>(R16::signExtend(offset)));
    z->oppXor(bytetemp);
}

/* OR A,IYH */
void instrFD__OR_A_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->oppOr(z->IYH);
}

/* OR A,IYL */
void instrFD__OR_A_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->oppOr(z->IYL);
}

/* OR A,(iy+dd) */
void instrFD__OR_A_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint8_t bytetemp = z->bus->readMemory(z->IY->get() + static_cast<uint16_t>(R16::signExtend(offset)));
    z->oppOr(bytetemp);
}

/* CP A,IYH */
void instrFD__CP_A_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->oppCp(z->IYH);
}

/* CP A,IYL */
void instrFD__CP_A_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->oppCp(z->IYL);
}

/* CP A,(iy+dd) */
void instrFD__CP_A_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint8_t bytetemp = z->bus->readMemory(z->IY->get() + static_cast<uint16_t>(R16::signExtend(offset)));
    z->oppCp(bytetemp);
}

/* shift DDFDCB */
void instrFD__SHIFT_DDFDCB(Z80* z, const uint8_t& opcode) {
    // z->Tstates += 4
    uint16_t addr = z->IY->get() + static_cast<uint16_t>(R16::signExtend(z->load8()));
    uint8_t opcode2 = z->load8();
    z->R++;
    opcodeDDCBFDCBStep(z, opcode2, addr);
}

/* POP iy */
void instrFD__POP_REG(Z80* z, const uint8_t& opcode) {
    z->Tstates += 14;
    z->popR(z->IY);
}

/* EX (SP),iy */
void instrFD__EX_iSP_REG(Z80* z, const uint8_t& opcode) {
    z->Tstates += 23;
    uint8_t bytetempl = z->bus->readMemory(z->sp);
    uint8_t bytetemph = z->bus->readMemory(z->sp + 1);
    // z->Memory.ContendReadNoMreq(z->sp+1, 1)
    z->bus->writeMemory(z->sp + 1, z->IYH);
    z->bus->writeMemory(z->sp, z->IYL);
    // z->Memory.ContendWriteNoMreq_loop(z->sp, 1, 2)
    z->IYL = bytetempl;
    z->IYH = bytetemph;
}

/* PUSH iy */
void instrFD__PUSH_REG(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    z->Tstates += 15;
    z->pushR(z->IY);
}

/* JP iy */
void instrFD__JP_REG(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->pc = z->IY->get();
    // z->SetPC(z->IY->get()) /* NB: NOT INDIRECT! */
}

/* LD SP,iy */
void instrFD__LD_SP_REG(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 2)
    z->sp = z->IY->get();
}

void (*opcodemapfd[256])(Z80*, const uint8_t&);

void initOpCodeFD() {

    // BEGIN of 0xfd shifted opcodes
    /* ADD REGISTER,BC */
    opcodemapfd[0x09] = instrFD__ADD_REG_BC;
    /* ADD REGISTER,DE */
    opcodemapfd[0x19] = instrFD__ADD_REG_DE;
    /* LD REGISTER,nnnn */
    opcodemapfd[0x21] = instrFD__LD_REG_NNNN;
    /* LD (nnnn),REGISTER */
    opcodemapfd[0x22] = instrFD__LD_iNNNN_REG;
    /* INC REGISTER */
    opcodemapfd[0x23] = instrFD__INC_REG;
    /* INC REGISTERH */
    opcodemapfd[0x24] = instrFD__INC_REGH;
    /* DEC REGISTERH */
    opcodemapfd[0x25] = instrFD__DEC_REGH;
    /* LD REGISTERH,nn */
    opcodemapfd[0x26] = instrFD__LD_REGH_NN;
    /* ADD REGISTER,REGISTER */
    opcodemapfd[0x29] = instrFD__ADD_REG_REG;
    /* LD REGISTER,(nnnn) */
    opcodemapfd[0x2a] = instrFD__LD_REG_iNNNN;
    /* DEC REGISTER */
    opcodemapfd[0x2b] = instrFD__DEC_REG;
    /* INC REGISTERL */
    opcodemapfd[0x2c] = instrFD__INC_REGL;
    /* DEC REGISTERL */
    opcodemapfd[0x2d] = instrFD__DEC_REGL;
    /* LD REGISTERL,nn */
    opcodemapfd[0x2e] = instrFD__LD_REGL_NN;
    /* INC (REGISTER+dd) */
    opcodemapfd[0x34] = instrFD__INC_iREGpDD;
    /* DEC (REGISTER+dd) */
    opcodemapfd[0x35] = instrFD__DEC_iREGpDD;
    /* LD (REGISTER+dd),nn */
    opcodemapfd[0x36] = instrFD__LD_iREGpDD_NN;
    /* ADD REGISTER,SP */
    opcodemapfd[0x39] = instrFD__ADD_REG_SP;
    /* LD B,REGISTERH */
    opcodemapfd[0x44] = instrFD__LD_B_REGH;
    /* LD B,REGISTERL */
    opcodemapfd[0x45] = instrFD__LD_B_REGL;
    /* LD B,(REGISTER+dd) */
    opcodemapfd[0x46] = instrFD__LD_B_iREGpDD;
    /* LD C,REGISTERH */
    opcodemapfd[0x4c] = instrFD__LD_C_REGH;
    /* LD C,REGISTERL */
    opcodemapfd[0x4d] = instrFD__LD_C_REGL;
    /* LD C,(REGISTER+dd) */
    opcodemapfd[0x4e] = instrFD__LD_C_iREGpDD;
    /* LD D,REGISTERH */
    opcodemapfd[0x54] = instrFD__LD_D_REGH;
    /* LD D,REGISTERL */
    opcodemapfd[0x55] = instrFD__LD_D_REGL;
    /* LD D,(REGISTER+dd) */
    opcodemapfd[0x56] = instrFD__LD_D_iREGpDD;
    /* LD E,REGISTERH */
    opcodemapfd[0x5c] = instrFD__LD_E_REGH;
    /* LD E,REGISTERL */
    opcodemapfd[0x5d] = instrFD__LD_E_REGL;
    /* LD E,(REGISTER+dd) */
    opcodemapfd[0x5e] = instrFD__LD_E_iREGpDD;
    /* LD REGISTERH,B */
    opcodemapfd[0x60] = instrFD__LD_REGH_B;
    /* LD REGISTERH,C */
    opcodemapfd[0x61] = instrFD__LD_REGH_C;
    /* LD REGISTERH,D */
    opcodemapfd[0x62] = instrFD__LD_REGH_D;
    /* LD REGISTERH,E */
    opcodemapfd[0x63] = instrFD__LD_REGH_E;
    /* LD REGISTERH,REGISTERH */
    opcodemapfd[0x64] = instrFD__LD_REGH_REGH;
    /* LD REGISTERH,REGISTERL */
    opcodemapfd[0x65] = instrFD__LD_REGH_REGL;
    /* LD H,(REGISTER+dd) */
    opcodemapfd[0x66] = instrFD__LD_H_iREGpDD;
    /* LD REGISTERH,A */
    opcodemapfd[0x67] = instrFD__LD_REGH_A;
    /* LD REGISTERL,B */
    opcodemapfd[0x68] = instrFD__LD_REGL_B;
    /* LD REGISTERL,C */
    opcodemapfd[0x69] = instrFD__LD_REGL_C;
    /* LD REGISTERL,D */
    opcodemapfd[0x6a] = instrFD__LD_REGL_D;
    /* LD REGISTERL,E */
    opcodemapfd[0x6b] = instrFD__LD_REGL_E;
    /* LD REGISTERL,REGISTERH */
    opcodemapfd[0x6c] = instrFD__LD_REGL_REGH;
    /* LD REGISTERL,REGISTERL */
    opcodemapfd[0x6d] = instrFD__LD_REGL_REGL;
    /* LD L,(REGISTER+dd) */
    opcodemapfd[0x6e] = instrFD__LD_L_iREGpDD;
    /* LD REGISTERL,A */
    opcodemapfd[0x6f] = instrFD__LD_REGL_A;
    /* LD (REGISTER+dd),B */
    opcodemapfd[0x70] = instrFD__LD_iREGpDD_r;
    /* LD (REGISTER+dd),C */
    opcodemapfd[0x71] = instrFD__LD_iREGpDD_r;
    /* LD (REGISTER+dd),D */
    opcodemapfd[0x72] = instrFD__LD_iREGpDD_r;
    /* LD (REGISTER+dd),E */
    opcodemapfd[0x73] = instrFD__LD_iREGpDD_r;
    /* LD (REGISTER+dd),H */
    opcodemapfd[0x74] = instrFD__LD_iREGpDD_r;
    /* LD (REGISTER+dd),L */
    opcodemapfd[0x75] = instrFD__LD_iREGpDD_r;
    /* LD (REGISTER+dd),A */
    opcodemapfd[0x77] = instrFD__LD_iREGpDD_r;
    /* LD A,REGISTERH */
    opcodemapfd[0x7c] = instrFD__LD_A_REGH;
    /* LD A,REGISTERL */
    opcodemapfd[0x7d] = instrFD__LD_A_REGL;
    /* LD A,(REGISTER+dd) */
    opcodemapfd[0x7e] = instrFD__LD_A_iREGpDD;
    /* ADD A,REGISTERH */
    opcodemapfd[0x84] = instrFD__ADD_A_REGH;
    /* ADD A,REGISTERL */
    opcodemapfd[0x85] = instrFD__ADD_A_REGL;
    /* ADD A,(REGISTER+dd) */
    opcodemapfd[0x86] = instrFD__ADD_A_iREGpDD;
    /* ADC A,REGISTERH */
    opcodemapfd[0x8c] = instrFD__ADC_A_REGH;
    /* ADC A,REGISTERL */
    opcodemapfd[0x8d] = instrFD__ADC_A_REGL;
    /* ADC A,(REGISTER+dd) */
    opcodemapfd[0x8e] = instrFD__ADC_A_iREGpDD;
    /* SUB A,REGISTERH */
    opcodemapfd[0x94] = instrFD__SUB_A_REGH;
    /* SUB A,REGISTERL */
    opcodemapfd[0x95] = instrFD__SUB_A_REGL;
    /* SUB A,(REGISTER+dd) */
    opcodemapfd[0x96] = instrFD__SUB_A_iREGpDD;
    /* SBC A,REGISTERH */
    opcodemapfd[0x9c] = instrFD__SBC_A_REGH;
    /* SBC A,REGISTERL */
    opcodemapfd[0x9d] = instrFD__SBC_A_REGL;
    /* SBC A,(REGISTER+dd) */
    opcodemapfd[0x9e] = instrFD__SBC_A_iREGpDD;
    /* AND A,REGISTERH */
    opcodemapfd[0xa4] = instrFD__AND_A_REGH;
    /* AND A,REGISTERL */
    opcodemapfd[0xa5] = instrFD__AND_A_REGL;
    /* AND A,(REGISTER+dd) */
    opcodemapfd[0xa6] = instrFD__AND_A_iREGpDD;
    /* XOR A,REGISTERH */
    opcodemapfd[0xac] = instrFD__XOR_A_REGH;
    /* XOR A,REGISTERL */
    opcodemapfd[0xad] = instrFD__XOR_A_REGL;
    /* XOR A,(REGISTER+dd) */
    opcodemapfd[0xae] = instrFD__XOR_A_iREGpDD;
    /* OR A,REGISTERH */
    opcodemapfd[0xb4] = instrFD__OR_A_REGH;
    /* OR A,REGISTERL */
    opcodemapfd[0xb5] = instrFD__OR_A_REGL;
    /* OR A,(REGISTER+dd) */
    opcodemapfd[0xb6] = instrFD__OR_A_iREGpDD;
    /* CP A,REGISTERH */
    opcodemapfd[0xbc] = instrFD__CP_A_REGH;
    /* CP A,REGISTERL */
    opcodemapfd[0xbd] = instrFD__CP_A_REGL;
    /* CP A,(REGISTER+dd) */
    opcodemapfd[0xbe] = instrFD__CP_A_iREGpDD;
    // /* shift DDFDCB */
    opcodemapfd[0xcb] = instrFD__SHIFT_DDFDCB;
    /* POP REGISTER */
    opcodemapfd[0xe1] = instrFD__POP_REG;
    /* EX (SP),REGISTER */
    opcodemapfd[0xe3] = instrFD__EX_iSP_REG;
    /* PUSH REGISTER */
    opcodemapfd[0xe5] = instrFD__PUSH_REG;
    /* JP REGISTER */
    opcodemapfd[0xe9] = instrFD__JP_REG;
    /* LD SP,REGISTER */
    opcodemapfd[0xf9] = instrFD__LD_SP_REG;

    // END of 0xfd shifted opcodes
}

void opcodeFDStep(Z80* z, const uint8_t opcode) {
    // z->Tstates += 4
    uint8_t opcode2 = z->load8();
    z->R++;
    opcodemapfd[opcode2](z, opcode2); // FIXME: verificar!!!!!
}