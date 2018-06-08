#include "filter.h"





filter::filter(const cv::String &file_path, cv::ImreadModes flags, QObject *parent):
    QObject(parent),
    _srcimagecvMat(cv::imread(file_path,flags))
{

//    qDebug()<<_srcimagecvMat.depth();
//    qDebug()<<_srcimagecvMat.type();
//    qDebug()<<_srcimagecvMat.channels();
//    _srcimage = cv::imread(file_path,flags);
//    QString temp = file_path;
//    qDebug()<<temp;
//    cv::namedWindow("MyImage");
//    cv::imshow("MyImage",_srcimage);
}

cv::Mat filter::getSrcImagecvMat()
{
    return _srcimagecvMat;
}

cv::Mat filter::getDstImagecvMat()
{
    return _dstimagecvMat;
}

void filter::executeGaussianFilter(uint8_t ksize,double sigma)
{
    qDebug()<<"gaussianfilter"<<ksize<<sigma;
    cv::GaussianBlur(_srcimagecvMat,_dstimagecvMat,cv::Size(ksize,ksize),sigma);
    emit SrcHasFiltered();
}

void filter::executeMedianFilter(uint8_t ksize)
{
    qDebug()<<"medianfilter";
    cv::medianBlur(_srcimagecvMat,_dstimagecvMat,ksize);
    emit SrcHasFiltered();
}

void filter::executeMeanFilter(uint8_t ksize)
{
    qDebug()<<"meanfilter";
    cv::blur(_srcimagecvMat,_dstimagecvMat,cv::Size(ksize,ksize));
    emit SrcHasFiltered();
}

void filter::executeHoughTrans(cv::Mat srcimage)
{
//    struct hough_cmp_gt
//    {
//        hough_cmp_gt(const int* _aux) : aux(_aux) {qDebug()<<"constructor"<<_aux;} //初始化列表
//        inline bool operator()(int l1, int l2) const
//        {
//            qDebug()<<"l1:"<<l1<<"l2:"<<l2<<"aux[l1] = "<<aux[l1]<<"aux[l2] = "<<aux[l2];
//            return aux[l1] > aux[l2] || (aux[l1] == aux[l2] && l1 < l2); //降序,并且
//        }
//        const int* aux;
//    };

//    std::vector<int> _softbuff = {1,4,3,2,5};
//    int acc[] = {100,3,20,6,7,23,52};
//    std::sort(_softbuff.begin(),_softbuff.end(),hough_cmp_gt(acc));

//    qDebug()<<"soft"<<_softbuff;
//    qDebug()<<"acc"<<acc;


    cv::Mat src, dst, color_dst;

    cv::blur(srcimage, src, cv::Size(3,3) );
    cv::Canny( src, dst, 50, 50*3, 3 );
    cv::cvtColor( dst, color_dst, cv::COLOR_GRAY2BGR );

    std::vector<cv::Vec2f> lines;
    cv::HoughLines( dst, lines, 1, CV_PI/180, 130 );

    for( size_t i = 0; i < lines.size(); i++ )
    {
         float rho = lines[i][0];
         float theta = lines[i][1];
         double a = cos(theta), b = sin(theta);
         double x0 = a*rho, y0 = b*rho;
         cv::Point pt1(cvRound(x0 + 1000*(-b)),
         cvRound(y0 + 1000*(a)));
         cv::Point pt2(cvRound(x0 - 1000*(-b)),
         cvRound(y0 - 1000*(a)));
         cv::line( color_dst, pt1, pt2, cv::Scalar(0,0,255), 3, 8 ); //scalar is color matrix
    }

    cv::namedWindow( "Detected Lines", 1 );
    cv::imshow( "Detected Lines", color_dst );
}

void filter::executeCalcuHistogram(QVector<double> &dstvector)
{

    for(int x = 0;x<_srcimagecvMat.rows;x++)
    {
        uchar *data = _srcimagecvMat.ptr<uchar>(x);
        for(int y = 0;y<_srcimagecvMat.cols;y++)
        {
            dstvector[data[y]]++;
        }
    }
}

void filter::executeHistogramEqualization()
{
    cv::Mat tempmat;
    if(_srcimagecvMat.type() != CV_8UC1){
       cv::cvtColor(_srcimagecvMat,tempmat,CV_RGB2GRAY);
    }
    else{
        tempmat = _srcimagecvMat;
    }

    cv::equalizeHist(tempmat,_dstimagecvMat);
    emit SrcHasFiltered();
}

void filter::executeMorhology(int optype,int shape,int ksize)
{
    cv::Mat element = cv::getStructuringElement(shape,cv::Size(ksize,ksize));

    cv::morphologyEx(_srcimagecvMat,_dstimagecvMat,optype,element);


//    cv::erode(_srcimagecvMat,_dstimagecvMat,element);

    emit SrcHasFiltered();
}

void filter::executeSrc2Gray()
{
    qDebug()<<"Src2Gry";
    if(_srcimagecvMat.type() != CV_8UC1){
        cv::cvtColor(_srcimagecvMat,_dstimagecvMat,CV_RGB2GRAY);
    }

    emit SrcHasFiltered();
}








