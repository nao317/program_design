/* kion-htmlfunc.c */

#include <stdio.h>
#include <stdlib.h>
#include "html-report.h"

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
    printf("<h1>日別気温統計データ</h1>\n");
    printf("<table border=1>\n");
    printf("<tr><th>月日</th><th>平均</th><th>最高</th><th>最低</th><th>日較差</th></tr>\n");

    for (int i = 0; i + DAYARRAY <= size; i += DAYARRAY) {
        for (int j = 0; j < DAYARRAY; j++) {
            kion[j] = kisyoudata[i + j].kion;
        }
        double average = kion_heikin(kion, DAYARRAY);
        double maxtemp = kion_max(kion, DAYARRAY);
        double mintemp = kion_min(kion, DAYARRAY);
        double diff = maxtemp - mintemp;
        int month = kisyoudata[i].month;
        int day = kisyoudata[i].day;

        printf("<tr>");
        printf("<td>%d月%d日</td>", month, day);
        printf("<td>%.1f</td>", average);
        printf("<td>%.1f</td>", maxtemp);
        printf("<td>%.1f</td>", mintemp);
        printf("<td>%.1f</td>", diff); // 日較差
        printf("</tr>\n");
    }

    printf("</table>\n");
    printf("</body>\n");
    printf("</html>\n");
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