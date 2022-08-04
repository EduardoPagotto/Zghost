# Zghost
Z80 processor emulator in c++ (to compare with Zzemu in Golang)

## Dependencias Compilador e Simulador auxiliar
```bash
# Lua
sudo apt install lua5.4

# Compiler sjasmplus
git clone git@github.com:vinniefalco/LuaBridge.git
git clone git@github.com:z00m128/sjasmplus.git
# Linkar sjasmplus -> LuaBridge

# Example
git clone git@github.com:maziac/z80-sample-program.git

# Rumtime
git clone git@github.com:chernandezba/zesarux.git
```

TODO: executar o debug no simulador! preciso refazer DEVICE ainda nao sei como!!!
https://z00m128.github.io/sjasmplus/documentation.html#po_device

## Extencoes do VScode:
```bash
code --list-extensions | xargs -L 1 echo code --install-extension

code --install-extension Gruntfuggly.todo-tree
code --install-extension jeff-hykin.better-cpp-syntax
code --install-extension maziac.asm-code-lens
code --install-extension maziac.dezog
code --install-extension maziac.z80-instruction-set
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