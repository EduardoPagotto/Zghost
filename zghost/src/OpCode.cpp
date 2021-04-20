#include <zghost/z80/OpCode.hpp>

void instr__NOP(Z80* z, uint8_t opcode) { z->Tstates += 4; }

void (*opcodemap[256])(Z80*, uint8_t);

void initOpCode() {
    opcodemap[0x0] = instr__NOP;
    // opcodemap[0x01] = instr__LD_BC_NNNN;
    // opcodemap[0x02] = instr__LD_iBC_A;
    // opcodemap[0x03] = instr__INC_BC;
    // opcodemap[0x04] = instr__INC_B;
    // opcodemap[0x05] = instr__DEC_B;
    // opcodemap[0x06] = instr__LD_B_NN;
    // opcodemap[0x07] = instr__RLCA;
    // opcodemap[0x08] = instr__EX_AF_AF;
    // opcodemap[0x09] = instr__ADD_HL_BC;
    // opcodemap[0x0a] = instr__LD_A_iBC;
    // opcodemap[0x0b] = instr__DEC_BC;
    // opcodemap[0x0c] = instr__INC_C;
    // opcodemap[0x0d] = instr__DEC_C;
    // opcodemap[0x0e] = instr__LD_C_NN;
    // opcodemap[0x0f] = instr__RRCA;
    // opcodemap[0x10] = instr__DJNZ_OFFSET;
    // opcodemap[0x11] = instr__LD_DE_NNNN;
    // opcodemap[0x12] = instr__LD_iDE_A;
    // opcodemap[0x13] = instr__INC_DE;
    // opcodemap[0x14] = instr__INC_D;
    // opcodemap[0x15] = instr__DEC_D;
    // opcodemap[0x16] = instr__LD_D_NN;
    // opcodemap[0x17] = instr__RLA;
    // opcodemap[0x18] = instr__JR_OFFSET;
    // opcodemap[0x19] = instr__ADD_HL_DE;
    // opcodemap[0x1a] = instr__LD_A_iDE;
    // opcodemap[0x1b] = instr__DEC_DE;
    // opcodemap[0x1c] = instr__INC_E;
    // opcodemap[0x1d] = instr__DEC_E;
    // opcodemap[0x1e] = instr__LD_E_NN;
    // opcodemap[0x1f] = instr__RRA;
    // opcodemap[0x20] = instr__JR_NZ_OFFSET;
    // opcodemap[0x21] = instr__LD_HL_NNNN;
    // opcodemap[0x22] = instr__LD_iNNNN_HL;
    // opcodemap[0x23] = instr__INC_HL;
    // opcodemap[0x24] = instr__INC_H;
    // opcodemap[0x25] = instr__DEC_H;
    // opcodemap[0x26] = instr__LD_H_NN;
    // opcodemap[0x27] = instr__DAA;
    // opcodemap[0x28] = instr__JR_Z_OFFSET;
    // opcodemap[0x29] = instr__ADD_HL_HL;
    // opcodemap[0x2a] = instr__LD_HL_iNNNN;
    // opcodemap[0x2b] = instr__DEC_HL;
    // opcodemap[0x2c] = instr__INC_L;
    // opcodemap[0x2d] = instr__DEC_L;
    // opcodemap[0x2e] = instr__LD_L_NN;
    // opcodemap[0x2f] = instr__CPL;
    // opcodemap[0x30] = instr__JR_NC_OFFSET;
    // opcodemap[0x31] = instr__LD_SP_NNNN;
    // opcodemap[0x32] = instr__LD_iNNNN_A;
    // opcodemap[0x33] = instr__INC_SP;
    // opcodemap[0x34] = instr__INC_iHL;
    // opcodemap[0x35] = instr__DEC_iHL;
    // opcodemap[0x36] = instr__LD_iHL_NN;
    // opcodemap[0x37] = instr__SCF;
    // opcodemap[0x38] = instr__JR_C_OFFSET;
    // opcodemap[0x39] = instr__ADD_HL_SP;
    // opcodemap[0x3a] = instr__LD_A_iNNNN;
    // opcodemap[0x3b] = instr__DEC_SP;
    // opcodemap[0x3c] = instr__INC_A;
    // opcodemap[0x3d] = instr__DEC_A;
    // opcodemap[0x3e] = instr__LD_A_NN;
    // opcodemap[0x3f] = instr__CCF;
    // opcodemap[0x40] = instr__LD_B_r;
    // opcodemap[0x41] = instr__LD_B_r;
    // opcodemap[0x42] = instr__LD_B_r;
    // opcodemap[0x43] = instr__LD_B_r;
    // opcodemap[0x44] = instr__LD_B_r;
    // opcodemap[0x45] = instr__LD_B_r;
    // opcodemap[0x46] = instr__LD_B_iHL;
    // opcodemap[0x47] = instr__LD_B_r;
    // opcodemap[0x48] = instr__LD_C_r;
    // opcodemap[0x49] = instr__LD_C_r;
    // opcodemap[0x4a] = instr__LD_C_r;
    // opcodemap[0x4b] = instr__LD_C_r;
    // opcodemap[0x4c] = instr__LD_C_r;
    // opcodemap[0x4d] = instr__LD_C_r;
    // opcodemap[0x4e] = instr__LD_C_iHL;
    // opcodemap[0x4f] = instr__LD_C_r;
    // opcodemap[0x50] = instr__LD_D_r;
    // opcodemap[0x51] = instr__LD_D_r;
    // opcodemap[0x52] = instr__LD_D_r;
    // opcodemap[0x53] = instr__LD_D_r;
    // opcodemap[0x54] = instr__LD_D_r;
    // opcodemap[0x55] = instr__LD_D_r;
    // opcodemap[0x56] = instr__LD_D_iHL;
    // opcodemap[0x57] = instr__LD_D_r;
    // opcodemap[0x58] = instr__LD_E_r;
    // opcodemap[0x59] = instr__LD_E_r;
    // opcodemap[0x5a] = instr__LD_E_r;
    // opcodemap[0x5b] = instr__LD_E_r;
    // opcodemap[0x5c] = instr__LD_E_r;
    // opcodemap[0x5d] = instr__LD_E_r;
    // opcodemap[0x5e] = instr__LD_E_iHL;
    // opcodemap[0x5f] = instr__LD_E_r;
    // opcodemap[0x60] = instr__LD_H_r;
    // opcodemap[0x61] = instr__LD_H_r;
    // opcodemap[0x62] = instr__LD_H_r;
    // opcodemap[0x63] = instr__LD_H_r;
    // opcodemap[0x64] = instr__LD_H_r;
    // opcodemap[0x65] = instr__LD_H_r;
    // opcodemap[0x66] = instr__LD_H_iHL;
    // opcodemap[0x67] = instr__LD_H_r;
    // opcodemap[0x68] = instr__LD_L_r;
    // opcodemap[0x69] = instr__LD_L_r;
    // opcodemap[0x6a] = instr__LD_L_r;
    // opcodemap[0x6b] = instr__LD_L_r;
    // opcodemap[0x6c] = instr__LD_L_r;
    // opcodemap[0x6d] = instr__LD_L_r;
    // opcodemap[0x6e] = instr__LD_L_iHL;
    // opcodemap[0x6f] = instr__LD_L_r;
    // opcodemap[0x70] = instr__LD_iHL_r;
    // opcodemap[0x71] = instr__LD_iHL_r;
    // opcodemap[0x72] = instr__LD_iHL_r;
    // opcodemap[0x73] = instr__LD_iHL_r;
    // opcodemap[0x74] = instr__LD_iHL_r;
    // opcodemap[0x75] = instr__LD_iHL_r;
    // opcodemap[0x76] = instr__HALT;
    // opcodemap[0x77] = instr__LD_iHL_r;
    // opcodemap[0x78] = instr__LD_A_r;
    // opcodemap[0x79] = instr__LD_A_r;
    // opcodemap[0x7a] = instr__LD_A_r;
    // opcodemap[0x7b] = instr__LD_A_r;
    // opcodemap[0x7c] = instr__LD_A_r;
    // opcodemap[0x7d] = instr__LD_A_r;
    // opcodemap[0x7e] = instr__LD_A_iHL;
    // opcodemap[0x7f] = instr__LD_A_r;
    // opcodemap[0x80] = instr__ADD_A_r;
    // opcodemap[0x81] = instr__ADD_A_r;
    // opcodemap[0x82] = instr__ADD_A_r;
    // opcodemap[0x83] = instr__ADD_A_r;
    // opcodemap[0x84] = instr__ADD_A_r;
    // opcodemap[0x85] = instr__ADD_A_r;
    // opcodemap[0x86] = instr__ADD_A_iHL;
    // opcodemap[0x87] = instr__ADD_A_r;
    // opcodemap[0x88] = instr__ADC_A_r;
    // opcodemap[0x89] = instr__ADC_A_r;
    // opcodemap[0x8a] = instr__ADC_A_r;
    // opcodemap[0x8b] = instr__ADC_A_r;
    // opcodemap[0x8c] = instr__ADC_A_r;
    // opcodemap[0x8d] = instr__ADC_A_r;
    // opcodemap[0x8e] = instr__ADC_A_iHL;
    // opcodemap[0x8f] = instr__ADC_A_r;
    // opcodemap[0x90] = instr__SUB_A_r;
    // opcodemap[0x91] = instr__SUB_A_r;
    // opcodemap[0x92] = instr__SUB_A_r;
    // opcodemap[0x93] = instr__SUB_A_r;
    // opcodemap[0x94] = instr__SUB_A_r;
    // opcodemap[0x95] = instr__SUB_A_r;
    // opcodemap[0x96] = instr__SUB_A_iHL;
    // opcodemap[0x97] = instr__SUB_A_r;
    // opcodemap[0x98] = instr__SBC_A_r;
    // opcodemap[0x99] = instr__SBC_A_r;
    // opcodemap[0x9a] = instr__SBC_A_r;
    // opcodemap[0x9b] = instr__SBC_A_r;
    // opcodemap[0x9c] = instr__SBC_A_r;
    // opcodemap[0x9d] = instr__SBC_A_r;
    // opcodemap[0x9e] = instr__SBC_A_iHL;
    // opcodemap[0x9f] = instr__SBC_A_r;
    // opcodemap[0xa0] = instr__AND_A_r;
    // opcodemap[0xa1] = instr__AND_A_r;
    // opcodemap[0xa2] = instr__AND_A_r;
    // opcodemap[0xa3] = instr__AND_A_r;
    // opcodemap[0xa4] = instr__AND_A_r;
    // opcodemap[0xa5] = instr__AND_A_r;
    // opcodemap[0xa6] = instr__AND_A_iHL;
    // opcodemap[0xa7] = instr__AND_A_r;
    // opcodemap[0xa8] = instr__XOR_A_r;
    // opcodemap[0xa9] = instr__XOR_A_r;
    // opcodemap[0xaa] = instr__XOR_A_r;
    // opcodemap[0xab] = instr__XOR_A_r;
    // opcodemap[0xac] = instr__XOR_A_r;
    // opcodemap[0xad] = instr__XOR_A_r;
    // opcodemap[0xae] = instr__XOR_A_iHL;
    // opcodemap[0xaf] = instr__XOR_A_r;
    // opcodemap[0xb0] = instr__OR_A_r;
    // opcodemap[0xb1] = instr__OR_A_r;
    // opcodemap[0xb2] = instr__OR_A_r;
    // opcodemap[0xb3] = instr__OR_A_r;
    // opcodemap[0xb4] = instr__OR_A_r;
    // opcodemap[0xb5] = instr__OR_A_r;
    // opcodemap[0xb6] = instr__OR_A_iHL;
    // opcodemap[0xb7] = instr__OR_A_r;
    // opcodemap[0xb8] = instr__CP_r;
    // opcodemap[0xb9] = instr__CP_r;
    // opcodemap[0xba] = instr__CP_r;
    // opcodemap[0xbb] = instr__CP_r;
    // opcodemap[0xbc] = instr__CP_r;
    // opcodemap[0xbd] = instr__CP_r;
    // opcodemap[0xbe] = instr__CP_iHL;
    // opcodemap[0xbf] = instr__CP_r;
    // opcodemap[0xc0] = instr__RET_NZ;
    // opcodemap[0xc1] = instr__POP_BC;
    // opcodemap[0xc2] = instr__JP_NZ_NNNN;
    // opcodemap[0xc3] = instr__JP_NNNN;
    // opcodemap[0xc4] = instr__CALL_NZ_NNNN;
    // opcodemap[0xc5] = instr__PUSH_BC;
    // opcodemap[0xc6] = instr__ADD_A_NN;
    // opcodemap[0xc7] = instr__RST_00;
    // opcodemap[0xc8] = instr__RET_Z;
    // opcodemap[0xc9] = instr__RET;
    // opcodemap[0xca] = instr__JP_Z_NNNN;
    // opcodemap[0xcb] = instr__SHIFT_CB;
    // opcodemap[0xcc] = instr__CALL_Z_NNNN;
    // opcodemap[0xcd] = instr__CALL_NNNN;
    // opcodemap[0xce] = instr__ADC_A_NN;
    // opcodemap[0xcf] = instr__RST_8;
    // opcodemap[0xd0] = instr__RET_NC;
    // opcodemap[0xd1] = instr__POP_DE;
    // opcodemap[0xd2] = instr__JP_NC_NNNN;
    // opcodemap[0xd3] = instr__OUT_iNN_A;
    // opcodemap[0xd4] = instr__CALL_NC_NNNN;
    // opcodemap[0xd5] = instr__PUSH_DE;
    // opcodemap[0xd6] = instr__SUB_NN;
    // opcodemap[0xd7] = instr__RST_10;
    // opcodemap[0xd8] = instr__RET_C;
    // opcodemap[0xd9] = instr__EXX;
    // opcodemap[0xda] = instr__JP_C_NNNN;
    // opcodemap[0xdb] = instr__IN_A_iNN;
    // opcodemap[0xdc] = instr__CALL_C_NNNN;
    // opcodemap[0xdd] = instr__SHIFT_DD;
    // opcodemap[0xde] = instr__SBC_A_NN;
    // opcodemap[0xdf] = instr__RST_18;
    // opcodemap[0xe0] = instr__RET_PO;
    // opcodemap[0xe1] = instr__POP_HL;
    // opcodemap[0xe2] = instr__JP_PO_NNNN;
    // opcodemap[0xe3] = instr__EX_iSP_HL;
    // opcodemap[0xe4] = instr__CALL_PO_NNNN;
    // opcodemap[0xe5] = instr__PUSH_HL;
    // opcodemap[0xe6] = instr__AND_NN;
    // opcodemap[0xe7] = instr__RST_20;
    // opcodemap[0xe8] = instr__RET_PE;
    // opcodemap[0xe9] = instr__JP_HL;
    // opcodemap[0xea] = instr__JP_PE_NNNN;
    // opcodemap[0xeb] = instr__EX_DE_HL;
    // opcodemap[0xec] = instr__CALL_PE_NNNN;
    // opcodemap[0xed] = instr__SHIFT_ED;
    // opcodemap[0xee] = instr__XOR_A_NN;
    // opcodemap[0xef] = instr__RST_28;
    // opcodemap[0xf0] = instr__RET_P;
    // opcodemap[0xf1] = instr__POP_AF;
    // opcodemap[0xf2] = instr__JP_P_NNNN;
    // opcodemap[0xf3] = instr__DI;
    // opcodemap[0xf4] = instr__CALL_P_NNNN;
    // opcodemap[0xf5] = instr__PUSH_AF;
    // opcodemap[0xf6] = instr__OR_NN;
    // opcodemap[0xf7] = instr__RST_30;
    // opcodemap[0xf8] = instr__RET_M;
    // opcodemap[0xf9] = instr__LD_SP_HL;
    // opcodemap[0xfa] = instr__JP_M_NNNN;
    // opcodemap[0xfb] = instr__EI;
    // opcodemap[0xfc] = instr__CALL_M_NNNN;
    // opcodemap[0xfd] = instr__SHIFT_FD;
    // opcodemap[0xfe] = instr__CP_NN;
    // opcodemap[0xff] = instr__RST_38;
}

