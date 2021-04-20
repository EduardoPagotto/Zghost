#include <zghost/z80/OpCodeCB.hpp>

/* RLC r */
void instrCB__RLC_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    uint8_t* reg = z->getPrtRegisterValByte(opcode);
    *reg = z->rlc(*reg);
}

/* RLC (HL) */
void instrCB__RLC_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 16;
    uint8_t bytetemp = z->bus->readMemory(z->HL->get());
    // z->Memory.ContendReadNoMreq(z->HL->get(), 1)
    bytetemp = z->rlc(bytetemp);
    z->bus->writeMemory(z->HL->get(), bytetemp);
}

/* RRC r */
void instrCB__RRC_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    uint8_t* reg = z->getPrtRegisterValByte(opcode);
    *reg = z->rrc(*reg);
}

/* RRC (HL) */
void instrCB__RRC_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 15;
    uint8_t bytetemp = z->bus->readMemory(z->HL->get());
    // z->Memory.ContendReadNoMreq(z->HL->get(), 1)
    bytetemp = z->rrc(bytetemp);
    z->bus->writeMemory(z->HL->get(), bytetemp);
}

/* RL r */
void instrCB__RL_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    uint8_t* reg = z->getPrtRegisterValByte(opcode);
    *reg = z->rl(*reg);
}

/* RL (HL) */
void instrCB__RL_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 15;
    uint8_t bytetemp = z->bus->readMemory(z->HL->get());
    // z->Memory.ContendReadNoMreq(z->HL->get(), 1)
    bytetemp = z->rl(bytetemp);
    z->bus->writeMemory(z->HL->get(), bytetemp);
}

/* RR r */
void instrCB__RR_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    uint8_t* reg = z->getPrtRegisterValByte(opcode);
    *reg = z->rr(*reg);
}

/* RR (HL) */
void instrCB__RR_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 15;
    uint8_t bytetemp = z->bus->readMemory(z->HL->get());
    // z->Memory.ContendReadNoMreq(z->HL->get(), 1)
    bytetemp = z->rr(bytetemp);
    z->bus->writeMemory(z->HL->get(), bytetemp);
}

/* SLA r */
void instrCB__SLA_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    uint8_t* reg = z->getPrtRegisterValByte(opcode);
    *reg = z->sla(*reg);
}

/* SLA (HL) */
void instrCB__SLA_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 15;
    uint8_t bytetemp = z->bus->readMemory(z->HL->get());
    // z->Memory.ContendReadNoMreq(z->HL->get(), 1)
    bytetemp = z->sla(bytetemp);
    z->bus->writeMemory(z->HL->get(), bytetemp);
}

/* SRA r */
void instrCB__SRA_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    uint8_t* reg = z->getPrtRegisterValByte(opcode);
    *reg = z->sra(*reg);
}

/* SRA (HL) */
void instrCB__SRA_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 15;
    uint8_t bytetemp = z->bus->readMemory(z->HL->get());
    // z->Memory.ContendReadNoMreq(z->HL->get(), 1)
    bytetemp = z->sra(bytetemp);
    z->bus->writeMemory(z->HL->get(), bytetemp);
}

/* SLL B */
void instrCB__SLL_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    uint8_t* reg = z->getPrtRegisterValByte(opcode);
    *reg = z->sll(*reg);
}

/* SLL (HL) */
void instrCB__SLL_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 15;
    uint8_t bytetemp = z->bus->readMemory(z->HL->get());
    // z->Memory.ContendReadNoMreq(z->HL->get(), 1)
    bytetemp = z->sll(bytetemp);
    z->bus->writeMemory(z->HL->get(), bytetemp);
}

/* SRL r */
void instrCB__SRL_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    uint8_t* reg = z->getPrtRegisterValByte(opcode);
    *reg = z->srl(*reg);
}

/* SRL (HL) */
void instrCB__SRL_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 15;
    uint8_t bytetemp = z->bus->readMemory(z->HL->get());
    // z->Memory.ContendReadNoMreq(z->HL->get(), 1)
    bytetemp = z->srl(bytetemp);
    z->bus->writeMemory(z->HL->get(), bytetemp);
}

