#include <zghost/z80/OpCodeED.hpp>

/* IN B,(C) */
void instrED__IN_B_iC(Z80* z, const uint8_t& opcode) {
    z->Tstates += 12;
    z->in(&z->B, z->BC.get());
}

/* OUT (C),B */
void instrED__OUT_iC_B(Z80* z, const uint8_t& opcode) {
    z->Tstates += 12;
    z->writePort(z->BC.get(), z->B);
}

/* SBC HL,BC */
void instrED__SBC_HL_BC(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->Tstates += 15;
    z->sbc16(z->BC.get());
}

/* LD (nnnn),BC */
void instrED__LD_iNNNN_BC(Z80* z, const uint8_t& opcode) {
    z->Tstates += 20;
    z->storeIndexR16(z->BC);
}

void instrED__RETI(Z80* z, const uint8_t& opcode) {
    // nao existia ???
    z->Tstates += 14;
    z->pc = z->pop();
}

/* NEG */
void instrED__NEG(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    uint8_t bytetemp = z->A;
    z->A = 0;
    z->sub(bytetemp);
}

/* RETN */
void instrED__RETN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 14;
    z->IFF1 = z->IFF2;
    z->pc = z->pop();
}

/* IM 0 */
void instrED__IM_0(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IM = 0;
}

/* LD I,A */
void instrED__LD_I_A(Z80* z, const uint8_t& opcode) {
    z->Tstates += 9;
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    z->I = z->A;
}

/* IN C,(C) */
void instrED__IN_C_iC(Z80* z, const uint8_t& opcode) {
    z->Tstates += 12;
    z->in(&z->C, z->BC.get());
}

/* OUT (C),C */
void instrED__OUT_iC_C(Z80* z, const uint8_t& opcode) {
    z->Tstates += 12;
    z->writePort(z->BC.get(), z->C);
}

/* ADC HL,BC */
void instrED__ADC_HL_BC(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->Tstates += 15;
    z->adc16(z->BC.get());
}

/* LD BC,(nnnn) */
void instrED__LD_BC_iNNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 20;
    z->loadIndexR16(z->BC);
}

/* LD R,A */
void instrED__LD_R_A(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    /* Keep the RZX instruction counter right */
    z->Tstates += 9;
    z->rzxInstructionsOffset += (int(z->R) - int(z->A));
    z->R = static_cast<uint16_t>(z->A);
    z->R7 = z->A;
}

/* IN D,(C) */
void instrED__IN_D_iC(Z80* z, const uint8_t& opcode) {
    z->Tstates += 12;
    z->in(&z->D, z->BC.get());
}

/* OUT (C),D */
void instrED__OUT_iC_D(Z80* z, const uint8_t& opcode) {
    z->Tstates += 12;
    z->writePort(z->BC.get(), z->D);
}

/* SBC HL,DE */
void instrED__SBC_HL_DE(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->Tstates += 15;
    z->sbc16(z->DE.get());
}

/* LD (nnnn),DE */
void instrED__LD_iNNNN_DE(Z80* z, const uint8_t& opcode) {
    z->Tstates += 20;
    z->storeIndexR16(z->DE);
}

/* IM 1 */
void instrED__IM_1(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IM = 1;
}

/* LD A,I */
void instrED__LD_A_I(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    z->Tstates += 9;
    z->A = z->I;
    z->F = (z->F & FLAG_C) | z->sz53Table[z->A] | (z->IFF2 != 0 ? FLAG_V : 0);
}

/* IN E,(C) */
void instrED__IN_E_iC(Z80* z, const uint8_t& opcode) {
    z->Tstates += 12;
    z->in(&z->E, z->BC.get());
}

/* OUT (C),E */
void instrED__OUT_iC_E(Z80* z, const uint8_t& opcode) {
    z->Tstates += 12;
    z->writePort(z->BC.get(), z->E);
}

/* ADC HL,DE */
void instrED__ADC_HL_DE(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->Tstates += 15;
    z->adc16(z->DE.get());
}

