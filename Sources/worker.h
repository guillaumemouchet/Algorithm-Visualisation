#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include "sortingalgorithms.h"

class Worker : public QObject
{
    Q_OBJECT
public:
    Worker(int *array, int left, int right);
private:
    SortingAlgorithms *sa;

    int left;
    int right;
    int *array;

public slots:
    void startInsertionSort();
    void startBogoSort();
signals:
    void finished(bool success);
};

#endif // WORKER_H
