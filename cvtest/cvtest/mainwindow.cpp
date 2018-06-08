#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "filter.h"

#include "emmintrin.h"

using namespace cv;



Mat src, src_gray;
Mat dst, detected_edges;

int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
char* window_name = "Edge Map";

/**
 * @函数 CannyThreshold
 * @简介： trackbar 交互回调 - Canny阈值输入比例1:3
 */
void CannyThreshold(int, void*)
{
  /// 使用 3x3内核降噪
  blur( src_gray, detected_edges, Size(3,3) );

  /// 运行Canny算子
  Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );

  /// 使用 Canny算子输出边缘作为掩码显示原图像
  dst = Scalar::all(0);

  src_gray.copyTo( dst, detected_edges);
  //imshow( window_name, dst );
  imshow( window_name, detected_edges );
 }




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Gauss_textBrowser->setAttribute(Qt::WA_TranslucentBackground);
    ui->filter_parentTab->setAttribute(Qt::WA_TranslucentBackground);

    _myQImage = new QImage;
    _gaussSigma_Exp = new QRegExp("[0-100]");
    _gaussKsize_Exp = new QRegExp("[0-51]");

    mortypeMap.insert("膨胀",MorphTypes::MORPH_ERODE);
    mortypeMap.insert("腐蚀",MorphTypes::MORPH_DILATE);
    mortypeMap.insert("开运算",MorphTypes::MORPH_OPEN);
    mortypeMap.insert("闭运算",MorphTypes::MORPH_CLOSE);

    morshapeMap.insert("矩形",MorphShapes::MORPH_RECT);
    morshapeMap.insert("圆形",MorphShapes::MORPH_ELLIPSE);
    morshapeMap.insert("叉形",MorphShapes::MORPH_CROSS);

    morParameter.shape = morshapeMap[ui->morShape_comboBox->currentText()];
    morParameter.operationType = mortypeMap[ui->morType_comboBox->currentText()];

