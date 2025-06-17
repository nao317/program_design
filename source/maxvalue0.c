#include <stdio.h>
#include <stdlib.h>

#define MAXDATA 100

int main(void) {
    int array[MAXDATA];
    int i, size;
    int value, maxvalue;
    for (size = 0; scanf("%d", &value) != EOF; size++) {
        if (size >= MAXDATA) {
            fprintf(stderr, "ERROR: 配列が溢れました。\n");
            exit(1);
        }
        array[size] = value;
    }
    maxvalue = array[0];
    for (i = 1; i < size; i++) {
        if (array[i] > maxvalue) {
            maxvalue = array[i];
        }
    }
    printf("--DATA--\n");
    for (i = 0; i < size; i++) {
        printf("%d: %d\n", i, array[i]);
    }
    printf("MAXVALUE: %d\n", maxvalue);
    return 0;
}