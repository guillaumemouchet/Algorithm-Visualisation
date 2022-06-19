#ifndef TIMSORT_H
#define TIMSORT_H

#include <time.h>
#include <iostream>
#include "utils.h"
const int RUN = 32;
/**
 * @brief The TimSort class
 * @ref https://www.geeksforgeeks.org/timsort/
 * @def The Sorts class are static, no constructors are needed
 */
class TimSort
{
public:
    static void timSort(int *array, int left, int right);
private:
    static void insertionSort(int *array, int left, int right);
    static void merge(int *array, int l, int m, int r);

};

#endif // TIMSORT_H
