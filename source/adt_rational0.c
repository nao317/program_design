#include <stdio.h>
#include "rational0.h"

int main(void)
{
    RATIONAL a, b, c, d;

    /* 有理数の生成 */
    a = newRational(2, 3);
    b = newRational(-3, 5);
    c = newRational(-4, -6);
    d = newRational(1, 1);

    /* 有理数の表示 */
    printf("a = ");
    raPrintNl(a);

    printf("b = ");
    raPrintNl(b);

    printf("c = ");
    raPrintNl(c);

    printf("d = ");
    raPrintNl(d);

    /* 加算 */
    printf("a + b = ");
    raPrintNl(raAdd(a, b));

    /* 減算 */
    printf("a - b = ");
    raPrintNl(raSub(a, b));

    /* 乗算 */
    printf("a * b = ");
    raPrintNl(raMul(a, b));

    /* 除算 */
    printf("a / b = ");
    raPrintNl(raDiv(a, b));

    /* 等値比較 */
    if (raEq(a, b)) {
        printf("a と b は等しい。\n");
    } else {
        printf("a と b は異なる。\n");
    }

    /* 大小比較 */
    if (raGt(a, b)) {
        printf("a が b より大きい。\n");
    } else {
        printf("b が a より大きい。\n");
    }

    /* 等値比較 */
    if (raEq(a, c)) {
        printf("a と c は等しい。\n");
    } else {
        printf("a と c は異なる。\n");
    }

    return 0;
}
