#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "function.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_xmin_slider_valueChanged(int value);

    void on_xmax_slider_valueChanged(int value);

    void on_funcSelector_activated(const QString &arg1);

    void on_xmin_edit_valueChanged(double arg1);

    void on_xmax_edit_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
