;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; TESTE DE PILHA
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

RAM:    EQU 0100H  ; INICIO DA RAM, CFG EM CONSOLE.TOTROM
TOP:    EQU 0120H  ; FIM DA RAM, CFG EM CONSOLE.TOTROM + CONNSOLE.SIZERAM

        ORG 0X0000
        LD SP,TOP
        LD A,0XAA
        LD BC,0X0123
        LD DE,0X4567
        LD HL,0X89AB
        LD IX,0XCDEF
        LD IY,0XFF00
        PUSH AF
        PUSH BC
        PUSH DE
        PUSH HL
        PUSH IX
        PUSH IY
        CALL RETORNA_0
        POP IY
        POP IX
        POP HL
        POP DE
        POP BC
        POP AF
        NOP
        HALT
        ;
RETORNA_0:
        LD A,0XFF
        LD BC,0XFFFF
        LD DE,0XFFFF
        LD HL,0XFFFF
        LD IX,0XFFFF
        LD IY,0XFFFF
        RET
        END.