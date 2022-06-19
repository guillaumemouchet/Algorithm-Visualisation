#include "fusionsort.h"
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                           PUBLIC                            *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void FusionSort::fusionSort(int *array, int *emptyArray, int left, int right)
{
    int mid;
    if (left < right){
        //find the middle of the array and sort both halfs independently with a merge sort
        mid=(left+right)/2;
        fusionSort(array,emptyArray,left,mid);
        fusionSort(array,emptyArray,mid+1,right);
        //merge or conquer sorted arrays
        merge(array,emptyArray, left ,mid, right);
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                           PRIVATE                           *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void FusionSort::merge(int *array, int *emptyArray, int left, int mid, int right)
{
    int i, j, k;
    i = left;
    k = left;
    j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (array[i] < array[j])
        {
            emptyArray[k] = array[i];
            k++;
            i++;
            Utils::updateGraph(array, left, right);
            QThread::msleep(75);
        }
        else
        {
            emptyArray[k] = array[j];
            k++;
            j++;
            Utils::updateGraph(array, left, right);
            QThread::msleep(75);
        }
    }
    while (i <= mid)
    {
        emptyArray[k] = array[i];
        k++;
        i++;
        Utils::updateGraph(array, left, right);
        QThread::msleep(75);
    }
    while (j <= right)
    {
        emptyArray[k] = array[j];
        k++;
        j++;
        Utils::updateGraph(array, left, right);
        QThread::msleep(75);
    }
    for (i = left; i < k; i++)  {
        array[i] = emptyArray[i];
        Utils::updateGraph(array, left, right);
        QThread::msleep(75);
    }
}