/* BIT b,r */
void instrCB__BIT_b_r(Z80* z, const uint8_t& opcode) {
    uint8_t* reg = z->getPrtRegisterValByte(opcode);
    uint8_t bitSel = (opcode & 0x38) >> 3;
    z->Tstates += 8;
    z->bit(bitSel, *reg);
}

/* BIT b,(HL) */
void instrCB__BIT_b_iHL(Z80* z, const uint8_t& opcode) {
    uint8_t bitSel = (opcode & 0x38) >> 3;
    z->Tstates += 12;
    uint8_t bytetemp = z->bus->readMemory(z->HL->get());
    // z->Memory.ContendReadNoMreq(z->HL->get(), 1)
    z->bit(bitSel, bytetemp);
}

/* RES b,n */
void instrCB__RES_b_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    uint8_t* reg = z->getPrtRegisterValByte(opcode);
    uint8_t bitSel = (opcode & 0x38) >> 3;
    *reg &= z->getMaskBitReset(bitSel);
}

/* RES b,(HL) */
void instrCB__RES_b_iHL(Z80* z, const uint8_t& opcode) {
    z->Tstates += 15;
    uint8_t bytetemp = z->bus->readMemory(z->HL->get());
    uint8_t bitSel = (opcode & 0x38) >> 3;
    uint8_t mask = z->getMaskBitReset(bitSel);
    // z->Memory.ContendReadNoMreq(z->HL->get(), 1)
    z->bus->writeMemory(z->HL->get(), bytetemp & mask);
}

/* SET b,r */
void instrCB__SET_b_r(Z80* z, const uint8_t& opcode) {
    z->Tstates += 8;
    uint8_t* reg = z->getPrtRegisterValByte(opcode);
    uint8_t bitSel = (opcode & 0x38) >> 3;
    *reg |= !z->getMaskBitReset(bitSel); // FIXME not!!!
}

/* SET b,(HL) */
void instrCB__SET_b_iHL(Z80* z, const uint8_t& opcode) {

    z->Tstates += 15;
    uint8_t bytetemp = z->bus->readMemory(z->HL->get());
    uint8_t bitSel = (opcode & 0x38) >> 3;
    uint8_t mask = !z->getMaskBitReset(bitSel);
    // z->Memory.ContendReadNoMreq(z->HL->get(), 1)
    z->bus->writeMemory(z->HL->get(), bytetemp | mask);
}

void (*opcodemapcb[256])(Z80*, const uint8_t&);

