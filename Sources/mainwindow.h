#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>
#include <unistd.h>
#include <QPushButton>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>

#include "utils.h"
#include "worker.h"

#include "sortingalgorithms.h"
#include "graph.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    void createActions();
    void createToolBars();


    QAction *actInsertion, *actBogo, *actFusion, *actHeap, *actTim, *actShell, *actShuffle;

    Graph *graph;
    SortingAlgorithms *sa;

    // All the instances of sorts use the same array, so it has the same start and end index
    int left;
    int right;
    int *array;

//Slots are used to help the display and know when a sort has started or ended
public slots:
    void threadDone(bool success);
    void shuffleArray();
    void createInsertionWorker();
    void createBogoWorker();
    void createFusionWorker();
    void createHeapWorker();
    void createTimWorker();
    void createShellWorker();



};
#endif // MAINWINDOW_H