// func instr__LD_BC_NNNN(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	z.LoadR(&z.BC)
// }

// func instr__LD_iBC_A(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.bus.WriteMemory(z.BC.Get(), z.A)
// }

// func instr__INC_BC(z *Z80, opcode byte) {
// 	z.Tstates += 6
// 	z.BC.Inc()
// }

// func instr__INC_B(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	var pReg *byte = z.GetPrtRegisterValByte(0)
// 	z.Inc(pReg)
// }

// func instr__DEC_B(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	var pReg *byte = z.GetPrtRegisterValByte(0)
// 	z.Dec(pReg)
// }

// func instr__LD_B_NN(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.B = z.Load8()
// }

// func instr__RLCA(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	z.A = (z.A << 1) | (z.A >> 7)
// 	z.F = (z.F & (FLAG_P | FLAG_Z | FLAG_S)) | (z.A & (FLAG_C | FLAG_3 | FLAG_5))
// }

// /* EX AF,AF' */
// func instr__EX_AF_AF(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	var olda, oldf = z.A, z.F
// 	z.A = z.A_
// 	z.F = z.F_
// 	z.A_ = olda
// 	z.F_ = oldf
// }

// /* ADD HL,BC */
// func instr__ADD_HL_BC(z *Z80, opcode byte) {
// 	z.Tstates += 11
// 	//z.Memory.ContendReadNoMreq_loop(z.IR(), 1, 7)
// 	z.Add16(z.HL, z.BC.Get())
// }

