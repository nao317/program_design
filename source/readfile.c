#include <stdio.h>
#include <stdlib.h>

#include "kion-htmlreport.h"

int readfile (char filename[], struct kisyou array[], int amax) {
    FILE *fp;
    int size = 0;
    int month, day, hour;
    double data;
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error: File Open\n");
        exit(1);
    }
    while (fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF) {
        array[size].month = month;
        array[size].day = day;
        array[size].hour = hour;
        array[size].kion = data;
        size++;
    }
    fclose(fp);

    return size;
}