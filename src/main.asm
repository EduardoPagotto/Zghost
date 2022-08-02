;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; PRIMEIRO TESTE
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

RAM:            EQU 0100H  ; INICIO DA RAM, CFG EM CONSOLE.TOTROM
TOP:            EQU 0120H  ; FIM DA RAM, CFG EM CONSOLE.TOTROM + CONNSOLE.SIZERAM
INT_OUNTER:     EQU RAM + 2
DEV1:           EQU 0X01
DEV2:           EQU 0X02

                ORG 0X0000
START:          JP BOOT
                ;
                ORG 0008H
                JP BOOL_FRIO
                ;
BOOT:           LD SP,TOP
BOOL_FRIO:      EI
                MI1
DORMIR:         HALT
                JR DORMIR
                ;
                ORG 0038H
                JR INTERRUPT38
                ;
DEFW 0XF0F0
                ;
                ORG 0066H
                JP INTETRRUPT66
                ORG 0080H
INTETRRUPT66:   PUSH AF
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
                RETN
EXEC_INTERRUPT: NOP
                RET
                ;
CONTINUA:       LD A,(INT_OUNTER)
                INC A
                LD (INT_OUNTER),A
                RET
INTERRUPT38:    DI
                EX AF,AF'
                EXX
                CALL CONTINUA
                EXX
                EX AF,AF'
                EI
                RETI
                END