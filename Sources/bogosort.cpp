#include "bogosort.h"

BogoSort::BogoSort()
{

}

void BogoSort::bogoSort(int *array, int left, int right)
{
    srand(time(0));

    // if array is not sorted then shuffle
    // the array again
    while (!BogoSort::isSorted(array, left, right))
    {
        //UPDATE LE CHARTSVIEW --> puis de le repaint
        Utils::updateGraph(array, left, right);
        QThread::msleep(100);
        BogoSort::shuffleBogo(array, left, right);
    }

}

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
