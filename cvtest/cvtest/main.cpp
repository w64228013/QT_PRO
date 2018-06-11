#include "mainwindow.h"
#include <QApplication>




#include <QDebug>







int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*for deployment ,we need add other libpath*/
    a.addLibraryPath("D:/opencv/cv_build/install/x86/mingw/bin/");
    foreach (const QString &path, a.libraryPaths())
          qDebug()<<path;

    MainWindow w;
    w.show();



















    return a.exec();
}
