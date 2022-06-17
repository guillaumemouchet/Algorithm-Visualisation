#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    int array[10];
    SortingAlgorithms::fillArray(array, 0, 9);
    this->graph = new Graph(array);
    ShellSort::shellSort(array, 0, 9);
    this->graph->newChartView(array);
    setCentralWidget(this->graph->chartView);
    setWindowTitle(tr("The Mouchets"));
    resize(420, 300);


}

MainWindow::~MainWindow()
{
}

