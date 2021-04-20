#include <zghost/z80/OpCodeFD.hpp>

// /* ADD iy,DE */
// func instrFD__ADD_REG_DE(z *Z80, opcode byte) {
// 	z.Tstates += 15
// 	//z.Memory.ContendReadNoMreq_loop(z.IR(), 1, 7)
// 	z.Add16(z.IY, z.DE.Get())
// }

// /* LD iy,nnnn */
// func instrFD__LD_REG_NNNN(z *Z80, opcode byte) {
// 	z.Tstates += 14
// 	z.LoadR(&z.IY)
// }

// /* LD (nnnn),iy */
// func instrFD__LD_iNNNN_REG(z *Z80, opcode byte) {
// 	z.Tstates += 20
// 	z.StoreIndexR(z.IY)
// }

// /* INC iy */
// func instrFD__INC_REG(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	//z.Memory.ContendReadNoMreq_loop(z.IR(), 1, 2)
// 	z.IY.Inc() //z.IncIY()
// }

// /* INC IYH */
// func instrFD__INC_REGH(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.Inc(&z.IYH)
// }

// /* DEC IYH */
// func instrFD__DEC_REGH(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.Dec(&z.IYH) //decIYH()
// }

// /* LD IYH,nn */
// func instrFD__LD_REGH_NN(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.IYH = z.Load8()
// }

// /* ADD iy,iy */
// func instrFD__ADD_REG_REG(z *Z80, opcode byte) {
// 	z.Tstates += 15
// 	//z.Memory.ContendReadNoMreq_loop(z.IR(), 1, 7)
// 	z.Add16(z.IY, z.IY.Get())
// }

// /* LD iy,(nnnn) */
// func instrFD__LD_REG_iNNNN(z *Z80, opcode byte) {
// 	z.Tstates += 20
// 	z.LoadIndexR(&z.IY)
// }

// /* DEC iy */
// func instrFD__DEC_REG(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	//z.Memory.ContendReadNoMreq_loop(z.IR(), 1, 2)
// 	z.IY.Dec()
// }

// /* INC IYL */
// func instrFD__INC_REGL(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.Inc(&z.IYL) // incIYL()
// }

// /* DEC IYL */
// func instrFD__DEC_REGL(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.Dec(&z.IYL) // decIYL()
// }

// /* LD IYL,nn */
// func instrFD__LD_REGL_NN(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.IYL = z.Load8()
// }

// /* INC (iy+dd) */
// func instrFD__INC_iREGpDD(z *Z80, opcode byte) {
// 	z.Tstates += 23
// 	var offset byte = z.Load8()
// 	//z.Memory.ContendReadNoMreq_loop(z.pc, 1, 5)
// 	var wordtemp uint16 = z.IY.Get() + uint16(signExtend(offset))
// 	var bytetemp byte = z.bus.ReadMemory(wordtemp)
// 	//z.Memory.ContendReadNoMreq(wordtemp, 1)
// 	z.Inc(&bytetemp)
// 	z.bus.WriteMemory(wordtemp, bytetemp)
// }

// /* DEC (iy+dd) */
// func instrFD__DEC_iREGpDD(z *Z80, opcode byte) {
// 	z.Tstates += 23
// 	var offset byte = z.Load8()
// 	//z.Memory.ContendReadNoMreq_loop(z.pc, 1, 5)
// 	var wordtemp uint16 = z.IY.Get() + uint16(signExtend(offset))
// 	var bytetemp byte = z.bus.ReadMemory(wordtemp)
// 	//z.Memory.ContendReadNoMreq(wordtemp, 1)
// 	z.Dec(&bytetemp)
// 	z.bus.WriteMemory(wordtemp, bytetemp)
// }

// /* LD (iy+dd),nn */
// func instrFD__LD_iREGpDD_NN(z *Z80, opcode byte) {
// 	z.Tstates += 19
// 	offset := z.Load8()
// 	value := z.Load8()
// 	//z.Memory.ContendReadNoMreq_loop(z.pc, 1, 2)
// 	z.bus.WriteMemory(z.IY.Get()+uint16(signExtend(offset)), value)
// }

