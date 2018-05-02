#include <string>

#include "mainwindow.h"
#include "ui_mainwindow.h"

void plot(std::string funcName, double xmin, double xmax);

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
    /*plot(ui->funcSelector->itemText(ui->funcSelector->currentIndex()).toStdString(),
         ui->xmin->value(),
         ui->xmax->value());*/
    ui->lineEdit->setText(QString::fromStdString(std::to_string(ui->xmin->value()) +
                                                 " - " +
                                                 std::to_string(ui->xmax->value())));
}

void MainWindow::on_xmin_valueChanged(int value)
{
    ui->xminLabel->setText(QString::fromStdString("from: " + std::to_string(value)));
}

void MainWindow::on_xmax_valueChanged(int value)
{
    ui->xmaxLabel->setText(QString::fromStdString("to: " + std::to_string(value)));
}
