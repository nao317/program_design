/* kion-fileprint.c */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    int month, day, hour;
    double data;

    /* ファイルのオープン：ファイル名と入力用の利用を規定 */
    if ((fp = fopen("kion-20180401.csv", "r")) == NULL) {
        /* 以下の2行はファイルがオープンできなかった時の処理 */
        fprintf(stderr, "Error: File Open\n");
        exit(1);
        /* プログラムをここで終了させる */
    }

    /* ファイルの最後 EOF(End of File)までの読み込み */
    while (fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF) {
        printf("%d月%d日%d時%.1f\n", month, day, hour, data);
    }

    /* ファイルのクローズ */
    fclose(fp);

    return 0;
}