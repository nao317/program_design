/* kion-filestructarray.c */

#include <stdio.h>
#include <stdlib.h> // exit() is included in it.

struct kisyou {
    int month;
    int day;
    int hour;
    double kion;
};

#define ARRAYSIZE 1000

int main(void) {
    FILE *fp;
    int month, day, hour;
    double data;
    struct kisyou kisyoudata[ARRAYSIZE];
    int size, i;
    if ((fp = fopen("kion-20180401.csv", "r")) == NULL) {
        fprintf(stderr, "Error: File Open\n");
        exit(1);
    }
    size = 0;
    while(fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF) {
        kisyoudata[size].month = month;
        kisyoudata[size].day = day;
        kisyoudata[size].hour = hour;
        kisyoudata[size].kion = data;
        size++;
    }
    fclose(fp);
    for (int i = 0; i < size; i++) {
        printf("%d月%d日%d時 %.1f\n", kisyoudata[i].month, kisyoudata[i].day, kisyoudata[i].hour, kisyoudata[i].kion);
    }
    return 0;
}