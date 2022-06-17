#include "timsort.h"

TimSort::TimSort()
{

}

void TimSort::timSort(int *array, int left, int right)
{
    int size = right-left + 1;
    //Tri des sous tableau de size run
        for (int i = 0; i < size; i += RUN)
            insertionSort(array, i, std::min((i + RUN - 1), (size - 1)));

        // Start merging from size RUN (or 32).
        // It will merge
        // to form size 64, then 128, 256
        // and so on ....
        for (int subSize = RUN; subSize < size; subSize = 2 * subSize)
        {

            // pick starting point of
            // left sub array. We
            // are going to merge
            // arr[left..left+size-1]
            // and arr[left+size, left+2*size-1]
            // After every merge, we
            // increase left by 2*size
            for (int left = 0; left < size; left += 2 * subSize)
            {

                // find ending point of
                // left sub array
                // mid+1 is starting point
                // of right sub array
                int mid = left + subSize - 1;
                int right = std::min((left + 2 * subSize - 1), (size - 1));

                // merge sub array arr[left.....mid] &
                // arr[mid+1....right]
                if (mid < right)
                    merge(array, left, mid, right);
            }
        }
}

void TimSort::insertionSort(int *array, int left, int right)
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
        }
        array[j + 1] = temp;
    }
}

void TimSort::merge(int *array, int l, int m, int r)
{

    int len1 = m - l + 1;
    int len2 = r - m;
    int left[len1];
    int right[len2];
    int i;
    int j;
    for (i = 0; i < len1; i++)
        left[i] = array[l+ i];
    for (j = 0; j < len2; j++)
        right[j] = array[m+ 1 + j];

    i = 0;
    j = 0;
    int k = l;

    // After comparing, we
    // merge those two array
    // in larger sub array
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left, if any
    while (i < len1)
    {
        array[k] = left[i];
        k++;
        i++;
    }

    // Copy remaining element of right, if any
    while (j < len2)
    {
        array[k] = right[j];
        k++;
        j++;
    }
}