//    cv::Mat tempMat = _myFilter->getSrcImage();
//    QImage image(tempMat.data,tempMat.rows,tempMat.cols,tempMat.step,QImage::Format_RGB888);
//    ui->imageshow_label->setPixmap(QPixmap::fromImage(image.rgbSwapped()));
//    ui->imageshow_label->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_FilterExecuter_But_clicked()
{
    if(_myFilter == Q_NULLPTR)
    {
      QMessageBox::warning(this,"需要一张图片","文件-打开图片(Executer)");
      return;
    }
    int curTabidx;
    QString curFilterMode;
    curTabidx = ui->filter_parentTab->currentIndex();
    curFilterMode = ui->filter_parentTab->tabText(curTabidx);

    if(curFilterMode == "高斯"){
        QString ksizeStr = ui->ksize_lineEdit->text();
        QString sigmaStr = ui->sigma_lineEdit->text();

        ksizeStr = ksizeStr.isEmpty() != true ? ksizeStr : "0";
        sigmaStr = sigmaStr.isEmpty() != true ? sigmaStr : "0";

        int tempksize = ksizeStr.toInt();
        float tempsigma = sigmaStr.toFloat();

        if( ((tempksize|int(tempsigma)) == 0)
                ||(tempsigma<0 || tempsigma >100)
                || (tempksize <0 || tempksize>51)
                || ((tempksize!=0)&&(tempksize % 2 == 0)))
        {
            QMessageBox::warning(this,"输入参数有误","标准差:0~100;\n核大小:0~51,且为奇数;参数不能都为0");
            return;
        }

        gausParameter.ksize = ksizeStr.toInt();
        gausParameter.sigma = sigmaStr.toFloat();

        _mySlotPause = true;
        ui->standvariance_Slider->setValue(gausParameter.sigma * 10);
        ui->ksize_Slider->setValue(gausParameter.ksize);
        _mySlotPause = false;

        _myFilter->executeGaussianFilter(gausParameter.ksize,gausParameter.sigma);
    }
    else if(curFilterMode == "中值"){
        QString ksizeStr = ui->median_ksize_lineEdit->text();
        ksizeStr = ksizeStr.isEmpty() != true ? ksizeStr : "0";
        int tempksize = ksizeStr.toInt();

        if ((tempksize < 0 || tempksize>51)
                ||(tempksize % 2 == 0))
        {
            QMessageBox::warning(this,"输入参数有误","核大小:0~51,且为奇数;参数不能都为0");
            return;
        }
        medianParameter.ksize = tempksize;
        _mySlotPause = true;
        ui->median_ksize_Slider->setValue(medianParameter.ksize);
        _mySlotPause = false;

        _myFilter->executeMedianFilter(medianParameter.ksize);
    }
    else if(curFilterMode == "均值"){
        QString ksizeStr = ui->mean_ksize_lineEdit->text();
        ksizeStr = ksizeStr.isEmpty() != true ? ksizeStr : "0";
        int tempksize = ksizeStr.toInt();

        if ((tempksize < 0 || tempksize>51)
                ||(tempksize % 2 == 0))
        {
            QMessageBox::warning(this,"输入参数有误","核大小:0~51,且为奇数;参数不能都为0");
            return;
        }
        meanParameter.ksize = tempksize;
        _mySlotPause = true;
        ui->mean_ksize_Slider->setValue(meanParameter.ksize);
        _mySlotPause = false;

        _myFilter->executeMeanFilter(meanParameter.ksize);
    }
    else if(curFilterMode == "直方图"){
        qDebug()<<"Histogram";

        _myFilter->executeSrc2Gray();
        Mat tempimage = _myFilter->getDstImagecvMat();
        DrawHistogram(tempimage);
    }
    else if(curFilterMode == "形态学"){

        QString ksizeStr = ui->mor_ksize_lineEdit->text();
        ksizeStr = ksizeStr.isEmpty() != true ? ksizeStr : "0";
        int tempksize = ksizeStr.toInt();

        if ((tempksize < 0 || tempksize>51)
                ||(tempksize % 2 == 0))
        {
            QMessageBox::warning(this,"输入参数有误","核大小:0~51,且为奇数;参数不能都为0");
            return;
        }
        _mySlotPause = true;
        ui->mor_ksize_Slider->setValue(tempksize);
        _mySlotPause = false;

        QString morshape = ui->morShape_comboBox->currentText();
//        if(morshape == "矩形"){
//            morParameter.shape = MorphShapes::MORPH_RECT;
//        }
//        else if(morshape == "圆形"){
//            morParameter.shape = MorphShapes::MORPH_ELLIPSE;
//        }
//        else if(morshape == "叉形"){
//            morParameter.shape = MorphShapes::MORPH_CROSS;
//        }
         morParameter.shape = morshapeMap[morshape];

        QString mortype = ui->morType_comboBox->currentText();
//        if(mortype == "腐蚀"){
//            morParameter.operationType = MorphTypes::MORPH_ERODE;
//        }
//        else if(mortype == "膨胀"){
//            morParameter.operationType = MorphTypes::MORPH_DILATE;
//        }
//        else if(mortype == "开运算"){
//            morParameter.operationType = MorphTypes::MORPH_OPEN;
//        }
//        else if(mortype == "闭运算"){
//            morParameter.operationType = MorphTypes::MORPH_CLOSE;
//        }
        morParameter.operationType = mortypeMap[mortype];
        _myFilter->executeMorhology(morParameter.operationType,morParameter.shape,tempksize);

    }
}

void MainWindow::UpdateTheImage()
{
    qDebug()<<"image update";
    cv::Mat tempMat = _myFilter->getDstImagecvMat();

    ui->imageshow_label->setPixmap(QPixmap::fromImage(_myFilter->ConvertMat2QImage(tempMat)));
}

