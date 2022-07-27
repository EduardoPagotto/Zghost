#include <zghost/z80/OpCodeDDCBFDCB.hpp>

/* LD r,RLC (REGISTER+dd) */
void instrDDCB__LD_r_RLC_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t& reg = z->getRegRef(opcode);
    reg = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    reg = z->rlc(reg);
    z->writeMem(address, reg);
}

/* RLC (REGISTER+dd) */
void instrDDCB__RLC_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    bytetemp = z->rlc(bytetemp);
    z->writeMem(address, bytetemp);
}

/* LD r,RRC (REGISTER+dd) */
void instrDDCB__LD_r_RRC_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t& reg = z->getRegRef(opcode);
    reg = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    reg = z->rrc(reg);
    z->writeMem(address, reg);
}

/* RRC (REGISTER+dd) */
void instrDDCB__RRC_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    bytetemp = z->rrc(bytetemp);
    z->writeMem(address, bytetemp);
}

/* LD B,RL (REGISTER+dd) */
void instrDDCB__LD_r_RL_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??
    uint8_t& reg = z->getRegRef(opcode);

    reg = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    reg = z->rl(reg);
    z->writeMem(address, reg);
}

/* RL (REGISTER+dd) */
void instrDDCB__RL_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    bytetemp = z->rl(bytetemp);
    z->writeMem(address, bytetemp);
}

/* LD r,RR (REGISTER+dd) */
void instrDDCB__LD_r_RR_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??
    uint8_t& reg = z->getRegRef(opcode);

    reg = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    reg = z->rr(reg);
    z->writeMem(address, reg);
}

/* RR (REGISTER+dd) */
void instrDDCB__RR_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    bytetemp = z->rr(bytetemp);
    z->writeMem(address, bytetemp);
}

/* LD r,SLA (REGISTER+dd) */
void instrDDCB__LD_r_SLA_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??
    uint8_t& reg = z->getRegRef(opcode);

    reg = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    reg = z->sla(reg);
    z->writeMem(address, reg);
}

/* SLA (REGISTER+dd) */
void instrDDCB__SLA_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    bytetemp = z->sla(bytetemp);
    z->writeMem(address, bytetemp);
}

/* LD B,SRA (REGISTER+dd) */
void instrDDCB__LD_r_SRA_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??
    uint8_t& reg = z->getRegRef(opcode);

    reg = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    reg = z->sra(reg);
    z->writeMem(address, reg);
}

/* SRA (REGISTER+dd) */
void instrDDCB__SRA_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    bytetemp = z->sra(bytetemp);
    z->writeMem(address, bytetemp);
}

/* LD r,SLL (REGISTER+dd) */
void instrDDCB__LD_r_SLL_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??
    uint8_t& reg = z->getRegRef(opcode);

    reg = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    reg = z->sll(reg);
    z->writeMem(address, reg);
}

/* SLL (REGISTER+dd) */
void instrDDCB__SLL_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    bytetemp = z->sll(bytetemp);
    z->writeMem(address, bytetemp);
}

/* LD r,SRL (REGISTER+dd) */
void instrDDCB__LD_r_SRL_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??
    uint8_t& reg = z->getRegRef(opcode);

    reg = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    reg = z->srl(reg);
    z->writeMem(address, reg);
}

/* SRL (REGISTER+dd) */
void instrDDCB__SRL_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    bytetemp = z->srl(bytetemp);
    z->writeMem(address, bytetemp);
}

/* BIT 0,(REGISTER+dd) */
void instrDDCB__BIT_0_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->biti(0, bytetemp, address);
}

/* BIT 1,(REGISTER+dd) */
void instrDDCB__BIT_1_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->biti(1, bytetemp, address);
}

/* BIT 2,(REGISTER+dd) */
void instrDDCB__BIT_2_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->biti(2, bytetemp, address);
}

/* BIT 3,(REGISTER+dd) */
void instrDDCB__BIT_3_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->biti(3, bytetemp, address);
}

/* BIT 4,(REGISTER+dd) */
void instrDDCB__BIT_4_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->biti(4, bytetemp, address);
}

/* BIT 5,(REGISTER+dd) */
void instrDDCB__BIT_5_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->biti(5, bytetemp, address);
}

/* BIT 6,(REGISTER+dd) */
void instrDDCB__BIT_6_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->biti(6, bytetemp, address);
}

/* BIT 7,(REGISTER+dd) */
void instrDDCB__BIT_7_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->biti(7, bytetemp, address);
}

/* LD r,RES b,(REGISTER+dd) */
void instrDDCB__LD_r_RES_b_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??
    uint8_t& reg = z->getRegRef(opcode);

    uint8_t offset = (opcode >> 4) & 0x07;
    uint8_t mask = z->getMaskBitReset(offset);

    reg = z->readMem(address) & mask; //  0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f

    // z->Memory.ContendReadNoMreq(address, 1)
    z->writeMem(address, reg);
}

