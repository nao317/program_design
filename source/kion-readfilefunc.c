/* kion-readfilefunc.c */

#include <stdio.h>
#include <stdlib.h>
int readfile (char filename[], double array[], int amax) {
    FILE *fp;
    int size;
    int month, day, hour;
    double data;
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error: File Open\n");
        exit(1);
    }
    while (fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF) {
        array[size] = data;
        size++;
    }
    fclose(fp);

    return size;
}

#define MAXFILENAME 100
#define ARRAYSIZE 1000

int main(void) {
    char filename[MAXFILENAME];
    double kion[ARRAYSIZE];
    int size;
    printf("ファイル名: ");
    scanf("%s", filename);

    size = readfile(filename, kion, ARRAYSIZE);

    for (int i = 0; i < size; i++) {
        printf("kion[%d]: %.1f\n", i, kion[i]);
    }

    return 0;

}