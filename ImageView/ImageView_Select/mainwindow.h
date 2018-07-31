#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QStandardPaths>
#include <QPixmap>
#include <QImage>
#include <QScrollArea>
#include <QRegExp>
#include <QRegExpValidator>
#include <QDebug>
#include <QSize>
#include <QIntValidator>
#include <QCursor>
#include <QDateTime>
#include <QIcon>
#include <QFileInfo>

#include "imagereader.h"
#include "myimageview.h"
#include "rectangle.h"
#include "mydiagitem.h"
#include "myscene.h"
#include "myimageview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow,public rectangle
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateROIImage(QRectF rectangle);
    void sendinfo(const QString &arg1);
    void sendstatus(const QString &arg1);
private slots:
    void on_actionOpen_triggered();

    void on_ROIwidthlineEdit_textChanged(const QString &arg1);

    void on_ROIheightlineEdit_textChanged(const QString &arg1);

    void on_SetROIButton_clicked();

    void on_SaveROIButton_clicked();

    void on_actionOpenFolder_triggered();

    void on_actionSetSavePath_triggered();

    void on_ROIPrefixEdit_textChanged(const QString &arg1);

    void on_infoBrowser_customContextMenuRequested(const QPoint &pos);

    void on_ImageView_customContextMenuRequested(const QPoint &pos);

    void on_actionDrag_triggered();

    void on_NextButton_clicked();

    void on_PrevButton_clicked();

    void on_TypeBox_currentIndexChanged(const QString &arg1);

    void on_SetROIButton_released();

    void on_actionZoomOut_triggered();

private:
    Ui::MainWindow *ui;
    myScene *ImageScene = Q_NULLPTR;
    QGraphicsScene *ROIScene = Q_NULLPTR;
    ImageReader *ImReader = Q_NULLPTR;
    QImage *CurrentImage = Q_NULLPTR;
    QPixmap *ROIImage = Q_NULLPTR;
    QRect ROIRec;
    QDir mySearchdir;
    int savecounts{0};

    struct Path
    {
        QString SavePath;
        QString FolderPath;
        QString ImagePath;
        QString ImageName;
        QString ImageSaveName;
        QString ImageType;
        QSize ImageSize;
    }myPath;

    QFileInfo myImage;
    void setROISize(QSize roiSize);

};

#endif // MAINWINDOW_H
