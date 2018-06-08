/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <../../qcustomplot.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *ColorOpen_action;
    QAction *GrayOpen_action;
    QWidget *centralWidget;
    QTabWidget *filter_parentTab;
    QWidget *Gauss_Tab;
    QTextBrowser *Gauss_textBrowser;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *sigma_label;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *sigma_lineEdit;
    QSpacerItem *verticalSpacer;
    QSlider *standvariance_Slider;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ksize_label;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *ksize_lineEdit;
    QSpacerItem *verticalSpacer_2;
    QSlider *ksize_Slider;
    QWidget *Median_Tab;
    QTextBrowser *Median_textBrowser;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *median_ksize_label;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *median_ksize_lineEdit;
    QSpacerItem *verticalSpacer_3;
    QSlider *median_ksize_Slider;
    QWidget *Average_Tab;
    QTextBrowser *mean_textBrowser_3;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *mean_ksize_label;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *mean_ksize_lineEdit;
    QSpacerItem *verticalSpacer_4;
    QSlider *mean_ksize_Slider;
    QWidget *Histogram_Tab;
    QFrame *frame;
    QCustomPlot *HistogramPlot;
    QPushButton *histequalizeButton;
    QWidget *tab;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *median_ksize_label_2;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *mor_ksize_lineEdit;
    QSpacerItem *verticalSpacer_5;
    QSlider *mor_ksize_Slider;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *median_ksize_label_4;
    QComboBox *morType_comboBox;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *median_ksize_label_3;
    QComboBox *morShape_comboBox;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *FilterExecuter_But;
    QPushButton *InvFilterExecuter_But;
    QSpacerItem *horizontalSpacer_2;
    QLabel *imageshow_label;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1037, 666);
        MainWindow->setMinimumSize(QSize(1037, 666));
        MainWindow->setMaximumSize(QSize(1037, 666));
        ColorOpen_action = new QAction(MainWindow);
        ColorOpen_action->setObjectName(QStringLiteral("ColorOpen_action"));
        GrayOpen_action = new QAction(MainWindow);
        GrayOpen_action->setObjectName(QStringLiteral("GrayOpen_action"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        filter_parentTab = new QTabWidget(centralWidget);
        filter_parentTab->setObjectName(QStringLiteral("filter_parentTab"));
        filter_parentTab->setGeometry(QRect(550, 10, 471, 471));
        Gauss_Tab = new QWidget();
        Gauss_Tab->setObjectName(QStringLiteral("Gauss_Tab"));
        Gauss_textBrowser = new QTextBrowser(Gauss_Tab);
        Gauss_textBrowser->setObjectName(QStringLiteral("Gauss_textBrowser"));
        Gauss_textBrowser->setGeometry(QRect(30, 220, 241, 121));
        Gauss_textBrowser->setFrameShape(QFrame::NoFrame);
        Gauss_textBrowser->setFrameShadow(QFrame::Plain);
        layoutWidget = new QWidget(Gauss_Tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 31, 314, 161));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        sigma_label = new QLabel(layoutWidget);
        sigma_label->setObjectName(QStringLiteral("sigma_label"));
        QFont font;
        font.setPointSize(15);
        sigma_label->setFont(font);
        sigma_label->setTextFormat(Qt::AutoText);

        horizontalLayout_3->addWidget(sigma_label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        sigma_lineEdit = new QLineEdit(layoutWidget);
        sigma_lineEdit->setObjectName(QStringLiteral("sigma_lineEdit"));

        horizontalLayout_3->addWidget(sigma_lineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(309, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        standvariance_Slider = new QSlider(layoutWidget);
        standvariance_Slider->setObjectName(QStringLiteral("standvariance_Slider"));
        standvariance_Slider->setEnabled(false);
        standvariance_Slider->setMaximum(1000);
        standvariance_Slider->setPageStep(10);
        standvariance_Slider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(standvariance_Slider);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ksize_label = new QLabel(layoutWidget);
        ksize_label->setObjectName(QStringLiteral("ksize_label"));
        ksize_label->setFont(font);
        ksize_label->setTextFormat(Qt::AutoText);

        horizontalLayout_2->addWidget(ksize_label);

        horizontalSpacer_3 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        ksize_lineEdit = new QLineEdit(layoutWidget);
        ksize_lineEdit->setObjectName(QStringLiteral("ksize_lineEdit"));

        horizontalLayout_2->addWidget(ksize_lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        ksize_Slider = new QSlider(layoutWidget);
        ksize_Slider->setObjectName(QStringLiteral("ksize_Slider"));
        ksize_Slider->setEnabled(false);
        ksize_Slider->setMaximum(100);
        ksize_Slider->setSingleStep(2);
        ksize_Slider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(ksize_Slider);

        filter_parentTab->addTab(Gauss_Tab, QString());
        Median_Tab = new QWidget();
        Median_Tab->setObjectName(QStringLiteral("Median_Tab"));
        Median_textBrowser = new QTextBrowser(Median_Tab);
        Median_textBrowser->setObjectName(QStringLiteral("Median_textBrowser"));
        Median_textBrowser->setGeometry(QRect(30, 220, 241, 121));
        Median_textBrowser->setFrameShape(QFrame::NoFrame);
        Median_textBrowser->setFrameShadow(QFrame::Plain);
        layoutWidget1 = new QWidget(Median_Tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 30, 314, 81));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        median_ksize_label = new QLabel(layoutWidget1);
        median_ksize_label->setObjectName(QStringLiteral("median_ksize_label"));
        median_ksize_label->setFont(font);
        median_ksize_label->setTextFormat(Qt::AutoText);

        horizontalLayout_4->addWidget(median_ksize_label);

        horizontalSpacer_5 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        median_ksize_lineEdit = new QLineEdit(layoutWidget1);
        median_ksize_lineEdit->setObjectName(QStringLiteral("median_ksize_lineEdit"));

        horizontalLayout_4->addWidget(median_ksize_lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        median_ksize_Slider = new QSlider(layoutWidget1);
        median_ksize_Slider->setObjectName(QStringLiteral("median_ksize_Slider"));
        median_ksize_Slider->setEnabled(false);
        median_ksize_Slider->setMinimum(1);
        median_ksize_Slider->setMaximum(100);
        median_ksize_Slider->setSingleStep(2);
        median_ksize_Slider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(median_ksize_Slider);

        filter_parentTab->addTab(Median_Tab, QString());
        Average_Tab = new QWidget();
        Average_Tab->setObjectName(QStringLiteral("Average_Tab"));
        mean_textBrowser_3 = new QTextBrowser(Average_Tab);
        mean_textBrowser_3->setObjectName(QStringLiteral("mean_textBrowser_3"));
        mean_textBrowser_3->setGeometry(QRect(30, 220, 241, 121));
        mean_textBrowser_3->setFrameShape(QFrame::NoFrame);
        mean_textBrowser_3->setFrameShadow(QFrame::Plain);
        layoutWidget_3 = new QWidget(Average_Tab);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(30, 30, 314, 81));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        mean_ksize_label = new QLabel(layoutWidget_3);
        mean_ksize_label->setObjectName(QStringLiteral("mean_ksize_label"));
        mean_ksize_label->setFont(font);
        mean_ksize_label->setTextFormat(Qt::AutoText);

        horizontalLayout_5->addWidget(mean_ksize_label);

        horizontalSpacer_6 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        mean_ksize_lineEdit = new QLineEdit(layoutWidget_3);
        mean_ksize_lineEdit->setObjectName(QStringLiteral("mean_ksize_lineEdit"));

        horizontalLayout_5->addWidget(mean_ksize_lineEdit);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        mean_ksize_Slider = new QSlider(layoutWidget_3);
        mean_ksize_Slider->setObjectName(QStringLiteral("mean_ksize_Slider"));
        mean_ksize_Slider->setEnabled(false);
        mean_ksize_Slider->setMinimum(1);
        mean_ksize_Slider->setMaximum(100);
        mean_ksize_Slider->setSingleStep(2);
        mean_ksize_Slider->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(mean_ksize_Slider);

        filter_parentTab->addTab(Average_Tab, QString());
        Histogram_Tab = new QWidget();
        Histogram_Tab->setObjectName(QStringLiteral("Histogram_Tab"));
        frame = new QFrame(Histogram_Tab);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 441, 391));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        HistogramPlot = new QCustomPlot(frame);
        HistogramPlot->setObjectName(QStringLiteral("HistogramPlot"));
        HistogramPlot->setGeometry(QRect(0, 0, 441, 391));
        histequalizeButton = new QPushButton(Histogram_Tab);
        histequalizeButton->setObjectName(QStringLiteral("histequalizeButton"));
        histequalizeButton->setGeometry(QRect(50, 410, 93, 28));
        filter_parentTab->addTab(Histogram_Tab, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget_2 = new QWidget(tab);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 30, 314, 81));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        median_ksize_label_2 = new QLabel(layoutWidget_2);
        median_ksize_label_2->setObjectName(QStringLiteral("median_ksize_label_2"));
        median_ksize_label_2->setFont(font);
        median_ksize_label_2->setTextFormat(Qt::AutoText);

        horizontalLayout_6->addWidget(median_ksize_label_2);

        horizontalSpacer_7 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        mor_ksize_lineEdit = new QLineEdit(layoutWidget_2);
        mor_ksize_lineEdit->setObjectName(QStringLiteral("mor_ksize_lineEdit"));

        horizontalLayout_6->addWidget(mor_ksize_lineEdit);


        verticalLayout_4->addLayout(horizontalLayout_6);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        mor_ksize_Slider = new QSlider(layoutWidget_2);
        mor_ksize_Slider->setObjectName(QStringLiteral("mor_ksize_Slider"));
        mor_ksize_Slider->setEnabled(false);
        mor_ksize_Slider->setMinimum(1);
        mor_ksize_Slider->setMaximum(100);
        mor_ksize_Slider->setSingleStep(2);
        mor_ksize_Slider->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(mor_ksize_Slider);

        layoutWidget_4 = new QWidget(tab);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(240, 140, 181, 28));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        median_ksize_label_4 = new QLabel(layoutWidget_4);
        median_ksize_label_4->setObjectName(QStringLiteral("median_ksize_label_4"));
        median_ksize_label_4->setFont(font);
        median_ksize_label_4->setTextFormat(Qt::AutoText);

        horizontalLayout_8->addWidget(median_ksize_label_4);

        morType_comboBox = new QComboBox(layoutWidget_4);
        morType_comboBox->addItem(QString());
        morType_comboBox->addItem(QString());
        morType_comboBox->addItem(QString());
        morType_comboBox->addItem(QString());
        morType_comboBox->setObjectName(QStringLiteral("morType_comboBox"));
        QFont font1;
        font1.setPointSize(12);
        morType_comboBox->setFont(font1);

        horizontalLayout_8->addWidget(morType_comboBox);

        layoutWidget2 = new QWidget(tab);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 140, 181, 28));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        median_ksize_label_3 = new QLabel(layoutWidget2);
        median_ksize_label_3->setObjectName(QStringLiteral("median_ksize_label_3"));
        median_ksize_label_3->setFont(font);
        median_ksize_label_3->setTextFormat(Qt::AutoText);

        horizontalLayout_7->addWidget(median_ksize_label_3);

        morShape_comboBox = new QComboBox(layoutWidget2);
        morShape_comboBox->addItem(QString());
        morShape_comboBox->addItem(QString());
        morShape_comboBox->addItem(QString());
        morShape_comboBox->setObjectName(QStringLiteral("morShape_comboBox"));
        morShape_comboBox->setFont(font1);

        horizontalLayout_7->addWidget(morShape_comboBox);

        filter_parentTab->addTab(tab, QString());
        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(550, 510, 461, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        FilterExecuter_But = new QPushButton(layoutWidget3);
        FilterExecuter_But->setObjectName(QStringLiteral("FilterExecuter_But"));

        horizontalLayout->addWidget(FilterExecuter_But);

        InvFilterExecuter_But = new QPushButton(layoutWidget3);
        InvFilterExecuter_But->setObjectName(QStringLiteral("InvFilterExecuter_But"));

        horizontalLayout->addWidget(InvFilterExecuter_But);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        imageshow_label = new QLabel(centralWidget);
        imageshow_label->setObjectName(QStringLiteral("imageshow_label"));
        imageshow_label->setGeometry(QRect(40, 30, 471, 531));
        imageshow_label->setMinimumSize(QSize(0, 0));
        imageshow_label->setScaledContents(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1037, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menu);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setIconSize(QSize(30, 30));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(menu_2->menuAction());
        menu_2->addAction(ColorOpen_action);
        menu_2->addAction(GrayOpen_action);

        retranslateUi(MainWindow);

        filter_parentTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        ColorOpen_action->setText(QApplication::translate("MainWindow", "\345\275\251\350\211\262\346\211\223\345\274\200", nullptr));
        GrayOpen_action->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246\346\211\223\345\274\200", nullptr));
        Gauss_textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\240\270\345\244\247\345\260\217\344\270\272\345\245\207\346\225\260\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\275\223\346\240\207\345\207\206\345\267\256\344\270\2720\346\227\266,\346\240\271\346\215\256\346\240\270\345\244\247\345\260\217\350\207\252\345\212\250\351\200\211\346\213\251\346\240\207\345\207\206\345\267\256\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"
                        "\">\345\217\215\344\271\213\344\272\246\347\204\266\343\200\202</p></body></html>", nullptr));
        sigma_label->setText(QApplication::translate("MainWindow", "\346\240\207\345\207\206\345\267\256", nullptr));
        ksize_label->setText(QApplication::translate("MainWindow", "\346\240\270\345\244\247\345\260\217", nullptr));
        filter_parentTab->setTabText(filter_parentTab->indexOf(Gauss_Tab), QApplication::translate("MainWindow", "\351\253\230\346\226\257", nullptr));
        Median_textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\240\270\345\244\247\345\260\217\344\270\272\345\245\207\346\225\260,\344\270\224\344\270\215\350\203\275\344\270\2720\343\200\202</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        median_ksize_label->setText(QApplication::translate("MainWindow", "\346\240\270\345\244\247\345\260\217", nullptr));
        filter_parentTab->setTabText(filter_parentTab->indexOf(Median_Tab), QApplication::translate("MainWindow", "\344\270\255\345\200\274", nullptr));
        mean_textBrowser_3->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\240\270\345\244\247\345\260\217\344\270\272\345\245\207\346\225\260,\344\270\224\344\270\215\350\203\275\344\270\2720\343\200\202</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        mean_ksize_label->setText(QApplication::translate("MainWindow", "\346\240\270\345\244\247\345\260\217", nullptr));
        filter_parentTab->setTabText(filter_parentTab->indexOf(Average_Tab), QApplication::translate("MainWindow", "\345\235\207\345\200\274", nullptr));
        histequalizeButton->setText(QApplication::translate("MainWindow", "\345\235\207\350\241\241\345\214\226", nullptr));
        filter_parentTab->setTabText(filter_parentTab->indexOf(Histogram_Tab), QApplication::translate("MainWindow", "\347\233\264\346\226\271\345\233\276", nullptr));
        median_ksize_label_2->setText(QApplication::translate("MainWindow", "\346\240\270\345\244\247\345\260\217", nullptr));
        median_ksize_label_4->setText(QApplication::translate("MainWindow", "\346\223\215\344\275\234", nullptr));
        morType_comboBox->setItemText(0, QApplication::translate("MainWindow", "\350\205\220\350\232\200", nullptr));
        morType_comboBox->setItemText(1, QApplication::translate("MainWindow", "\350\206\250\350\203\200", nullptr));
        morType_comboBox->setItemText(2, QApplication::translate("MainWindow", "\345\274\200\350\277\220\347\256\227", nullptr));
        morType_comboBox->setItemText(3, QApplication::translate("MainWindow", "\351\227\255\350\277\220\347\256\227", nullptr));

        median_ksize_label_3->setText(QApplication::translate("MainWindow", "\346\240\270\345\275\242\347\212\266", nullptr));
        morShape_comboBox->setItemText(0, QApplication::translate("MainWindow", "\347\237\251\345\275\242", nullptr));
        morShape_comboBox->setItemText(1, QApplication::translate("MainWindow", "\345\234\206\345\275\242", nullptr));
        morShape_comboBox->setItemText(2, QApplication::translate("MainWindow", "\345\217\211\345\275\242", nullptr));

        filter_parentTab->setTabText(filter_parentTab->indexOf(tab), QApplication::translate("MainWindow", "\345\275\242\346\200\201\345\255\246", nullptr));
        FilterExecuter_But->setText(QApplication::translate("MainWindow", "\346\211\247\350\241\214\346\223\215\344\275\234", nullptr));
        InvFilterExecuter_But->setText(QApplication::translate("MainWindow", "\345\217\230\345\233\236\345\216\237\345\233\276", nullptr));
        imageshow_label->setText(QString());
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
