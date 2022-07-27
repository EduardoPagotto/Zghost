#include <zghost/z80/OpCodeDD.hpp>
#include <zghost/z80/OpCodeDDCBFDCB.hpp>

/* ADD ix,BC */
void instrDD__ADD_REG_BC(Z80* z, const uint8_t& opcode) {
    z->Tstates += 15;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->add16(z->IX, z->BC.get());
}

/* ADD ix,DE */
void instrDD__ADD_REG_DE(Z80* z, const uint8_t& opcode) {
    z->Tstates += 15;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->add16(z->IX, z->DE.get());
}

/* LD ix,nnnn */
void instrDD__LD_REG_NNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 14;
    z->loadR(z->IX);
}

/* LD (nnnn),ix */
void instrDD__LD_iNNNN_REG(Z80* z, const uint8_t& opcode) {
    z->Tstates += 20;
    z->storeIndexR(z->IX);
}

/* INC ix */
void instrDD__INC_REG(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 2)
    z->IX.inc(); // z->IncIX()
}

/* INC IXH */
void instrDD__INC_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->inc(&z->IXH); // incIXH()
}

/* DEC IXH */
void instrDD__DEC_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->dec(&z->IXH); // decIXH()
}

/* LD IXH,nn */
void instrDD__LD_REGH_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 14;
    z->IXH = z->load8();
}

/* ADD ix,ix */
void instrDD__ADD_REG_REG(Z80* z, const uint8_t& opcode) {
    z->Tstates += 15;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->add16(z->IX, z->IX.get());
}

/* LD ix,(nnnn) */
void instrDD__LD_REG_iNNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 20;
    z->loadIndexR(z->IX);
}

/* DEC ix */
void instrDD__DEC_REG(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 2)
    z->IX.dec();
}

/* INC IXL */
void instrDD__INC_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->inc(&z->IXL);
}

/* DEC IXL */
void instrDD__DEC_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->dec(&z->IXL);
}

/* LD IXL,nn */
void instrDD__LD_REGL_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 14;
    z->IXL = z->load8();
}

/* INC (ix+dd) */
void instrDD__INC_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 23;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint16_t wordtemp = z->IX.get() + static_cast<uint16_t>(R16::signExtend(offset));
    uint8_t bytetemp = z->readMem(wordtemp);
    // z->Memory.ContendReadNoMreq(wordtemp, 1)
    z->inc(&bytetemp);
    z->writeMem(wordtemp, bytetemp);
}

/* DEC (ix+dd) */
void instrDD__DEC_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 23;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint16_t wordtemp = z->IX.get() + static_cast<uint16_t>(R16::signExtend(offset));
    uint8_t bytetemp = z->readMem(wordtemp);
    // z->Memory.ContendReadNoMreq(wordtemp, 1)
    z->dec(&bytetemp);
    z->writeMem(wordtemp, bytetemp);
}

/* LD (ix+dd),nn */
void instrDD__LD_iREGpDD_NN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    uint8_t value = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 2)
    z->writeMem(z->IX.get() + static_cast<uint16_t>(R16::signExtend(offset)), value);
}

/* ADD ix,SP */
void instrDD__ADD_REG_SP(Z80* z, const uint8_t& opcode) {
    z->Tstates += 15;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->add16(z->IX, z->sp);
}

/* LD B,IXH */
void instrDD__LD_B_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->B = z->IXH;
}

/* LD B,IXL */
void instrDD__LD_B_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->B = z->IXL;
}

/* LD B,(ix+dd) */
void instrDD__LD_B_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    z->B = z->readMem(z->IX.get() + static_cast<uint16_t>(R16::signExtend(offset)));
}

/* LD C,IXH */
void instrDD__LD_C_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->C = z->IXH;
}

/* LD C,IXL */
void instrDD__LD_C_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->C = z->IXL;
}

/* LD C,(ix+dd) */
void instrDD__LD_C_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    z->C = z->readMem(z->IX.get() + static_cast<uint16_t>(R16::signExtend(offset)));
}

/* LD D,IXH */
void instrDD__LD_D_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->D = z->IXH;
}

/* LD D,IXL */
void instrDD__LD_D_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->D = z->IXL;
}

/* LD D,(ix+dd) */
void instrDD__LD_D_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    z->D = z->readMem(z->IX.get() + static_cast<uint16_t>(R16::signExtend(offset)));
}

/* LD E,IXH */
void instrDD__LD_E_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->E = z->IXH;
}

/* LD E,IXL */
void instrDD__LD_E_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->E = z->IXL;
}

/* LD E,(ix+dd) */
void instrDD__LD_E_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    z->E = z->readMem(z->IX.get() + static_cast<uint16_t>(R16::signExtend(offset)));
}

