#include <stdio.h>
#include <stdlib.h>

#define MAXDATA 100

int readdata(int array[], int size);
int maxvalue(int array[], int size);
void printdata(int maxvalue, int array[], int size);

int main(void) {
    int array[MAXDATA];
    int size, value;
    size = readdata(array, MAXDATA);
    value = maxvalue(array, size);
    printdata(value, array, size);
    return 0;
}