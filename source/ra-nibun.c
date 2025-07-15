#include <stdio.h>
#include "rational.h"

int main(void)
{
    RATIONAL x1, x2, x, v;
    RATIONAL eps, c1, c2;

    eps = newRational(2, 1000);  // eps = 0.002
    c1 = newRational(1, 1);      // 定数 1
    c2 = newRational(2, 1);      // 定数 2

    x1 = newRational(0, 1);
    x2 = newRational(1, 1);

    while (raGt(raSub(x2, x1), eps)) {
        x = raDiv(raAdd(x1, x2), c2);  // x = (x1 + x2) / 2

        // v = x * (x * x + 1) - 1
        v = raSub(raMul(x, raAdd(raMul(x, x), c1)), c1);

        // 表示
        printf("x1 = "); raPrint(x1);
        printf(", x2 = "); raPrint(x2);
        printf(", x = "); raPrint(x);
        printf(", v = "); raPrintNl(v);

        if (raGt(v, newRational(0, 1)))  // v > 0
            x2 = x;
        else
            x1 = x;
    }

    // 解の出力
    x = raDiv(raAdd(x1, x2), c2);  // x = (x1 + x2) / 2
    printf("解の近似値 x = "); raPrintNl(x);

    return 0;
}