// /* LD A,(BC) */
// func instr__LD_A_iBC(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.A = z.bus.ReadMemory(z.BC.Get())
// }

// /* DEC BC */
// func instr__DEC_BC(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq_loop(z.IR(), 1, 2)
// 	z.Tstates += 6
// 	z.BC.Dec()
// }

// /* INC C */
// func instr__INC_C(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	var pReg *byte = z.GetPrtRegisterValByte(1)
// 	z.Inc(pReg)
// }

// /* DEC C */
// func instr__DEC_C(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	var pReg *byte = z.GetPrtRegisterValByte(1)
// 	z.Dec(pReg)
// }

// // /* LD C,nn */
// func instr__LD_C_NN(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.C = z.Load8()
// }

// /* RRCA */
// func instr__RRCA(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	z.F = (z.F & (FLAG_P | FLAG_Z | FLAG_S)) | (z.A & FLAG_C)
// 	z.A = (z.A >> 1) | (z.A << 7)
// 	z.F |= (z.A & (FLAG_3 | FLAG_5))
// }

// /* DJNZ offset */
// func instr__DJNZ_OFFSET(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	z.B--
// 	if z.B != 0 {
// 		z.Tstates += 1
// 		z.Jr()
// 	} else {
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		z.Tstates += 8
// 		z.pc++
// 	}
// 	//z.IncPC(1) // TESTAR!!!!!!
// }

