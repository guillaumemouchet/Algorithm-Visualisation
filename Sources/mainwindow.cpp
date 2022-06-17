#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    int array[10];
    Utils::fillArray(array, 0,9);
    Utils::shuffleArray(array, 0,9);

    this->graph =getInstance();
    this->graph->createChartView(array);

    SortingAlgorithms *sa = new SortingAlgorithms();
    sa->bogoSort(array, 0,9);

    this->graph->createChartView(array);
    setCentralWidget(this->graph->chartView);

    //Apparence
    setWindowTitle(tr("The Mouchets"));
    resize(420, 300);


}

MainWindow::~MainWindow()
{

}

