#ifndef GRAPH_H
#define GRAPH_H

#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>
#include <QCoreApplication>

class Graph
{
public:
    static Graph *getInstance();

    QChartView *chartView;
    void createChartView(int *array, int left, int right);
    void setSet(int *array, int left, int right);

    Graph(Graph &other) = delete;
    void operator=(const Graph &other) = delete;
private:
    Graph();
    void createSet(int *array, int left, int right);
    void createSeries();
    void createChart(QString s = "Sorting visualisation");
    void createYAxis(int left, int right);

    QBarSet *set;
    QBarSeries * series;
    QChart *chart;
    QValueAxis *axisY;
    static Graph *instance;

};



#endif // GRAPH_H
