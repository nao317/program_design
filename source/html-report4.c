#include <stdio.h>
#include <stdlib.h>
#include "kion-htmlreport.h"
#include "kionstat.h"

#define DAYARRAY 24

void html_report(struct kisyou kisyoudata[], int size, char htmlfilename[]) {
    FILE *fp;
    double kion[DAYARRAY];
    char *str;
    if ((fp = fopen(htmlfilename, "w")) == NULL) {
        fprintf(stderr, "Error: 出力ファイルのオープンエラー _ %s\n", htmlfilename);
        exit(1);
    }

    /* HTML */
    fprintf(fp, "<html>\n");
    fprintf(fp, "<head>\n");
    fprintf(fp, "<title>気温データ</title>\n");
    fprintf(fp, "</head>\n");
    fprintf(fp, "<body>\n");
    fprintf(fp, "<h1>日別気温統計データ</h1>\n");
    fprintf(fp, "<table border=1>\n");
    fprintf(fp, "<tr><th>月日</th><th>平均</th><th>最高</th><th>最低</th><th>日較差</th></tr>\n");

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

        fprintf(fp, "<tr>");
        fprintf(fp, "<td>%d月%d日</td>", month, day);
        fprintf(fp, "<td>%.1f</td>", average);
        fprintf(fp, "<td>%.1f</td>", maxtemp);
        fprintf(fp, "<td>%.1f</td>", mintemp);
        fprintf(fp, "<td>%.1f</td>", diff); // 日較差
        fprintf(fp, "</tr>\n");
    }

    fprintf(fp, "</table>\n");
    fprintf(fp, "</body>\n");
    fprintf(fp, "</html>\n");
    /* END HTML */

    fclose(fp);
}