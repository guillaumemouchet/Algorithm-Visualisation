#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include "sortingalgorithms.h"
/**
 * @brief The Worker class used for Threads
 * @ref https://forum.qt.io/topic/74958/gui-freeze-in-loop/7
 */
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
    void startFusionSort();
    void startHeapSort();
    void startTimSort();
    void startShellSort();

signals:
    void finished(bool success);
};

#endif // WORKER_H
