#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "sortingalgorithms.h"
#include "utils.h"

/**
 * @brief The HeapSort class
 * @def The Sorts class are static, no constructors are needed
 */
class HeapSort
{
public:
    static void heapSort(int *array, int left, int right);

private:
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
    *                           PRIVATE                            *
    \* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    static void heapify(int *array, int i, int right);
    static int getNbSons(int currentId, int right);
    static int maxSons(int *array, int currentId, int nbSons);
    static void init(int *array, int left, int right);
    static void startHeapSort(int *array, int left, int right);

};

#endif // HEAPSORT_H