// /* ADD iy,SP */
// func instrFD__ADD_REG_SP(z *Z80, opcode byte) {
// 	z.Tstates += 15
// 	//z.Memory.ContendReadNoMreq_loop(z.IR(), 1, 7)
// 	z.Add16(z.IY, z.sp)
// }

// /* LD B,IYH */
// func instrFD__LD_B_REGH(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.B = z.IYH
// }

// /* LD B,IYL */
// func instrFD__LD_B_REGL(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.B = z.IYL
// }

// /* LD B,(iy+dd) */
// func instrFD__LD_B_iREGpDD(z *Z80, opcode byte) {
// 	z.Tstates += 19
// 	var offset byte = z.Load8()
// 	//z.Memory.ContendReadNoMreq_loop(z.pc, 1, 5)
// 	z.B = z.bus.ReadMemory(z.IY.Get() + uint16(signExtend(offset)))
// }

// /* LD C,IYH */
// func instrFD__LD_C_REGH(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.C = z.IYH
// }

// /* LD C,IYL */
// func instrFD__LD_C_REGL(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.C = z.IYL
// }

// /* LD C,(iy+dd) */
// func instrFD__LD_C_iREGpDD(z *Z80, opcode byte) {
// 	z.Tstates += 19
// 	var offset byte = z.Load8()
// 	//z.Memory.ContendReadNoMreq_loop(z.pc, 1, 5)
// 	z.C = z.bus.ReadMemory(z.IY.Get() + uint16(signExtend(offset)))
// }

// /* LD D,IYH */
// func instrFD__LD_D_REGH(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.D = z.IYH
// }

// /* LD D,IYL */
// func instrFD__LD_D_REGL(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.D = z.IYL
// }

// /* LD D,(iy+dd) */
// func instrFD__LD_D_iREGpDD(z *Z80, opcode byte) {
// 	z.Tstates += 19
// 	var offset byte = z.Load8()
// 	//z.Memory.ContendReadNoMreq_loop(z.pc, 1, 5)
// 	z.D = z.bus.ReadMemory(z.IY.Get() + uint16(signExtend(offset)))
// }

// /* LD E,IYH */
// func instrFD__LD_E_REGH(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.E = z.IYH
// }

// /* LD E,IYL */
// func instrFD__LD_E_REGL(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.E = z.IYL
// }

// /* LD E,(iy+dd) */
// func instrFD__LD_E_iREGpDD(z *Z80, opcode byte) {
// 	z.Tstates += 19
// 	var offset byte = z.Load8()
// 	//z.Memory.ContendReadNoMreq_loop(z.pc, 1, 5)
// 	z.E = z.bus.ReadMemory(z.IY.Get() + uint16(signExtend(offset)))
// }

// /* LD IYH,B */
// func instrFD__LD_REGH_B(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.IYH = z.B
// }

// /* LD IYH,C */
// func instrFD__LD_REGH_C(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.IYH = z.C
// }

// /* LD IYH,D */
// func instrFD__LD_REGH_D(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.IYH = z.D
// }

// /* LD IYH,E */
// func instrFD__LD_REGH_E(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.IYH = z.E
// }

// /* LD IYH,IYH */
// func instrFD__LD_REGH_REGH(z *Z80, opcode byte) {
// 	z.Tstates += 8
// }

// /* LD IYH,IYL */
// func instrFD__LD_REGH_REGL(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.IYH = z.IYL
// }

// /* LD H,(iy+dd) */
// func instrFD__LD_H_iREGpDD(z *Z80, opcode byte) {
// 	z.Tstates += 19
// 	var offset byte = z.Load8()
// 	//z.Memory.ContendReadNoMreq_loop(z.pc, 1, 5)
// 	z.H = z.bus.ReadMemory(z.IY.Get() + uint16(signExtend(offset)))
// }

// /* LD IYH,A */
// func instrFD__LD_REGH_A(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.IYH = z.A
// }

// /* LD IYL,B */
// func instrFD__LD_REGL_B(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.IYL = z.B
// }

// /* LD IYL,C */
// func instrFD__LD_REGL_C(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.IYL = z.C
// }

// /* LD IYL,D */
// func instrFD__LD_REGL_D(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.IYL = z.D
// }

