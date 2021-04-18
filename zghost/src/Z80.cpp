#include <zghost/z80/Z80.hpp>

Z80::Z80(Bus* pBus) {
    A, F, B, C, D, E, H, L = 0;
    A_, F_, B_, C_, D_, E_, H_, L_ = 0;
    IXH, IXL, IYH, IYL = 0;
    I, IFF1, IFF2, IM = 0;

    R7 = 0;
    R = 0;
    pc = 0;
    sp = 0xffff;

    AF = new R16(&A, &F);
    BC = new R16(&B, &C);
    DE = new R16(&D, &E);
    HL = new R16(&H, &L);
    IX = new R16(&IXH, &IXL);
    IY = new R16(&IYH, &IYH);
    AF_ = new R16(&A_, &F_);
    BC_ = new R16(&B_, &C_);
    DE_ = new R16(&D_, &E_);
    HL_ = new R16(&H_, &L_);

    bus = pBus;
}

Z80::~Z80() {}