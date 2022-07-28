;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; TESTE DE PILHA
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

RAM:    EQU 0100H  ; INICIO DA RAM, CFG EM CONSOLE.TOTROM
TOP:    EQU 0120H  ; FIM DA RAM, CFG EM CONSOLE.TOTROM + CONNSOLE.SIZERAM

        ORG 0X0000
        LD SP,(VALTOP)
        LD A,0XAA
        LD BC,0X0123
        PUSH  BC
        POP BC
        LD DE,0X4567
        LD HL,0X89AB
        LD IX,0XCDEF
        LD IY,0X789A
        LD (RAM),A
        LD (RAM+2),BC
        LD (RAM+4),DE
        LD (RAM+6),HL
        LD (RAM+8),IX
        LD (RAM+10),IY
        LD A,0XFF
        LD BC,0XFFFF
        LD DE,0XFFFF
        LD HL,0XFFFF
        LD IX,0XFFFF
        LD IY,0XFFFF
        LD A,(RAM)
        LD BC,(RAM+2)
        LD DE,(RAM+4)
        LD HL,(RAM+6)
        LD IX,(RAM+8)
        LD IY,(RAM+10)
        HALT
VALTOP: DEFW  0X0120
        END.