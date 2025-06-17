#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 200

int main(void) {
    FILE *fp;
    char buff[MAXLINE];
    int lgcode;
    char zipstr[10], prefname[20], cityname[50],  addrstr[200];

    if ((fp = fopen("YUBIN.csv", "r")) == NULL) {
        fprintf(stderr, "Error: fopen\n");
        exit(1);
    }

    while (fgets(buff, MAXLINE, fp) != NULL) {
        if (sscanf(buff, "%d, %[^,],%[^,],%[^,],%s", &lgcode, zipstr, prefname, cityname, addrstr) != 5) {
            fprintf(stderr, "Error: sscanf\n");
            exit(2);
        }
        printf("%s, %s, %s, %s\n", zipstr, prefname, cityname, addrstr);
    }

    fclose(fp);

    return 0;

}