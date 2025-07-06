typedef struct rational {
    int bunshi;
    int bunbo;
} RATIONAL;

RATIONAL newRational(int n, int d);

RATIONAL raAdd(RATIONAL a, RATIONAL b);
RATIONAL raSub(RATIONAL a, RATIONAL b);
RATIONAL raMul(RATIONAL a, RATIONAL b);
RATIONAL raDiv(RATIONAL a, RATIONAL b);

int raEq(RATIONAL a, RATIONAL b);
int raGt(RATIONAL a, RATIONAL b);
int raLt(RATIONAL a, RATIONAL b);

void raPrint(RATIONAL v);
void raPrintNl(RATIONAL);

