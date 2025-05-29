#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 2000

int main(int argc, char *argv[]) {
    FILE *fp;
    char buff[MAXLINE];
    int num = 1;
    if (argc != 2) {
        fprintf(stderr, "Error: ファイル名がありません\n");
        exit(1);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: ファイルのオープンエラー _ %s\n", argv[1]);
        exit(2);
    }

    while (fgets(buff, MAXLINE, fp) != NULL) {
        printf("%5d: %s", num++, buff);
    }

    fclose(fp);
    return 0;
}