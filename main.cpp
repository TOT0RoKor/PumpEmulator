#include "mainwindow.h"
#include <QApplication>

#include "gaminghandler.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    GamingHandler handler;

    handler.show();

    return a.exec();
}
