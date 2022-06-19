#include "graph.h"

Graph* Graph::instance = nullptr;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                           PUBLIC                            *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * @brief Graph::getInstance
 * @return Either a new instance of a graph if none existe, or the already existing instance
 */
Graph* Graph::getInstance()
{
    if(instance==nullptr)
    {
        instance = new Graph();
    }
    return instance;
}
/**
 * @brief Graph::createChartView
 * @param array, left, right
 * @def Creating the initial view with and creating the chartview
 */
void Graph::createChartView(int *array, int left, int right)
{
    createSet(array, left, right);
    createSeries();
    createChart();
    createYAxis(left, right);
    this->chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}

/**
 * @brief Graph::setSet
 * @param array, left, right
 * @def Used to update the graph, by modifying the set he use to display on the chartview
 */
void Graph::setSet(int *array, int left, int right)
{
    for(int i = left; i < right+1; i++)
    {
    set->replace(i, array[i]);
    }
    chartView->update();
    QCoreApplication::processEvents();
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                           PRIVATE                           *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/**
 * @brief Graph::Graph
 * @def the constructor is private because the class is a Singleton
 */
Graph::Graph()
{

}

/**
 * @brief Graph::createSet
 * @param array, left, right
 * @def Use to initialize the first set to display
 */
void Graph::createSet(int *array, int left, int right)
{
    set = new QBarSet("0-99 data");

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

/**
 * @brief Graph::createYAxis
 * @param left, right
 * @def Create the Axis to put the bargraph on it
 */
void Graph::createYAxis(int left, int right)
{
    axisY = new QValueAxis();
    axisY->setRange(left,right+1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
}