void MainWindow::DrawHistogram(Mat histImage)
{
    Mat histgram;
    int histsize = 256;
    QVector<double> yaix(256);
    QVector<double> xaix(256);

    float range[] = {0,255};
    const float *ranges = {range};
    const int channel = 1;
//        calcHist(&tempimage,1,0,Mat(),
//                 histgram,1,&histsize,&ranges,true,true);

    for(int x = 0;x<histImage.rows;x++)
    {
        uchar *data = histImage.ptr<uchar>(x);
        for(int y = 0;y<histImage.cols;y++)
        {
            xaix[data[y]]++;
        }
    }

    for(int i = 0;i<256;i++)
        yaix[i] = i;

    QVector<double> tempvector(256);
    tempvector = xaix;
    std::sort(tempvector.begin(),tempvector.end());

    //向绘图区域QCustomPlot(从widget提升来的)添加一条曲线
    ui->HistogramPlot->removeGraph(0);
    ui->HistogramPlot->addGraph();
    //添加数据
//        ui->HistogramPlot->graph(0)->setData(yaix,xaix);

    //设置坐标轴标签名称
    ui->HistogramPlot->xAxis->setLabel("x");
    ui->HistogramPlot->yAxis->setLabel("y");

    //设置坐标轴显示范围,否则我们只能看到默认的范围
    ui->HistogramPlot->xAxis->setRange(-10,300);
    ui->HistogramPlot->yAxis->setRange(0,tempvector[255] + 200);

//        QCPBars *bars = new QCPBars(ui->HistogramPlot->xAxis, ui->HistogramPlot->yAxis);
//        bars->setData(yaix, xaix);
//        bars->setPen(QColor(0, 0, 0));
//        bars->setWidth(0.1);

    ui->HistogramPlot->graph(0)->setData(yaix, xaix);
    ui->HistogramPlot->graph(0)->setPen(QColor(0, 0, 0));

    ui->HistogramPlot->setVisible(true);
    ui->HistogramPlot->replot();
}

QString MainWindow::GetImagePath()
{
    QString temppath = QFileDialog::getOpenFileName(this,"打开文件",_myOpenFilePath,"图片(*.png *.jpg *.bmp)");
    int idx = temppath.lastIndexOf("/");

    _myOpenFilePath = temppath.left(idx);
    return temppath;
}


void MainWindow::on_InvFilterExecuter_But_clicked()
{
    if(_myFilter == Q_NULLPTR)
    {
      QMessageBox::warning(this,"需要一张图片","文件-打开图片(InvExecuter)");
      return;
    }
    cv::Mat tempMat = _myFilter->getSrcImagecvMat();

    ui->imageshow_label->setPixmap(QPixmap::fromImage(_myFilter->ConvertMat2QImage(tempMat)));
}

void MainWindow::on_ksize_Slider_valueChanged(int value)
{
    if(_mySlotPause == true)
        return;
    if(_myFilter == Q_NULLPTR)
    {
      QMessageBox::warning(this,"需要一张图片","文件-打开图片(ksizeslider)");
      return;
    }
    gausParameter.ksize = value << 1;
    gausParameter.ksize = gausParameter.ksize != 0 ? --gausParameter.ksize:gausParameter.ksize;

    ui->ksize_lineEdit->setText(QString::number(gausParameter.ksize));
    if((gausParameter.sigma == 0)&&(gausParameter.ksize == 0))
    {
        QMessageBox::warning(this,"输入参数有误","标准差:0~100;\n核大小:0~51,且为奇数;参数不能都为0");
        return;
    }
    _myFilter->executeGaussianFilter(gausParameter.ksize,gausParameter.sigma);
}

void MainWindow::on_standvariance_Slider_valueChanged(int value)
{
    if(_mySlotPause == true)
        return;
    if(_myFilter == Q_NULLPTR)
    {
      QMessageBox::warning(this,"需要一张图片","文件-打开图片(standvarianceSlider)");
      //ui->standvariance_Slider->setSliderPosition(0);
      return;
    }
    gausParameter.sigma = float(value)/10;
    ui->sigma_lineEdit->setText(QString::number(gausParameter.sigma));

    if((gausParameter.sigma == 0)&&(gausParameter.ksize == 0))
    {
        QMessageBox::warning(this,"输入参数有误","标准差:0~100;\n核大小:0~51,且为奇数;参数不能都为0");
        return;
    }
    _myFilter->executeGaussianFilter(gausParameter.ksize,gausParameter.sigma);
}

void MainWindow::on_median_ksize_Slider_valueChanged(int value)
{
    if(_mySlotPause == true)
        return;
    if(_myFilter == Q_NULLPTR)
    {
      QMessageBox::warning(this,"需要一张图片","文件-打开图片(ksizeslider)");
      return;
    }
    medianParameter.ksize = value << 1;
    medianParameter.ksize = medianParameter.ksize != 0 ? --medianParameter.ksize:medianParameter.ksize;

    ui->median_ksize_lineEdit->setText(QString::number(medianParameter.ksize));
    _myFilter->executeMedianFilter(medianParameter.ksize);

}

