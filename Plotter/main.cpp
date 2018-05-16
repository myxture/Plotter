#include "qcustomplot.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(530, 330);
    w.show();

    return a.exec();
}
