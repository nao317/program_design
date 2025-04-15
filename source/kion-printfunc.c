#include <stdio.h>
#define ARRAYSIZE 24

void kion_print(double kion[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d時: %.1f\n", i, kion[i]);
    }
}
int main(void) {
    double kion[ARRAYSIZE] = {12.8, 12.0, 11.4, 11.2, 10.6, 10.6, 10.3, 10.6, 13.1, 16.9,
                     20.1, 22.2, 21.9, 22.5, 23.9, 24.1, 22.9, 21.9, 20.1,
                     18.9, 17.6, 17.0, 16.4, 15.7};
    int i;
    kion_print(kion, ARRAYSIZE);
    return 0;
}
