#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    left = 0;
    right = 99;
    array = new int[right-left+1];
    sa = new SortingAlgorithms();
    createActions();
    createMenus();
    createToolBars();
    createInsertionWorker();
    createBogoWorker();
    statusBar()->showMessage(tr("Lancer un tri"));
    Utils::fillArray(array, left, right);



    this->graph = Graph::getInstance();
    this->graph->createChartView(array, left, right);




    setCentralWidget(this->graph->chartView);

    //Apparence
    setWindowTitle(tr("The Mouchets"));
    resize(420, 300);

}

void MainWindow::createActions()
{
    actInsertion = new QAction(tr("&Insertion Sort"), this);
    actInsertion->setShortcut(tr("Ctrl+1"));
    actInsertion->setStatusTip(tr("Démarrer le tri"));
    connect(actInsertion, &QAction::triggered, this, &MainWindow::createInsertionWorker);


    actBogo = new QAction(tr("&Bogo Sort"), this);
    actBogo->setShortcut(tr("Ctrl+2"));
    actBogo->setStatusTip(tr("Démarrer le tri"));
    connect(actBogo, &QAction::triggered, this, &MainWindow::createBogoWorker);


    actShuffle = new QAction(tr("&Shuffle"), this);
    actShuffle->setShortcut(tr("Ctrl+O"));
    actShuffle->setStatusTip(tr("Shuffles array"));
    connect(actShuffle, &QAction::triggered, this, &MainWindow::shuffleArray);
}

void MainWindow::createMenus()
{
    /*QMenu* fileMenu = menuBar()->addMenu(tr("&Commencer algo"));
    fileMenu->addAction(actInsertion);
    fileMenu->addAction(actShuffle);*/

}

void MainWindow::createToolBars()
{
    QToolBar* toolBar = addToolBar(tr("Principale"));
    toolBar->addAction(actInsertion);
    toolBar->addAction(actBogo);
    toolBar->addSeparator();
    toolBar->addAction(actShuffle);
}

void MainWindow::threadDone(bool success)
{

}

void MainWindow::shuffleArray()
{
    Utils::shuffleArray(array, left, right);
    graph->setSet(array, left, right);
}

void MainWindow::createInsertionWorker()
{
    Worker *worker = new Worker(array, left, right);
    QThread *thread = new QThread();

    worker->moveToThread(thread);

    connect(actInsertion, &QAction::triggered, worker, &Worker::startInsertionSort);
    connect(worker, &Worker::finished, this, &MainWindow::threadDone);

    connect(worker, &Worker::finished, thread, &QThread::quit);
    connect(worker, &Worker::finished, worker, &Worker::deleteLater);
    connect(worker, &Worker::finished, thread, &QThread::deleteLater);

    thread->start();
}

void MainWindow::createBogoWorker()
{
    Worker *worker = new Worker(array, left, right);
    QThread *thread = new QThread();

    worker->moveToThread(thread);

    connect(actBogo, &QAction::triggered, worker, &Worker::startBogoSort);
    connect(worker, &Worker::finished, this, &MainWindow::threadDone);

    connect(worker, &Worker::finished, thread, &QThread::quit);
    connect(worker, &Worker::finished, worker, &Worker::deleteLater);
    connect(worker, &Worker::finished, thread, &QThread::deleteLater);

    thread->start();
}
MainWindow::~MainWindow()
{

}

