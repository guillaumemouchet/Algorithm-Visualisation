#include "mainwindow.h"
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                           PUBLIC                            *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //initializing the array and the sortingAlgorithms class
    left = 0;
    right = 99;
    array = new int[right-left+1];
    sa = new SortingAlgorithms();
    Utils::fillArray(array, left, right);

    createActions();
    createToolBars();

    //Creating the worker so they can call their respective start methode with threads
    //They are precreated so when the action are triggered it is called directly
    createInsertionWorker();
    createBogoWorker();
    createFusionWorker();
    createShellWorker();
    createHeapWorker();
    createTimWorker();

    statusBar()->showMessage(tr("Lancer un tri"));

    //since the graph is a singleton we need to get his instance
    this->graph = Graph::getInstance();
    this->graph->createChartView(array, left, right);

    //the chart view is the central widget, he will get updated during the sorts
    setCentralWidget(this->graph->chartView);

    //Apparence
    setWindowTitle(tr("The Mouchets"));
    resize(600, 450);

}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                           PRIVATE                           *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void MainWindow::createActions()
{
    actInsertion = new QAction(tr("&Insertion Sort"), this);
    actInsertion->setShortcut(tr("Ctrl+1"));
    actInsertion->setStatusTip(tr("Start Sorting"));
    connect(actInsertion, &QAction::triggered, this, &MainWindow::createInsertionWorker);

    actShell = new QAction(tr("&Shell Sort"), this);
    actShell->setShortcut(tr("Ctrl+2"));
    actShell->setStatusTip(tr("Start Sorting"));
    connect(actShell, &QAction::triggered, this, &MainWindow::createShellWorker);

    actFusion = new QAction(tr("&Fusion Sort"), this);
    actFusion->setShortcut(tr("Ctrl+3"));
    actFusion->setStatusTip(tr("Start Sorting"));
    connect(actFusion, &QAction::triggered, this, &MainWindow::createFusionWorker);

    actHeap = new QAction(tr("&Heap Sort"), this);
    actHeap->setShortcut(tr("Ctrl+4"));
    actHeap->setStatusTip(tr("Start Sorting"));
    connect(actHeap, &QAction::triggered, this, &MainWindow::createHeapWorker);

    actTim = new QAction(tr("&Tim Sort"), this);
    actTim->setShortcut(tr("Ctrl+5"));
    actTim->setStatusTip(tr("Start Sorting"));
    connect(actTim, &QAction::triggered, this, &MainWindow::createTimWorker);

    actBogo = new QAction(tr("&Bogo Sort"), this);
    actBogo->setShortcut(tr("Ctrl+6"));
    actBogo->setStatusTip(tr("Start Sorting"));
    connect(actBogo, &QAction::triggered, this, &MainWindow::createBogoWorker);

    actShuffle = new QAction(tr("&Shuffle"), this);
    actShuffle->setShortcut(tr("Ctrl+O"));
    actShuffle->setStatusTip(tr("Shuffles array"));
    connect(actShuffle, &QAction::triggered, this, &MainWindow::shuffleArray);
}

void MainWindow::createToolBars()
{
    QToolBar* toolBar = addToolBar(tr("Principale"));
    toolBar->addAction(actInsertion);
    toolBar->addAction(actShell);
    toolBar->addAction(actFusion);
    toolBar->addAction(actHeap);
    toolBar->addAction(actTim);
    toolBar->addAction(actBogo);

    toolBar->addSeparator();
    toolBar->addAction(actShuffle);
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                            SLOTS                            *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void MainWindow::threadDone(bool success)
{
    qDebug() << success;
}

void MainWindow::shuffleArray()
{
    Utils::shuffleArray(array, left, right);
    graph->setSet(array, left, right);
}


/**
 * @brief MainWindow::createWorkers
 * @def each worker are created once so they are already connected, so when the user click on the Action the sort is directly displaying
 */


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

void MainWindow::createFusionWorker()
{
    Worker *worker = new Worker(array, left, right);
    QThread *thread = new QThread();

    worker->moveToThread(thread);

    connect(actFusion, &QAction::triggered, worker, &Worker::startFusionSort);
    connect(worker, &Worker::finished, this, &MainWindow::threadDone);

    connect(worker, &Worker::finished, thread, &QThread::quit);
    connect(worker, &Worker::finished, worker, &Worker::deleteLater);
    connect(worker, &Worker::finished, thread, &QThread::deleteLater);

    thread->start();
}

void MainWindow::createHeapWorker()
{
    Worker *worker = new Worker(array, left, right);
    QThread *thread = new QThread();

    worker->moveToThread(thread);

    connect(actHeap, &QAction::triggered, worker, &Worker::startHeapSort);
    connect(worker, &Worker::finished, this, &MainWindow::threadDone);

    connect(worker, &Worker::finished, thread, &QThread::quit);
    connect(worker, &Worker::finished, worker, &Worker::deleteLater);
    connect(worker, &Worker::finished, thread, &QThread::deleteLater);

    thread->start();
}

void MainWindow::createTimWorker()
{
    Worker *worker = new Worker(array, left, right);
    QThread *thread = new QThread();

    worker->moveToThread(thread);

    connect(actTim, &QAction::triggered, worker, &Worker::startTimSort);
    connect(worker, &Worker::finished, this, &MainWindow::threadDone);

    connect(worker, &Worker::finished, thread, &QThread::quit);
    connect(worker, &Worker::finished, worker, &Worker::deleteLater);
    connect(worker, &Worker::finished, thread, &QThread::deleteLater);

    thread->start();
}

void MainWindow::createShellWorker()
{
    Worker *worker = new Worker(this->array, this->left, this->right);
    QThread *thread = new QThread();

    worker->moveToThread(thread);

    connect(actShell, &QAction::triggered, worker, &Worker::startShellSort);
    connect(worker, &Worker::finished, this, &MainWindow::threadDone);

    connect(worker, &Worker::finished, thread, &QThread::quit);
    connect(worker, &Worker::finished, worker, &Worker::deleteLater);
    connect(worker, &Worker::finished, thread, &QThread::deleteLater);

    thread->start();
}

MainWindow::~MainWindow()
{

}

