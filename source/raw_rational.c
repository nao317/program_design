#include <stdio.h>

typedef struct rational {
    int bunshi;
    int bunbo;
} RATIONAL;

int main(void) {
    RATIONAL a = {2,3};
    RATIONAL b = {-3, 5};
    RATIONAL x;

    printf("a = %d/%d\n", a.bunshi, a.bunbo);
    printf("b = %d/%d\n", b.bunshi, b.bunbo);

    x.bunshi = a.bunshi * b.bunbo + b.bunshi * a.bunbo;
    x.bunbo = a.bunbo * b.bunbo;
    printf("a + b = %d/%d\n", x.bunshi, x.bunbo);

    x.bunshi = a.bunshi * b.bunbo - b.bunshi * a.bunbo;
    x.bunbo = a.bunbo * b.bunbo;
    printf("a - b = %d/%d\n", x.bunshi, x.bunbo);

    x.bunshi = a.bunshi *b.bunshi;
    x.bunbo = a.bunbo * b.bunbo;
    printf("a * b = %d/%d\n", x.bunshi, x.bunbo);

    x.bunshi = a.bunshi * b.bunbo;
    x.bunbo = a.bunbo * b.bunshi;
    printf("a / b = %d/%d\n", x.bunshi, x.bunbo);

    if (a.bunshi * b.bunbo - b.bunshi * a.bunbo == 0) {
        printf("aとbは等しい。\n");
    } else {
        printf("aとbは異なる。\n");
    }

    if (a.bunshi * b.bunbo - b.bunshi * a.bunbo > 0) {
        printf("aがbより大きい。\n");
    } else {
        printf("aよりbが大きい。\n");
    }

    return 0;
}