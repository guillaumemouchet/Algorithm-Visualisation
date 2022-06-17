#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include <QVector>
#include <QDebug>
#include <QRandomGenerator>
#include "bogosort.h"
#include "fusionsort.h"
#include "heapsort.h"
#include "shellsort.h"
#include "timsort.h"
#include "utils.h"

class SortingAlgorithms
{

public:
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
    *                           PUBLIC                            *
    \* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    SortingAlgorithms();

    void bogoSort(int *array, int left, int right);
    void fusionSort(int *array, int left, int right);
    void heapSort(int *array, int left, int right);
    void shellSort(int *array, int left, int right);
    void timSort(int *array, int left, int right);


protected:
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
    *                           PROTECTED                           *
    \* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


};

#endif // SORTINGALGORITHMS_H
