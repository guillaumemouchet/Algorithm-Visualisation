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
    Graph(int *array);
    QChartView *chartView;
    void createChartView(int *array);

private:
    void createSet(int *array);
    void createSeries();
    void createChart();
    void createYAxis();


    QBarSet *set;
    QBarSeries * series;
    QChart *chart;
    QValueAxis *axisY;

};

#endif // GRAPH_H
