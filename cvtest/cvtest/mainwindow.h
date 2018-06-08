#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include "filter.h"
#include <iostream>
#include <QDebug>
#include <QRegExp>
#include <QMessageBox>
#include <QFileDialog>
#include <algorithm>
#include <vector>
#include <QVector>
#include <QImage>
#include "qcustomplot.h"
#include <QMap>


namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //virtual void paintEvent();

    std::vector<int> a;
    filter *_myFilter = Q_NULLPTR;
    QImage *_myQImage = Q_NULLPTR;
    QRegExp *_gaussSigma_Exp = Q_NULLPTR;
    QRegExp *_gaussKsize_Exp = Q_NULLPTR;
private slots:

    void on_FilterExecuter_But_clicked();

    void on_InvFilterExecuter_But_clicked();

//    void on_ksize_Slider_sliderMoved(int position);

//    void on_standvariance_Slider_sliderMoved(int position);

    void on_ksize_Slider_valueChanged(int value);

    void on_standvariance_Slider_valueChanged(int value);

//    void on_openimage_action_triggered();

    void on_median_ksize_Slider_valueChanged(int value);

    void on_mean_ksize_Slider_valueChanged(int value);

    void on_ColorOpen_action_triggered();

    void on_GrayOpen_action_triggered();

    void on_histequalizeButton_clicked();

    void on_mor_ksize_Slider_valueChanged(int value);

    void on_morShape_comboBox_currentIndexChanged(const QString &arg1);

    void on_morType_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    struct filterParameter{
        double sigma{0};
        int ksize{0};
    };
    struct morhologyParameter{
        int operationType{0};
        int shape{0};
    };

    filterParameter gausParameter;
    filterParameter medianParameter;
    filterParameter meanParameter;
    morhologyParameter morParameter;

    bool _mySlotPause{0};
    QString _myImageFilename;

    QString _myOpenFilePath;

    QMap<QString,int> mortypeMap;
    QMap<QString,int> morshapeMap;

    void UpdateTheImage();
    void DrawHistogram(cv::Mat histImage);
    QString GetImagePath();

protected:
//    void paintEvent(QPaintEvent *e);
};

#endif // MAINWINDOW_H
