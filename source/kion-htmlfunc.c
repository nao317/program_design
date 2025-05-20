/* kion-html.c */

#include <stdio.h>
#include <stdlib.h>

double kion_heikin(double array[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}
double kion_max(double array[], int size) {
    double maxtemp = array[0];
    for (int i = 1; i < size; i++) {
        if (maxtemp < array[i]) {
            maxtemp = array[i];
        }
    }
    return maxtemp;
}
double kion_min(double array[], int size) {
    double mintemp = array[0];
    for (int i = 1; i < size; i++) {
        if (mintemp > array[i]) {
            mintemp = array[i];
        }
    }
    return mintemp;
}
struct kisyou {
    int month;
    int day;
    int hour;
    double kion;
};
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
#define MAXFILENAME 100
#define ARRAYSIZE 10000
#define DAYARRAY 24

void kion_html(struct kisyou kisyoudata[], int size) {
    /* HTML */
    double kion[DAYARRAY];
    printf("<html>\n");
    printf("<head>\n");
    printf("<title>気温データ</title>\n");
    printf("</head>\n");
    printf("<body>\n");
    printf("<h1>日別気温統計データ</h1>");
    printf("<table border=1>\n");
    printf("<tr><th>月日</th><th>平均</th><th>最高</th><th>最低</th><tr>\n");

    for (int i = 0; i < size; i += DAYARRAY) {
        for (int j = 0; j < DAYARRAY; j++) {
            kion[j] = kisyoudata[i + j].kion;
        }
        double average = kion_heikin(kion, DAYARRAY);
        double maxtemp = kion_max(kion, DAYARRAY);
        double mintemp = kion_min(kion, DAYARRAY);
        int month = kisyoudata[i].month;
        int day = kisyoudata[i].day;
        printf("<tr>");
        printf("<td>%d月%d日</td>", month, day);
        printf("<td>%.1f</td>", average);
        printf("<td>%.1f</td>", maxtemp);
        printf("<td>%.1f</td>", mintemp);
        printf("</tr>\n");
    }

    printf("</table>\n");
    printf("</body>\n");
    printf("</html>\n");
    /* HTML end */
}
int main(void) {
    char filename[MAXFILENAME];
    struct kisyou kisyoudata[ARRAYSIZE];
    int size;
    int i, di;

    fprintf(stderr, "データファイル名：");
    scanf("%s", filename);

    size = readfile(filename, kisyoudata, ARRAYSIZE);
    kion_html(kisyoudata, size);    
    return 0;

}