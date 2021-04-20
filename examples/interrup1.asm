;===========================================================
; Primeiro Teste
;
; Autor : Eduardo Pagotto
; Data: 2020-04-13 
;
;===========================================================

ram:        equ 0100h   ; Inicio da ram, cfg em Console.TotROM
top:        equ 0120h   ; Fim da ram, cfg em Console.TotROM + Connsole.SizeRAM
int_ounter  equ ram + 2
dev1:       equ 0x01
dev2:       equ 0x02

org 0x0000
start:
        di
        jp boot
org 0008h
        jp bool_frio
boot:
        ld sp, top
bool_frio:
        ei
        mi2
dormir:
        halt
        jr dormir
org 0038h
        jp interrupt38
defw    0xf0f0
; org 0066h
;         jp intetrrupt66
; org 0080h
; intetrrupt66:
;         push af
;         push bc
;         push de
;         push hl
;         push ix
;         push iy
;         exx
;         call exec_interrupt
;         exx
;         pop iy
;         pop ix
;         pop hl
;         pop de
;         pop bc
;         pop af
;         retn
; exec_interrupt:
;         nop
;         ret
continua:
        ld a,(int_ounter)
        inc a
        ld (int_ounter), a
        ret
interrupt38:
        di
        ex af,af'
        exx
        call continua
        exx
        ex af,af'
        ei
        reti
end