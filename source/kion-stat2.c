#include <stdio.h>
#define ARRAYSIZE 24

double kion_max(double kion[], int n) {
    double maxtemp = kion[0];
    for (int i = 1; i < n; i++) {
        if (maxtemp < kion[i]) {
            maxtemp = kion[i];
        }
    }
    return maxtemp;
}
double kion_min(double kion[], int n) {
    double mintemp = kion[0];
    for (int i = 1; i < n; i++) {
        if (mintemp > kion[i]) {
            mintemp = kion[i];
        }
    }
    return mintemp;
}
void kion_print(double kion[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d時: %.1f\n", i, kion[i]);
    }
}
double kion_heikin(double kion[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += kion[i];
    }
    return sum / n;
}
int main(void) {
    double kion[ARRAYSIZE] = {12.8, 12.0, 11.4, 11.2, 10.6, 10.6, 10.3, 10.6, 13.1, 16.9,
                     20.1, 22.2, 21.9, 22.5, 23.9, 24.1, 22.9, 21.9, 20.1,
                     18.9, 17.6, 17.0, 16.4, 15.7};
    kion_print(kion, ARRAYSIZE);
    printf("平均気温: %.1f\n", kion_heikin(kion, ARRAYSIZE));
    printf("最高値: %.1f\n", kion_max(kion, ARRAYSIZE));
    printf("最低値: %.1f\n", kion_min(kion, ARRAYSIZE));
    return 0;
}
