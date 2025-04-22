/* kion-filestat.c */

/* 今回の演習はデータの出力部分の関数化である */

#include <stdio.h> // headerfile
#include <stdlib.h> // exitが入っている

#define ARRAYSIZE 10000

// 気温の平均値
double kion_heikin(double kion[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += kion[i];
    }
    return sum / n;
}

// 気温の最高値
double kion_max(double kion[], int n) {
    double maxtemp = kion[0];
    for (int i = 1; i < n; i++) {
        if (maxtemp < kion[i]) {
            maxtemp = kion[i];
        }
    }
    return maxtemp;
}

// 気温の最低値
double kion_min(double kion[], int n) {
    double mintemp = kion[0];
    for (int i = 1; i < n; i++) {
        if (mintemp > kion[i]) {
            mintemp = kion[i];
        }
    }
    return mintemp;
}

// 気温データの出力
void kion_print(double kion[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d時: %.1f\n", i, kion[i]);
    }
}

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
    kion_print(kion, ARRAYSIZE);
    printf("平均気温: %.1f\n", kion_heikin(kion, size));
    printf("最高値: %.1f\n", kion_max(kion, size));
    printf("最低値: %.1f\n", kion_min(kion, size));
    return 0;

}