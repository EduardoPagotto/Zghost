;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; TESTE DE IX
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

RAM:    EQU 0100H   ; INICIO DA RAM, CFG EM CONSOLE.TOTROM
TOP:    EQU 0120H   ; FIM DA RAM, CFG EM CONSOLE.TOTROM + CONNSOLE.SIZERAM
PORTA:  EQU 0X01
PORTB:  EQU 0X02

        ORG 0X0000
        LD SP,TOP
        LD IX,D_MEIO
        LD B,0
        LD C,PORTA
        LD A,(IX-5);
        OUT (C),A;
        LD A,(IX-4);
        OUT (C),A;
        LD A,(IX-3);
        OUT (C),A;
        LD A,(IX-2);
        OUT (C),A;
        LD A,(IX-1);
        OUT (C),A;
        LD A,(IX+0);
        OUT (C),A;
        LD A,(IX+1);
        OUT (C),A;
        LD A,(IX+2);
        OUT (C),A;
        LD A,(IX+3);
        OUT (C),A;
        LD A,(IX+4);
        OUT (C),A;
        LD A,(IX+5);
        OUT (C),A;
        HALT
        ;
D_INIT: DEFB    01,02,03,04,05,06,07,08,09,10
D_MEIO: DEFB    11,12,13,14,15,16,17,18,19,20
D_FIM:  DEFB    21,22,23,24,25,26,27,28,29,30


start:  LD SP, top      ; fixa o SP no fima da memoria ram
        LD A, 0x10
        LD (ram), A
        LD A, 0x0
        LD A,(ram)
        CP 0x10
        JP NZ,fim
        DI
        ; rst 0x0
fim:    halt
; Data
ram_top: defw 0x0030
         ds 10, 0xee
         defb 0xff, 0xff, 0xff
line1:   defb ' primeira,',13,'$'
line2_3: defb ' segunda,',13,'terceita,',13,'$'
line4:   defb ' quarta.',13,13,'$'
         end.