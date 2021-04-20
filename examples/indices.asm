;===========================================================
; Teste de pilha
;
; Autor : Eduardo Pagotto
; Data: 2020-04-13 
;
;===========================================================

ram:        equ 0100h   ; Inicio da ram, cfg em Console.TotROM
top:        equ 0120h   ; Fim da ram, cfg em Console.TotROM + Connsole.SizeRAM

org 0x0000
        ld sp, (valtop)
        ld a, 0xaa
        ld bc, 0x0123
        push bc
        pop bc
        ld de, 0x4567
        ld hl, 0x89AB
        ld ix, 0xCDEF
        ld iy, 0xFF00
        ld (ram), a
        ld (ram+2), bc
        ld (ram+4), de
        ld (ram+6), hl
        ld (ram+8), ix
        ld (ram+10), iy
        ld a, 0xff
        ld bc, 0xffff
        ld de, 0xffff
        ld hl, 0xffff
        ld ix, 0xffff
        ld iy, 0xffff
        ld a, (ram)
        ld bc, (ram+2)
        ld de, (ram+4)
        ld hl, (ram+6)
        ld ix, (ram+8)
        ld iy, (ram+10)
        halt
valtop: defw 0x0120
end.