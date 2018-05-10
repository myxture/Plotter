#include <vector>
#include <map>
#include <string>

#include "mainwindow.h"
#include "plotter.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include "function.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_plotBtn_clicked()
{
    plot(ui->xmin->value(),
         ui->xmax->value(),
         ui->funcSelector->itemText(ui->funcSelector->currentIndex()).toStdString(),
         ui->customPlot);
}

void MainWindow::on_xmin_valueChanged(int value)
{
    ui->xminLabel->setText(QString::fromStdString("from: " + std::to_string(value)));
}

void MainWindow::on_xmax_valueChanged(int value)
{
    ui->xmaxLabel->setText(QString::fromStdString("to: " + std::to_string(value)));
}

void plot(double xMin, double xMax, std::string funcName, QCustomPlot *sheet)
{
    if(funcName.compare("Choose function") == 0)
        return;
    f func = plot_functions[funcName];
    std::vector<double> x = xs(xMin, xMax);
    std::vector<double> y = func(x);
    QVector<double> Qx = QVector<double>::fromStdVector(x);
    QVector<double> Qy = QVector<double>::fromStdVector(y);

    sheet->addGraph();
    sheet->graph(0)->setData(Qx, Qy);

    sheet->xAxis->setLabel("x");
    sheet->yAxis->setLabel(QString::fromStdString(funcName + "(x)"));

    sheet->xAxis->setRange(xMin, xMax);
    sheet->yAxis->setRange(-1, 1);
    sheet->replot();
}