/* LD DE,(nnnn) */
void instrED__LD_DE_iNNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 20;
    z->loadIndexR16(z->DE);
}

/* IM 2 */
void instrED__IM_2(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    z->IM = 2;
}

/* LD A,R */
void instrED__LD_A_R(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    z->Tstates += 9;
    z->A = static_cast<uint8_t>(z->R & 0x7f) | (z->R7 & 0x80);
    z->F = (z->F & FLAG_C) | z->sz53Table[z->A] | (z->IFF2 != 0 ? FLAG_V : 0);
}

/* IN H,(C) */
void instrED__IN_H_iC(Z80* z, const uint8_t& opcode) {
    z->Tstates += 12;
    z->in(&z->H, z->BC.get());
}

/* OUT (C),H */
void instrED__OUT_iC_H(Z80* z, const uint8_t& opcode) {
    z->Tstates += 12;
    z->writePort(z->BC.get(), z->H);
}

/* SBC HL,HL */
void instrED__SBC_HL_HL(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->Tstates += 15;
    z->sbc16(z->HL.get());
}

/* LD (nnnn),HL */
void instrED__LD_iNNNN_HL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 20;
    z->storeIndexR16(z->HL);
}

/* RRD */
void instrED__RRD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 18;
    uint8_t bytetemp = z->readMem(z->HL.get());
    // z->Memory.ContendReadNoMreq_loop(z->HL.get(), 1, 4)
    z->writeMem(z->HL.get(), (z->A << 4) | (bytetemp >> 4));
    z->A = (z->A & 0xf0) | (bytetemp & 0x0f);
    z->F = (z->F & FLAG_C) | z->sz53pTable[z->A];
}

/* IN L,(C) */
void instrED__IN_L_iC(Z80* z, const uint8_t& opcode) {
    z->Tstates += 12;
    z->in(&z->L, z->BC.get());
}

/* OUT (C),L */
void instrED__OUT_iC_L(Z80* z, const uint8_t& opcode) {
    z->Tstates += 12;
    z->writePort(z->BC.get(), z->L);
}

/* ADC HL,HL */
void instrED__ADC_HL_HL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 15;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->adc16(z->HL.get());
}

/* LD HL,(nnnn) */
void instrED__LD_HL_iNNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 20;
    z->loadIndexR16(z->HL);
}

/* RLD */
void instrED__RLD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 18;
    uint8_t bytetemp = z->readMem(z->HL.get());
    // z->Memory.ContendReadNoMreq_loop(z->HL.get(), 1, 4)
    z->writeMem(z->HL.get(), (bytetemp << 4) | (z->A & 0x0f));
    z->A = (z->A & 0xf0) | (bytetemp >> 4);
    z->F = (z->F & FLAG_C) | z->sz53pTable[z->A];
}

/* IN F,(C) */
void instrED__IN_F_iC(Z80* z, const uint8_t& opcode) {
    z->Tstates += 12;
    uint8_t bytetemp;
    z->in(&bytetemp, z->BC.get()); // FIXME nao entendi!!!
}

/* OUT (C),0 */
void instrED__OUT_iC_0(Z80* z, const uint8_t& opcode) {
    z->Tstates += 12;
    z->writePort(z->BC.get(), 0);
}

/* SBC HL,SP */
void instrED__SBC_HL_SP(Z80* z, const uint8_t& opcode) {
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->Tstates += 15;
    z->sbc16(z->sp);
}

/* LD (nnnn),SP */
void instrED__LD_iNNNN_SP(Z80* z, const uint8_t& opcode) {
    z->Tstates += 20;

    uint8_t sph, spl;
    std::tie(sph, spl) = R16::splitword(z->sp);

    uint16_t ldtemp = z->load16();
    z->writeMem(ldtemp, spl);
    ldtemp++;
    z->writeMem(ldtemp, sph);
}

/* IN A,(C) */
void instrED__IN_A_iC(Z80* z, const uint8_t& opcode) {
    z->Tstates += 12;
    z->in(&z->A, z->BC.get());
}

