#ifndef UTILS_H
#define UTILS_H

#include <QtDebug>
#include <QRandomGenerator>
#include <QCoreApplication>
#include <QThread>
#include <QEventLoop>
#include "graph.h"

class Utils
{
public:
    static void swap(int *array, int i, int j);
    static void display(int *array, int left, int right);
    static void fillArray(int *array, int left, int right);
    static void shuffleArray(int *array, int left, int right);
    static void updateGraph(int *array, int left, int right);

};

#endif // UTILS_H
