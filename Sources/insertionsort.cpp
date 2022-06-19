#include "insertionsort.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                           PUBLIC                            *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/**
 * @brief InsertionSort::insertionSort
 * @param array, left, right
 */
void InsertionSort::insertionSort(int *array, int left, int right)
{
    int temp, i ,j;
    for (i = left + 1; i <= right; i++)
    {
        temp = array[i];
        j = i - 1;
        while (j >= left && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
            Utils::updateGraph(array, left, right);
            QThread::msleep(75);
        }
        array[j + 1] = temp;
        Utils::updateGraph(array, left, right);


    }
}