void MainWindow::on_mean_ksize_Slider_valueChanged(int value)
{
    if(_mySlotPause == true)
        return;
    if(_myFilter == Q_NULLPTR)
    {
      QMessageBox::warning(this,"需要一张图片","文件-打开图片(ksizeslider)");
      return;
    }
    meanParameter.ksize = value << 1;
    meanParameter.ksize = meanParameter.ksize != 0 ? --meanParameter.ksize:meanParameter.ksize;

    ui->mean_ksize_lineEdit->setText(QString::number(meanParameter.ksize));
    _myFilter->executeMeanFilter(meanParameter.ksize);
}

void MainWindow::on_ColorOpen_action_triggered()
{
    if(_myFilter != Q_NULLPTR)
        delete _myFilter;

    QString imagename = GetImagePath();

    if(imagename.isEmpty()){
        QMessageBox::warning(this,"没有选择图片","没有选择图片");
        return;
    }

    _myFilter = new filter(imagename.toStdString(),cv::IMREAD_COLOR,this);
    connect(_myFilter,&filter::SrcHasFiltered,this,UpdateTheImage);

    ui->standvariance_Slider->setEnabled(true);
    ui->ksize_Slider->setEnabled(true);
    ui->mean_ksize_Slider->setEnabled(true);
    ui->median_ksize_Slider->setEnabled(true);
    ui->mor_ksize_Slider->setEnabled(true);

    Mat tempMat = _myFilter->getSrcImagecvMat();

//    namedWindow("gray");
//    imshow("gray",tempMat);

    QImage tempimage = _myFilter->ConvertMat2QImage(tempMat);

    ui->imageshow_label->setPixmap(QPixmap::fromImage(tempimage));
}

void MainWindow::on_GrayOpen_action_triggered()
{
    if(_myFilter != Q_NULLPTR)
        delete _myFilter;
    QString imagename = GetImagePath();

    if(imagename.isEmpty()){
        QMessageBox::warning(this,"没有选择图片","没有选择图片");
        return;
    }

    _myFilter = new filter(imagename.toStdString(),cv::IMREAD_GRAYSCALE,this);
    connect(_myFilter,&filter::SrcHasFiltered,this,UpdateTheImage);

    ui->standvariance_Slider->setEnabled(true);
    ui->ksize_Slider->setEnabled(true);
    ui->mean_ksize_Slider->setEnabled(true);
    ui->median_ksize_Slider->setEnabled(true);
    ui->mor_ksize_Slider->setEnabled(true);

    Mat tempMat = _myFilter->getSrcImagecvMat();

//    namedWindow("gray");
//    imshow("gray",tempMat);

    QImage tempimage = _myFilter->ConvertMat2QImage(tempMat);

    ui->imageshow_label->setPixmap(QPixmap::fromImage(tempimage));
}

void MainWindow::on_histequalizeButton_clicked()
{
    _myFilter->executeHistogramEqualization();
    Mat tempMat = _myFilter->getDstImagecvMat();
    DrawHistogram(tempMat);
}

void MainWindow::on_mor_ksize_Slider_valueChanged(int value)
{
    if(_mySlotPause == true)
        return;
    if(_myFilter == Q_NULLPTR)
    {
      QMessageBox::warning(this,"需要一张图片","文件-打开图片(ksizeslider)");
      return;
    }

    int ksize = value << 1;
    ksize = ksize != 0 ? --ksize:ksize;

    ui->mor_ksize_lineEdit->setText(QString::number(ksize));
    _myFilter->executeMorhology(morParameter.operationType,morParameter.shape,ksize);


}

void MainWindow::on_morShape_comboBox_currentIndexChanged(const QString &arg1)
{
    qDebug()<<arg1<<ui->morShape_comboBox->currentText();
    morParameter.shape = morshapeMap[ui->morShape_comboBox->currentText()];
}

void MainWindow::on_morType_comboBox_currentIndexChanged(const QString &arg1)
{
    qDebug()<<arg1<<ui->morType_comboBox->currentText();
    morParameter.operationType = mortypeMap[ui->morType_comboBox->currentText()];
}







