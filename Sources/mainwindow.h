#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>
#include <unistd.h>

#include "utils.h"

#include "sortingalgorithms.h"
#include "graph.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Graph *graph;

};
#endif // MAINWINDOW_H
