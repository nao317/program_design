/* wordcounthash1.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordcount.h"

#define HASH_TABLE_SIZE 4441

typedef struct wordcountlist {
    struct wordcountlist *next;
    WORDCOUNT info;
} WORDCOUNTLIST;

WORDCOUNTLIST *HashTable[HASH_TABLE_SIZE];

void wordcountInit(void) {
    int i;
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        HashTable[i] = NULL;
    }   
}

unsigned int hash(char *s) {
    unsigned int v;
    for (v = 0; *s != '\0'; s++) {
        v = (v >> 2) + *s;
    }
    return v % HASH_TABLE_SIZE;
}

WORDCOUNT *wordcountSearch(char *word) {
    unsigned int hash_value;
    WORDCOUNTLIST *wcl;

    hash_value = hash(word);

    if (HashTable[hash_value] != NULL) {

    }

    return NULL;
}