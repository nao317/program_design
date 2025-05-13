#include <stdio.h>
#include <stdlib.h>

struct kisyou {
    int month;
    int day;
    int hour;
    double kion;
};

#define MAXFILENAME 100
#define ARRAYSIZE 100000

int readfile(char filename[], struct kisyou array[], int amax) {
    int month, day, hour;
    double data;
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error: File Open\n");
        exit(1);
    }
    int size = 0;
    while(fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF && size < ARRAYSIZE) {
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



int main(void) {
    char filename[MAXFILENAME];
    struct kisyou kisyoudata[ARRAYSIZE];
    int size;
    double tempa, tempb;
    int i;

    fprintf(stderr, "データファイル名：");
    scanf("%s", filename);

    size = readfile(filename, kisyoudata, ARRAYSIZE);

    while (1) {
        
        fprintf(stderr, "気温範囲：");
        scanf("%lf %lf", &tempa, &tempb);
        if (tempa > tempb) {
            double temp = tempa;
            tempa = tempb;
            tempb = temp;
        }
        if (tempa >= 100) {
            fprintf(stderr, "検索を終了します。\n");
            break;
        }
        for (i = 0; i < size; i++) {
            if (tempa <= kisyoudata[i].kion && tempb >= kisyoudata[i].kion) {
                printrecord(kisyoudata[i]);
            }
        }
        fprintf(stderr, "\n");
    }

    return 0;

}