/* OUT (C),A */
void instrED__OUT_iC_A(Z80* z, const uint8_t& opcode) {
    z->Tstates += 12;
    z->writePort(z->BC.get(), z->A);
}

/* ADC HL,SP */
void instrED__ADC_HL_SP(Z80* z, const uint8_t& opcode) {
    z->Tstates += 15;
    // z->Memory.ContendReadNoMreq_loop(z->IR(), 1, 7)
    z->adc16(z->sp);
}

/* LD SP,(nnnn) */
void instrED__LD_SP_iNNNN(Z80* z, const uint8_t& opcode) {
    z->Tstates += 20;
    uint16_t ldtemp = z->load16();
    uint8_t spl = z->readMem(ldtemp);
    ldtemp++;
    uint8_t sph = z->readMem(ldtemp);
    z->sp = R16::joinBytes(sph, spl);
}

/* LDI */
void instrED__LDI(Z80* z, const uint8_t& opcode) {
    z->Tstates += 16;
    uint8_t bytetemp = z->readMem(z->HL.get());
    z->BC.dec(); // DecBC()
    z->writeMem(z->DE.get(), bytetemp);
    // z->Memory.ContendWriteNoMreq_loop(z->DE.get(), 1, 2)
    z->DE.inc(); // IncDE()
    z->HL.inc(); // IncHL()
    bytetemp += z->A;
    z->F = (z->F & (FLAG_C | FLAG_Z | FLAG_S)) |  //
           ((z->BC.get() != 0) ? FLAG_V : 0) |    //
           (bytetemp & FLAG_3) |                  //
           ((bytetemp & 0x02) != 0 ? FLAG_5 : 0); //
}

/* CPI */
void instrED__CPI(Z80* z, const uint8_t& opcode) {
    z->Tstates += 16;
    uint8_t value = z->readMem(z->HL.get());
    uint8_t bytetemp = z->A - value;
    uint8_t lookup = ((z->A & 0x08) >> 3) | (((value)&0x08) >> 2) | ((bytetemp & 0x08) >> 1);
    // z->Memory.ContendReadNoMreq_loop(z->HL.get(), 1, 5)
    z->HL.inc(); // IncHL()
    z->BC.dec(); // DecBC()

    z->F = (z->F & FLAG_C) |                                   //
           ((z->BC.get() != 0) ? (FLAG_V | FLAG_N) : FLAG_N) | //
           z->halfcarrySubTable[lookup] |                      //
           ((bytetemp != 0) ? 0 : FLAG_Z) |                    //
           (bytetemp & FLAG_S);                                //

    if ((z->F & FLAG_H) != 0) {
        bytetemp--;
    }

    z->F |= (bytetemp & FLAG_3) | ((bytetemp & 0x02) != 0 ? FLAG_5 : 0);
}

/* INI */
void instrED__INI(Z80* z, const uint8_t& opcode) {
    z->Tstates += 16;
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    uint8_t initemp = z->readPort(z->BC.get());
    z->writeMem(z->HL.get(), initemp);

    z->B--;
    z->HL.inc(); // IncHL()
    uint8_t initemp2 = initemp + z->C + 1;
    z->F = ((initemp & 0x80) != 0 ? FLAG_N : 0) |                         //
           (initemp2 < initemp ? FLAG_H | FLAG_C : 0) |                   //
           (z->parityTable[(initemp2 & 0x07) ^ z->B] != 0 ? FLAG_P : 0) | //
           z->sz53Table[z->B];                                            // FIXME xo problemas!!!!!
}

