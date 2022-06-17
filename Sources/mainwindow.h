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
    void createMenus();
    void createToolBars();


    QAction *actInsertion, *actBogo, *actShuffle;
    QMenu *menu;

    Graph *graph;
    SortingAlgorithms *sa;

    int left;
    int right;
    int *array;

public slots:
    void threadDone(bool success);
    void shuffleArray();
    void createInsertionWorker();
    void createBogoWorker();



};
#endif // MAINWINDOW_H