/* RES 0,(REGISTER+dd) */
void instrDDCB__RES_0_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {
    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->writeMem(address, bytetemp & 0xfe);
}

/* RES 1,(REGISTER+dd) */
void instrDDCB__RES_1_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {
    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->writeMem(address, bytetemp & 0xfd);
}

/* RES 2,(REGISTER+dd) */
void instrDDCB__RES_2_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {
    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->writeMem(address, bytetemp & 0xfb);
}

/* RES 3,(REGISTER+dd) */
void instrDDCB__RES_3_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {
    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->writeMem(address, bytetemp & 0xf7);
}

/* RES 4,(REGISTER+dd) */
void instrDDCB__RES_4_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {
    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->writeMem(address, bytetemp & 0xef);
}

/* RES 5,(REGISTER+dd) */
void instrDDCB__RES_5_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {
    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->writeMem(address, bytetemp & 0xdf);
}

/* RES 6,(REGISTER+dd) */
void instrDDCB__RES_6_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {
    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->writeMem(address, bytetemp & 0xbf);
}

/* RES 7,(REGISTER+dd) */
void instrDDCB__RES_7_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {
    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->writeMem(address, bytetemp & 0x7f);
}

/* LD r,SET b,(REGISTER+dd) */
void instrDDCB__LD_r_SET_b_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??
    uint8_t& reg = z->getRegRef(opcode);

    uint8_t offset = (opcode >> 4) & 0x07;
    uint8_t mask = !z->getMaskBitReset(offset);

    reg = z->readMem(address) | mask;
    // z->Memory.ContendReadNoMreq(address, 1)
    z->writeMem(address, reg);
}

/* SET 0,(REGISTER+dd) */
void instrDDCB__SET_0_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->writeMem(address, bytetemp | 0x01);
}

/* SET 1,(REGISTER+dd) */
void instrDDCB__SET_1_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->writeMem(address, bytetemp | 0x02);
}

/* SET 2,(REGISTER+dd) */
void instrDDCB__SET_2_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->writeMem(address, bytetemp | 0x04);
}

/* SET 3,(REGISTER+dd) */
void instrDDCB__SET_3_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->writeMem(address, bytetemp | 0x08);
}

/* SET 4,(REGISTER+dd) */
void instrDDCB__SET_4_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->writeMem(address, bytetemp | 0x10);
}

/* SET 5,(REGISTER+dd) */
void instrDDCB__SET_5_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->writeMem(address, bytetemp | 0x20);
}

/* SET 6,(REGISTER+dd) */
void instrDDCB__SET_6_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->writeMem(address, bytetemp | 0x40);
}

/* SET 7,(REGISTER+dd) */
void instrDDCB__SET_7_iREGpDD(Z80* z, const uint8_t& opcode, const uint16_t& address) {

    z->Tstates += 15; // FIXME ??

    uint8_t bytetemp = z->readMem(address);
    // z->Memory.ContendReadNoMreq(address, 1)
    z->writeMem(address, bytetemp | 0x80);
}

void (*opcodemapddbcfdcb[256])(Z80* z, const uint8_t&, const uint16_t&);