/* OUTI */
void instrED__OUTI(Z80* z, const uint8_t& opcode) {
    z->Tstates += 16;
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    uint8_t outitemp = z->readMem(z->HL.get());
    z->B--; /* This does happen first, despite what the specs say */
    z->writePort(z->BC.get(), outitemp);

    z->HL.inc(); // IncHL()
    uint8_t outitemp2 = outitemp + z->L;

    z->F = ((outitemp & 0x80) != 0 ? FLAG_N : 0) |                         //
           ((outitemp2 < outitemp) ? FLAG_H | FLAG_C : 0) |                //
           (z->parityTable[(outitemp2 & 0x07) ^ z->B] != 0 ? FLAG_P : 0) | //
           z->sz53Table[z->B];                                             // FIXME xor problema!!!!
}

/* LDD */
void instrED__LDD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 16;
    uint8_t bytetemp = z->readMem(z->HL.get());
    z->BC.dec(); // DecBC()
    z->writeMem(z->DE.get(), bytetemp);
    // z->Memory.ContendWriteNoMreq_loop(z->DE.get(), 1, 2)
    z->DE.dec(); // DecDE()
    z->HL.dec(); // DecHL()
    bytetemp += z->A;

    z->F = (z->F & (FLAG_C | FLAG_Z | FLAG_S)) |  //
           ((z->BC.get() != 0) ? FLAG_V : 0) |    //
           (bytetemp & FLAG_3) |                  //
           ((bytetemp & 0x02) != 0 ? FLAG_5 : 0); //
}

/* CPD */
void instrED__CPD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 16;
    uint8_t value = z->readMem(z->HL.get());
    uint8_t bytetemp = z->A - value;
    uint8_t lookup = ((z->A & 0x08) >> 3) | (((value)&0x08) >> 2) | ((bytetemp & 0x08) >> 1);
    // z->Memory.ContendReadNoMreq_loop(z->HL.get(), 1, 5)
    z->HL.dec(); // DecHL()
    z->BC.dec(); // DecBC()

    z->F = (z->F & FLAG_C) |                                   //
           ((z->BC.get() != 0) ? (FLAG_V | FLAG_N) : FLAG_N) | //
           z->halfcarrySubTable[lookup] |                      //
           (bytetemp != 0 ? 0 : FLAG_Z) |                      //
           (bytetemp & FLAG_S);                                //

    if ((z->F & FLAG_H) != 0) {
        bytetemp--;
    }
    z->F |= (bytetemp & FLAG_3) | ((bytetemp & 0x02) != 0 ? FLAG_5 : 0);
}

/* IND */
void instrED__IND(Z80* z, const uint8_t& opcode) {
    z->Tstates += 16;
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    uint8_t initemp = z->readPort(z->BC.get());
    z->writeMem(z->HL.get(), initemp);

    z->B--;
    z->HL.dec();
    uint8_t initemp2 = initemp + z->C - 1;

    z->F = ((initemp & 0x80) != 0 ? FLAG_N : 0) |                           //
           ((initemp2 < initemp) ? (FLAG_H | FLAG_C) : 0) |                 //
           ((z->parityTable[(initemp2 & 0x07) ^ z->B] != 0) ? FLAG_P : 0) | //
           z->sz53Table[z->B];                                              // FIXME testar
}

/* OUTD */
void instrED__OUTD(Z80* z, const uint8_t& opcode) {
    z->Tstates += 16;
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    uint8_t outitemp = z->readMem(z->HL.get());
    z->B--; /* This does happen first, despite what the specs say */
    z->writePort(z->BC.get(), outitemp);

    z->HL.dec();
    uint8_t outitemp2 = outitemp + z->L;

    z->F = (((outitemp & 0x80) != 0) ? FLAG_N : 0) |                         //
           ((outitemp2 < outitemp) ? (FLAG_H | FLAG_C) : 0) |                //
           ((z->parityTable[(outitemp2 & 0x07) ^ z->B] != 0) ? FLAG_P : 0) | //
           z->sz53Table[z->B];
}

