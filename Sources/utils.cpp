#include "utils.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                           PUBLIC                            *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Utils::display(int *array, int left, int right)
{
    qDebug() << "[";
    for (int i = left; i < right + 1; i++)
    {
        qDebug() << array[i];
        if (i != right)
        {
            qDebug() << ", ";
        }
    }
    qDebug() << "]";
}


void Utils::fillArray(int *array, int left, int right)
{
    int size = right - left + 1;
    for(int i = 0; i< size; i++)
    {
        array[i] = i;
    }
    shuffleArray(array, left, right);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                           Protected                           *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/**
 * @brief SortingAlgorithms::shuffleArray
 * @param array, left, right
 * @ref https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
 */
void Utils::shuffleArray(int *array, int left, int right)
{
     for(int i = right; i > left; i--)
     {
         quint32 value = QRandomGenerator::global()->bounded(right-1) + 1;
         swap(array, i, value);
     }
}


void Utils::swap(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void Utils::updateGraph(int *array, int left, int right)
{
    Graph::getInstance()->setSet(array, left, right);
}
