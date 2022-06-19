#include "bogosort.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                           PUBLIC                            *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void BogoSort::bogoSort(int *array, int left, int right)
{
    srand(time(0));

    // While the array is not sorted, we shuffle it until we find the results
    while (!BogoSort::isSorted(array, left, right))
    {
        Utils::updateGraph(array, left, right);
        QThread::msleep(100);
        BogoSort::shuffleBogo(array, left, right);
    }

}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                           PRIVATE                           *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void BogoSort::shuffleBogo(int *array, int left, int right)
{
    int size = right - left + 1;
    for (int i=0; i < size; i++)
    {
        Utils::swap(array, i, rand()%size);
    }
}

bool BogoSort::isSorted(int *array, int left, int right)
{
    int n = right-left+1;
    while ( n-- > 1 )
        if (array[n] < array[n-1])
            return false;
    return true;
}