// /* LD DE,nnnn */
// func instr__LD_DE_NNNN(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	z.LoadR(&z.DE)
// }

// /* LD (DE),A */
// func instr__LD_iDE_A(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.bus.WriteMemory(z.DE.Get(), z.A)
// }

// /* INC DE */
// func instr__INC_DE(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq_loop(z.IR(), 1, 2)
// 	z.Tstates += 6
// 	z.DE.Inc()
// }

// /* INC D */
// func instr__INC_D(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	var pReg *byte = z.GetPrtRegisterValByte(2)
// 	z.Inc(pReg)
// }

// /* DEC D */
// func instr__DEC_D(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	var pReg *byte = z.GetPrtRegisterValByte(2)
// 	z.Dec(pReg)
// }

// // /* LD D,nn */
// func instr__LD_D_NN(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.D = z.Load8()
// }

// /* RLA */
// func instr__RLA(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	var bytetemp byte = z.A
// 	z.A = (z.A << 1) | (z.F & FLAG_C)
// 	z.F = (z.F & (FLAG_P | FLAG_Z | FLAG_S)) | (z.A & (FLAG_3 | FLAG_5)) | (bytetemp >> 7)
// }

// /* JR offset */
// func instr__JR_OFFSET(z *Z80, opcode byte) {
// 	z.Jr()
// }

// /* ADD HL,DE */
// func instr__ADD_HL_DE(z *Z80, opcode byte) {
// 	z.Tstates += 11
// 	//z.Memory.ContendReadNoMreq_loop(z.IR(), 1, 7)
// 	z.Add16(z.HL, z.DE.Get())
// }

// /* LD A,(DE) */
// func instr__LD_A_iDE(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.A = z.bus.ReadMemory(z.DE.Get())
// }

// /* DEC DE */
// func instr__DEC_DE(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq_loop(z.IR(), 1, 2)
// 	z.Tstates += 6
// 	z.DE.Dec()
// }

// /* INC E */
// func instr__INC_E(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	var pReg *byte = z.GetPrtRegisterValByte(3)
// 	z.Inc(pReg)
// }

// /* DEC E */
// func instr__DEC_E(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	var pReg *byte = z.GetPrtRegisterValByte(3)
// 	z.Dec(pReg)
// }

// // /* LD E,nn */
// func instr__LD_E_NN(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.E = z.Load8()
// }

// /* RRA */
// func instr__RRA(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	var bytetemp byte = z.A
// 	z.A = (z.A >> 1) | (z.F << 7)
// 	z.F = (z.F & (FLAG_P | FLAG_Z | FLAG_S)) | (z.A & (FLAG_3 | FLAG_5)) | (bytetemp & FLAG_C)
// }

// /* JR NZ,offset */
// func instr__JR_NZ_OFFSET(z *Z80, opcode byte) {
// 	if (z.F & FLAG_Z) == 0 {
// 		z.Jr()
// 	} else {
// 		z.Tstates += 7
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		z.pc++
// 	}
// }

// /* LD HL,nnnn */
// func instr__LD_HL_NNNN(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	z.LoadR(&z.HL)
// }

// /* LD (nnnn),HL */
// func instr__LD_iNNNN_HL(z *Z80, opcode byte) {
// 	z.Tstates += 16
// 	z.StoreIndexR(z.HL)
// }

// /* INC HL */
// func instr__INC_HL(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq_loop(z.IR(), 1, 2)
// 	z.Tstates += 6
// 	z.HL.Inc()
// }

// /* INC H */
// func instr__INC_H(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	var pReg *byte = z.GetPrtRegisterValByte(4)
// 	z.Inc(pReg)
// }

// /* DEC H */
// func instr__DEC_H(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	var pReg *byte = z.GetPrtRegisterValByte(4)
// 	z.Dec(pReg)
// }

// // /* LD H,nn */
// func instr__LD_H_NN(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.H = z.Load8()
// }

// /* DAA */
// func instr__DAA(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	var add, carry byte = 0, (z.F & FLAG_C)
// 	if ((z.F & FLAG_H) != 0) || ((z.A & 0x0f) > 9) {
// 		add = 6
// 	}
// 	if (carry != 0) || (z.A > 0x99) {
// 		add |= 0x60
// 	}
// 	if z.A > 0x99 {
// 		carry = FLAG_C
// 	}
// 	if (z.F & FLAG_N) != 0 {
// 		z.Sub(add)
// 	} else {
// 		z.Add(add)
// 	}
// 	var temp byte = byte(int(z.F) & ^(FLAG_C|FLAG_P)) | carry | parityTable[z.A]
// 	z.F = temp
// }

// /* JR Z,offset */
// func instr__JR_Z_OFFSET(z *Z80, opcode byte) {
// 	if (z.F & FLAG_Z) != 0 {
// 		z.Jr()
// 	} else {
// 		z.Tstates += 7
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		z.pc++
// 	}
// }

