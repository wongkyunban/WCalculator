#include "wcalculator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WCalculator w;
    w.show();
    return a.exec();
}
