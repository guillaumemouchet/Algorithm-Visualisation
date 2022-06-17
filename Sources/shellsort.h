#ifndef SHELLSORT_H
#define SHELLSORT_H

#include "utils.h"


class ShellSort
{
public:
    ShellSort();
    static void shellSort(int *array, int left, int right);

private:
    static QList<int> getStep(int size);
    static void sortArrayByStep(int *array, int left, int right, int step);

};

#endif // SHELLSORT_H
