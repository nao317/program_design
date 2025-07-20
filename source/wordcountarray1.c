/* wordcountarray1.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordcount.h"

#define MAXWORD 10000

WORDCOUNT WordCount[MAXWORD];
int WordNum;

void wordcountInit(void) {
    WordNum = 0;
    totalWords = 0;
    uniqueWords = 0;
    totalComparisons = 0;
}


WORDCOUNT *wordcountSearch(char *word) {
    for (int i = 0; i < WordNum; i++) {
        totalComparisons++;
        if (strcmp(WordCount[i].word, word) == 0) {
            return &WordCount[i];
        }
    }
    return NULL;
}


void wordcountRegister(char *word) {
    WORDCOUNT *id;
    totalWords++;  // 単語処理数カウント

    if ((id = wordcountSearch(word)) != NULL) {
        id->count++;
    } else {
        strcpy(WordCount[WordNum].word, word);
        WordCount[WordNum].count = 1;
        WordNum++;
        uniqueWords++;
    }
}


void wordcountStatistics(void) {
    printf("ユニークな単語数: %d\n", uniqueWords);
    printf("処理した単語の総数: %d\n", totalWords);
    printf("文字列の比較回数: %ld\n", totalComparisons);
    if (totalWords > 0)
        printf("1単語あたりの比較回数: %.2f\n", (double)totalComparisons / totalWords);
}