// /* ADD HL,HL */
// func instr__ADD_HL_HL(z *Z80, opcode byte) {
// 	z.Tstates += 11
// 	//z.Memory.ContendReadNoMreq_loop(z.IR(), 1, 7)
// 	z.Add16(z.HL, z.HL.Get())
// }

// /* LD HL,(nnnn) */
// func instr__LD_HL_iNNNN(z *Z80, opcode byte) {
// 	z.Tstates += 16
// 	z.LoadIndexR(&z.HL)
// }

// /* DEC HL */
// func instr__DEC_HL(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq_loop(z.IR(), 1, 2)
// 	z.Tstates += 6
// 	z.HL.Dec()
// }

// /* INC L */
// func instr__INC_L(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	var pReg *byte = z.GetPrtRegisterValByte(5)
// 	z.Inc(pReg)
// }

// /* DEC L */
// func instr__DEC_L(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	var pReg *byte = z.GetPrtRegisterValByte(5)
// 	z.Dec(pReg)
// }

// // /* LD L,nn */
// func instr__LD_L_NN(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.L = z.Load8()
// }

// /* CPL */
// func instr__CPL(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	z.A ^= 0xff
// 	z.F = (z.F & (FLAG_C | FLAG_P | FLAG_Z | FLAG_S)) |
// 		(z.A & (FLAG_3 | FLAG_5)) |
// 		(FLAG_N | FLAG_H)
// }

// /* JR NC,offset */
// func instr__JR_NC_OFFSET(z *Z80, opcode byte) {
// 	if (z.F & FLAG_C) == 0 {
// 		z.Jr()
// 	} else {
// 		z.Tstates += 7
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		z.pc++
// 	}
// }

// // /* LD SP,nnnn */
// func instr__LD_SP_NNNN(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	z.sp = z.Load16()
// }

// // /* LD (nnnn),A */
// func instr__LD_iNNNN_A(z *Z80, opcode byte) {
// 	z.Tstates += 13
// 	z.StoreIndex8(z.A)
// }

// /* INC SP */
// func instr__INC_SP(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq_loop(z.IR(), 1, 2)
// 	z.Tstates += 6
// 	z.sp++
// }

// /* INC (HL) */
// func instr__INC_iHL(z *Z80, opcode byte) {
// 	z.Tstates += 11
// 	var bytetemp byte = z.bus.ReadMemory(z.HL.Get())
// 	//z.Memory.ContendReadNoMreq(z.HL(), 1)
// 	z.Inc(&bytetemp)
// 	z.bus.WriteMemory(z.HL.Get(), bytetemp)

// }

// /* DEC (HL) */
// func instr__DEC_iHL(z *Z80, opcode byte) {
// 	z.Tstates += 11
// 	var bytetemp byte = z.bus.ReadMemory(z.HL.Get())
// 	//z.Memory.ContendReadNoMreq(z.HL(), 1)
// 	z.Dec(&bytetemp)
// 	z.bus.WriteMemory(z.HL.Get(), bytetemp)
// }

// /* LD (HL),nn */
// func instr__LD_iHL_NN(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	z.bus.WriteMemory(z.HL.Get(), z.Load8())
// }

// /* SCF */
// func instr__SCF(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	z.F = (z.F & (FLAG_P | FLAG_Z | FLAG_S)) |
// 		(z.A & (FLAG_3 | FLAG_5)) |
// 		FLAG_C
// }

// /* JR C,offset */
// func instr__JR_C_OFFSET(z *Z80, opcode byte) {
// 	if (z.F & FLAG_C) != 0 {
// 		z.Jr()
// 	} else {
// 		z.Tstates += 7
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		z.pc++
// 	}
// }

// /* ADD HL,SP */
// func instr__ADD_HL_SP(z *Z80, opcode byte) {
// 	z.Tstates += 11
// 	//z.Memory.ContendReadNoMreq_loop(z.IR(), 1, 7)
// 	z.Add16(z.HL, z.sp)
// }

// /* LD A,(nnnn) */
// func instr__LD_A_iNNNN(z *Z80, opcode byte) {
// 	z.Tstates += 13
// 	z.LoadIndex8(&z.A)
// }

// /* DEC SP */
// func instr__DEC_SP(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq_loop(z.IR(), 1, 2)
// 	z.Tstates += 6
// 	z.sp--
// }

// /* INC A */
// func instr__INC_A(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	var pReg *byte = z.GetPrtRegisterValByte(7)
// 	z.Inc(pReg)
// }

// /* DEC A */
// func instr__DEC_A(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	var pReg *byte = z.GetPrtRegisterValByte(7)
// 	z.Dec(pReg)
// }

// // /* LD A,nn */
// func instr__LD_A_NN(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.A = z.Load8()
// }

// /* CCF */
// func instr__CCF(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	z.F = (z.F & (FLAG_P | FLAG_Z | FLAG_S)) |
// 		ternOpB((z.F&FLAG_C) != 0, FLAG_H, FLAG_C) |
// 		(z.A & (FLAG_3 | FLAG_5))
// }

// /* LD B,r */
// func instr__LD_B_r(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.B = z.GetRegisterValByte(opcode)
// }

// /* LD B,(HL) */
// func instr__LD_B_iHL(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.B = z.bus.ReadMemory(z.HL.Get())
// }

// /* LD C,r */
// func instr__LD_C_r(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.C = z.GetRegisterValByte(opcode)
// }

// /* LD C,(HL) */
// func instr__LD_C_iHL(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.C = z.bus.ReadMemory(z.HL.Get())
// }

// /* LD D,r */
// func instr__LD_D_r(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.D = z.GetRegisterValByte(opcode)
// }

// /* LD D,(HL) */
// func instr__LD_D_iHL(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.D = z.bus.ReadMemory(z.HL.Get())
// }

// /* LD E,r */
// func instr__LD_E_r(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.E = z.GetRegisterValByte(opcode)
// }

// /* LD E,(HL) */
// func instr__LD_E_iHL(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.E = z.bus.ReadMemory(z.HL.Get())
// }

// /* LD H,r */
// func instr__LD_H_r(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.H = z.GetRegisterValByte(opcode)
// }

// /* LD H,(HL) */
// func instr__LD_H_iHL(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.H = z.bus.ReadMemory(z.HL.Get())
// }

