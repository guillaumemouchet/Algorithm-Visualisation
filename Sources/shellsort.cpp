#include "shellsort.h"

ShellSort::ShellSort()
{

}

void ShellSort::shellSort(int *array, int left, int right)
{
    int size = right - left + 1;
    QList<int> steps = getStep(size);

    for (int k = 0; k < steps.size(); k++)
        sortArrayByStep(array, left, right, steps.at(k));
}

QList<int> ShellSort::getStep(int size)
{
    int pasMax = ceil(size / 9.0);
    QList<int> array;

    int startPas = 1;
    int currentPas = 1;
    int k = 1;
    array.push_front(startPas);

    while (currentPas < pasMax)
    {
        //currentPas = currentPas * 3 + 1;
        currentPas = pow(4,k)+3*pow(2,k-1)+1;
        array.push_front(currentPas);
    }

    return array;
}

void ShellSort::sortArrayByStep(int *array, int left, int right, int step)
{
    for (int k = left; k < left + step; k++)
    {
        int length = 1;

        while (k + length * step <= right)
            length++;

        for (int j = k; j <= right; j += step)
        {
            int value = array[j];
            int l =  j - step;

            while (l >= 0 && array[l] > value)
            {
                array[l + step] = array[l];
                l -= step;
            }

            array[l + step] = value;
        }
    }
}


