#include "fusionsort.h"

FusionSort::FusionSort()
{

}

void FusionSort::fusionSort(int *array, int *emptyArray, int left, int right)
{
    int mid;
    if (left < right){
        //divide the array at mid and sort independently using merge sort
        mid=(left+right)/2;
        fusionSort(array,emptyArray,left,mid);
        fusionSort(array,emptyArray,mid+1,right);
        //merge or conquer sorted arrays
        merge(array,emptyArray, left ,mid, right);
    }
}

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
        }
        else
        {
            emptyArray[k] = array[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        emptyArray[k] = array[i];
        k++;
        i++;
    }
    while (j <= right)
    {
        emptyArray[k] = array[j];
        k++;
        j++;
    }
    for (i = left; i < k; i++)  {
        array[i] = emptyArray[i];
    }
}
