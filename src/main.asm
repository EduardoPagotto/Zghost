;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Main
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

RAM:            EQU $100        ; Inicio memoria RAM
TOP:            EQU $0ff        ; Fim memoria RAM
COUNTER:        EQU RAM + 2     ; Memoria do contador
;DEV1:           EQU $01
;DEV2:           EQU $02

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; RESET HARDWARE e Vetores de Interrupcao
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        org $0
reset:          
        jp boot                 ; Salta para reset principal
        ;
        org $8
        jp int8
        ;
        org $38 
        jp int38        ; entrada interrupcao 38 (principal)
        ;
        org $66
        jp nmi
        ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Clear Memory na interrupcao int8
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
boot:           
        ld sp,TOP
int8:      
        ei
        mi1
dormir:       
        halt
        jr dormir       ; ao voltar da interrupcao entrar em halt novamente   
        ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; NMI  interrupcao de alta prioridade
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        org $80
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
.continua:  
        ld a,(COUNTER)
        inc a
        ld (COUNTER),a
        ret
        ;
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
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Sinalizacao de 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        defw reset
        defb 'FI'
        end