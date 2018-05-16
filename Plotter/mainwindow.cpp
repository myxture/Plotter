#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

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

void MainWindow::on_xmin_slider_valueChanged(int value)
{
    if(ui->xmin_slider->value() > ui->xmax_slider->value())
        ui->xmin_slider->setValue(value = ui->xmax_slider->value());
    double tmp;
    ui->xmin_edit->setValue(value + std::modf(ui->xmin_edit->value(), &tmp));
}

void MainWindow::on_xmax_slider_valueChanged(int value)
{
    if(ui->xmax_slider->value() < ui->xmin_slider->value())
        ui->xmax_slider->setValue(value = ui->xmin_slider->value());
    double tmp;
    ui->xmax_edit->setValue(value + std::modf(ui->xmax_edit->value(), &tmp));
}

void MainWindow::on_xmin_edit_valueChanged(double arg1)
{
    if(ui->xmin_slider->minimum() <= arg1 && arg1 <= ui->xmin_slider->maximum())
        ui->xmin_slider->setValue(arg1);
    else
    {
        double range = std::fabs(arg1 * ui->xmin_slider->maximum() / ui->xmin_slider->value());
        ui->xmin_slider->setMaximum( range);
        ui->xmin_slider->setMinimum(-range);
        ui->xmin_slider->setValue(arg1);
    }
    plot(ui->xmin_slider->value(),
         ui->xmax_slider->value(),
         ui->funcSelector->itemText(ui->funcSelector->currentIndex()).toStdString(),
         ui->customPlot);
}

void MainWindow::on_xmax_edit_valueChanged(double arg1)
{
    if(ui->xmax_slider->minimum() <= arg1 && arg1 <= ui->xmax_slider->maximum())
        ui->xmax_slider->setValue(arg1);
    else
    {
        double range = std::fabs(arg1 * ui->xmax_slider->maximum() / ui->xmax_slider->value());
        ui->xmax_slider->setMaximum( range);
        ui->xmax_slider->setMinimum(-range);
        ui->xmax_slider->setValue(arg1);
    }
    plot(ui->xmin_slider->value(),
         ui->xmax_slider->value(),
         ui->funcSelector->itemText(ui->funcSelector->currentIndex()).toStdString(),
         ui->customPlot);
}

void MainWindow::on_funcSelector_activated(const QString &arg1)
{
    if(arg1.compare("sin" ) == 0 ||
       arg1.compare("cos" ) == 0 ||
       arg1.compare("tan" ) == 0)
    {
        ui->xmin_edit->setSuffix("°");
        ui->xmax_edit->setSuffix("°");
    }
    else
    {
        ui->xmin_edit->setSuffix("");
        ui->xmax_edit->setSuffix("");
    }
    plot(ui->xmin_slider->value(),
         ui->xmax_slider->value(),
         ui->funcSelector->itemText(ui->funcSelector->currentIndex()).toStdString(),
         ui->customPlot);
}

void plot(double xmin_slider, double xmax_slider, std::string funcName, QCustomPlot *sheet)
{
    if(funcName.compare("Choose function") == 0)
        return;
    f func = plot_functions[funcName];
    auto x = xs(xmin_slider, xmax_slider);
    auto y = func(x);
    for(int i = 1; i < y.size(); ++i) {
        if(std::abs(y[i] / y[i - 1]) > 1000) {
            x[i] = x.back();
            x.pop_back();
            y[i] = y.back();
            y.pop_back();
        }
    }

    auto Qx = QVector<double>::fromStdVector(x);
    auto Qy = QVector<double>::fromStdVector(y);

    sheet->addGraph();
    sheet->graph(0)->setData(Qx, Qy);

    sheet->xAxis->setLabel("x");

    if((funcName.compare("1/x") == 0) || (funcName.compare("x^2") == 0))
        sheet->yAxis->setLabel(QString::fromStdString(funcName));
    else
        sheet->yAxis->setLabel(QString::fromStdString(funcName + "(x)"));

    auto xRange = std::minmax_element(x.begin(), x.end());
    sheet->xAxis->setRange(x[xRange.first - x.begin()], x[xRange.second - x.begin()]);
    auto yRange = std::minmax_element(y.begin(), y.end());
    sheet->yAxis->setRange(y[yRange.first - y.begin()], y[yRange.second - y.begin()]);
    sheet->replot();
}
