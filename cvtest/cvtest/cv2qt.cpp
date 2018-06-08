#include "cv2qt.h"

cv2qt::cv2qt(QObject *parent)
{

}

QImage cv2qt::ConvertMat2QImage(cv::Mat &srcImage)
{
    switch(srcImage.type()){


    case CV_8UC1 :{      //灰度图
        /* CV_8UC1 */
        QImage conImage(srcImage.data, srcImage.cols, srcImage.rows, srcImage.step,QImage::Format_Indexed8);

        QVector<QRgb> grayVector(256);
        for(int i = 0; i < 256; i++)
        grayVector.replace(i,qRgb(i,i,i));

        conImage.setColorTable(grayVector);
        return conImage.rgbSwapped();
       /* case CV_8UC1 END*/
    }


    case CV_8UC3 : {     //rgb图
    /* case CV_8UC3 */
        QImage conImage(srcImage.data, srcImage.cols, srcImage.rows, srcImage.step,QImage::Format_RGB888);

        return conImage.rgbSwapped();
    /* case CV_8UC3 END*/
    }

    default: return QImage(Q_NULLPTR);
  }
}
