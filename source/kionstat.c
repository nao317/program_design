#include "kionstat.h"
double kion_heikin(double array[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}
double kion_max(double array[], int size) {
    double maxtemp = array[0];
    for (int i = 1; i < size; i++) {
        if (maxtemp < array[i]) {
            maxtemp = array[i];
        }
    }
    return maxtemp;
}
double kion_min(double array[], int size) {
    double mintemp = array[0];
    for (int i = 1; i < size; i++) {
        if (mintemp > array[i]) {
            mintemp = array[i];
        }
    }
    return mintemp;
}