/* LD IXH,B */
void instrDD__LD_REGH_B(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IXH = z->B;
}

/* LD IXH,C */
void instrDD__LD_REGH_C(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IXH = z->C;
}

/* LD IXH,D */
void instrDD__LD_REGH_D(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IXH = z->D;
}

/* LD IXH,E */
void instrDD__LD_REGH_E(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IXH = z->E;
}

/* LD IXH,IXH */
void instrDD__LD_REGH_REGH(Z80* z, const uint8_t& opcode) { z->Tstates += 8; }

/* LD IXH,IXL */
void instrDD__LD_REGH_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IXH = z->IXL;
}

/* LD H,(ix+dd) */
void instrDD__LD_H_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    z->H = z->readMem(z->IX.get() + static_cast<uint16_t>(R16::signExtend(offset)));
}

/* LD IXH,A */
void instrDD__LD_REGH_A(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IXH = z->A;
}

/* LD IXL,B */
void instrDD__LD_REGL_B(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IXL = z->B;
}

/* LD IXL,C */
void instrDD__LD_REGL_C(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IXL = z->C;
}

/* LD IXL,D */
void instrDD__LD_REGL_D(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IXL = z->D;
}

/* LD IXL,E */
void instrDD__LD_REGL_E(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IXL = z->E;
}

/* LD IXL,IXH */
void instrDD__LD_REGL_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IXL = z->IXH;
}

/* LD IXL,IXL */
void instrDD__LD_REGL_REGL(Z80* z, const uint8_t& opcode) { z->Tstates += 8; }

/* LD L,(ix+dd) */
void instrDD__LD_L_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    z->L = z->readMem(z->IX.get() + static_cast<uint16_t>(R16::signExtend(offset)));
}

/* LD IXL,A */
void instrDD__LD_REGL_A(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IXL = z->A;
}

/* LD (ix+dd),r */
void instrDD__LD_iREGpDD_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint8_t reg = z->getRegisterValByte(opcode);
    z->writeMem(z->IX.get() + static_cast<uint16_t>(R16::signExtend(offset)), reg);
}

/* LD A,IXH */
void instrDD__LD_A_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->A = z->IXH;
}

/* LD A,IXL */
void instrDD__LD_A_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->A = z->IXL;
}

/* LD A,(ix+dd) */
void instrDD__LD_A_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    z->A = z->readMem(z->IX.get() + static_cast<uint16_t>(R16::signExtend(offset)));
}

/* ADD A,IXH */
void instrDD__ADD_A_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->add(z->IXH);
}

/* ADD A,IXL */
void instrDD__ADD_A_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->add(z->IXL);
}

/* ADD A,(ix+dd) */
void instrDD__ADD_A_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint8_t bytetemp = z->readMem(z->IX.get() + static_cast<uint16_t>(R16::signExtend(offset)));
    z->add(bytetemp);
}

/* ADC A,IXH */
void instrDD__ADC_A_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->adc(z->IXH);
}

/* ADC A,IXL */
void instrDD__ADC_A_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->adc(z->IXL);
}

/* ADC A,(ix+dd) */
void instrDD__ADC_A_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint8_t bytetemp = z->readMem(z->IX.get() + static_cast<uint16_t>(R16::signExtend(offset)));
    z->adc(bytetemp);
}

/* SUB A,IXH */
void instrDD__SUB_A_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->sub(z->IXH);
}

/* SUB A,IXL */
void instrDD__SUB_A_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->sub(z->IXL);
}

/* SUB A,(ix+dd) */
void instrDD__SUB_A_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint8_t bytetemp = z->readMem(z->IX.get() + static_cast<uint16_t>(R16::signExtend(offset)));
    z->sub(bytetemp);
}

/* SBC A,IXH */
void instrDD__SBC_A_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->sbc(z->IXH);
}

/* SBC A,IXL */
void instrDD__SBC_A_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->sbc(z->IXL);
}

/* SBC A,(ix+dd) */
void instrDD__SBC_A_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint8_t bytetemp = z->readMem(z->IX.get() + static_cast<uint16_t>(R16::signExtend(offset)));
    z->sbc(bytetemp);
}

/* AND A,IXH */
void instrDD__AND_A_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->oppAnd(z->IXH);
}

/* AND A,IXL */
void instrDD__AND_A_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->oppAnd(z->IXL);
}

/* AND A,(ix+dd) */
void instrDD__AND_A_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint8_t bytetemp = z->readMem(z->IX.get() + static_cast<uint16_t>(R16::signExtend(offset)));
    z->oppAnd(bytetemp);
}

