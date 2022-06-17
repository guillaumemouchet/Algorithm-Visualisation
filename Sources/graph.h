#ifndef GRAPH_H
#define GRAPH_H

#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>

class Graph
{
public:
    static Graph *getInstance();

    QChartView *chartView;
    void createChartView(int *array);
    void setSet(int *array);

    Graph(Graph &other) = delete;
    void operator=(const Graph &other) = delete;
private:
    Graph();
    void createSet(int *array);
    void createSeries();
    void createChart();
    void createYAxis();


    QBarSet *set;
    QBarSeries * series;
    QChart *chart;
    QValueAxis *axisY;
    static Graph *instance;

};



#endif // GRAPH_H
