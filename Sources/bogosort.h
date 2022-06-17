#ifndef BOGOSORT_H
#define BOGOSORT_H

#include <time.h>
#include "utils.h"

class BogoSort
{
public:
    BogoSort();
    static void bogoSort(int *array, int left, int right);

private:
    static bool isSorted(int *array, int left, int right);
    static void shuffleBogo(int *array, int left, int right);

};

#endif // BOGOSORT_H
