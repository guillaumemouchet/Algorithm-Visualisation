#ifndef BOGOSORT_H
#define BOGOSORT_H

#include <time.h>
#include <QRandomGenerator>
#include "utils.h"

/**
 * @brief The BogoSort class
 * @ref https://www.geeksforgeeks.org/bogosort-permutation-sort/
 * @def The Sorts class are static, no constructors are needed
 */
class BogoSort
{
public:
    static void bogoSort(int *array, int left, int right);

private:
    static bool isSorted(int *array, int left, int right);
    static void shuffleBogo(int *array, int left, int right);

};

#endif // BOGOSORT_H
