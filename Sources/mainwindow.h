#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>
#include <unistd.h>

#include "sortingalgorithms.h"
#include "shellsort.h"
#include "heapsort.h"
#include "fusionsort.h"
#include "timsort.h"
#include "bogosort.h"
#include "graph.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    QMdiArea *mdiArea;
    Graph *graph;

};
#endif // MAINWINDOW_H
