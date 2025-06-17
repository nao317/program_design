#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 200
#define MAXPREFNAME 20
#define MAXPREFNUM 100

struct pref_zip_count {
    char pref_name[MAXPREFNAME];
    int zipcount;
};

#define NOT_FOUND -1

int zip_pref_search (struct pref_zip_count data[], int size, char prefname[]);
void zip_pref_add (struct pref_zip_count data[], int pos, char prefname[]);
void zip_pref_print(struct pref_zip_count data[], int size);

int main(void) {
    FILE *fp;
    char buff[MAXLINE];
    char prefname[MAXPREFNAME];
    struct pref_zip_count zip_count[MAXPREFNUM];
    int index, prefcount;

    if((fp = fopen("YUBIN.csv", "r")) == NULL) {
        fprintf(stderr, "Error: File Open\n");
        exit(1);
    }

    prefcount = 0;

    while (fgets(buff, MAXLINE, fp) != NULL) {
        sscanf(buff, "%*d, %*[^,],%[^,]", prefname);

        if ((index = zip_pref_search(zip_count, prefcount, prefname)) != NOT_FOUND) {
            zip_count[index].zipcount++;
        } else {
            zip_pref_add(zip_count, prefcount, prefname);
            prefcount++;
        }
        
    }

    fclose(fp);

    zip_pref_print(zip_count, prefcount);

    return 0;

}

int zip_pref_search(struct pref_zip_count data[], int size, char prefname[]) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(prefname, data[i].pref_name) == 0) {
            return i;
        }
    }
    return NOT_FOUND;
}

void zip_pref_add (struct pref_zip_count data[], int pos, char prefname[]) {
    strcpy(data[pos].pref_name, prefname);
    data[pos].zipcount = 1;
}

void zip_pref_print(struct pref_zip_count data[], int size) {
    int i, prefcount;
    for (i = 0; i < size; i++) {
        printf("%d: %s\n", data[i].zipcount, data[i].pref_name);
    }
}