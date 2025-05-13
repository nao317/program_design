    /* kion-recordstat.c */
#include <stdio.h>
#include <stdlib.h>
struct kisyou {
    int month;
    int day;
    int hour;
    double kion;
};
double kion_heikin (double array[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}
double kion_max (double array[], int size) {
    double maxtemp = array[0];
    for (int i = 1; i < size; i++) {
        if (maxtemp < array[i]) {
            maxtemp = array[i];
        }
    }
    return maxtemp;
}
double kion_min (double array[], int size) {
    double mintemp = array[0];
    for (int i = 1; i < size; i++) {
        if (mintemp > array[i]) {
            mintemp = array[i];
        }
    }
    return mintemp;
}
int readfile(char filename[], struct kisyou array[], int amax) {
    int month, day, hour;
    double data;
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error: File Open\n");
        exit(1);
    }
    int size = 0;
    while(fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF) {
        array[size].month = month;
        array[size].day = day;
        array[size].hour = hour;
        array[size].kion = data;
        size++;
    }
    return size;
}
#define MAXFILESIZE 100
#define ARRAYSIZE 10000
#define DAYARRAY 24
int main(void) {

    char filename[MAXFILESIZE];
    struct kisyou kisyoudata[ARRAYSIZE];
    double kion[DAYARRAY];
    int size;
    int month, day;
    fprintf(stderr, "データファイル名：");
    scanf("%s", filename);
    size = readfile(filename, kisyoudata, ARRAYSIZE);

    while(1) {
        fprintf(stderr, "月日：");
        scanf("%d %d", &month, &day);
        if (month == 0) {
            fprintf(stderr, "検索を終了します。\n");
            break;
        }
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (month == kisyoudata[i].month && day == kisyoudata[i].day && count < DAYARRAY) {
                kion[count] = kisyoudata[i].kion;
                count++;
            }
        }
        
        printf("%d月%d日： %.1f", month, day, kion_heikin(kion, DAYARRAY));
        printf(" %.1f", kion_max(kion, DAYARRAY));
        printf(" %.1f\n", kion_min(kion, DAYARRAY));
    }
    return 0;
}