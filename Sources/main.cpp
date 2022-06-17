#include "mainwindow.h"
#include "sortingalgorithms.h"
#include "heapsort.h"
#include "shellsort.h"
#include "fusionsort.h"
#include "bogosort.h"
#include "timsort.h"


#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    int array[10];

    Utils::fillArray(array, 0,9);
    Utils::display(array,0,9);

    SortingAlgorithms *sa = new SortingAlgorithms();

    qDebug() << "HeapSort: ";
    sa->timSort(array, 0,9);
    Utils::display(array,0,9);


    return a.exec();
}
