#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include <QVector>
#include <QDebug>
#include <QRandomGenerator>

class SortingAlgorithms
{

public:
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
    *                           PUBLIC                            *
    \* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    SortingAlgorithms();

    static void display(int *array, int left, int right);
    static void heapSort(int *array, int left, int right);
    static void fillArray(int *array, int left, int right);

protected:
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
    *                           PROTECTED                           *
    \* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    static void swap(int *array, int i, int j);
    static void shuffleArray(int *array, int left, int right);



};

#endif // SORTINGALGORITHMS_H
