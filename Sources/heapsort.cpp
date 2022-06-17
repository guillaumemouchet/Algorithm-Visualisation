#include "heapsort.h"

HeapSort::HeapSort()
{

}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                           PUBLIC                            *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/**
 * @brief HeapSort taken from the first semster
 * @param array
 * @param left
 * @param right
 */
void HeapSort::heapSort(int *array, int left, int right)
{
    init(array, left, right);
    startHeapSort(array, left, right);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                           PRIVATE                           *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void HeapSort::init(int *array, int left, int right)
{
    for(int i = (right-left+1)/2; i >= 1; i--)
    {
        heapify(array, i, right);
    }
}

void HeapSort::heapify(int *array, int i, int right)
{
    int root = i;
    bool isMaximied = false;
    int nbrSons = getNbSons(i, right);
    while (nbrSons > 0 && isMaximied == false)
    {
        int maxSon = maxSons(array, root, nbrSons);
        if (array[maxSon] > array[root])
        {
            Utils::swap(array, maxSon, root);
            root = maxSon;
            nbrSons = getNbSons(maxSon, right);
        }
        else
        {
            isMaximied = true;
        }
    }
}

int HeapSort::maxSons(int *array, int currentId, int nbrOfSons)
{
    int leftSon = currentId * 2;
    int rightSon = currentId * 2 + 1;
    if (nbrOfSons == 1)
    {

        return leftSon;
    }
    else if (nbrOfSons == 2)
    {
        if (array[leftSon] >= array[rightSon])
        {

            return leftSon;

        }
        else
        {

            return rightSon;
        }
    }
    else
    {
        qDebug() << "Wrong amount of sons";
        return -1;
    }
}

void HeapSort::startHeapSort(int *array, int left, int right)
{
    int j = right;
    while (j > left)
    {
        Utils::swap(array, left, j);
        j--;
        heapify(array, left, j);
    }

}

int HeapSort::getNbSons(int currentId, int right)
{
    int leftSon = currentId * 2;
    int rightSon = currentId * 2 + 1;
    int nbrSons = 0;

    if (leftSon <= right)
    {
        nbrSons++;
    }
    if (rightSon <= right)
    {
        nbrSons++;
    }
    return nbrSons;
}