void initOpCodeDDCBFDCB() {

    // BEGIN of 0xddfdcb shifted opcodes
    /* LD B,RLC (REGISTER+dd) */
    opcodemapddbcfdcb[0x00] = instrDDCB__LD_r_RLC_iREGpDD;
    /* LD C,RLC (REGISTER+dd) */
    opcodemapddbcfdcb[0x01] = instrDDCB__LD_r_RLC_iREGpDD;
    /* LD D,RLC (REGISTER+dd) */
    opcodemapddbcfdcb[0x02] = instrDDCB__LD_r_RLC_iREGpDD;
    /* LD E,RLC (REGISTER+dd) */
    opcodemapddbcfdcb[0x03] = instrDDCB__LD_r_RLC_iREGpDD;
    /* LD H,RLC (REGISTER+dd) */
    opcodemapddbcfdcb[0x04] = instrDDCB__LD_r_RLC_iREGpDD;
    /* LD L,RLC (REGISTER+dd) */
    opcodemapddbcfdcb[0x05] = instrDDCB__LD_r_RLC_iREGpDD;
    /* RLC (REGISTER+dd) */
    opcodemapddbcfdcb[0x06] = instrDDCB__RLC_iREGpDD;
    /* LD A,RLC (REGISTER+dd) */
    opcodemapddbcfdcb[0x07] = instrDDCB__LD_r_RLC_iREGpDD;
    /* LD B,RRC (REGISTER+dd) */
    opcodemapddbcfdcb[0x08] = instrDDCB__LD_r_RRC_iREGpDD;
    /* LD C,RRC (REGISTER+dd) */
    opcodemapddbcfdcb[0x09] = instrDDCB__LD_r_RRC_iREGpDD;
    /* LD D,RRC (REGISTER+dd) */
    opcodemapddbcfdcb[0x0a] = instrDDCB__LD_r_RRC_iREGpDD;
    /* LD E,RRC (REGISTER+dd) */
    opcodemapddbcfdcb[0x0b] = instrDDCB__LD_r_RRC_iREGpDD;
    /* LD H,RRC (REGISTER+dd) */
    opcodemapddbcfdcb[0x0c] = instrDDCB__LD_r_RRC_iREGpDD;
    /* LD L,RRC (REGISTER+dd) */
    opcodemapddbcfdcb[0x0d] = instrDDCB__LD_r_RRC_iREGpDD;
    /* RRC (REGISTER+dd) */
    opcodemapddbcfdcb[0x0e] = instrDDCB__RRC_iREGpDD;
    /* LD A,RRC (REGISTER+dd) */
    opcodemapddbcfdcb[0x0f] = instrDDCB__LD_r_RRC_iREGpDD;
    /* LD B,RL (REGISTER+dd) */
    opcodemapddbcfdcb[0x10] = instrDDCB__LD_r_RL_iREGpDD;
    /* LD C,RL (REGISTER+dd) */
    opcodemapddbcfdcb[0x11] = instrDDCB__LD_r_RL_iREGpDD;
    /* LD D,RL (REGISTER+dd) */
    opcodemapddbcfdcb[0x12] = instrDDCB__LD_r_RL_iREGpDD;
    /* LD E,RL (REGISTER+dd) */
    opcodemapddbcfdcb[0x13] = instrDDCB__LD_r_RL_iREGpDD;
    /* LD H,RL (REGISTER+dd) */
    opcodemapddbcfdcb[0x14] = instrDDCB__LD_r_RL_iREGpDD;
    /* LD L,RL (REGISTER+dd) */
    opcodemapddbcfdcb[0x15] = instrDDCB__LD_r_RL_iREGpDD;
    /* RL (REGISTER+dd) */
    opcodemapddbcfdcb[0x16] = instrDDCB__RL_iREGpDD;
    /* LD A,RL (REGISTER+dd) */
    opcodemapddbcfdcb[0x17] = instrDDCB__LD_r_RL_iREGpDD;
    /* LD B,RR (REGISTER+dd) */
    opcodemapddbcfdcb[0x18] = instrDDCB__LD_r_RR_iREGpDD;
    /* LD C,RR (REGISTER+dd) */
    opcodemapddbcfdcb[0x19] = instrDDCB__LD_r_RR_iREGpDD;
    /* LD D,RR (REGISTER+dd) */
    opcodemapddbcfdcb[0x1a] = instrDDCB__LD_r_RR_iREGpDD;
    /* LD E,RR (REGISTER+dd) */
    opcodemapddbcfdcb[0x1b] = instrDDCB__LD_r_RR_iREGpDD;
    /* LD H,RR (REGISTER+dd) */
    opcodemapddbcfdcb[0x1c] = instrDDCB__LD_r_RR_iREGpDD;
    /* LD L,RR (REGISTER+dd) */
    opcodemapddbcfdcb[0x1d] = instrDDCB__LD_r_RR_iREGpDD;
    /* RR (REGISTER+dd) */
    opcodemapddbcfdcb[0x1e] = instrDDCB__RR_iREGpDD;
    /* LD A,RR (REGISTER+dd) */
    opcodemapddbcfdcb[0x1f] = instrDDCB__LD_r_RR_iREGpDD;
    /* LD B,SLA (REGISTER+dd) */
    opcodemapddbcfdcb[0x20] = instrDDCB__LD_r_SLA_iREGpDD;
    /* LD C,SLA (REGISTER+dd) */
    opcodemapddbcfdcb[0x21] = instrDDCB__LD_r_SLA_iREGpDD;
    /* LD D,SLA (REGISTER+dd) */
    opcodemapddbcfdcb[0x22] = instrDDCB__LD_r_SLA_iREGpDD;
    /* LD E,SLA (REGISTER+dd) */
    opcodemapddbcfdcb[0x23] = instrDDCB__LD_r_SLA_iREGpDD;
    /* LD H,SLA (REGISTER+dd) */
    opcodemapddbcfdcb[0x24] = instrDDCB__LD_r_SLA_iREGpDD;
    /* LD L,SLA (REGISTER+dd) */
    opcodemapddbcfdcb[0x25] = instrDDCB__LD_r_SLA_iREGpDD;
    /* SLA (REGISTER+dd) */
    opcodemapddbcfdcb[0x26] = instrDDCB__SLA_iREGpDD;
    /* LD A,SLA (REGISTER+dd) */
    opcodemapddbcfdcb[0x27] = instrDDCB__LD_r_SLA_iREGpDD;
    /* LD B,SRA (REGISTER+dd) */
    opcodemapddbcfdcb[0x28] = instrDDCB__LD_r_SRA_iREGpDD;
    /* LD C,SRA (REGISTER+dd) */
    opcodemapddbcfdcb[0x29] = instrDDCB__LD_r_SRA_iREGpDD;
    /* LD D,SRA (REGISTER+dd) */
    opcodemapddbcfdcb[0x2a] = instrDDCB__LD_r_SRA_iREGpDD;
    /* LD E,SRA (REGISTER+dd) */
    opcodemapddbcfdcb[0x2b] = instrDDCB__LD_r_SRA_iREGpDD;
    /* LD H,SRA (REGISTER+dd) */
    opcodemapddbcfdcb[0x2c] = instrDDCB__LD_r_SRA_iREGpDD;
    /* LD L,SRA (REGISTER+dd) */
    opcodemapddbcfdcb[0x2d] = instrDDCB__LD_r_SRA_iREGpDD;
    /* SRA (REGISTER+dd) */
    opcodemapddbcfdcb[0x2e] = instrDDCB__SRA_iREGpDD;
    /* LD A,SRA (REGISTER+dd) */
    opcodemapddbcfdcb[0x2f] = instrDDCB__LD_r_SRA_iREGpDD;
    /* LD B,SLL (REGISTER+dd) */
    opcodemapddbcfdcb[0x30] = instrDDCB__LD_r_SLL_iREGpDD;
    /* LD C,SLL (REGISTER+dd) */
    opcodemapddbcfdcb[0x31] = instrDDCB__LD_r_SLL_iREGpDD;
    /* LD D,SLL (REGISTER+dd) */
    opcodemapddbcfdcb[0x32] = instrDDCB__LD_r_SLL_iREGpDD;
    /* LD E,SLL (REGISTER+dd) */
    opcodemapddbcfdcb[0x33] = instrDDCB__LD_r_SLL_iREGpDD;
    /* LD H,SLL (REGISTER+dd) */
    opcodemapddbcfdcb[0x34] = instrDDCB__LD_r_SLL_iREGpDD;
    /* LD L,SLL (REGISTER+dd) */
    opcodemapddbcfdcb[0x35] = instrDDCB__LD_r_SLL_iREGpDD;
    /* SLL (REGISTER+dd) */
    opcodemapddbcfdcb[0x36] = instrDDCB__SLL_iREGpDD;
    /* LD A,SLL (REGISTER+dd) */
    opcodemapddbcfdcb[0x37] = instrDDCB__LD_r_SLL_iREGpDD;
    /* LD B,SRL (REGISTER+dd) */
    opcodemapddbcfdcb[0x38] = instrDDCB__LD_r_SRL_iREGpDD;
    /* LD C,SRL (REGISTER+dd) */
    opcodemapddbcfdcb[0x39] = instrDDCB__LD_r_SRL_iREGpDD;
    /* LD D,SRL (REGISTER+dd) */
    opcodemapddbcfdcb[0x3a] = instrDDCB__LD_r_SRL_iREGpDD;
    /* LD E,SRL (REGISTER+dd) */
    opcodemapddbcfdcb[0x3b] = instrDDCB__LD_r_SRL_iREGpDD;
    /* LD H,SRL (REGISTER+dd) */
    opcodemapddbcfdcb[0x3c] = instrDDCB__LD_r_SRL_iREGpDD;
    /* LD L,SRL (REGISTER+dd) */
    opcodemapddbcfdcb[0x3d] = instrDDCB__LD_r_SRL_iREGpDD;
    /* SRL (REGISTER+dd) */
    opcodemapddbcfdcb[0x3e] = instrDDCB__SRL_iREGpDD;
    /* LD A,SRL (REGISTER+dd) */
    opcodemapddbcfdcb[0x3f] = instrDDCB__LD_r_SRL_iREGpDD;
    /* BIT 0,(REGISTER+dd) */
    opcodemapddbcfdcb[0x47] = instrDDCB__BIT_0_iREGpDD;
    // Fallthrough cases
    opcodemapddbcfdcb[0x40] = opcodemapddbcfdcb[0x47];
    opcodemapddbcfdcb[0x41] = opcodemapddbcfdcb[0x47];
    opcodemapddbcfdcb[0x42] = opcodemapddbcfdcb[0x47];
    opcodemapddbcfdcb[0x43] = opcodemapddbcfdcb[0x47];
    opcodemapddbcfdcb[0x44] = opcodemapddbcfdcb[0x47];
    opcodemapddbcfdcb[0x45] = opcodemapddbcfdcb[0x47];
    opcodemapddbcfdcb[0x46] = opcodemapddbcfdcb[0x47];
    /* BIT 1,(REGISTER+dd) */
    opcodemapddbcfdcb[0x4f] = instrDDCB__BIT_1_iREGpDD;
    // Fallthrough cases
    opcodemapddbcfdcb[0x48] = opcodemapddbcfdcb[0x4f];
    opcodemapddbcfdcb[0x49] = opcodemapddbcfdcb[0x4f];
    opcodemapddbcfdcb[0x4a] = opcodemapddbcfdcb[0x4f];
    opcodemapddbcfdcb[0x4b] = opcodemapddbcfdcb[0x4f];
    opcodemapddbcfdcb[0x4c] = opcodemapddbcfdcb[0x4f];
    opcodemapddbcfdcb[0x4d] = opcodemapddbcfdcb[0x4f];
    opcodemapddbcfdcb[0x4e] = opcodemapddbcfdcb[0x4f];
    /* BIT 2,(REGISTER+dd) */
    opcodemapddbcfdcb[0x57] = instrDDCB__BIT_2_iREGpDD;
    // Fallthrough cases
    opcodemapddbcfdcb[0x50] = opcodemapddbcfdcb[0x57];
    opcodemapddbcfdcb[0x51] = opcodemapddbcfdcb[0x57];
    opcodemapddbcfdcb[0x52] = opcodemapddbcfdcb[0x57];
    opcodemapddbcfdcb[0x53] = opcodemapddbcfdcb[0x57];
    opcodemapddbcfdcb[0x54] = opcodemapddbcfdcb[0x57];
    opcodemapddbcfdcb[0x55] = opcodemapddbcfdcb[0x57];
    opcodemapddbcfdcb[0x56] = opcodemapddbcfdcb[0x57];
    /* BIT 3,(REGISTER+dd) */
    opcodemapddbcfdcb[0x5f] = instrDDCB__BIT_3_iREGpDD;
    // Fallthrough cases
    opcodemapddbcfdcb[0x58] = opcodemapddbcfdcb[0x5f];
    opcodemapddbcfdcb[0x59] = opcodemapddbcfdcb[0x5f];
    opcodemapddbcfdcb[0x5a] = opcodemapddbcfdcb[0x5f];
    opcodemapddbcfdcb[0x5b] = opcodemapddbcfdcb[0x5f];
    opcodemapddbcfdcb[0x5c] = opcodemapddbcfdcb[0x5f];
    opcodemapddbcfdcb[0x5d] = opcodemapddbcfdcb[0x5f];
    opcodemapddbcfdcb[0x5e] = opcodemapddbcfdcb[0x5f];
    /* BIT 4,(REGISTER+dd) */
    opcodemapddbcfdcb[0x67] = instrDDCB__BIT_4_iREGpDD;
    // Fallthrough cases
    opcodemapddbcfdcb[0x60] = opcodemapddbcfdcb[0x67];
    opcodemapddbcfdcb[0x61] = opcodemapddbcfdcb[0x67];
    opcodemapddbcfdcb[0x62] = opcodemapddbcfdcb[0x67];
    opcodemapddbcfdcb[0x63] = opcodemapddbcfdcb[0x67];
    opcodemapddbcfdcb[0x64] = opcodemapddbcfdcb[0x67];
    opcodemapddbcfdcb[0x65] = opcodemapddbcfdcb[0x67];
    opcodemapddbcfdcb[0x66] = opcodemapddbcfdcb[0x67];
    /* BIT 5,(REGISTER+dd) */
    opcodemapddbcfdcb[0x6f] = instrDDCB__BIT_5_iREGpDD;
    // Fallthrough cases
    opcodemapddbcfdcb[0x68] = opcodemapddbcfdcb[0x6f];
    opcodemapddbcfdcb[0x69] = opcodemapddbcfdcb[0x6f];
    opcodemapddbcfdcb[0x6a] = opcodemapddbcfdcb[0x6f];
    opcodemapddbcfdcb[0x6b] = opcodemapddbcfdcb[0x6f];
    opcodemapddbcfdcb[0x6c] = opcodemapddbcfdcb[0x6f];
    opcodemapddbcfdcb[0x6d] = opcodemapddbcfdcb[0x6f];
    opcodemapddbcfdcb[0x6e] = opcodemapddbcfdcb[0x6f];
    /* BIT 6,(REGISTER+dd) */
    opcodemapddbcfdcb[0x77] = instrDDCB__BIT_6_iREGpDD;
    // Fallthrough cases
    opcodemapddbcfdcb[0x70] = opcodemapddbcfdcb[0x77];
    opcodemapddbcfdcb[0x71] = opcodemapddbcfdcb[0x77];
    opcodemapddbcfdcb[0x72] = opcodemapddbcfdcb[0x77];
    opcodemapddbcfdcb[0x73] = opcodemapddbcfdcb[0x77];
    opcodemapddbcfdcb[0x74] = opcodemapddbcfdcb[0x77];
    opcodemapddbcfdcb[0x75] = opcodemapddbcfdcb[0x77];
    opcodemapddbcfdcb[0x76] = opcodemapddbcfdcb[0x77];
    /* BIT 7,(REGISTER+dd) */
    opcodemapddbcfdcb[0x7f] = instrDDCB__BIT_7_iREGpDD;
    // Fallthrough cases
    opcodemapddbcfdcb[0x78] = opcodemapddbcfdcb[0x7f];
    opcodemapddbcfdcb[0x79] = opcodemapddbcfdcb[0x7f];
    opcodemapddbcfdcb[0x7a] = opcodemapddbcfdcb[0x7f];
    opcodemapddbcfdcb[0x7b] = opcodemapddbcfdcb[0x7f];
    opcodemapddbcfdcb[0x7c] = opcodemapddbcfdcb[0x7f];
    opcodemapddbcfdcb[0x7d] = opcodemapddbcfdcb[0x7f];
    opcodemapddbcfdcb[0x7e] = opcodemapddbcfdcb[0x7f];
    /* LD B,RES 0,(REGISTER+dd) */
    opcodemapddbcfdcb[0x80] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD C,RES 0,(REGISTER+dd) */
    opcodemapddbcfdcb[0x81] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD D,RES 0,(REGISTER+dd) */
    opcodemapddbcfdcb[0x82] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD E,RES 0,(REGISTER+dd) */
    opcodemapddbcfdcb[0x83] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD H,RES 0,(REGISTER+dd) */
    opcodemapddbcfdcb[0x84] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD L,RES 0,(REGISTER+dd) */
    opcodemapddbcfdcb[0x85] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* RES 0,(REGISTER+dd) */
    opcodemapddbcfdcb[0x86] = instrDDCB__RES_0_iREGpDD;
    /* LD A,RES 0,(REGISTER+dd) */
    opcodemapddbcfdcb[0x87] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD B,RES 1,(REGISTER+dd) */
    opcodemapddbcfdcb[0x88] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD C,RES 1,(REGISTER+dd) */
    opcodemapddbcfdcb[0x89] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD D,RES 1,(REGISTER+dd) */
    opcodemapddbcfdcb[0x8a] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD E,RES 1,(REGISTER+dd) */
    opcodemapddbcfdcb[0x8b] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD H,RES 1,(REGISTER+dd) */
    opcodemapddbcfdcb[0x8c] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD L,RES 1,(REGISTER+dd) */
    opcodemapddbcfdcb[0x8d] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* RES 1,(REGISTER+dd) */
    opcodemapddbcfdcb[0x8e] = instrDDCB__RES_1_iREGpDD;
    /* LD A,RES 1,(REGISTER+dd) */
    opcodemapddbcfdcb[0x8f] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD B,RES 2,(REGISTER+dd) */
    opcodemapddbcfdcb[0x90] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD C,RES 2,(REGISTER+dd) */
    opcodemapddbcfdcb[0x91] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD D,RES 2,(REGISTER+dd) */
    opcodemapddbcfdcb[0x92] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD E,RES 2,(REGISTER+dd) */
    opcodemapddbcfdcb[0x93] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD H,RES 2,(REGISTER+dd) */
    opcodemapddbcfdcb[0x94] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD L,RES 2,(REGISTER+dd) */
    opcodemapddbcfdcb[0x95] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* RES 2,(REGISTER+dd) */
    opcodemapddbcfdcb[0x96] = instrDDCB__RES_2_iREGpDD;
    /* LD A,RES 2,(REGISTER+dd) */
    opcodemapddbcfdcb[0x97] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD B,RES 3,(REGISTER+dd) */
    opcodemapddbcfdcb[0x98] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD C,RES 3,(REGISTER+dd) */
    opcodemapddbcfdcb[0x99] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD D,RES 3,(REGISTER+dd) */
    opcodemapddbcfdcb[0x9a] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD E,RES 3,(REGISTER+dd) */
    opcodemapddbcfdcb[0x9b] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD H,RES 3,(REGISTER+dd) */
    opcodemapddbcfdcb[0x9c] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD L,RES 3,(REGISTER+dd) */
    opcodemapddbcfdcb[0x9d] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* RES 3,(REGISTER+dd) */
    opcodemapddbcfdcb[0x9e] = instrDDCB__RES_3_iREGpDD;
    /* LD A,RES 3,(REGISTER+dd) */
    opcodemapddbcfdcb[0x9f] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD B,RES 4,(REGISTER+dd) */
    opcodemapddbcfdcb[0xa0] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD C,RES 4,(REGISTER+dd) */
    opcodemapddbcfdcb[0xa1] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD D,RES 4,(REGISTER+dd) */
    opcodemapddbcfdcb[0xa2] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD E,RES 4,(REGISTER+dd) */
    opcodemapddbcfdcb[0xa3] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD H,RES 4,(REGISTER+dd) */
    opcodemapddbcfdcb[0xa4] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD L,RES 4,(REGISTER+dd) */
    opcodemapddbcfdcb[0xa5] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* RES 4,(REGISTER+dd) */
    opcodemapddbcfdcb[0xa6] = instrDDCB__RES_4_iREGpDD;
    /* LD A,RES 4,(REGISTER+dd) */
    opcodemapddbcfdcb[0xa7] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD B,RES 5,(REGISTER+dd) */
    opcodemapddbcfdcb[0xa8] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD C,RES 5,(REGISTER+dd) */
    opcodemapddbcfdcb[0xa9] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD D,RES 5,(REGISTER+dd) */
    opcodemapddbcfdcb[0xaa] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD E,RES 5,(REGISTER+dd) */
    opcodemapddbcfdcb[0xab] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD H,RES 5,(REGISTER+dd) */
    opcodemapddbcfdcb[0xac] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD L,RES 5,(REGISTER+dd) */
    opcodemapddbcfdcb[0xad] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* RES 5,(REGISTER+dd) */
    opcodemapddbcfdcb[0xae] = instrDDCB__RES_5_iREGpDD;
    /* LD A,RES 5,(REGISTER+dd) */
    opcodemapddbcfdcb[0xaf] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD B,RES 6,(REGISTER+dd) */
    opcodemapddbcfdcb[0xb0] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD C,RES 6,(REGISTER+dd) */
    opcodemapddbcfdcb[0xb1] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD D,RES 6,(REGISTER+dd) */
    opcodemapddbcfdcb[0xb2] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD E,RES 6,(REGISTER+dd) */
    opcodemapddbcfdcb[0xb3] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD H,RES 6,(REGISTER+dd) */
    opcodemapddbcfdcb[0xb4] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD L,RES 6,(REGISTER+dd) */
    opcodemapddbcfdcb[0xb5] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* RES 6,(REGISTER+dd) */
    opcodemapddbcfdcb[0xb6] = instrDDCB__RES_6_iREGpDD;
    /* LD A,RES 6,(REGISTER+dd) */
    opcodemapddbcfdcb[0xb7] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD B,RES 7,(REGISTER+dd) */
    opcodemapddbcfdcb[0xb8] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD C,RES 7,(REGISTER+dd) */
    opcodemapddbcfdcb[0xb9] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD D,RES 7,(REGISTER+dd) */
    opcodemapddbcfdcb[0xba] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD E,RES 7,(REGISTER+dd) */
    opcodemapddbcfdcb[0xbb] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD H,RES 7,(REGISTER+dd) */
    opcodemapddbcfdcb[0xbc] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD L,RES 7,(REGISTER+dd) */
    opcodemapddbcfdcb[0xbd] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* RES 7,(REGISTER+dd) */
    opcodemapddbcfdcb[0xbe] = instrDDCB__RES_7_iREGpDD;
    /* LD A,RES 7,(REGISTER+dd) */
    opcodemapddbcfdcb[0xbf] = instrDDCB__LD_r_RES_b_iREGpDD;
    /* LD B,SET 0,(REGISTER+dd) */
    opcodemapddbcfdcb[0xc0] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD C,SET 0,(REGISTER+dd) */
    opcodemapddbcfdcb[0xc1] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD D,SET 0,(REGISTER+dd) */
    opcodemapddbcfdcb[0xc2] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD E,SET 0,(REGISTER+dd) */
    opcodemapddbcfdcb[0xc3] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD H,SET 0,(REGISTER+dd) */
    opcodemapddbcfdcb[0xc4] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD L,SET 0,(REGISTER+dd) */
    opcodemapddbcfdcb[0xc5] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* SET 0,(REGISTER+dd) */
    opcodemapddbcfdcb[0xc6] = instrDDCB__SET_0_iREGpDD;
    /* LD A,SET 0,(REGISTER+dd) */
    opcodemapddbcfdcb[0xc7] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD B,SET 1,(REGISTER+dd) */
    opcodemapddbcfdcb[0xc8] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD C,SET 1,(REGISTER+dd) */
    opcodemapddbcfdcb[0xc9] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD D,SET 1,(REGISTER+dd) */
    opcodemapddbcfdcb[0xca] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD E,SET 1,(REGISTER+dd) */
    opcodemapddbcfdcb[0xcb] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD H,SET 1,(REGISTER+dd) */
    opcodemapddbcfdcb[0xcc] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD L,SET 1,(REGISTER+dd) */
    opcodemapddbcfdcb[0xcd] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* SET 1,(REGISTER+dd) */
    opcodemapddbcfdcb[0xce] = instrDDCB__SET_1_iREGpDD;
    /* LD A,SET 1,(REGISTER+dd) */
    opcodemapddbcfdcb[0xcf] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD B,SET 2,(REGISTER+dd) */
    opcodemapddbcfdcb[0xd0] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD C,SET 2,(REGISTER+dd) */
    opcodemapddbcfdcb[0xd1] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD D,SET 2,(REGISTER+dd) */
    opcodemapddbcfdcb[0xd2] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD E,SET 2,(REGISTER+dd) */
    opcodemapddbcfdcb[0xd3] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD H,SET 2,(REGISTER+dd) */
    opcodemapddbcfdcb[0xd4] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD L,SET 2,(REGISTER+dd) */
    opcodemapddbcfdcb[0xd5] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* SET 2,(REGISTER+dd) */
    opcodemapddbcfdcb[0xd6] = instrDDCB__SET_2_iREGpDD;
    /* LD A,SET 2,(REGISTER+dd) */
    opcodemapddbcfdcb[0xd7] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD B,SET 3,(REGISTER+dd) */
    opcodemapddbcfdcb[0xd8] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD C,SET 3,(REGISTER+dd) */
    opcodemapddbcfdcb[0xd9] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD D,SET 3,(REGISTER+dd) */
    opcodemapddbcfdcb[0xda] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD E,SET 3,(REGISTER+dd) */
    opcodemapddbcfdcb[0xdb] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD H,SET 3,(REGISTER+dd) */
    opcodemapddbcfdcb[0xdc] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD L,SET 3,(REGISTER+dd) */
    opcodemapddbcfdcb[0xdd] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* SET 3,(REGISTER+dd) */
    opcodemapddbcfdcb[0xde] = instrDDCB__SET_3_iREGpDD;
    /* LD A,SET 3,(REGISTER+dd) */
    opcodemapddbcfdcb[0xdf] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD B,SET 4,(REGISTER+dd) */
    opcodemapddbcfdcb[0xe0] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD C,SET 4,(REGISTER+dd) */
    opcodemapddbcfdcb[0xe1] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD D,SET 4,(REGISTER+dd) */
    opcodemapddbcfdcb[0xe2] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD E,SET 4,(REGISTER+dd) */
    opcodemapddbcfdcb[0xe3] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD H,SET 4,(REGISTER+dd) */
    opcodemapddbcfdcb[0xe4] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD L,SET 4,(REGISTER+dd) */
    opcodemapddbcfdcb[0xe5] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* SET 4,(REGISTER+dd) */
    opcodemapddbcfdcb[0xe6] = instrDDCB__SET_4_iREGpDD;
    /* LD A,SET 4,(REGISTER+dd) */
    opcodemapddbcfdcb[0xe7] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD B,SET 5,(REGISTER+dd) */
    opcodemapddbcfdcb[0xe8] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD C,SET 5,(REGISTER+dd) */
    opcodemapddbcfdcb[0xe9] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD D,SET 5,(REGISTER+dd) */
    opcodemapddbcfdcb[0xea] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD E,SET 5,(REGISTER+dd) */
    opcodemapddbcfdcb[0xeb] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD H,SET 5,(REGISTER+dd) */
    opcodemapddbcfdcb[0xec] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD L,SET 5,(REGISTER+dd) */
    opcodemapddbcfdcb[0xed] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* SET 5,(REGISTER+dd) */
    opcodemapddbcfdcb[0xee] = instrDDCB__SET_5_iREGpDD;
    /* LD A,SET 5,(REGISTER+dd) */
    opcodemapddbcfdcb[0xef] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD B,SET 6,(REGISTER+dd) */
    opcodemapddbcfdcb[0xf0] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD C,SET 6,(REGISTER+dd) */
    opcodemapddbcfdcb[0xf1] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD D,SET 6,(REGISTER+dd) */
    opcodemapddbcfdcb[0xf2] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD E,SET 6,(REGISTER+dd) */
    opcodemapddbcfdcb[0xf3] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD H,SET 6,(REGISTER+dd) */
    opcodemapddbcfdcb[0xf4] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD L,SET 6,(REGISTER+dd) */
    opcodemapddbcfdcb[0xf5] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* SET 6,(REGISTER+dd) */
    opcodemapddbcfdcb[0xf6] = instrDDCB__SET_6_iREGpDD;
    /* LD A,SET 6,(REGISTER+dd) */
    opcodemapddbcfdcb[0xf7] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD B,SET 7,(REGISTER+dd) */
    opcodemapddbcfdcb[0xf8] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD C,SET 7,(REGISTER+dd) */
    opcodemapddbcfdcb[0xf9] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD D,SET 7,(REGISTER+dd) */
    opcodemapddbcfdcb[0xfa] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD E,SET 7,(REGISTER+dd) */
    opcodemapddbcfdcb[0xfb] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD H,SET 7,(REGISTER+dd) */
    opcodemapddbcfdcb[0xfc] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* LD L,SET 7,(REGISTER+dd) */
    opcodemapddbcfdcb[0xfd] = instrDDCB__LD_r_SET_b_iREGpDD;
    /* SET 7,(REGISTER+dd) */
    opcodemapddbcfdcb[0xfe] = instrDDCB__SET_7_iREGpDD;
    /* LD A,SET 7,(REGISTER+dd) */
    opcodemapddbcfdcb[0xff] = instrDDCB__LD_r_SET_b_iREGpDD;
}
void opcodeDDCBFDCBStep(Z80* z, const uint8_t& opcode, const uint16_t& address) {}
