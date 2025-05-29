/* kion-htmlreportcmd.c */

#include <stdio.h>
#include <stdlib.h>

#include "kion-htmlreport.h"
#include "kionstat.h"
#define ARRAYSIZE 10000

int main(int argc, char *argv[]) {
    struct kisyou kisyoudata[ARRAYSIZE];
    int size;

    if (argc != 3) {
        fprintf(stderr, "データファイル名を指定してください. \n");
        exit(1);
    }
    size = readfile(argv[1], kisyoudata, ARRAYSIZE);
    html_report(kisyoudata, size, argv[2]);
    return 0;
}