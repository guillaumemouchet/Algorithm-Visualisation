#include "worker.h"

Worker::Worker(int *array, int left, int right)
{
    this->left = left;
    this->right = right;
    this->array = array;
    sa = new SortingAlgorithms;
}

void Worker::startInsertionSort()
{
    sa->insertionSort(array, left, right);
    emit finished(true);
}

void Worker::startBogoSort()
{
    sa->bogoSort(array, left, right);
    emit finished(true);
}
