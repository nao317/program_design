/* kion-recordsearch.c */

#include <stdio.h>
#include <stdlib.h>

struct kisyou {
    int month;
    int day;
    int hour;
    double kion;
};

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

void printrecord(struct kisyou record) {
    printf("%d月%d日%d時 %.1f\n", record.month, record.day, record.hour, record.kion);
}

#define MAXFILENAME 100

#define ARRAYSIZE 1000

int main(void) {
    char filename[MAXFILENAME];
    struct kisyou kisyoudata[ARRAYSIZE];
    int size;
    int month, day;
    int i;

    fprintf(stderr, "データファイル名：");
    scanf("%s", filename);

    size = readfile(filename, kisyoudata, ARRAYSIZE);

    fprintf(stderr, "月日：");
    scanf("%d %d", &month, &day);

    for (i = 0; i < size; i++) {
        if (month == kisyoudata[i].month && day == kisyoudata[i].day) {
            printrecord(kisyoudata[i]);
        }
    }
}