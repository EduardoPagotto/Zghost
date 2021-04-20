;==============================================================================
; Interrupt Mode 2
;==============================================================================
; Description:
;   Short routine that prepares memory to activate IM2.
; Author:
;   TK90X Fan 
;   (reikainosuke-tk@yahoo.com.br, http://cantinhotk90x.blogspot.com.br)
; Version: 
;   1.0 - Jul/13/2014
; License: 
;   The routine itself isn't new, it has been used for a long time in many ZX
;   spectrum programs and I presume it's public domain. 
;==============================================================================

;==============================================================================
; Constants
; ---------
; These labels defines some parameters of this routine. The commented out ones
;must be properly assigned in the assembly file where this one is included. The
;suggested values create an interrupt vector table at $FE00-$FF00 (65024-65280),
;put an JP instruction at $FDFD (65021-65023) and define real interrupt address
;at $8000 (32768).
; Warning: values of I register (IM2Vector) in the 64-127 ($40-$7F) range 
;cause snow bug (http://www.zxdesign.info/harlequinSnow.shtml).  
;==============================================================================

;IM2Vector   EQU $FE             ; MSB of interrupt vector address, to be 
                                ;assigned to I registers. When interrupt is 
                                ;requested in mode 2, this value is joined with 
                                ;one byte read from data bus and an address is 
                                ;made, where Z80 will fetch a 2-byte address
                                ;to jump to. 
;IM2JumpH    EQU $FD             ; 1 byte of address where Z80 will jump after an
                                ;interrupt request. Both LSB and MSB of address
                                ;must have this same value. 
;IM2Routine  EQU 32768           ; The real IM2 rotine address.   

IM2VTable   EQU 256*IM2Vector   ; Address of IM2 vector table.

;==============================================================================
; Main Routine
; ------------
; Used registers: AF, BC=0, DE, HL, I. 
;==============================================================================

    LD HL,IM2VTable             ; Prepare IM2 routine address vector table. It's 
    LD DE,IM2VTable+1           ;composed by 257 bytes, which all values are 
    LD BC,257                   ;equal to IM2JumpH.  
    LD (HL),IM2JumpH
    LDIR
    LD HL,IM2JumpH+256*IM2JumpH ; Point HL to address where Z80 would jump to.
    LD (HL),$C3                 ; Opcode for 'JP'.
    INC HL
    LD (HL),IM2Routine%256      ; LSB of real IM2 routine address. 
    INC HL
    LD (HL),IM2Routine/256      ; MSB of real IM2 routine address. 
    LD A,IM2Vector              ; Assign IM2 Vector Register value. 
    LD I,A
    IM 2                        ; Set interrupt mode. 