// /* LD IYL,E */
// func instrFD__LD_REGL_E(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.IYL = z.E
// }

// /* LD IYL,IYH */
// func instrFD__LD_REGL_REGH(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.IYL = z.IYH
// }

// /* LD IYL,IYL */
// func instrFD__LD_REGL_REGL(z *Z80, opcode byte) {
// 	z.Tstates += 8
// }

// /* LD L,(iy+dd) */
// func instrFD__LD_L_iREGpDD(z *Z80, opcode byte) {
// 	z.Tstates += 19
// 	var offset byte = z.Load8()
// 	//z.Memory.ContendReadNoMreq_loop(z.pc, 1, 5)
// 	z.L = z.bus.ReadMemory(z.IY.Get() + uint16(signExtend(offset)))
// }

// /* LD IYL,A */
// func instrFD__LD_REGL_A(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.IYL = z.A
// }

// /* LD (iy+dd),r */
// func instrFD__LD_iREGpDD_r(z *Z80, opcode byte) {
// 	z.Tstates += 19
// 	offset := z.Load8()
// 	//z.Memory.ContendReadNoMreq_loop(z.pc, 1, 5)
// 	var reg *byte = z.GetPrtRegisterValByte(opcode)
// 	z.bus.WriteMemory(z.IY.Get()+uint16(signExtend(offset)), *reg)
// }

// /* LD A,IYH */
// func instrFD__LD_A_REGH(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.A = z.IYH
// }

// /* LD A,IYL */
// func instrFD__LD_A_REGL(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.A = z.IYL
// }

// /* LD A,(iy+dd) */
// func instrFD__LD_A_iREGpDD(z *Z80, opcode byte) {
// 	z.Tstates += 19
// 	var offset byte = z.Load8()
// 	//z.Memory.ContendReadNoMreq_loop(z.pc, 1, 5)
// 	z.A = z.bus.ReadMemory(z.IY.Get() + uint16(signExtend(offset)))

// }

// /* ADD A,IYH */
// func instrFD__ADD_A_REGH(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.Add(z.IYH)
// }

// /* ADD A,IYL */
// func instrFD__ADD_A_REGL(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.Add(z.IYL)
// }

// /* ADD A,(iy+dd) */
// func instrFD__ADD_A_iREGpDD(z *Z80, opcode byte) {
// 	z.Tstates += 19
// 	var offset byte = z.Load8()
// 	//z.Memory.ContendReadNoMreq_loop(z.pc, 1, 5)
// 	var bytetemp byte = z.bus.ReadMemory(z.IY.Get() + uint16(signExtend(offset)))
// 	z.Add(bytetemp)
// }

// /* ADC A,IYH */
// func instrFD__ADC_A_REGH(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.Adc(z.IYH)
// }

// /* ADC A,IYL */
// func instrFD__ADC_A_REGL(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.Adc(z.IYL)
// }

// /* ADC A,(iy+dd) */
// func instrFD__ADC_A_iREGpDD(z *Z80, opcode byte) {
// 	z.Tstates += 19
// 	var offset byte = z.Load8()
// 	//z.Memory.ContendReadNoMreq_loop(z.pc, 1, 5)
// 	var bytetemp byte = z.bus.ReadMemory(z.IY.Get() + uint16(signExtend(offset)))
// 	z.Adc(bytetemp)
// }

// /* SUB A,IYH */
// func instrFD__SUB_A_REGH(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.Sub(z.IYH)
// }

// /* SUB A,IYL */
// func instrFD__SUB_A_REGL(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.Sub(z.IYL)
// }

// /* SUB A,(iy+dd) */
// func instrFD__SUB_A_iREGpDD(z *Z80, opcode byte) {
// 	z.Tstates += 19
// 	var offset byte = z.Load8()
// 	//z.Memory.ContendReadNoMreq_loop(z.pc, 1, 5)
// 	var bytetemp byte = z.bus.ReadMemory(z.IY.Get() + uint16(signExtend(offset)))
// 	z.Sub(bytetemp)
// }

// /* SBC A,IYH */
// func instrFD__SBC_A_REGH(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.Sbc(z.IYH)
// }

// /* SBC A,IYL */
// func instrFD__SBC_A_REGL(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.Sbc(z.IYL)
// }