/* LDIR */
void instrED__LDIR(Z80* z, const uint8_t& opcode) {
    z->Tstates += 16;
    uint8_t bytetemp = z->readMem(z->HL.get());
    z->writeMem(z->DE.get(), bytetemp);
    // z->Memory.ContendWriteNoMreq_loop(z->DE.get(), 1, 2)
    z->BC.dec();
    bytetemp += z->A;

    z->F = (z->F & (FLAG_C | FLAG_Z | FLAG_S)) |    //
           ((z->BC.get() != 0) ? FLAG_V : 0) |      //
           (bytetemp & FLAG_3) |                    //
           (((bytetemp & 0x02) != 0) ? FLAG_5 : 0); //

    if (z->BC.get() != 0) {
        // z->Memory.ContendWriteNoMreq_loop(z->DE.get(), 1, 5)
        z->pc -= 2;      // DecPC(2)
        z->Tstates += 5; // FIXME: Testar
    }
    z->HL.inc();
    z->DE.inc();
}

/* CPIR */
void instrED__CPIR(Z80* z, const uint8_t& opcode) {
    z->Tstates += 16;
    uint8_t value = z->readMem(z->HL.get());
    uint8_t bytetemp = z->A - value;
    uint8_t lookup = ((z->A & 0x08) >> 3) | (((value)&0x08) >> 2) | ((bytetemp & 0x08) >> 1);
    // z->Memory.ContendReadNoMreq_loop(z->HL.get(), 1, 5)
    z->BC.dec();

    z->F = (z->F & FLAG_C) |                                     //
           (((z->BC.get() != 0) ? (FLAG_V | FLAG_N) : FLAG_N)) | //
           z->halfcarrySubTable[lookup] |                        //
           (((bytetemp != 0) ? 0 : FLAG_Z)) |                    //
           (bytetemp & FLAG_S);

    if ((z->F & FLAG_H) != 0) {
        bytetemp--;
    }

    z->F |= (bytetemp & FLAG_3) | ((bytetemp & 0x02) != 0 ? FLAG_5 : 0);

    if ((z->F & (FLAG_V | FLAG_Z)) == FLAG_V) {
        // z->Memory.ContendReadNoMreq_loop(z->HL.get(), 1, 5)
        z->pc -= 2;      // z->pc -= 2
        z->Tstates += 5; // Testar
    }
    z->HL.inc(); // FIXME: testar
}

/* INIR */
void instrED__INIR(Z80* z, const uint8_t& opcode) {
    z->Tstates += 16;
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    uint8_t initemp = z->readPort(z->BC.get());
    z->writeMem(z->HL.get(), initemp);

    z->B--;
    uint8_t initemp2 = initemp + z->C + 1;

    z->F = ((initemp & 0x80) != 0 ? FLAG_N : 0) |                           //
           ((initemp2 < initemp) ? (FLAG_H | FLAG_C) : 0) |                 //
           ((z->parityTable[(initemp2 & 0x07) ^ z->B] != 0) ? FLAG_P : 0) | //
           z->sz53Table[z->B];                                              //

    if (z->B != 0) {
        // z->Memory.ContendWriteNoMreq_loop(z->HL.get(), 1, 5)
        z->pc -= 2;
        z->Tstates += 5;
    }
    z->HL.inc();
}

/* OTIR */
void instrED__OTIR(Z80* z, const uint8_t& opcode) {
    z->Tstates += 16;
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    uint8_t outitemp = z->readMem(z->HL.get());
    z->B--; /* This does happen first, despite what the specs say */
    z->writePort(z->BC.get(), outitemp);

    z->HL.inc();
    uint8_t outitemp2 = outitemp + z->L;

    z->F = (((outitemp & 0x80) != 0) ? FLAG_N : 0) |                         //
           ((outitemp2 < outitemp) ? (FLAG_H | FLAG_C) : 0) |                //
           ((z->parityTable[(outitemp2 & 0x07) ^ z->B] != 0) ? FLAG_P : 0) | //
           z->sz53Table[z->B];                                               // FIXME XOR issue

    if (z->B != 0) {
        // z->Memory.ContendReadNoMreq_loop(z->BC.get(), 1, 5)
        z->pc -= 2;
        z->Tstates += 5;
    }
}

