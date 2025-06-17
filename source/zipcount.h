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

int zip_pref_search (struct pref_zip_count data[], int size, char prefname[]);
void zip_pref_add (struct pref_zip_count data[], int pos, char prefname[]);
void zip_pref_print(struct pref_zip_count data[], int size);