// /* SBC A,(iy+dd) */
// func instrFD__SBC_A_iREGpDD(z *Z80, opcode byte) {
// 	z.Tstates += 18
// 	var offset byte = z.Load8()
// 	//z.Memory.ContendReadNoMreq_loop(z.pc, 1, 5)
// 	var bytetemp byte = z.bus.ReadMemory(z.IY.Get() + uint16(signExtend(offset)))
// 	z.Sbc(bytetemp)
// }

// /* AND A,IYH */
// func instrFD__AND_A_REGH(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.And(z.IYH)
// }

// /* AND A,IYL */
// func instrFD__AND_A_REGL(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.And(z.IYL)
// }

// /* AND A,(iy+dd) */
// func instrFD__AND_A_iREGpDD(z *Z80, opcode byte) {
// 	z.Tstates += 19
// 	var offset byte = z.Load8()
// 	//z.Memory.ContendReadNoMreq_loop(z.pc, 1, 5)
// 	var bytetemp byte = z.bus.ReadMemory(z.IY.Get() + uint16(signExtend(offset)))
// 	z.And(bytetemp)
// }

// /* XOR A,IYH */
// func instrFD__XOR_A_REGH(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.Xor(z.IYH)
// }

// /* XOR A,IYL */
// func instrFD__XOR_A_REGL(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.Xor(z.IYL)
// }

// /* XOR A,(iy+dd) */
// func instrFD__XOR_A_iREGpDD(z *Z80, opcode byte) {
// 	z.Tstates += 19
// 	var offset byte = z.Load8()
// 	//z.Memory.ContendReadNoMreq_loop(z.pc, 1, 5)
// 	var bytetemp byte = z.bus.ReadMemory(z.IY.Get() + uint16(signExtend(offset)))
// 	z.Xor(bytetemp)
// }

// /* OR A,IYH */
// func instrFD__OR_A_REGH(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.Or(z.IYH)
// }

// /* OR A,IYL */
// func instrFD__OR_A_REGL(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.Or(z.IYL)
// }

// /* OR A,(iy+dd) */
// func instrFD__OR_A_iREGpDD(z *Z80, opcode byte) {
// 	z.Tstates += 19
// 	var offset byte = z.Load8()
// 	//z.Memory.ContendReadNoMreq_loop(z.pc, 1, 5)
// 	var bytetemp byte = z.bus.ReadMemory(z.IY.Get() + uint16(signExtend(offset)))
// 	z.Or(bytetemp)
// }

// /* CP A,IYH */
// func instrFD__CP_A_REGH(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.Cp(z.IYH)
// }

// /* CP A,IYL */
// func instrFD__CP_A_REGL(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.Cp(z.IYL)
// }

// /* CP A,(iy+dd) */
// func instrFD__CP_A_iREGpDD(z *Z80, opcode byte) {
// 	z.Tstates += 19
// 	var offset byte = z.Load8()
// 	//z.Memory.ContendReadNoMreq_loop(z.pc, 1, 5)
// 	var bytetemp byte = z.bus.ReadMemory(z.IY.Get() + uint16(signExtend(offset)))
// 	z.Cp(bytetemp)
// }

// /* shift DDFDCB */
// func instrFD__SHIFT_DDFDCB(z *Z80, opcode byte) {
// 	//z.Tstates += 4
// 	addr := z.IY.Get() + uint16(signExtend(z.Load8()))
// 	opcode2 := z.Load8()
// 	z.R++
// 	OpcodeDDCBMap[opcode2](z, opcode2, addr)
// }

// /* POP iy */
// func instrFD__POP_REG(z *Z80, opcode byte) {
// 	z.Tstates += 14
// 	z.PopR(&z.IY)
// }

// /* EX (SP),iy */
// func instrFD__EX_iSP_REG(z *Z80, opcode byte) {
// 	z.Tstates += 23
// 	var bytetempl = z.bus.ReadMemory(z.sp)
// 	var bytetemph = z.bus.ReadMemory(z.sp + 1)
// 	//z.Memory.ContendReadNoMreq(z.sp+1, 1)
// 	z.bus.WriteMemory(z.sp+1, z.IYH)
// 	z.bus.WriteMemory(z.sp, z.IYL)
// 	//z.Memory.ContendWriteNoMreq_loop(z.sp, 1, 2)
// 	z.IYL = bytetempl
// 	z.IYH = bytetemph
// }

