;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Primeiro Teste
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RAM:    EQU 0100H   ; INICIO DA RAM, CFG EM CONSOLE.TOTROM
TOP:    EQU 0120H   ; FIM DA RAM, CFG EM CONSOLE.TOTROM + CONNSOLE.SIZERAM
DEV1:   EQU 0X01
DEV2:   EQU 0X02
        ;
        ORG 0X0000
        JP BOOT
        ;
        ORG 0008H
        JP BOOL_FRIO
        ;
        ORG 0038H
        PUSH AF
        PUSH BC
        PUSH DE
        PUSH HL
        PUSH IX
        PUSH IY
        EXX
        CALL EXEC_INTERRUPT
        EXX
        POP IY
        POP IX
        POP HL
        POP DE
        POP BC
        POP AF
        RETI
        ;
EXEC_INTERRUPT:
        NOP
        RET
        ;
BOOT:   LD SP,TOP
        LD HL,1234
        LD B,0X80
        LD C,DEV1
        OUT (C),L
        OUT (C),H
        LD HL,0X0000
        LD C,DEV2
        IN L,(C)
        IN H,(C)
        EI
        HALT
        ;
BOOL_FRIO:
        HALT
        END.