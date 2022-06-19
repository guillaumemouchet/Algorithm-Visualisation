#ifndef FUSIONSORT_H
#define FUSIONSORT_H

#include "utils.h"
/**
 * @brief The FusionSort class
 * @def The Sorts class are static, no constructors are needed
*/
class FusionSort
{
public:
    static void fusionSort(int *array, int *emptyArray , int left, int right);
private:
    static void merge(int *array, int *emptyArray, int left, int mid, int right);
};

#endif // FUSIONSORT_H
