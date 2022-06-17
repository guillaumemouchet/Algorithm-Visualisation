#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "sortingalgorithms.h"
#include "utils.h"


class HeapSort
{
public:

    HeapSort();
    static void heapSort(int *array, int left, int right);

private:
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
    *                           PRIVATE                           *
    \* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
    *                           HEAPSORT                           *
    \* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    static void heapify(int *array, int i, int right);
    static int getNbSons(int currentId, int right);
    static int maxSons(int *array, int currentId, int nbSons);
    static void init(int *array, int left, int right);
    static void startHeapSort(int *array, int left, int right);

};

#endif // HEAPSORT_H