/* LDDR */
void instrED__LDDR(Z80* z, const uint8_t& opcode) {
    z->Tstates += 16;
    uint8_t bytetemp = z->readMem(z->HL.get());
    z->writeMem(z->DE.get(), bytetemp);
    // z->Memory.ContendWriteNoMreq_loop(z->DE.get(), 1, 2)
    z->BC.dec();
    bytetemp += z->A;

    z->F = (z->F & (FLAG_C | FLAG_Z | FLAG_S)) |    //
           ((z->BC.get() != 0) ? FLAG_V : 0) |      //
           (bytetemp & FLAG_3) |                    //
           (((bytetemp & 0x02) != 0) ? FLAG_5 : 0); //

    if (z->BC.get() != 0) {
        // z->Memory.ContendWriteNoMreq_loop(z->DE.get(), 1, 5)
        z->pc -= 2;
        z->Tstates += 5;
    }
    z->HL.dec();
    z->DE.dec();
}

/* CPDR */
void instrED__CPDR(Z80* z, const uint8_t& opcode) {
    z->Tstates += 16;
    uint8_t value = z->readMem(z->HL.get());
    uint8_t bytetemp = z->A - value;
    uint8_t lookup = ((z->A & 0x08) >> 3) | (((value)&0x08) >> 2) | ((bytetemp & 0x08) >> 1);
    // z->Memory.ContendReadNoMreq_loop(z->HL.get(), 1, 5)
    z->BC.dec();

    z->F = (z->F & FLAG_C) |                                     //
           (((z->BC.get() != 0) ? (FLAG_V | FLAG_N) : FLAG_N)) | //
           z->halfcarrySubTable[lookup] |                        //
           (((bytetemp != 0) ? 0 : FLAG_Z)) |                    //
           (bytetemp & FLAG_S);

    if ((z->F & FLAG_H) != 0) {
        bytetemp--;
    }

    z->F |= (bytetemp & FLAG_3) | ((bytetemp & 0x02) != 0 ? FLAG_5 : 0);

    if ((z->F & (FLAG_V | FLAG_Z)) == FLAG_V) {
        // z->Memory.ContendReadNoMreq_loop(z->HL.get(), 1, 5)
        z->pc -= 2;
        z->Tstates += 5;
    }

    z->HL.dec();
}

/* INDR */
void instrED__INDR(Z80* z, const uint8_t& opcode) {
    z->Tstates += 16;
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    uint8_t initemp = z->readPort(z->BC.get());
    z->writeMem(z->HL.get(), initemp);

    z->B--;
    uint8_t initemp2 = initemp + z->C - 1;

    z->F = ((initemp & 0x80) != 0 ? FLAG_N : 0) |                         //
           ((initemp2 < initemp) ? FLAG_H | FLAG_C : 0) |                 //
           (z->parityTable[(initemp2 & 0x07) ^ z->B] != 0 ? FLAG_P : 0) | //
           z->sz53Table[z->B];                                            //

    if (z->B != 0) {
        // z->Memory.ContendWriteNoMreq_loop(z->HL.get(), 1, 5)
        z->pc -= 2;
        z->Tstates += 5;
    }
    z->HL.dec();
}

/* OTDR */
void instrED__OTDR(Z80* z, const uint8_t& opcode) {
    z->Tstates += 16;
    // z->Memory.ContendReadNoMreq(z->IR(), 1)
    uint8_t outitemp = z->readMem(z->HL.get());
    z->B--; /* This does happen first, despite what the specs say */
    z->writePort(z->BC.get(), outitemp);

    z->HL.dec();
    uint8_t outitemp2 = outitemp + z->L;

    z->F = (((outitemp & 0x80) != 0) ? FLAG_N : 0) |                         //
           ((outitemp2 < outitemp) ? (FLAG_H | FLAG_C) : 0) |                //
           ((z->parityTable[(outitemp2 & 0x07) ^ z->B] != 0) ? FLAG_P : 0) | //
           z->sz53Table[z->B];                                               //

    if (z->B != 0) {
        // z->Memory.ContendReadNoMreq_loop(z->BC.get(), 1, 5)
        z->pc -= 2;
        z->Tstates += 5;
    }
}

