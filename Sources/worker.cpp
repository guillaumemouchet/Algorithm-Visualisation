#include "worker.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                           PUBLIC                            *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

Worker::Worker(int *array, int left, int right)
{
    this->left = left;
    this->right = right;
    this->array = array;
    sa = new SortingAlgorithms;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                           PRIVATE                           *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

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

void Worker::startFusionSort()
{
    sa->fusionSort(array, left, right);
    emit finished(true);
}

void Worker::startHeapSort()
{
    sa->heapSort(array, left, right);
    emit finished(true);
}

void Worker::startTimSort()
{
    sa->timSort(array, left, right);
    emit finished(true);
}

void Worker::startShellSort()
{
    sa->shellSort(array, left, right);
    emit finished(true);
}
