;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Main
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RAM:            EQU $200        ; Inicio memoria RAM
TOP:            EQU $2ff        ; Fim memoria RAM
COUNTER:        EQU RAM + 2     ; Memoria do contador
DEV1:           EQU $01
DEV2:           EQU $02

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; RESET HARDWARE e Vetores de Interrupcao
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        org $0
reset:          
        jp boot                 ; Salta para reset principal
        ;
        ds $8 - $               ; 8 - address prev. (8 - 2) = ds 4,0
        jp int8
        ;
        ds $38 - $              ; 56 - address prev. (56 - 10) = ds 46
        jp int38                ; entrada interrupcao 38 (principal)
        ;
        ds $66 - $             
        jp nmi
        ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Clear Memory na interrupcao int8
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
boot:           
        ld sp,TOP
        ld hl,TOP
        ld bc,256
        CCF
.clear
        ld (hl),$0
        dec hl
        dec bc
        ld a,b
        or c
        jr nz, .clear
int8:      
        ei
        ;mi1
dormir:       
        halt
        jr dormir       ; ao voltar da interrupcao entrar em halt novamente   
        ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; NMI  interrupcao de alta prioridade
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        ds $84 - $     ; org $100
nmi:   
        push af
        push bc
        push de
        push hl
        push ix
        push iy
        exx
        call .exec_nmi
        exx
        pop iy
        pop ix
        pop hl
        pop de
        pop bc
        pop af
        retn
.exec_nmi: 
        nop        
        ret
        ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Incrementa contador
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
int38:    
        di
        ex af,af'
        exx
        call .continua
        exx
        ex af,af'
        ei
        reti
        ;
.continua:  
        ld a,(COUNTER)
        inc a
        ld (COUNTER),a
        ret
        ;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Sinalizacao de 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        ds $1fc - $
        defb 'FI'
        defw reset
        end