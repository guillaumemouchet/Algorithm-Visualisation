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

void Graph::setSet(int *array, int left, int right)
{
    for(int i = left; i < right+1; i++)
    {
    set->replace(i, array[i]);
    }
    chartView->update();
    QCoreApplication::processEvents();
}

void Graph::createSet(int *array, int left, int right)
{
    set = new QBarSet("Test");

    for (int i = left; i < right+1; i++) {
        set->append(array[i]);
    }

}

void Graph::createSeries()
{
    series = new QBarSeries();
    series->append(set);
}

void Graph::createChart(QString s)
{
    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(s);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
}

void Graph::createYAxis(int left, int right)
{
    axisY = new QValueAxis();
    axisY->setRange(left,right+1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
}

void Graph::createChartView(int *array, int left, int right)
{
    createSet(array, left, right);
    createSeries();
    createChart();
    createYAxis(left, right);
    this->chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}



