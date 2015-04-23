#include <QtGui/QApplication>
#include "mainBoard.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainBoard * w = new mainBoard();
    w->show();
    return a.exec();
}