// /* LD L,r */
// func instr__LD_L_r(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.L = z.GetRegisterValByte(opcode)
// }

// /* LD L,(HL) */
// func instr__LD_L_iHL(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.L = z.bus.ReadMemory(z.HL.Get())
// }

// // /* LD (HL),r */
// func instr__LD_iHL_r(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.bus.WriteMemory(z.HL.Get(), z.GetRegisterValByte(opcode))
// }

// // /* HALT */
// func instr__HALT(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	z.Halted = true
// 	//z.pc++
// }

// // /* LD A,r */
// func instr__LD_A_r(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	z.A = z.GetRegisterValByte(opcode)
// }

// // /* LD A,(HL) */
// func instr__LD_A_iHL(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.A = z.bus.ReadMemory(z.HL.Get())
// }

// /* ADD A,r */
// func instr__ADD_A_r(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	z.Add(z.GetRegisterValByte(opcode))
// }

// /* ADD A,(HL) */
// func instr__ADD_A_iHL(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.Add(z.bus.ReadMemory(z.HL.Get()))
// }

// // /* ADC A,r */
// func instr__ADC_A_r(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	z.Adc(z.GetRegisterValByte(opcode))
// }

// /* ADC A,(HL) */
// func instr__ADC_A_iHL(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	z.Adc(z.bus.ReadMemory(z.HL.Get()))
// }

// /* SUB A,r */
// func instr__SUB_A_r(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	z.Sub(z.GetRegisterValByte(opcode))
// }

// /* SUB A,(HL) */
// func instr__SUB_A_iHL(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.Sub(z.bus.ReadMemory(z.HL.Get()))
// }

// /* SBC A,r */
// func instr__SBC_A_r(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	z.Sbc(z.GetRegisterValByte(opcode))
// }

// /* SBC A,(HL) */
// func instr__SBC_A_iHL(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.Sbc(z.bus.ReadMemory(z.HL.Get()))
// }

// /* AND A,r */
// func instr__AND_A_r(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	z.And(z.GetRegisterValByte(opcode))
// }

// /* AND A,(HL) */
// func instr__AND_A_iHL(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.And(z.bus.ReadMemory(z.HL.Get()))
// }

// // /* XOR A,r */
// func instr__XOR_A_r(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	z.Xor(z.GetRegisterValByte(opcode))
// }

// /* XOR A,(HL) */
// func instr__XOR_A_iHL(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.Xor(z.bus.ReadMemory(z.HL.Get()))
// }

// /* OR A,r */
// func instr__OR_A_r(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	z.Or(z.GetRegisterValByte(opcode))
// }

// /* OR A,(HL) */
// func instr__OR_A_iHL(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.Or(z.bus.ReadMemory(z.HL.Get()))
// }

// /* CP r */
// func instr__CP_r(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	z.Cp(z.GetRegisterValByte(opcode))
// }

// /* CP (HL) */
// func instr__CP_iHL(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.Cp(z.bus.ReadMemory(z.HL.Get()))
// }

// /* RET NZ */
// func instr__RET_NZ(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	if !((z.F & FLAG_Z) != 0) {
// 		z.Tstates += 11
// 		z.pc = z.Pop()
// 	} else {
// 		z.Tstates += 5
// 	}
// }

// // /* POP BC */
// func instr__POP_BC(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	z.PopR(&z.BC)
// }

// /* JP NZ,nnnn */
// func instr__JP_NZ_NNNN(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	if (z.F & FLAG_Z) == 0 {
// 		z.pc = z.Load16()
// 	} else {
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		//z.Memory.ContendRead(z.PC()+1, 3)
// 		z.pc += 2
// 	}
// }

// // /* JP nnnn */
// func instr__JP_NNNN(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	z.pc = z.Load16()
// }

// /* CALL NZ,nnnn */
// func instr__CALL_NZ_NNNN(z *Z80, opcode byte) {
// 	if (z.F & FLAG_Z) == 0 {
// 		z.Call()
// 	} else {
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		//z.Memory.ContendRead(z.PC()+1, 3)
// 		z.Tstates += 10
// 		z.pc += 2
// 	}
// }

// // /* PUSH BC */
// func instr__PUSH_BC(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	z.Tstates += 11
// 	z.PushR(z.BC)
// }

// /* ADD A,nn */
// func instr__ADD_A_NN(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.Add(z.Load8())
// }

// /* RST 00 */
// func instr__RST_00(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	z.Tstates += 11
// 	z.Rst(0x00)
// }

// /* RET Z */
// func instr__RET_Z(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	if (z.F & FLAG_Z) != 0 {
// 		z.Tstates += 11
// 		z.pc = z.Pop()
// 	} else {
// 		z.Tstates += 5
// 	}
// }

// // /* RET */
// func instr__RET(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	z.pc = z.Pop()
// }

// /* JP Z,nnnn */
// func instr__JP_Z_NNNN(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	if (z.F & FLAG_Z) != 0 {
// 		z.pc = z.Load16()
// 	} else {
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		//z.Memory.ContendRead(z.PC()+1, 3)
// 		z.pc += 2 //z.IncPC(2)
// 	}
// }

// /* shift CB */
// func instr__SHIFT_CB(z *Z80, opcode byte) {
// 	//z.Tstates += 4
// 	opcode2 := z.Load8()
// 	z.R++
// 	OpcodeCBMap[opcode2](z, opcode2)
// }

// /* CALL Z,nnnn */
// func instr__CALL_Z_NNNN(z *Z80, opcode byte) {
// 	if (z.F & FLAG_Z) != 0 {
// 		z.Call()
// 	} else {
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		//z.Memory.ContendRead(z.PC()+1, 3)
// 		z.Tstates += 10
// 		z.pc += 2
// 	}
// }

// // /* CALL nnnn */
// func instr__CALL_NNNN(z *Z80, opcode byte) {
// 	z.Call() // z.Tstate incluido
// }

// /* ADC A,nn */
// func instr__ADC_A_NN(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	var bytetemp byte = z.Load8()
// 	z.Adc(bytetemp)
// }

