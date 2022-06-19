#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <QList>
#include <QEventLoop>
#include "utils.h"

/**
 * @brief The ShellSort class
 * @def The Sorts class are static, no constructors are needed

 */
class ShellSort
{
public:
    static void shellSort(int *array, int left, int right);

private:
    static QList<int> getStep(int size);
    static void sortArrayByStep(int *array, int left, int right, int step);

};

#endif // SHELLSORT_H
