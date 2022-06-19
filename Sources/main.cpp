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

    return a.exec();
}
