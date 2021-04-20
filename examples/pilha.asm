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
        ld sp, top
        ld a, 0xaa
        ld bc, 0x0123
        ld de, 0x4567
        ld hl, 0x89AB
        ld ix, 0xCDEF
        ld iy, 0xFF00
        push af
        push bc
        push de
        push hl
        push ix
        push iy
        call vaievolta
        pop iy
        pop ix
        pop hl
        pop de
        pop bc
        pop af
        nop
        halt
vaievolta:
        ld a, 0xff
        ld bc, 0xffff
        ld de, 0xffff
        ld hl, 0xffff
        ld ix, 0xffff
        ld iy, 0xffff
        ret 
end.