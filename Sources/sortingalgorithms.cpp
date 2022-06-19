#include "sortingalgorithms.h"


SortingAlgorithms::SortingAlgorithms()
{


}

void SortingAlgorithms::bogoSort(int *array, int left, int right)
{
    BogoSort::bogoSort(array,left, right);
}
void SortingAlgorithms::fusionSort(int *array, int left, int right)
{
    int EmptyArray[right+1];
    FusionSort::fusionSort(array,EmptyArray,left,right);
}
void SortingAlgorithms::heapSort(int *array, int left, int right)
{
    HeapSort::heapSort(array,left+1, right);
}
void SortingAlgorithms::shellSort(int *array, int left, int right)
{
    ShellSort::shellSort(array,left, right);
}
void SortingAlgorithms::timSort(int *array, int left, int right)
{
    TimSort::timSort(array,left, right);
}
void SortingAlgorithms::insertionSort(int *array, int left, int right)
{
    InsertionSort::insertionSort(array, left, right);
}