/* slttrap */
// void instrED__SLTTRAP(Z80* z, const uint8_t& opcode) {
//     z->Tstates += 4; //????
//     z->sltTrap(int16(z->HL.get()), z->A);
// }

void (*opcodemaped[256])(Z80*, const uint8_t&);

void initOpCodeED() {

    // BEGIN of 0xed shifted opcodes
    /* IN B,(C) */
    opcodemaped[0x40] = instrED__IN_B_iC;
    /* OUT (C),B */
    opcodemaped[0x41] = instrED__OUT_iC_B;
    /* SBC HL,BC */
    opcodemaped[0x42] = instrED__SBC_HL_BC;
    /* LD (nnnn),BC */
    opcodemaped[0x43] = instrED__LD_iNNNN_BC;
    /* RETI */
    opcodemaped[0x4d] = instrED__RETI;
    /* NEG */
    opcodemaped[0x7c] = instrED__NEG;
    // Fallthrough cases
    opcodemaped[0x44] = opcodemaped[0x7c];
    opcodemaped[0x4c] = opcodemaped[0x7c];
    opcodemaped[0x54] = opcodemaped[0x7c];
    opcodemaped[0x5c] = opcodemaped[0x7c];
    opcodemaped[0x64] = opcodemaped[0x7c];
    opcodemaped[0x6c] = opcodemaped[0x7c];
    opcodemaped[0x74] = opcodemaped[0x7c];
    /* RETN */
    opcodemaped[0x7d] = instrED__RETN;
    // Fallthrough cases
    opcodemaped[0x45] = opcodemaped[0x7d];
    // opcodemaped[0x4d] = opcodemaped[0x7d];
    opcodemaped[0x55] = opcodemaped[0x7d];
    opcodemaped[0x5d] = opcodemaped[0x7d];
    opcodemaped[0x65] = opcodemaped[0x7d];
    opcodemaped[0x6d] = opcodemaped[0x7d];
    opcodemaped[0x75] = opcodemaped[0x7d];
    /* IM 0 */
    opcodemaped[0x6e] = instrED__IM_0;
    // Fallthrough cases
    opcodemaped[0x46] = opcodemaped[0x6e];
    opcodemaped[0x4e] = opcodemaped[0x6e];
    opcodemaped[0x66] = opcodemaped[0x6e];
    /* LD I,A */
    opcodemaped[0x47] = instrED__LD_I_A;
    /* IN C,(C) */
    opcodemaped[0x48] = instrED__IN_C_iC;
    // 	/* OUT (C),C */
    opcodemaped[0x49] = instrED__OUT_iC_C;
    /* ADC HL,BC */
    opcodemaped[0x4a] = instrED__ADC_HL_BC;
    /* LD BC,(nnnn) */
    opcodemaped[0x4b] = instrED__LD_BC_iNNNN;
    /* LD R,A */
    opcodemaped[0x4f] = instrED__LD_R_A;
    /* IN D,(C) */
    opcodemaped[0x50] = instrED__IN_D_iC;
    /* OUT (C),D */
    opcodemaped[0x51] = instrED__OUT_iC_D;
    /* SBC HL,DE */
    opcodemaped[0x52] = instrED__SBC_HL_DE;
    /* LD (nnnn),DE */
    opcodemaped[0x53] = instrED__LD_iNNNN_DE;
    /* IM 1 */
    opcodemaped[0x76] = instrED__IM_1;
    // Fallthrough cases
    opcodemaped[0x56] = opcodemaped[0x76];
    /* LD A,I */
    opcodemaped[0x57] = instrED__LD_A_I;
    /* IN E,(C) */
    opcodemaped[0x58] = instrED__IN_E_iC;
    /* OUT (C),E */
    opcodemaped[0x59] = instrED__OUT_iC_E;
    /* ADC HL,DE */
    opcodemaped[0x5a] = instrED__ADC_HL_DE;
    /* LD DE,(nnnn) */
    opcodemaped[0x5b] = instrED__LD_DE_iNNNN;
    /* IM 2 */
    opcodemaped[0x7e] = instrED__IM_2;
    // Fallthrough cases
    opcodemaped[0x5e] = opcodemaped[0x7e];
    /* LD A,R */
    opcodemaped[0x5f] = instrED__LD_A_R;
    /* IN H,(C) */
    opcodemaped[0x60] = instrED__IN_H_iC;
    /* OUT (C),H */
    opcodemaped[0x61] = instrED__OUT_iC_H;
    /* SBC HL,HL */
    opcodemaped[0x62] = instrED__SBC_HL_HL;
    /* LD (nnnn),HL */
    opcodemaped[0x63] = instrED__LD_iNNNN_HL;
    /* RRD */
    opcodemaped[0x67] = instrED__RRD;
    /* IN L,(C) */
    opcodemaped[0x68] = instrED__IN_L_iC;
    /* OUT (C),L */
    opcodemaped[0x69] = instrED__OUT_iC_L;
    /* ADC HL,HL */
    opcodemaped[0x6a] = instrED__ADC_HL_HL;
    /* LD HL,(nnnn) */
    opcodemaped[0x6b] = instrED__LD_HL_iNNNN;
    /* RLD */
    opcodemaped[0x6f] = instrED__RLD;
    /* IN F,(C) */
    opcodemaped[0x70] = instrED__IN_F_iC;
    /* OUT (C),0 */
    opcodemaped[0x71] = instrED__OUT_iC_0;
    /* SBC HL,SP */
    opcodemaped[0x72] = instrED__SBC_HL_SP;
    /* LD (nnnn),SP */
    opcodemaped[0x73] = instrED__LD_iNNNN_SP;
    /* IN A,(C) */
    opcodemaped[0x78] = instrED__IN_A_iC;
    /* OUT (C),A */
    opcodemaped[0x79] = instrED__OUT_iC_A;
    /* ADC HL,SP */
    opcodemaped[0x7a] = instrED__ADC_HL_SP;
    /* LD SP,(nnnn) */
    opcodemaped[0x7b] = instrED__LD_SP_iNNNN;
    /* LDI */
    opcodemaped[0xa0] = instrED__LDI;
    /* CPI */
    opcodemaped[0xa1] = instrED__CPI;
    /* INI */
    opcodemaped[0xa2] = instrED__INI;
    /* OUTI */
    opcodemaped[0xa3] = instrED__OUTI;
    /* LDD */
    opcodemaped[0xa8] = instrED__LDD;
    /* CPD */
    opcodemaped[0xa9] = instrED__CPD;
    /* IND */
    opcodemaped[0xaa] = instrED__IND;
    /* OUTD */
    opcodemaped[0xab] = instrED__OUTD;
    /* LDIR */
    opcodemaped[0xb0] = instrED__LDIR;
    /* CPIR */
    opcodemaped[0xb1] = instrED__CPIR;
    /* INIR */
    opcodemaped[0xb2] = instrED__INIR;
    /* OTIR */
    opcodemaped[0xb3] = instrED__OTIR;
    /* LDDR */
    opcodemaped[0xb8] = instrED__LDDR;
    /* CPDR */
    opcodemaped[0xb9] = instrED__CPDR;
    /* INDR */
    opcodemaped[0xba] = instrED__INDR;
    /* OTDR */
    opcodemaped[0xbb] = instrED__OTDR;
    // /* slttrap */
    // opcodemaped[0xfb] = instrED__SLTTRAP;

    // // 	// END of 0xed shifted opcodes
}

void opcodeEDStep(Z80* z, const uint8_t opcode) {
    uint8_t opcode2 = z->load8();
    z->R++;
    opcodemaped[opcode2](z, opcode2); // FIXME: implementar
}