/* XOR A,IXH */
void instrDD__XOR_A_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->oppXor(z->IXH);
}

/* XOR A,IXL */
void instrDD__XOR_A_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->oppXor(z->IXL);
}

/* XOR A,(ix+dd) */
void instrDD__XOR_A_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint8_t bytetemp = z->readMem(z->IX.get() + static_cast<uint16_t>(R16::signExtend(offset)));
    z->oppXor(bytetemp);
}

/* OR A,IXH */
void instrDD__OR_A_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->oppOr(z->IXH);
}

/* OR A,IXL */
void instrDD__OR_A_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->oppOr(z->IXL);
}

/* OR A,(ix+dd) */
void instrDD__OR_A_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->readMem(z->pc);
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint8_t bytetemp = z->readMem(z->IX.get() + static_cast<uint16_t>(R16::signExtend(offset)));
    z->oppOr(bytetemp);
}

/* CP A,IXH */
void instrDD__CP_A_REGH(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->oppCp(z->IXH);
}

/* CP A,IXL */
void instrDD__CP_A_REGL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->oppCp(z->IXL);
}

/* CP A,(ix+dd) */
void instrDD__CP_A_iREGpDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 19;
    uint8_t offset = z->load8();
    // z->Memory.ContendReadNoMreq_loop(z->pc, 1, 5)
    uint8_t bytetemp = z->readMem(z->IX.get() + static_cast<uint16_t>(R16::signExtend(offset)));
    z->oppCp(bytetemp);
}

/* shift DDFDCB */
void instrDD__SHIFT_DDFDCB(Z80* z, const uint8_t& opcode) {
    // z->Tstates += 4
    uint16_t addr = z->IX.get() + static_cast<uint16_t>(R16::signExtend(z->load8()));
    uint8_t opcode2 = z->load8();
    z->R++;
    // OpcodeDDCBMap[opcode2](z, opcode2, addr)
    opcodeDDCBFDCBStep(z, opcode2, addr);
}

/* POP ix */
void instrDD__POP_REG(Z80* z, const uint8_t& opcode) {
    z->Tstates += 14;
    z->popR(z->IX);
}

/* EX (SP),ix */
void instrDD__EX_iSP_REG(Z80* z, const uint8_t& opcode) {
    z->Tstates += 23;
    uint8_t bytetempl = z->readMem(z->sp);
    uint8_t bytetemph = z->readMem(z->sp + 1);

    // z->Memory.ContendReadNoMreq(z->SP()+1, 1)
    z->writeMem(z->sp + 1, z->IXH);
    z->writeMem(z->sp, z->IXL);
    // z->Memory.ContendWriteNoMreq_loop(z->SP(), 1, 2)
    z->IXL = bytetempl;
    z->IXH = bytetemph;
}

/* PUSH ix */
void instrDD__PUSH_REG(Z80* z, const uint8_t& opcode) {
    z->Tstates += 15;
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    z->pushR(z->IX);
}

/* JP ix */
void instrDD__JP_REG(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->pc = z->IX.get();
}

/* LD SP,ix */
void instrDD__LD_SP_REG(Z80* z, const uint8_t& opcode) {
    z->Tstates += 10;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 2)
    z->sp = z->IX.get();
}

void (*opcodemapdd[256])(Z80*, const uint8_t&);