// /* PUSH iy */
// func instrFD__PUSH_REG(z *Z80, opcode byte) {
// 	//z.Memory.ContendReadNoMreq(z.IR(), 1)
// 	z.Tstates += 15
// 	z.PushR(z.IY)
// }

// /* JP iy */
// func instrFD__JP_REG(z *Z80, opcode byte) {
// 	z.Tstates += 8
// 	z.pc = z.IY.Get()
// 	//z.SetPC(z.IY.Get()) /* NB: NOT INDIRECT! */
// }

// /* LD SP,iy */
// func instrFD__LD_SP_REG(z *Z80, opcode byte) {
// 	z.Tstates += 10
// 	//z.Memory.ContendReadNoMreq_loop(z.IR(), 1, 2)
// 	z.sp = z.IY.Get()
// }

void (*opcodemapfd[256])(Z80*, const uint8_t&);

void initOpCodeFD() {

    // // BEGIN of 0xfd shifted opcodes
    // /* ADD REGISTER,BC */
    // OpcodeDFMap[0x09] = instrFD__ADD_REG_BC;
    // /* ADD REGISTER,DE */
    // OpcodeDFMap[0x19] = instrFD__ADD_REG_DE;
    // /* LD REGISTER,nnnn */
    // OpcodeDFMap[0x21] = instrFD__LD_REG_NNNN;
    // /* LD (nnnn),REGISTER */
    // OpcodeDFMap[0x22] = instrFD__LD_iNNNN_REG;
    // /* INC REGISTER */
    // OpcodeDFMap[0x23] = instrFD__INC_REG;
    // /* INC REGISTERH */
    // OpcodeDFMap[0x24] = instrFD__INC_REGH;
    // /* DEC REGISTERH */
    // OpcodeDFMap[0x25] = instrFD__DEC_REGH;
    // /* LD REGISTERH,nn */
    // OpcodeDFMap[0x26] = instrFD__LD_REGH_NN;
    // /* ADD REGISTER,REGISTER */
    // OpcodeDFMap[0x29] = instrFD__ADD_REG_REG;
    // /* LD REGISTER,(nnnn) */
    // OpcodeDFMap[0x2a] = instrFD__LD_REG_iNNNN;
    // /* DEC REGISTER */
    // OpcodeDFMap[0x2b] = instrFD__DEC_REG;
    // /* INC REGISTERL */
    // OpcodeDFMap[0x2c] = instrFD__INC_REGL;
    // /* DEC REGISTERL */
    // OpcodeDFMap[0x2d] = instrFD__DEC_REGL;
    // /* LD REGISTERL,nn */
    // OpcodeDFMap[0x2e] = instrFD__LD_REGL_NN;
    // /* INC (REGISTER+dd) */
    // OpcodeDFMap[0x34] = instrFD__INC_iREGpDD;
    // /* DEC (REGISTER+dd) */
    // OpcodeDFMap[0x35] = instrFD__DEC_iREGpDD;
    // /* LD (REGISTER+dd),nn */
    // OpcodeDFMap[0x36] = instrFD__LD_iREGpDD_NN;
    // /* ADD REGISTER,SP */
    // OpcodeDFMap[0x39] = instrFD__ADD_REG_SP;
    // /* LD B,REGISTERH */
    // OpcodeDFMap[0x44] = instrFD__LD_B_REGH;
    // /* LD B,REGISTERL */
    // OpcodeDFMap[0x45] = instrFD__LD_B_REGL;
    // /* LD B,(REGISTER+dd) */
    // OpcodeDFMap[0x46] = instrFD__LD_B_iREGpDD;
    // /* LD C,REGISTERH */
    // OpcodeDFMap[0x4c] = instrFD__LD_C_REGH;
    // /* LD C,REGISTERL */
    // OpcodeDFMap[0x4d] = instrFD__LD_C_REGL;
    // /* LD C,(REGISTER+dd) */
    // OpcodeDFMap[0x4e] = instrFD__LD_C_iREGpDD;
    // /* LD D,REGISTERH */
    // OpcodeDFMap[0x54] = instrFD__LD_D_REGH;
    // /* LD D,REGISTERL */
    // OpcodeDFMap[0x55] = instrFD__LD_D_REGL;
    // /* LD D,(REGISTER+dd) */
    // OpcodeDFMap[0x56] = instrFD__LD_D_iREGpDD;
    // /* LD E,REGISTERH */
    // OpcodeDFMap[0x5c] = instrFD__LD_E_REGH;
    // /* LD E,REGISTERL */
    // OpcodeDFMap[0x5d] = instrFD__LD_E_REGL;
    // /* LD E,(REGISTER+dd) */
    // OpcodeDFMap[0x5e] = instrFD__LD_E_iREGpDD;
    // /* LD REGISTERH,B */
    // OpcodeDFMap[0x60] = instrFD__LD_REGH_B;
    // /* LD REGISTERH,C */
    // OpcodeDFMap[0x61] = instrFD__LD_REGH_C;
    // /* LD REGISTERH,D */
    // OpcodeDFMap[0x62] = instrFD__LD_REGH_D;
    // /* LD REGISTERH,E */
    // OpcodeDFMap[0x63] = instrFD__LD_REGH_E;
    // /* LD REGISTERH,REGISTERH */
    // OpcodeDFMap[0x64] = instrFD__LD_REGH_REGH;
    // /* LD REGISTERH,REGISTERL */
    // OpcodeDFMap[0x65] = instrFD__LD_REGH_REGL;
    // /* LD H,(REGISTER+dd) */
    // OpcodeDFMap[0x66] = instrFD__LD_H_iREGpDD;
    // /* LD REGISTERH,A */
    // OpcodeDFMap[0x67] = instrFD__LD_REGH_A;
    // /* LD REGISTERL,B */
    // OpcodeDFMap[0x68] = instrFD__LD_REGL_B;
    // /* LD REGISTERL,C */
    // OpcodeDFMap[0x69] = instrFD__LD_REGL_C;
    // /* LD REGISTERL,D */
    // OpcodeDFMap[0x6a] = instrFD__LD_REGL_D;
    // /* LD REGISTERL,E */
    // OpcodeDFMap[0x6b] = instrFD__LD_REGL_E;
    // /* LD REGISTERL,REGISTERH */
    // OpcodeDFMap[0x6c] = instrFD__LD_REGL_REGH;
    // /* LD REGISTERL,REGISTERL */
    // OpcodeDFMap[0x6d] = instrFD__LD_REGL_REGL;
    // /* LD L,(REGISTER+dd) */
    // OpcodeDFMap[0x6e] = instrFD__LD_L_iREGpDD;
    // /* LD REGISTERL,A */
    // OpcodeDFMap[0x6f] = instrFD__LD_REGL_A;
    // /* LD (REGISTER+dd),B */
    // OpcodeDFMap[0x70] = instrFD__LD_iREGpDD_r;
    // /* LD (REGISTER+dd),C */
    // OpcodeDFMap[0x71] = instrFD__LD_iREGpDD_r;
    // /* LD (REGISTER+dd),D */
    // OpcodeDFMap[0x72] = instrFD__LD_iREGpDD_r;
    // /* LD (REGISTER+dd),E */
    // OpcodeDFMap[0x73] = instrFD__LD_iREGpDD_r;
    // /* LD (REGISTER+dd),H */
    // OpcodeDFMap[0x74] = instrFD__LD_iREGpDD_r;
    // /* LD (REGISTER+dd),L */
    // OpcodeDFMap[0x75] = instrFD__LD_iREGpDD_r;
    // /* LD (REGISTER+dd),A */
    // OpcodeDFMap[0x77] = instrFD__LD_iREGpDD_r;
    // /* LD A,REGISTERH */
    // OpcodeDFMap[0x7c] = instrFD__LD_A_REGH;
    // /* LD A,REGISTERL */
    // OpcodeDFMap[0x7d] = instrFD__LD_A_REGL;
    // /* LD A,(REGISTER+dd) */
    // OpcodeDFMap[0x7e] = instrFD__LD_A_iREGpDD;
    // /* ADD A,REGISTERH */
    // OpcodeDFMap[0x84] = instrFD__ADD_A_REGH;
    // /* ADD A,REGISTERL */
    // OpcodeDFMap[0x85] = instrFD__ADD_A_REGL;
    // /* ADD A,(REGISTER+dd) */
    // OpcodeDFMap[0x86] = instrFD__ADD_A_iREGpDD;
    // /* ADC A,REGISTERH */
    // OpcodeDFMap[0x8c] = instrFD__ADC_A_REGH;
    // /* ADC A,REGISTERL */
    // OpcodeDFMap[0x8d] = instrFD__ADC_A_REGL;
    // /* ADC A,(REGISTER+dd) */
    // OpcodeDFMap[0x8e] = instrFD__ADC_A_iREGpDD;
    // /* SUB A,REGISTERH */
    // OpcodeDFMap[0x94] = instrFD__SUB_A_REGH;
    // /* SUB A,REGISTERL */
    // OpcodeDFMap[0x95] = instrFD__SUB_A_REGL;
    // /* SUB A,(REGISTER+dd) */
    // OpcodeDFMap[0x96] = instrFD__SUB_A_iREGpDD;
    // /* SBC A,REGISTERH */
    // OpcodeDFMap[0x9c] = instrFD__SBC_A_REGH;
    // /* SBC A,REGISTERL */
    // OpcodeDFMap[0x9d] = instrFD__SBC_A_REGL;
    // /* SBC A,(REGISTER+dd) */
    // OpcodeDFMap[0x9e] = instrFD__SBC_A_iREGpDD;
    // /* AND A,REGISTERH */
    // OpcodeDFMap[0xa4] = instrFD__AND_A_REGH;
    // /* AND A,REGISTERL */
    // OpcodeDFMap[0xa5] = instrFD__AND_A_REGL;
    // /* AND A,(REGISTER+dd) */
    // OpcodeDFMap[0xa6] = instrFD__AND_A_iREGpDD;
    // /* XOR A,REGISTERH */
    // OpcodeDFMap[0xac] = instrFD__XOR_A_REGH;
    // /* XOR A,REGISTERL */
    // OpcodeDFMap[0xad] = instrFD__XOR_A_REGL;
    // /* XOR A,(REGISTER+dd) */
    // OpcodeDFMap[0xae] = instrFD__XOR_A_iREGpDD;
    // /* OR A,REGISTERH */
    // OpcodeDFMap[0xb4] = instrFD__OR_A_REGH;
    // /* OR A,REGISTERL */
    // OpcodeDFMap[0xb5] = instrFD__OR_A_REGL;
    // /* OR A,(REGISTER+dd) */
    // OpcodeDFMap[0xb6] = instrFD__OR_A_iREGpDD;
    // /* CP A,REGISTERH */
    // OpcodeDFMap[0xbc] = instrFD__CP_A_REGH;
    // /* CP A,REGISTERL */
    // OpcodeDFMap[0xbd] = instrFD__CP_A_REGL;
    // /* CP A,(REGISTER+dd) */
    // OpcodeDFMap[0xbe] = instrFD__CP_A_iREGpDD;
    // /* shift DDFDCB */
    // OpcodeDFMap[0xcb] = instrFD__SHIFT_DDFDCB;
    // /* POP REGISTER */
    // OpcodeDFMap[0xe1] = instrFD__POP_REG;
    // /* EX (SP),REGISTER */
    // OpcodeDFMap[0xe3] = instrFD__EX_iSP_REG;
    // /* PUSH REGISTER */
    // OpcodeDFMap[0xe5] = instrFD__PUSH_REG;
    // /* JP REGISTER */
    // OpcodeDFMap[0xe9] = instrFD__JP_REG;
    // /* LD SP,REGISTER */
    // OpcodeDFMap[0xf9] = instrFD__LD_SP_REG;

    // // END of 0xfd shifted opcodes
}

void opcodeFDStep(Z80* z, const uint8_t opcode) {
    // z->Tstates += 4
    uint8_t opcode2 = z->load8();
    z->R++;
    opcodemapfd[opcode2](z, opcode2); // FIXME: verificar!!!!!
}