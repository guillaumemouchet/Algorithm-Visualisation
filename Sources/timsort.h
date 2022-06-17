#ifndef TIMSORT_H
#define TIMSORT_H

#include <time.h>
#include <iostream>
#include "sortingalgorithms.h"
const int RUN = 32;

class TimSort: public SortingAlgorithms
{
public:
    TimSort();
    static void timSort(int *array, int left, int right);
    static void insertionSort(int *array, int left, int right);
    static void merge(int *array, int l, int m, int r);

};

#endif // TIMSORT_H
