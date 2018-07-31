#include "mainwindow.h"
#include <QApplication>

#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QCommandLineParser commandLineParser;
    commandLineParser.addHelpOption();
    commandLineParser.process(QCoreApplication::arguments());

    if (!commandLineParser.positionalArguments().isEmpty()) {
        return -1;
    }

    MainWindow w;
    w.show();

    return a.exec();
}