void initOpCodeDD() {

    // BEGIN of 0xdd shifted opcodes
    /* ADD REGISTER,BC */
    opcodemapdd[0x09] = instrDD__ADD_REG_BC;
    /* ADD REGISTER,DE */
    opcodemapdd[0x19] = instrDD__ADD_REG_DE;
    /* LD REGISTER,nnnn */
    opcodemapdd[0x21] = instrDD__LD_REG_NNNN;
    /* LD (nnnn),REGISTER */
    opcodemapdd[0x22] = instrDD__LD_iNNNN_REG;
    /* INC REGISTER */
    opcodemapdd[0x23] = instrDD__INC_REG;
    /* INC REGISTERH */
    opcodemapdd[0x24] = instrDD__INC_REGH;
    /* DEC REGISTERH */
    opcodemapdd[0x25] = instrDD__DEC_REGH;
    /* LD REGISTERH,nn */
    opcodemapdd[0x26] = instrDD__LD_REGH_NN;
    /* ADD REGISTER,REGISTER */
    opcodemapdd[0x29] = instrDD__ADD_REG_REG;
    /* LD REGISTER,(nnnn) */
    opcodemapdd[0x2a] = instrDD__LD_REG_iNNNN;
    /* DEC REGISTER */
    opcodemapdd[0x2b] = instrDD__DEC_REG;
    /* INC REGISTERL */
    opcodemapdd[0x2c] = instrDD__INC_REGL;
    /* DEC REGISTERL */
    opcodemapdd[0x2d] = instrDD__DEC_REGL;
    /* LD REGISTERL,nn */
    opcodemapdd[0x2e] = instrDD__LD_REGL_NN;
    /* INC (REGISTER+dd) */
    opcodemapdd[0x34] = instrDD__INC_iREGpDD;
    /* DEC (REGISTER+dd) */
    opcodemapdd[0x35] = instrDD__DEC_iREGpDD;
    /* LD (REGISTER+dd),nn */
    opcodemapdd[0x36] = instrDD__LD_iREGpDD_NN;
    /* ADD REGISTER,SP */
    opcodemapdd[0x39] = instrDD__ADD_REG_SP;
    /* LD B,REGISTERH */
    opcodemapdd[0x44] = instrDD__LD_B_REGH;
    /* LD B,REGISTERL */
    opcodemapdd[0x45] = instrDD__LD_B_REGL;
    /* LD B,(REGISTER+dd) */
    opcodemapdd[0x46] = instrDD__LD_B_iREGpDD;
    /* LD C,REGISTERH */
    opcodemapdd[0x4c] = instrDD__LD_C_REGH;
    /* LD C,REGISTERL */
    opcodemapdd[0x4d] = instrDD__LD_C_REGL;
    /* LD C,(REGISTER+dd) */
    opcodemapdd[0x4e] = instrDD__LD_C_iREGpDD;
    // 	/* LD D,REGISTERH */
    opcodemapdd[0x54] = instrDD__LD_D_REGH;
    /* LD D,REGISTERL */
    opcodemapdd[0x55] = instrDD__LD_D_REGL;
    /* LD D,(REGISTER+dd) */
    opcodemapdd[0x56] = instrDD__LD_D_iREGpDD;
    // 	/* LD E,REGISTERH */
    opcodemapdd[0x5c] = instrDD__LD_E_REGH;
    /* LD E,REGISTERL */
    opcodemapdd[0x5d] = instrDD__LD_E_REGL;
    /* LD E,(REGISTER+dd) */
    opcodemapdd[0x5e] = instrDD__LD_E_iREGpDD;
    // 	/* LD REGISTERH,B */
    opcodemapdd[0x60] = instrDD__LD_REGH_B;
    /* LD REGISTERH,C */
    opcodemapdd[0x61] = instrDD__LD_REGH_C;
    /* LD REGISTERH,D */
    opcodemapdd[0x62] = instrDD__LD_REGH_D;
    /* LD REGISTERH,E */
    opcodemapdd[0x63] = instrDD__LD_REGH_E;
    /* LD REGISTERH,REGISTERH */
    opcodemapdd[0x64] = instrDD__LD_REGH_REGH;
    /* LD REGISTERH,REGISTERL */
    opcodemapdd[0x65] = instrDD__LD_REGH_REGL;
    /* LD H,(REGISTER+dd) */
    opcodemapdd[0x66] = instrDD__LD_H_iREGpDD;
    // 	/* LD REGISTERH,A */
    opcodemapdd[0x67] = instrDD__LD_REGH_A;
    /* LD REGISTERL,B */
    opcodemapdd[0x68] = instrDD__LD_REGL_B;
    /* LD REGISTERL,C */
    opcodemapdd[0x69] = instrDD__LD_REGL_C;
    /* LD REGISTERL,D */
    opcodemapdd[0x6a] = instrDD__LD_REGL_D;
    /* LD REGISTERL,E */
    opcodemapdd[0x6b] = instrDD__LD_REGL_E;
    /* LD REGISTERL,REGISTERH */
    opcodemapdd[0x6c] = instrDD__LD_REGL_REGH;
    /* LD REGISTERL,REGISTERL */
    opcodemapdd[0x6d] = instrDD__LD_REGL_REGL;
    /* LD L,(REGISTER+dd) */
    opcodemapdd[0x6e] = instrDD__LD_L_iREGpDD;
    /* LD REGISTERL,A */
    opcodemapdd[0x6f] = instrDD__LD_REGL_A;
    /* LD (REGISTER+dd),B */
    opcodemapdd[0x70] = instrDD__LD_iREGpDD_r;
    /* LD (REGISTER+dd),C */
    opcodemapdd[0x71] = instrDD__LD_iREGpDD_r;
    /* LD (REGISTER+dd),D */
    opcodemapdd[0x72] = instrDD__LD_iREGpDD_r;
    /* LD (REGISTER+dd),E */
    opcodemapdd[0x73] = instrDD__LD_iREGpDD_r;
    /* LD (REGISTER+dd),H */
    opcodemapdd[0x74] = instrDD__LD_iREGpDD_r;
    /* LD (REGISTER+dd),L */
    opcodemapdd[0x75] = instrDD__LD_iREGpDD_r;
    /* LD (REGISTER+dd),A */
    opcodemapdd[0x77] = instrDD__LD_iREGpDD_r;
    /* LD A,REGISTERH */
    opcodemapdd[0x7c] = instrDD__LD_A_REGH;
    /* LD A,REGISTERL */
    opcodemapdd[0x7d] = instrDD__LD_A_REGL;
    /* LD A,(REGISTER+dd) */
    opcodemapdd[0x7e] = instrDD__LD_A_iREGpDD;
    /* ADD A,REGISTERH */
    opcodemapdd[0x84] = instrDD__ADD_A_REGH;
    /* ADD A,REGISTERL */
    opcodemapdd[0x85] = instrDD__ADD_A_REGL;
    /* ADD A,(REGISTER+dd) */
    opcodemapdd[0x86] = instrDD__ADD_A_iREGpDD;
    /* ADC A,REGISTERH */
    opcodemapdd[0x8c] = instrDD__ADC_A_REGH;
    /* ADC A,REGISTERL */
    opcodemapdd[0x8d] = instrDD__ADC_A_REGL;
    /* ADC A,(REGISTER+dd) */
    opcodemapdd[0x8e] = instrDD__ADC_A_iREGpDD;
    /* SUB A,REGISTERH */
    opcodemapdd[0x94] = instrDD__SUB_A_REGH;
    /* SUB A,REGISTERL */
    opcodemapdd[0x95] = instrDD__SUB_A_REGL;
    /* SUB A,(REGISTER+dd) */
    opcodemapdd[0x96] = instrDD__SUB_A_iREGpDD;
    /* SBC A,REGISTERH */
    opcodemapdd[0x9c] = instrDD__SBC_A_REGH;
    /* SBC A,REGISTERL */
    opcodemapdd[0x9d] = instrDD__SBC_A_REGL;
    /* SBC A,(REGISTER+dd) */
    opcodemapdd[0x9e] = instrDD__SBC_A_iREGpDD;
    /* AND A,REGISTERH */
    opcodemapdd[0xa4] = instrDD__AND_A_REGH;
    /* AND A,REGISTERL */
    opcodemapdd[0xa5] = instrDD__AND_A_REGL;
    /* AND A,(REGISTER+dd) */
    opcodemapdd[0xa6] = instrDD__AND_A_iREGpDD;
    /* XOR A,REGISTERH */
    opcodemapdd[0xac] = instrDD__XOR_A_REGH;
    /* XOR A,REGISTERL */
    opcodemapdd[0xad] = instrDD__XOR_A_REGL;
    /* XOR A,(REGISTER+dd) */
    opcodemapdd[0xae] = instrDD__XOR_A_iREGpDD;
    /* OR A,REGISTERH */
    opcodemapdd[0xb4] = instrDD__OR_A_REGH;
    /* OR A,REGISTERL */
    opcodemapdd[0xb5] = instrDD__OR_A_REGL;
    /* OR A,(REGISTER+dd) */
    opcodemapdd[0xb6] = instrDD__OR_A_iREGpDD;
    /* CP A,REGISTERH */
    opcodemapdd[0xbc] = instrDD__CP_A_REGH;
    /* CP A,REGISTERL */
    opcodemapdd[0xbd] = instrDD__CP_A_REGL;
    /* CP A,(REGISTER+dd) */
    opcodemapdd[0xbe] = instrDD__CP_A_iREGpDD;
    /* shift DDFDCB */
    opcodemapdd[0xcb] = instrDD__SHIFT_DDFDCB;
    /* POP REGISTER */
    opcodemapdd[0xe1] = instrDD__POP_REG;
    /* EX (SP),REGISTER */
    opcodemapdd[0xe3] = instrDD__EX_iSP_REG;
    /* PUSH REGISTER */
    opcodemapdd[0xe5] = instrDD__PUSH_REG;
    /* JP REGISTER */
    opcodemapdd[0xe9] = instrDD__JP_REG;
    /* LD SP,REGISTER */
    opcodemapdd[0xf9] = instrDD__LD_SP_REG;

    // END of 0xdd shifted opcodes
}

void opcodeDDStep(Z80* z, const uint8_t opcode) {
    // z->Tstates += 4
    uint8_t opcode2 = z->load8();
    z->R++;
    opcodemapdd[opcode2](z, opcode2); // FIXME: verificar!!!!!
}