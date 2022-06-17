#ifndef FUSIONSORT_H
#define FUSIONSORT_H

#include "utils.h"

class FusionSort
{
public:
    FusionSort();
    static void fusionSort(int *array, int *emptyArray , int left, int right);
private:
    static void merge(int *array, int *emptyArray, int left, int mid, int right);
};

#endif // FUSIONSORT_H
