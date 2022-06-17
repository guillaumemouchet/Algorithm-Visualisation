#include "graph.h"

Graph* Graph::instance = nullptr;

Graph* Graph::getInstance()
{
    if(instance==nullptr)
    {
        instance = new Graph();
    }
    return instance;
}

Graph::Graph()
{

}

void Graph::setSet(int *array)
{
    for(int i = 0; i < 10; i++)
    {
    set->replace(i, array[i]);
    }
    chartView->update();
}

void Graph::createSet(int *array)
{
    set = new QBarSet("Test");

    for (int i = 0; i < 10; i++) {
        set->append(array[i]);
    }

}

void Graph::createSeries()
{
    series = new QBarSeries();
    series->append(set);
}

void Graph::createChart()
{
    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple barchart example");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
}

void Graph::createYAxis()
{
    axisY = new QValueAxis();
    axisY->setRange(0,100);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
}

void Graph::createChartView(int *array)
{
    createSet(array);
    createSeries();
    createChart();
    createYAxis();
    this->chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}
