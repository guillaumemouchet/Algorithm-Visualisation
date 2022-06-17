#ifndef SHELLSORT_H
#define SHELLSORT_H


#include "sortingalgorithms.h"

class ShellSort : public SortingAlgorithms
{
public:
    ShellSort();
    static void shellSort(int *array, int left, int right);

private:
    static QList<int> getStep(int size);
    static void sortArrayByStep(int *array, int left, int right, int step);

};

#endif // SHELLSORT_H
