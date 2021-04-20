;===========================================================
; Primeiro Teste
;
; Autor : Eduardo Pagotto
; Data: 2020-04-13 
;
;===========================================================

ram:        equ 0100h   ; Inicio da ram, cfg em Console.TotROM
top:        equ 0120h   ; Fim da ram, cfg em Console.TotROM + Connsole.SizeRAM
dev1:       equ 0x01
dev2:       equ 0x02

org 0x0000
        di
        jp boot
org 0008h
        jp bool_frio
org 0038h
        push af
        push bc
        push de
        push hl
        push ix
        push iy
        exx
        call exec_interrupt
        exx
        pop iy
        pop ix
        pop hl
        pop de
        pop bc
        pop af
        reti
exec_interrupt:
        nop
        ret 
boot:
        ld sp, top
        ld hl, 1234
        ld b, 0x80
        ld c, dev1
        out (c), l
        out (c), h
        ld hl, 0x0000
        ld c, dev2
        in l, (c)
        in h, (c)
        ei
        halt
bool_frio:
        halt


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