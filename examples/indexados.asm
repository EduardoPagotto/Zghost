;===========================================================
; teste de IX
;
; Autor : Eduardo Pagotto
; Data: 2020-04-21 
;
;===========================================================

ram:            equ     0100h   ; Inicio da ram, cfg em Console.TotROM
top:            equ     0120h   ; Fim da ram, cfg em Console.TotROM + Connsole.SizeRAM
portA:          equ     0x01
portB:          equ     0x02

org             0x0000
                ld      sp,top
                ld      ix,d_meio
                ld      B,0
                ld      c,portA
                ld      a,(ix-5);
                out     (c),a;
                ld      a,(ix-4);
                out     (c),a;
                ld      a,(ix-3);
                out     (c),a;
                ld      a,(ix-2);
                out     (c),a;
                ld      a,(ix-1);
                out     (c),a;
                ld      a,(ix+0);
                out     (c),a;
                ld      a,(ix+1);
                out     (c),a;
                ld      a,(ix+2);
                out     (c),a;
                ld      a,(ix+3);
                out     (c),a;
                ld      a,(ix+4);
                out     (c),a;
                ld      a,(ix+5);
                out     (c),a;
                halt

d_init:
                defb    01,02,03,04,05,06,07,08,09,10
d_meio:
                defb    11,12,13,14,15,16,17,18,19,20
d_fim:
                defb    21,22,23,24,25,26,27,28,29,30


; start:  LD SP, top      ; fixa o SP no fima da memoria ram
;         LD A, 0x10
;         LD (ram), A
;         LD A, 0x0
;         LD A,(ram)
;         CP 0x10
;         JP NZ,fim
;         DI
;         ; rst     0x0
; fim:    halt
; ; Data
; ; ram_top:        defw 0x0030
; ds              10, 0xee
; defb            0xff,0xff,0xff
; ;line1:    defb ' primeira,',13,'$'
; ;line2_3:  defb ' segunda,',13,'terceita,',13,'$'
; ;line4:    defb ' quarta.',13,13,'$'
end.