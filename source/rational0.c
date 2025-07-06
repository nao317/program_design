#include <stdio.h>
#include "rational0.h"

static int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

static RATIONAL simplify(RATIONAL r) {
    int g = gcd(r.bunshi < 0 ? -r.bunshi : r.bunshi, r.bunbo);
    r.bunshi /= g;
    r.bunbo /= g;

    if (r.bunbo < 0) {
        r.bunbo = -r.bunbo;
        r.bunshi = -r.bunshi;
    }

    return r;
}

RATIONAL newRational(int n, int d) {
    RATIONAL r;
    r.bunshi = n;
    r.bunbo = d;
    return simplify(r);
}
RATIONAL raAdd(RATIONAL a, RATIONAL b) {
    RATIONAL r;
    r.bunshi = a.bunshi * b.bunbo + b.bunshi * a.bunbo;
    r.bunbo = a.bunbo * b.bunbo;
    return simplify(r);
}
RATIONAL raSub(RATIONAL a, RATIONAL b) {
    RATIONAL r;
    r.bunshi = a.bunshi * b.bunbo - b.bunshi * a.bunbo;
    r.bunbo = a.bunbo * b.bunbo;
    return simplify(r);
}
RATIONAL raMul(RATIONAL a, RATIONAL b) {
    RATIONAL r;
    r.bunshi = a.bunshi * b.bunshi;
    r.bunbo = a.bunbo * b.bunbo;
    return simplify(r);
}
RATIONAL raDiv(RATIONAL a, RATIONAL b) {
    RATIONAL r;
    r.bunshi = a.bunshi * b.bunbo;
    r.bunbo = a.bunbo * b.bunshi;
    return simplify(r);
}
int raEq(RATIONAL a, RATIONAL b) {
    a = simplify(a);
    b = simplify(b);
    return a.bunshi == b.bunshi && a.bunbo == b.bunbo;
}
int raGt(RATIONAL a, RATIONAL b) {
    return (a.bunshi * b.bunbo) > (b.bunshi * a.bunbo);
}
int raLt(RATIONAL a, RATIONAL b) {
    return (a.bunshi * b.bunbo) < (b.bunshi * a.bunbo);
}
void raPrint(RATIONAL r) {
    printf("%d/%d", r.bunshi, r.bunbo);
}

void raPrintNl(RATIONAL r) {
    raPrint(r);
    printf("\n");
}
