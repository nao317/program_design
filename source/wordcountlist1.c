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

// 統計用グローバル変数
int totalWords = 0;        // 処理した単語数
int uniqueWords = 0;       // ユニークな単語数
long totalComparisons = 0; // 文字列比較回数

void wordcountInit(void) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        HashTable[i] = NULL;
    }
    totalWords = 0;
    uniqueWords = 0;
    totalComparisons = 0;
}

unsigned int hash(char *s) {
    unsigned int v;
    for (v = 0; *s != '\0'; s++) {
        v = (v >> 2) + *s;
    }
    return v % HASH_TABLE_SIZE;
}

WORDCOUNT *wordcountSearch(char *word) {
    unsigned int hash_value = hash(word);
    WORDCOUNTLIST *wcl = HashTable[hash_value];

    while (wcl != NULL) {
        totalComparisons++;
        if (strcmp(wcl->info.word, word) == 0) {
            return &wcl->info;
        }
        wcl = wcl->next;
    }

    return NULL;
}

void wordcountRegister(char *word) {
    WORDCOUNT *id;
    totalWords++;  // 単語処理数カウント

    if ((id = wordcountSearch(word)) != NULL) {
        id->count++;
    } else {
        // 新しい単語を登録
        unsigned int hash_value = hash(word);
        WORDCOUNTLIST *new_node = (WORDCOUNTLIST *)malloc(sizeof(WORDCOUNTLIST));
        if (new_node == NULL) {
            fprintf(stderr, "メモリ確保に失敗しました\n");
            exit(3);
        }
        strcpy(new_node->info.word, word);
        new_node->info.count = 1;
        new_node->next = HashTable[hash_value];
        HashTable[hash_value] = new_node;
        uniqueWords++;
    }
}

void wordcountStatistics(void) {
    printf("ユニークな単語数: %d\n", uniqueWords);
    printf("処理した単語の総数: %d\n", totalWords);
    printf("文字列の比較回数: %ld\n", totalComparisons);
    if (totalWords > 0) {
        printf("1単語あたりの比較回数: %.2f\n", (double)totalComparisons / totalWords);
    }
}
