#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zipcount.h"
#define NOT_FOUND -1
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