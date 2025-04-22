/* kion-filearray.c */

#include <stdio.h> // headerfile
#include <stdlib.h> // exitが入っている

#define ARRAYSIZE 10000

int main(void) {
    FILE *fp;
    int month, day, hour;
    double data;
    double kion[ARRAYSIZE];
    int size; // 配列の添え字、配列に読み込まれたデータ数として利用
    int i;
    // ファイルの入力処理
    if ((fp = fopen("kion-20180401.csv", "r")) == NULL) {
        fprintf(stderr, "Error: File Open\n");
        exit(1);
    }

    size = 0; // fileのインデックスを初期化
    
    while (fscanf(fp, "%d,%d,%d,%lf", &month, &day, &hour, &data) != EOF) {
        // month, day, hour は読み取ったが今回は使用しない
        kion[size] = data; // 読み込んだデータは配列のはじめから順に格納
        size++; // 次に値を格納する位置の添え字に更新
    }

    fclose(fp);

    // ここからは配列に読み込まれたデータの処理
    for (i = 0; i < size; i++) {
        printf("kion[%d]: %.1f\n", i, kion[i]);
    }

    return 0;

}