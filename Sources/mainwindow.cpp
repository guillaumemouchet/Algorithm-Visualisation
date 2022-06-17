#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    int array[10];
    SortingAlgorithms::fillArray(array, 0, 9);
    this->graph = Graph::getInstance();
    graph->createChartView(array);
    setCentralWidget(this->graph->chartView);
    setWindowTitle(tr("The Mouchets"));
    resize(420, 300);

    HeapSort::heapSort(array, 0, 9);
    this->graph->setSet(array);

}

MainWindow::~MainWindow()
{
}

