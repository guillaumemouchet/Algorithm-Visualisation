#include "mainwindow.h"
#include "sortingalgorithms.h"
#include "heapsort.h"
#include "shellsort.h"
#include "fusionsort.h"
#include "bogosort.h"
#include "timsort.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*int array[10];
    qDebug() << "HeapSort: ";
    HeapSort::fillArray(array, 0, 9);
    SortingAlgorithms::display(array, 1, 9);
    HeapSort::heapSort(array, 1, 9);
    SortingAlgorithms::display(array, 1, 9);
    qDebug() << "ShellSort";
    ShellSort::fillArray(array, 0, 9);
    SortingAlgorithms::display(array, 0, 9);
    ShellSort::shellSort(array, 0, 9);
    SortingAlgorithms::display(array, 0, 9);
    qDebug()<<"merge sort";
    int emptyArray[10];
    FusionSort::fillArray(array, 0, 9);
    SortingAlgorithms::display(array, 0, 9);
    FusionSort::fusionSort(array, emptyArray,0, 9);
    SortingAlgorithms::display(array, 0, 9);

    qDebug()<<"bogo sort";
    SortingAlgorithms::fillArray(array, 0, 9);
    SortingAlgorithms::display(array, 0, 9);
    BogoSort::bogoSort(array, 0, 9);
    SortingAlgorithms::display(array, 0, 9);

    qDebug()<<"Tim sort";
    SortingAlgorithms::fillArray(array, 0, 9);
    SortingAlgorithms::display(array, 0, 9);
    TimSort::timSort(array, 0, 9);
    SortingAlgorithms::display(array, 0, 9);*/




    return a.exec();
}
