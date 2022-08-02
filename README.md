# Zghost
Z80 processor emulator in c++ (to compare with Zzemu in Golang)

## compiler
ref: https://pasmo.speccy.org/

## Extencoes do VScode:
```bash
code --list-extensions | xargs -L 1 echo code --install-extension

code --install-extension cschlosser.doxdocgen
code --install-extension Gruntfuggly.todo-tree
code --install-extension jeff-hykin.better-cpp-syntax
code --install-extension mborik.z80-macroasm
code --install-extension ms-vscode.cmake-tools
code --install-extension ms-vscode.cpptools
code --install-extension ms-vscode.cpptools-extension-pack
code --install-extension ms-vscode.cpptools-themes
code --install-extension ms-vscode.hexeditor
code --install-extension PKief.material-icon-theme
code --install-extension QiaoJie.binary-viewer
code --install-extension twxs.cmake
code --install-extension vadimcn.vscode-lldb
code --install-extension xaver.clang-format
```


## Resumo diretivas para 8 bis
```asm
        org 0x0000              ; aponta para 0x0000
        ld a,#FF
        ld b,#02
        ld c,#03

                                ; Exemplo de dados constantes
        org $ca                 ; aponta para 0x00CA
        defb 25                 ; Decimal
        defb 10d                ; Decimal
        defb 0xfc               ; Hex 1 byte
        defb #aa                ; Hex 1 byte
        defb $22                ; Hex 1 byte
        defb %11010001          ; binario 1 byte
        defb '4'                ; caracter 1 byte
        defb '1234544'          ; string (bytes da string em ascii)
        defw 6000               ; decimal 2 bytes (little-endian)
        defw $eeee              ; hexa 2 bytes (little-endian)
        defb $04,$05,$77        ; sequencia de numericos em hexa
        defw $ccdd              ; write 2 bytes (little-endian) (dw)
        ds 10, $ff              ; reserva 10 bytes com 0xFF
        dw $0123,$4567,$89ab    ; lista de 2 bytes separadas por ',' (little-endian)
```