// // /* RST 8 */
// func instr__RST_8(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	z.Tstates += 11
// 	z.Rst(0x08)
// }

// /* RET NC */
// func instr__RET_NC(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	if !((z.F & FLAG_C) != 0) {
// 		z.Tstates += 11
// 		z.pc = z.Pop()
// 	} else {
// 		z.Tstates += 5
// 	}
// }

// // /* POP DE */
// func instr__POP_DE(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	z.PopR(&z.DE)
// }

// /* JP NC,nnnn */
// func instr__JP_NC_NNNN(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	if (z.F & FLAG_C) == 0 {
// 		z.pc = z.Load16()
// 	} else {
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		//z.Memory.ContendRead(z.PC()+1, 3)
// 		z.pc += 2
// 	}
// }

// /* OUT (nn),A */
// func instr__OUT_iNN_A(z *Z80, opcode byte) {
// 	z.Tstates += 11
// 	var addrOut uint16 = uint16(z.Load8()) + (uint16(z.A) << 8)
// 	z.writePort(addrOut, z.A)
// }

// /* CALL NC,nnnn */
// func instr__CALL_NC_NNNN(z *Z80, opcode byte) {
// 	if (z.F & FLAG_C) == 0 {
// 		z.Call()
// 	} else {
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		//z.Memory.ContendRead(z.PC()+1, 3)
// 		z.Tstates += 10
// 		z.pc += 2
// 	}
// }

// // /* PUSH DE */
// func instr__PUSH_DE(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	z.Tstates += 11
// 	z.PushR(z.DE)
// }

// /* SUB nn */
// func instr__SUB_NN(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	var bytetemp byte = z.Load8()
// 	z.Sub(bytetemp)
// }

// /* RST 10 */
// func instr__RST_10(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	z.Tstates += 11
// 	z.Rst(0x10)
// }

// /* RET C */
// func instr__RET_C(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	if (z.F & FLAG_C) != 0 {
// 		z.Tstates += 11
// 		z.pc = z.Pop()
// 	} else {
// 		z.Tstates += 5
// 	}
// }

// /* EXX */
// func instr__EXX(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	var wordtemp uint16 = z.BC.Get()
// 	z.BC.Set(z.BC_.Get())
// 	z.BC_.Set(wordtemp)

// 	wordtemp = z.DE.Get()
// 	z.DE.Set(z.DE_.Get())
// 	z.DE_.Set(wordtemp)

// 	wordtemp = z.HL.Get()
// 	z.HL.Set(z.HL_.Get())
// 	z.HL_.Set(wordtemp)
// }

// /* JP C,nnnn */
// func instr__JP_C_NNNN(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	if (z.F & FLAG_C) != 0 {
// 		z.pc = z.Load16()
// 	} else {
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		//z.Memory.ContendRead(z.PC()+1, 3)
// 		z.pc += 2
// 	}
// }

// /* IN A,(nn) */
// func instr__IN_A_iNN(z *Z80, opcode byte) {
// 	z.Tstates += 11
// 	var intemp uint16 = uint16(z.Load8()) + (uint16(z.A) << 8) // FIXME: preciso deslocar ????
// 	z.A = z.readPort(intemp)
// }

// /* CALL C,nnnn */
// func instr__CALL_C_NNNN(z *Z80, opcode byte) {
// 	if (z.F & FLAG_C) != 0 {
// 		z.Call()
// 	} else {
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		//z.Memory.ContendRead(z.PC()+1, 3)
// 		z.Tstates += 10
// 		z.pc += 2
// 	}
// }

// /* shift DD */
// func instr__SHIFT_DD(z *Z80, opcode byte) {
// 	//z.Tstates += 4
// 	opcode2 := z.Load8()
// 	z.R++
// 	if f := OpcodeDDMap[opcode2]; f != nil {
// 		f(z, opcode2)
// 	} else {
// 		/* Instruction did not involve H or L */
// 		OpcodeMap[opcode2](z, opcode2) // FIXME: verificar!!!!!
// 	}
// }

// /* SBC A,nn */
// func instr__SBC_A_NN(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	var bytetemp byte = z.Load8()
// 	z.Sbc(bytetemp)
// }

// /* RST 18 */
// func instr__RST_18(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	z.Tstates += 11
// 	z.Rst(0x18)
// }

// /* RET PO */
// func instr__RET_PO(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	if !((z.F & FLAG_P) != 0) {
// 		z.Tstates += 11
// 		z.pc = z.Pop()
// 	} else {
// 		z.Tstates += 5
// 	}
// }

// // /* POP HL */
// func instr__POP_HL(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	z.PopR(&z.HL)
// }

// /* JP PO,nnnn */
// func instr__JP_PO_NNNN(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	if (z.F & FLAG_P) == 0 {
// 		z.pc = z.Load16()
// 	} else {
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		//z.Memory.ContendRead(z.PC()+1, 3)
// 		z.pc += 2
// 	}
// }

// /* EX (SP),HL */
// func instr__EX_iSP_HL(z *Z80, opcode byte) {
// 	z.Tstates += 19
// 	var bytetempl = z.bus.ReadMemory(z.sp)
// 	var bytetemph = z.bus.ReadMemory(z.sp + 1)
// 	//z.Memory.ContendReadNoMreq(z.SP()+1, 1)
// 	z.bus.WriteMemory(z.sp+1, z.H)
// 	z.bus.WriteMemory(z.sp, z.L)
// 	//z.Memory.ContendWriteNoMreq_loop(z.SP(), 1, 2)
// 	z.L = bytetempl
// 	z.H = bytetemph
// }

// /* CALL PO,nnnn */
// func instr__CALL_PO_NNNN(z *Z80, opcode byte) {
// 	if (z.F & FLAG_P) == 0 {
// 		z.Call()
// 	} else {
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		//z.Memory.ContendRead(z.PC()+1, 3)
// 		z.Tstates += 10
// 		z.pc += 2
// 	}
// }

// // /* PUSH HL */
// func instr__PUSH_HL(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	z.Tstates += 11
// 	z.PushR(z.HL)
// }

