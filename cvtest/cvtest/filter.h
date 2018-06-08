#ifndef FILTER_H
#define FILTER_H

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <QDebug>
#include <vector>
#include <QTextCodec>
#include <QVector>
#include "cv2qt.h"

class filter : public QObject, public cv2qt
{
    Q_OBJECT
public:
    filter(const cv::String &file_path, cv::ImreadModes flags = cv::IMREAD_COLOR, QObject *parent = nullptr);
    //filter(const QString &file_path, cv::ImreadModes flags = cv::IMREAD_COLOR, QObject *parent = nullptr);
    cv::Mat getSrcImagecvMat();
    cv::Mat getDstImagecvMat();
private:
    cv::Mat _srcimagecvMat;
    cv::Mat _dstimagecvMat;

public:

    void executeGaussianFilter(uint8_t ksize,double sigma);
    void executeMedianFilter(uint8_t ksize);
    void executeMeanFilter(uint8_t ksize);
    void executeHoughTrans(cv::Mat srcimage);
    void executeCalcuHistogram(QVector<double> &dstvector);
    void executeHistogramEqualization();
    void executeMorhology(int optype, int shape, int ksize);
    void executeSrc2Gray();
signals:
    void SrcHasFiltered();
};

#endif // FILTER_H
