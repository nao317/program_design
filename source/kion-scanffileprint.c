/* kion-scanfileprint.c */

#include <stdio.h>
#include <stdlib.h>

#define MAXFILENAME 100 // ファイル名の最大長

int main(void) {
    char filename[MAXFILENAME];
    FILE *fp;
    int month, day, hour;
    double data;
    fprintf(stderr, "データファイル名:");
    scanf("%s", filename);

    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error: File Open\n");
        exit(1);
    }

    while (fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF) {
        printf("%d月%d日%d時 %.1f\n", month, day, hour, data);
    }

    fclose(fp);

    return 0;

}