// /* AND nn */
// func instr__AND_NN(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.And(z.Load8())
// }

// /* RST 20 */
// func instr__RST_20(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	z.Tstates += 11
// 	z.Rst(0x20)
// }

// /* RET PE */
// func instr__RET_PE(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	if (z.F & FLAG_P) != 0 {
// 		z.Tstates += 11
// 		z.pc = z.Pop()
// 	} else {
// 		z.Tstates += 5
// 	}
// }

// /* JP HL */
// func instr__JP_HL(z *Z80, opcode byte) {
// 	z.Tstates += 4 // NÃoO É INDIRETO!!!
// 	z.pc = z.HL.Get()
// }

// /* JP PE,nnnn */
// func instr__JP_PE_NNNN(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	if (z.F & FLAG_P) != 0 {
// 		z.pc = z.Load16()
// 	} else {
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		//z.Memory.ContendRead(z.PC()+1, 3)
// 		z.pc += 2
// 	}
// }

// /* EX DE,HL */
// func instr__EX_DE_HL(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	d := z.D
// 	e := z.E
// 	z.D = z.H
// 	z.E = z.L
// 	z.H = d
// 	z.L = e
// }

// /* CALL PE,nnnn */
// func instr__CALL_PE_NNNN(z *Z80, opcode byte) {
// 	if (z.F & FLAG_P) != 0 {
// 		z.Call()
// 	} else {
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		//z.Memory.ContendRead(z.PC()+1, 3)
// 		z.Tstates += 10
// 		z.pc += 2
// 	}
// }

// /* shift ED */
// func instr__SHIFT_ED(z *Z80, opcode byte) {
// 	//z.Tstates += 4
// 	opcode2 := z.Load8()
// 	z.R++
// 	if f := OpcodeEDMap[opcode2]; f != nil {
// 		f(z, opcode2)
// 	} else {
// 		invalidOpcode(z, opcode2)
// 	}
// }

// /* XOR A,nn */
// func instr__XOR_A_NN(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.Xor(z.Load8())
// }

// /* RST 28 */
// func instr__RST_28(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	z.Tstates += 11
// 	z.Rst(0x28)
// }

// /* RET P */
// func instr__RET_P(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	if !((z.F & FLAG_S) != 0) {
// 		z.Tstates += 11
// 		z.pc = z.Pop()
// 	} else {
// 		z.Tstates += 5
// 	}
// }

// /* POP AF */
// func instr__POP_AF(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	z.PopR(&z.AF)
// }

// /* JP P,nnnn */
// func instr__JP_P_NNNN(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	if (z.F & FLAG_S) == 0 {
// 		z.pc = z.Load16()
// 	} else {
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		//z.Memory.ContendRead(z.PC()+1, 3)
// 		z.pc += 2
// 	}
// }

// // /* DI */
// func instr__DI(z *Z80, opcode byte) {
// 	z.Tstates += 4
// 	z.IFF1, z.IFF2 = 0, 0
// }

// /* CALL P,nnnn */
// func instr__CALL_P_NNNN(z *Z80, opcode byte) {
// 	if (z.F & FLAG_S) == 0 {
// 		z.Call()
// 	} else {
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		//z.Memory.ContendRead(z.PC()+1, 3)
// 		z.Tstates += 10
// 		z.pc += 2
// 	}
// }

// // /* PUSH AF */
// func instr__PUSH_AF(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	z.Tstates += 11
// 	z.PushR(z.AF)
// }

// /* OR nn */
// func instr__OR_NN(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.Or(z.Load8())
// }

// /* RST 30 */
// func instr__RST_30(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	z.Tstates += 11
// 	z.Rst(0x30)
// }

// /* RET M */
// func instr__RET_M(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	if (z.F & FLAG_S) != 0 {
// 		z.Tstates += 11
// 		z.pc = z.Pop()
// 	} else {
// 		z.Tstates += 5
// 	}
// }

// // /* LD SP,HL */
// func instr__LD_SP_HL(z *Z80, opcode byte) {
// 	z.Tstates += 6
// 	z.sp = z.HL.Get()
// }

// /* JP M,nnnn */
// func instr__JP_M_NNNN(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	if (z.F & FLAG_S) != 0 {
// 		z.pc = z.Load16()
// 	} else {
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		//z.Memory.ContendRead(z.PC()+1, 3)
// 		z.pc += 2
// 	}
// }

// /* EI */
// func instr__EI(z *Z80, opcode byte) {
// 	/* Interrupts are not accepted immediately after an EI, but are
// 	   accepted after the next instruction */
// 	z.Tstates += 4
// 	z.IFF1, z.IFF2 = 1, 1
// 	z.interruptsEnabledAt = int(z.Tstates)
// 	// eventAdd(z.Tstates + 1, z80InterruptEvent)
// }

// /* CALL M,nnnn */
// func instr__CALL_M_NNNN(z *Z80, opcode byte) {
// 	if (z.F & FLAG_S) != 0 {
// 		z.Call()
// 	} else {
// 		//z.Memory.ContendRead(z.PC(), 3)
// 		//z.Memory.ContendRead(z.PC()+1, 3)
// 		z.Tstates += 10
// 		z.pc += 2
// 	}
// }

// /* shift FD */
// func instr__SHIFT_FD(z *Z80, opcode byte) {
// 	//z.Tstates += 4
// 	opcode2 := z.Load8()
// 	z.R++
// 	if f := OpcodeDFMap[opcode2]; f != nil {
// 		f(z, opcode)
// 	} else {
// 		/* Instruction did not involve H or L */
// 		OpcodeMap[opcode2](z, opcode2) // FIXME: verificar se é isto mesmo!!!
// 	}
// }

// /* CP nn */
// func instr__CP_NN(z *Z80, opcode byte) {
// 	z.Tstates += 7
// 	z.Cp(z.Load8())
// }

// /* RST 38 */
// func instr__RST_38(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	z.Tstates += 11
// 	z.Rst(0x38)
// }

void opcodeStep(Z80* z, const uint8_t opcode) { opcodemap[opcode](z, opcode); }
