#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    int array[10];
<<<<<<< HEAD
    SortingAlgorithms::fillArray(array, 0, 9);
    this->graph = Graph::getInstance();
    graph->createChartView(array);
=======
    Utils::fillArray(array, 0,9);
    Utils::shuffleArray(array, 0,9);

    this->graph =getInstance();
    this->graph->createChartView(array);

    SortingAlgorithms *sa = new SortingAlgorithms();
    sa->bogoSort(array, 0,9);

    this->graph->createChartView(array);
>>>>>>> 4b773ed (First commit)
    setCentralWidget(this->graph->chartView);

    //Apparence
    setWindowTitle(tr("The Mouchets"));
    resize(420, 300);

    HeapSort::heapSort(array, 0, 9);
    this->graph->setSet(array);

}

MainWindow::~MainWindow()
{

}

