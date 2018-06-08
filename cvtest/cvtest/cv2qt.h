#ifndef CV2QT_H
#define CV2QT_H

#include <QObject>
#include <QImage>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <QImage>
#include <QVector>

/*
 * Mat.depth() 返回枚举值
 * enum{
 *       CV_8U=0,
 *       CV_8S=1,
 *       CV_16U=2,
 *       CV_16S=3,
 *       CV_32S=4,
 *       CV_32F=5,
 *       CV_64F=6
 * }
 *
 *
 *
 *
 *
 *
 */






class cv2qt
{

public:
    explicit cv2qt(QObject *parent = nullptr);

signals:

public slots:

public:
    QImage ConvertMat2QImage(cv::Mat &srcImage);




private:

};

#endif // CV2QT_H