void initOpCodeCB() {

    // BEGIN of 0xcb shifted opcodes
    /* RLC B */
    opcodemapcb[0x00] = instrCB__RLC_r;
    /* RLC C */
    opcodemapcb[0x01] = instrCB__RLC_r;
    /* RLC D */
    opcodemapcb[0x02] = instrCB__RLC_r;
    /* RLC E */
    opcodemapcb[0x03] = instrCB__RLC_r;
    /* RLC H */
    opcodemapcb[0x04] = instrCB__RLC_r;
    /* RLC L */
    opcodemapcb[0x05] = instrCB__RLC_r;
    /* RLC (HL) */
    opcodemapcb[0x06] = instrCB__RLC_iHL;
    /* RLC A */
    opcodemapcb[0x07] = instrCB__RLC_r;
    /* RRC B */
    opcodemapcb[0x08] = instrCB__RRC_r;
    /* RRC C */
    opcodemapcb[0x09] = instrCB__RRC_r;
    /* RRC D */
    opcodemapcb[0x0a] = instrCB__RRC_r;
    /* RRC E */
    opcodemapcb[0x0b] = instrCB__RRC_r;
    /* RRC H */
    opcodemapcb[0x0c] = instrCB__RRC_r;
    /* RRC L */
    opcodemapcb[0x0d] = instrCB__RRC_r;
    /* RRC (HL) */
    opcodemapcb[0x0e] = instrCB__RRC_iHL;
    /* RRC A */
    opcodemapcb[0x0f] = instrCB__RRC_r;
    /* RL B */
    opcodemapcb[0x10] = instrCB__RL_r;
    /* RL C */
    opcodemapcb[0x11] = instrCB__RL_r;
    /* RL D */
    opcodemapcb[0x12] = instrCB__RL_r;
    /* RL E */
    opcodemapcb[0x13] = instrCB__RL_r;
    /* RL H */
    opcodemapcb[0x14] = instrCB__RL_r;
    /* RL L */
    opcodemapcb[0x15] = instrCB__RL_r;
    /* RL (HL) */
    opcodemapcb[0x16] = instrCB__RL_iHL;
    /* RL A */
    opcodemapcb[0x17] = instrCB__RL_r;
    /* RR B */
    opcodemapcb[0x18] = instrCB__RR_r;
    /* RR C */
    opcodemapcb[0x19] = instrCB__RR_r;
    /* RR D */
    opcodemapcb[0x1a] = instrCB__RR_r;
    /* RR E */
    opcodemapcb[0x1b] = instrCB__RR_r;
    /* RR H */
    opcodemapcb[0x1c] = instrCB__RR_r;
    /* RR L */
    opcodemapcb[0x1d] = instrCB__RR_r;
    /* RR (HL) */
    opcodemapcb[0x1e] = instrCB__RR_iHL;
    /* RR A */
    opcodemapcb[0x1f] = instrCB__RR_r;
    /* SLA B */
    opcodemapcb[0x20] = instrCB__SLA_r;
    /* SLA C */
    opcodemapcb[0x21] = instrCB__SLA_r;
    /* SLA D */
    opcodemapcb[0x22] = instrCB__SLA_r;
    /* SLA E */
    opcodemapcb[0x23] = instrCB__SLA_r;
    /* SLA H */
    opcodemapcb[0x24] = instrCB__SLA_r;
    /* SLA L */
    opcodemapcb[0x25] = instrCB__SLA_r;
    /* SLA (HL) */
    opcodemapcb[0x26] = instrCB__SLA_iHL;
    /* SLA A */
    opcodemapcb[0x27] = instrCB__SLA_r;
    /* SRA B */
    opcodemapcb[0x28] = instrCB__SRA_r;
    /* SRA C */
    opcodemapcb[0x29] = instrCB__SRA_r;
    /* SRA D */
    opcodemapcb[0x2a] = instrCB__SRA_r;
    /* SRA E */
    opcodemapcb[0x2b] = instrCB__SRA_r;
    /* SRA H */
    opcodemapcb[0x2c] = instrCB__SRA_r;
    /* SRA L */
    opcodemapcb[0x2d] = instrCB__SRA_r;
    /* SRA (HL) */
    opcodemapcb[0x2e] = instrCB__SRA_iHL;
    /* SRA A */
    opcodemapcb[0x2f] = instrCB__SRA_r;
    /* SLL B */
    opcodemapcb[0x30] = instrCB__SLL_r;
    /* SLL C */
    opcodemapcb[0x31] = instrCB__SLL_r;
    /* SLL D */
    opcodemapcb[0x32] = instrCB__SLL_r;
    /* SLL E */
    opcodemapcb[0x33] = instrCB__SLL_r;
    /* SLL H */
    opcodemapcb[0x34] = instrCB__SLL_r;
    /* SLL L */
    opcodemapcb[0x35] = instrCB__SLL_r;
    /* SLL (HL) */
    opcodemapcb[0x36] = instrCB__SLL_iHL;
    /* SLL A */
    opcodemapcb[0x37] = instrCB__SLL_r;
    /* SRL B */
    opcodemapcb[0x38] = instrCB__SRL_r;
    /* SRL C */
    opcodemapcb[0x39] = instrCB__SRL_r;
    /* SRL D */
    opcodemapcb[0x3a] = instrCB__SRL_r;
    /* SRL E */
    opcodemapcb[0x3b] = instrCB__SRL_r;
    /* SRL H */
    opcodemapcb[0x3c] = instrCB__SRL_r;
    /* SRL L */
    opcodemapcb[0x3d] = instrCB__SRL_r;
    /* SRL (HL) */
    opcodemapcb[0x3e] = instrCB__SRL_iHL;
    /* SRL A */
    opcodemapcb[0x3f] = instrCB__SRL_r;
    /* BIT 0,B */
    opcodemapcb[0x40] = instrCB__BIT_b_r;
    /* BIT 0,C */
    opcodemapcb[0x41] = instrCB__BIT_b_r;
    /* BIT 0,D */
    opcodemapcb[0x42] = instrCB__BIT_b_r;
    /* BIT 0,E */
    opcodemapcb[0x43] = instrCB__BIT_b_r;
    /* BIT 0,H */
    opcodemapcb[0x44] = instrCB__BIT_b_r;
    /* BIT 0,L */
    opcodemapcb[0x45] = instrCB__BIT_b_r;
    /* BIT 0,(HL) */
    opcodemapcb[0x46] = instrCB__BIT_b_iHL;
    /* BIT 0,A */
    opcodemapcb[0x47] = instrCB__BIT_b_r;
    /* BIT 1,B */
    opcodemapcb[0x48] = instrCB__BIT_b_r;
    /* BIT 1,C */
    opcodemapcb[0x49] = instrCB__BIT_b_r;
    /* BIT 1,D */
    opcodemapcb[0x4a] = instrCB__BIT_b_r;
    /* BIT 1,E */
    opcodemapcb[0x4b] = instrCB__BIT_b_r;
    /* BIT 1,H */
    opcodemapcb[0x4c] = instrCB__BIT_b_r;
    /* BIT 1,L */
    opcodemapcb[0x4d] = instrCB__BIT_b_r;
    /* BIT 1,(HL) */
    opcodemapcb[0x4e] = instrCB__BIT_b_iHL;
    /* BIT 1,A */
    opcodemapcb[0x4f] = instrCB__BIT_b_r;
    /* BIT 2,B */
    opcodemapcb[0x50] = instrCB__BIT_b_r;
    /* BIT 2,C */
    opcodemapcb[0x51] = instrCB__BIT_b_r;
    /* BIT 2,D */
    opcodemapcb[0x52] = instrCB__BIT_b_r;
    /* BIT 2,E */
    opcodemapcb[0x53] = instrCB__BIT_b_r;
    /* BIT 2,H */
    opcodemapcb[0x54] = instrCB__BIT_b_r;
    /* BIT 2,L */
    opcodemapcb[0x55] = instrCB__BIT_b_r;
    /* BIT 2,(HL) */
    opcodemapcb[0x56] = instrCB__BIT_b_iHL;
    /* BIT 2,A */
    opcodemapcb[0x57] = instrCB__BIT_b_r;
    /* BIT 3,B */
    opcodemapcb[0x58] = instrCB__BIT_b_r;
    /* BIT 3,C */
    opcodemapcb[0x59] = instrCB__BIT_b_r;
    /* BIT 3,D */
    opcodemapcb[0x5a] = instrCB__BIT_b_r;
    /* BIT 3,E */
    opcodemapcb[0x5b] = instrCB__BIT_b_r;
    /* BIT 3,H */
    opcodemapcb[0x5c] = instrCB__BIT_b_r;
    /* BIT 3,L */
    opcodemapcb[0x5d] = instrCB__BIT_b_r;
    /* BIT 3,(HL) */
    opcodemapcb[0x5e] = instrCB__BIT_b_iHL;
    /* BIT 3,A */
    opcodemapcb[0x5f] = instrCB__BIT_b_r;
    /* BIT 4,B */
    opcodemapcb[0x60] = instrCB__BIT_b_r;
    /* BIT 4,C */
    opcodemapcb[0x61] = instrCB__BIT_b_r;
    /* BIT 4,D */
    opcodemapcb[0x62] = instrCB__BIT_b_r;
    /* BIT 4,E */
    opcodemapcb[0x63] = instrCB__BIT_b_r;
    /* BIT 4,H */
    opcodemapcb[0x64] = instrCB__BIT_b_r;
    /* BIT 4,L */
    opcodemapcb[0x65] = instrCB__BIT_b_r;
    /* BIT 4,(HL) */
    opcodemapcb[0x66] = instrCB__BIT_b_iHL;
    /* BIT 4,A */
    opcodemapcb[0x67] = instrCB__BIT_b_r;
    /* BIT 5,B */
    opcodemapcb[0x68] = instrCB__BIT_b_r;
    /* BIT 5,C */
    opcodemapcb[0x69] = instrCB__BIT_b_r;
    /* BIT 5,D */
    opcodemapcb[0x6a] = instrCB__BIT_b_r;
    /* BIT 5,E */
    opcodemapcb[0x6b] = instrCB__BIT_b_r;
    /* BIT 5,H */
    opcodemapcb[0x6c] = instrCB__BIT_b_r;
    /* BIT 5,L */
    opcodemapcb[0x6d] = instrCB__BIT_b_r;
    /* BIT 5,(HL) */
    opcodemapcb[0x6e] = instrCB__BIT_b_iHL;
    /* BIT 5,A */
    opcodemapcb[0x6f] = instrCB__BIT_b_r;
    /* BIT 6,B */
    opcodemapcb[0x70] = instrCB__BIT_b_r;
    /* BIT 6,C */
    opcodemapcb[0x71] = instrCB__BIT_b_r;
    /* BIT 6,D */
    opcodemapcb[0x72] = instrCB__BIT_b_r;
    /* BIT 6,E */
    opcodemapcb[0x73] = instrCB__BIT_b_r;
    /* BIT 6,H */
    opcodemapcb[0x74] = instrCB__BIT_b_r;
    /* BIT 6,L */
    opcodemapcb[0x75] = instrCB__BIT_b_r;
    /* BIT 6,(HL) */
    opcodemapcb[0x76] = instrCB__BIT_b_iHL;
    /* BIT 6,A */
    opcodemapcb[0x77] = instrCB__BIT_b_r;
    /* BIT 7,B */
    opcodemapcb[0x78] = instrCB__BIT_b_r;
    /* BIT 7,C */
    opcodemapcb[0x79] = instrCB__BIT_b_r;
    /* BIT 7,D */
    opcodemapcb[0x7a] = instrCB__BIT_b_r;
    /* BIT 7,E */
    opcodemapcb[0x7b] = instrCB__BIT_b_r;
    /* BIT 7,H */
    opcodemapcb[0x7c] = instrCB__BIT_b_r;
    /* BIT 7,L */
    opcodemapcb[0x7d] = instrCB__BIT_b_r;
    /* BIT 7,(HL) */
    opcodemapcb[0x7e] = instrCB__BIT_b_iHL;
    /* BIT 7,A */
    opcodemapcb[0x7f] = instrCB__BIT_b_r;
    /* RES 0,B */
    opcodemapcb[0x80] = instrCB__RES_b_r;
    /* RES 0,C */
    opcodemapcb[0x81] = instrCB__RES_b_r;
    /* RES 0,D */
    opcodemapcb[0x82] = instrCB__RES_b_r;
    /* RES 0,E */
    opcodemapcb[0x83] = instrCB__RES_b_r;
    /* RES 0,H */
    opcodemapcb[0x84] = instrCB__RES_b_r;
    /* RES 0,L */
    opcodemapcb[0x85] = instrCB__RES_b_r;
    /* RES 0,(HL) */
    opcodemapcb[0x86] = instrCB__RES_b_iHL;
    /* RES 0,A */
    opcodemapcb[0x87] = instrCB__RES_b_r;
    /* RES 1,B */
    opcodemapcb[0x88] = instrCB__RES_b_r;
    /* RES 1,C */
    opcodemapcb[0x89] = instrCB__RES_b_r;
    /* RES 1,D */
    opcodemapcb[0x8a] = instrCB__RES_b_r;
    /* RES 1,E */
    opcodemapcb[0x8b] = instrCB__RES_b_r;
    /* RES 1,H */
    opcodemapcb[0x8c] = instrCB__RES_b_r;
    /* RES 1,L */
    opcodemapcb[0x8d] = instrCB__RES_b_r;
    /* RES 1,(HL) */
    opcodemapcb[0x8e] = instrCB__RES_b_iHL;
    /* RES 1,A */
    opcodemapcb[0x8f] = instrCB__RES_b_r;
    /* RES 2,B */
    opcodemapcb[0x90] = instrCB__RES_b_r;
    /* RES 2,C */
    opcodemapcb[0x91] = instrCB__RES_b_r;
    /* RES 2,D */
    opcodemapcb[0x92] = instrCB__RES_b_r;
    /* RES 2,E */
    opcodemapcb[0x93] = instrCB__RES_b_r;
    /* RES 2,H */
    opcodemapcb[0x94] = instrCB__RES_b_r;
    /* RES 2,L */
    opcodemapcb[0x95] = instrCB__RES_b_r;
    /* RES 2,(HL) */
    opcodemapcb[0x96] = instrCB__RES_b_iHL;
    /* RES 2,A */
    opcodemapcb[0x97] = instrCB__RES_b_r;
    /* RES 3,B */
    opcodemapcb[0x98] = instrCB__RES_b_r;
    /* RES 3,C */
    opcodemapcb[0x99] = instrCB__RES_b_r;
    /* RES 3,D */
    opcodemapcb[0x9a] = instrCB__RES_b_r;
    /* RES 3,E */
    opcodemapcb[0x9b] = instrCB__RES_b_r;
    /* RES 3,H */
    opcodemapcb[0x9c] = instrCB__RES_b_r;
    /* RES 3,L */
    opcodemapcb[0x9d] = instrCB__RES_b_r;
    /* RES 3,(HL) */
    opcodemapcb[0x9e] = instrCB__RES_b_iHL;
    /* RES 3,A */
    opcodemapcb[0x9f] = instrCB__RES_b_r;
    /* RES 4,B */
    opcodemapcb[0xa0] = instrCB__RES_b_r;
    /* RES 4,C */
    opcodemapcb[0xa1] = instrCB__RES_b_r;
    /* RES 4,D */
    opcodemapcb[0xa2] = instrCB__RES_b_r;
    /* RES 4,E */
    opcodemapcb[0xa3] = instrCB__RES_b_r;
    /* RES 4,H */
    opcodemapcb[0xa4] = instrCB__RES_b_r;
    /* RES 4,L */
    opcodemapcb[0xa5] = instrCB__RES_b_r;
    /* RES 4,(HL) */
    opcodemapcb[0xa6] = instrCB__RES_b_iHL;
    /* RES 4,A */
    opcodemapcb[0xa7] = instrCB__RES_b_r;
    /* RES 5,B */
    opcodemapcb[0xa8] = instrCB__RES_b_r;
    /* RES 5,C */
    opcodemapcb[0xa9] = instrCB__RES_b_r;
    /* RES 5,D */
    opcodemapcb[0xaa] = instrCB__RES_b_r;
    /* RES 5,E */
    opcodemapcb[0xab] = instrCB__RES_b_r;
    /* RES 5,H */
    opcodemapcb[0xac] = instrCB__RES_b_r;
    /* RES 5,L */
    opcodemapcb[0xad] = instrCB__RES_b_r;
    /* RES 5,(HL) */
    opcodemapcb[0xae] = instrCB__RES_b_iHL;
    /* RES 5,A */
    opcodemapcb[0xaf] = instrCB__RES_b_r;
    /* RES 6,B */
    opcodemapcb[0xb0] = instrCB__RES_b_r;
    /* RES 6,C */
    opcodemapcb[0xb1] = instrCB__RES_b_r;
    /* RES 6,D */
    opcodemapcb[0xb2] = instrCB__RES_b_r;
    /* RES 6,E */
    opcodemapcb[0xb3] = instrCB__RES_b_r;
    /* RES 6,H */
    opcodemapcb[0xb4] = instrCB__RES_b_r;
    /* RES 6,L */
    opcodemapcb[0xb5] = instrCB__RES_b_r;
    /* RES 6,(HL) */
    opcodemapcb[0xb6] = instrCB__RES_b_iHL;
    /* RES 6,A */
    opcodemapcb[0xb7] = instrCB__RES_b_r;
    /* RES 7,B */
    opcodemapcb[0xb8] = instrCB__RES_b_r;
    /* RES 7,C */
    opcodemapcb[0xb9] = instrCB__RES_b_r;
    /* RES 7,D */
    opcodemapcb[0xba] = instrCB__RES_b_r;
    /* RES 7,E */
    opcodemapcb[0xbb] = instrCB__RES_b_r;
    /* RES 7,H */
    opcodemapcb[0xbc] = instrCB__RES_b_r;
    /* RES 7,L */
    opcodemapcb[0xbd] = instrCB__RES_b_r;
    /* RES 7,(HL) */
    opcodemapcb[0xbe] = instrCB__RES_b_iHL;
    /* RES 7,A */
    opcodemapcb[0xbf] = instrCB__RES_b_r;
    /* SET 0,B */
    opcodemapcb[0xc0] = instrCB__SET_b_r;
    /* SET 0,C */
    opcodemapcb[0xc1] = instrCB__SET_b_r;
    /* SET 0,D */
    opcodemapcb[0xc2] = instrCB__SET_b_r;
    /* SET 0,E */
    opcodemapcb[0xc3] = instrCB__SET_b_r;
    /* SET 0,H */
    opcodemapcb[0xc4] = instrCB__SET_b_r;
    /* SET 0,L */
    opcodemapcb[0xc5] = instrCB__SET_b_r;
    /* SET 0,(HL) */
    opcodemapcb[0xc6] = instrCB__SET_b_iHL;
    /* SET 0,A */
    opcodemapcb[0xc7] = instrCB__SET_b_r;
    /* SET 1,B */
    opcodemapcb[0xc8] = instrCB__SET_b_r;
    /* SET 1,C */
    opcodemapcb[0xc9] = instrCB__SET_b_r;
    /* SET 1,D */
    opcodemapcb[0xca] = instrCB__SET_b_r;
    /* SET 1,E */
    opcodemapcb[0xcb] = instrCB__SET_b_r;
    /* SET 1,H */
    opcodemapcb[0xcc] = instrCB__SET_b_r;
    /* SET 1,L */
    opcodemapcb[0xcd] = instrCB__SET_b_r;
    /* SET 1,(HL) */
    opcodemapcb[0xce] = instrCB__SET_b_iHL;
    /* SET 1,A */
    opcodemapcb[0xcf] = instrCB__SET_b_r;
    /* SET 2,B */
    opcodemapcb[0xd0] = instrCB__SET_b_r;
    /* SET 2,C */
    opcodemapcb[0xd1] = instrCB__SET_b_r;
    /* SET 2,D */
    opcodemapcb[0xd2] = instrCB__SET_b_r;
    /* SET 2,E */
    opcodemapcb[0xd3] = instrCB__SET_b_r;
    /* SET 2,H */
    opcodemapcb[0xd4] = instrCB__SET_b_r;
    /* SET 2,L */
    opcodemapcb[0xd5] = instrCB__SET_b_r;
    /* SET 2,(HL) */
    opcodemapcb[0xd6] = instrCB__SET_b_iHL;
    /* SET 2,A */
    opcodemapcb[0xd7] = instrCB__SET_b_r;
    /* SET 3,B */
    opcodemapcb[0xd8] = instrCB__SET_b_r;
    /* SET 3,C */
    opcodemapcb[0xd9] = instrCB__SET_b_r;
    /* SET 3,D */
    opcodemapcb[0xda] = instrCB__SET_b_r;
    /* SET 3,E */
    opcodemapcb[0xdb] = instrCB__SET_b_r;
    /* SET 3,H */
    opcodemapcb[0xdc] = instrCB__SET_b_r;
    /* SET 3,L */
    opcodemapcb[0xdd] = instrCB__SET_b_r;
    /* SET 3,(HL) */
    opcodemapcb[0xde] = instrCB__SET_b_iHL;
    /* SET 3,A */
    opcodemapcb[0xdf] = instrCB__SET_b_r;
    /* SET 4,B */
    opcodemapcb[0xe0] = instrCB__SET_b_r;
    /* SET 4,C */
    opcodemapcb[0xe1] = instrCB__SET_b_r;
    /* SET 4,D */
    opcodemapcb[0xe2] = instrCB__SET_b_r;
    /* SET 4,E */
    opcodemapcb[0xe3] = instrCB__SET_b_r;
    /* SET 4,H */
    opcodemapcb[0xe4] = instrCB__SET_b_r;
    /* SET 4,L */
    opcodemapcb[0xe5] = instrCB__SET_b_r;
    /* SET 4,(HL) */
    opcodemapcb[0xe6] = instrCB__SET_b_iHL;
    /* SET 4,A */
    opcodemapcb[0xe7] = instrCB__SET_b_r;
    /* SET 5,B */
    opcodemapcb[0xe8] = instrCB__SET_b_r;
    /* SET 5,C */
    opcodemapcb[0xe9] = instrCB__SET_b_r;
    /* SET 5,D */
    opcodemapcb[0xea] = instrCB__SET_b_r;
    /* SET 5,E */
    opcodemapcb[0xeb] = instrCB__SET_b_r;
    /* SET 5,H */
    opcodemapcb[0xec] = instrCB__SET_b_r;
    /* SET 5,L */
    opcodemapcb[0xed] = instrCB__SET_b_r;
    /* SET 5,(HL) */
    opcodemapcb[0xee] = instrCB__SET_b_iHL;
    /* SET 5,A */
    opcodemapcb[0xef] = instrCB__SET_b_r;
    /* SET 6,B */
    opcodemapcb[0xf0] = instrCB__SET_b_r;
    /* SET 6,C */
    opcodemapcb[0xf1] = instrCB__SET_b_r;
    /* SET 6,D */
    opcodemapcb[0xf2] = instrCB__SET_b_r;
    /* SET 6,E */
    opcodemapcb[0xf3] = instrCB__SET_b_r;
    /* SET 6,H */
    opcodemapcb[0xf4] = instrCB__SET_b_r;
    /* SET 6,L */
    opcodemapcb[0xf5] = instrCB__SET_b_r;
    /* SET 6,(HL) */
    opcodemapcb[0xf6] = instrCB__SET_b_iHL;
    /* SET 6,A */
    opcodemapcb[0xf7] = instrCB__SET_b_r;
    /* SET 7,B */
    opcodemapcb[0xf8] = instrCB__SET_b_r;
    /* SET 7,C */
    opcodemapcb[0xf9] = instrCB__SET_b_r;
    /* SET 7,D */
    opcodemapcb[0xfa] = instrCB__SET_b_r;
    /* SET 7,E */
    opcodemapcb[0xfb] = instrCB__SET_b_r;
    /* SET 7,H */
    opcodemapcb[0xfc] = instrCB__SET_b_r;
    /* SET 7,L */
    opcodemapcb[0xfd] = instrCB__SET_b_r;
    /* SET 7,(HL) */
    opcodemapcb[0xfe] = instrCB__SET_b_iHL;
    /* SET 7,A */
    opcodemapcb[0xff] = instrCB__SET_b_r;

    // END of 0xcb shifted opcodes
}

void opcodeCBStep(Z80* z, const uint8_t opcode) {

    // z->Tstates += 4
    uint8_t opcode2 = z->load8();
    z->R++;
    opcodemapcb[opcode2](z, opcode2); // FIXME: implementar
}