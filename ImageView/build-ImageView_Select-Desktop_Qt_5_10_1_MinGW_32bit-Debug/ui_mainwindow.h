/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myimageview.h"
#include "mytextbrowser.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionOpenFolder;
    QAction *actionSetSavePath;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QAction *actionDrag;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    myImageView *ImageView;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QGraphicsView *ROIView;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *ROIPrefixEdit;
    QComboBox *TypeBox;
    QPushButton *SaveROIButton;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *ROIwidthlineEdit;
    QLineEdit *ROIheightlineEdit;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QPushButton *SetROIButton;
    myTextBrowser *infoBrowser;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *PrevButton;
    QPushButton *NextButton;
    QMenuBar *menuBar;
    QMenu *menufile;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1573, 817);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpenFolder = new QAction(MainWindow);
        actionOpenFolder->setObjectName(QStringLiteral("actionOpenFolder"));
        actionSetSavePath = new QAction(MainWindow);
        actionSetSavePath->setObjectName(QStringLiteral("actionSetSavePath"));
        actionZoomIn = new QAction(MainWindow);
        actionZoomIn->setObjectName(QStringLiteral("actionZoomIn"));
        actionZoomOut = new QAction(MainWindow);
        actionZoomOut->setObjectName(QStringLiteral("actionZoomOut"));
        actionDrag = new QAction(MainWindow);
        actionDrag->setObjectName(QStringLiteral("actionDrag"));
        actionDrag->setCheckable(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/icon/hand_black.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/icon/icon/hand_black.png"), QSize(), QIcon::Normal, QIcon::On);
        icon.addFile(QStringLiteral(":/icon/icon/hand_blue.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon.addFile(QStringLiteral(":/icon/icon/hand_blue.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon.addFile(QStringLiteral(":/icon/icon/hand_blue.png"), QSize(), QIcon::Active, QIcon::Off);
        icon.addFile(QStringLiteral(":/icon/icon/hand_blue.png"), QSize(), QIcon::Active, QIcon::On);
        icon.addFile(QStringLiteral(":/icon/icon/hand_blue.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon.addFile(QStringLiteral(":/icon/icon/hand_blue.png"), QSize(), QIcon::Selected, QIcon::On);
        actionDrag->setIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ImageView = new myImageView(centralWidget);
        ImageView->setObjectName(QStringLiteral("ImageView"));
        ImageView->setMinimumSize(QSize(800, 600));
        ImageView->setContextMenuPolicy(Qt::CustomContextMenu);
        ImageView->setAutoFillBackground(false);
        ImageView->setStyleSheet(QStringLiteral("background:transparent"));
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        ImageView->setBackgroundBrush(brush);
        ImageView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        ImageView->setDragMode(QGraphicsView::NoDrag);

        gridLayout->addWidget(ImageView, 0, 1, 1, 1);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(300, 0));
        frame->setMaximumSize(QSize(300, 16777215));
        frame->setLayoutDirection(Qt::LeftToRight);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        ROIView = new QGraphicsView(frame);
        ROIView->setObjectName(QStringLiteral("ROIView"));
        ROIView->setMinimumSize(QSize(300, 300));
        ROIView->setMaximumSize(QSize(300, 300));
        ROIView->setLayoutDirection(Qt::LeftToRight);
        ROIView->setStyleSheet(QStringLiteral("background:transparent"));

        verticalLayout_3->addWidget(ROIView);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Devanagari"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ROIPrefixEdit = new QLineEdit(frame);
        ROIPrefixEdit->setObjectName(QStringLiteral("ROIPrefixEdit"));

        horizontalLayout->addWidget(ROIPrefixEdit);

        TypeBox = new QComboBox(frame);
        TypeBox->setObjectName(QStringLiteral("TypeBox"));
        TypeBox->setMinimumSize(QSize(120, 0));
        TypeBox->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(TypeBox);


        verticalLayout_2->addLayout(horizontalLayout);

        SaveROIButton = new QPushButton(frame);
        SaveROIButton->setObjectName(QStringLiteral("SaveROIButton"));

        verticalLayout_2->addWidget(SaveROIButton);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ROIwidthlineEdit = new QLineEdit(frame);
        ROIwidthlineEdit->setObjectName(QStringLiteral("ROIwidthlineEdit"));

        horizontalLayout_2->addWidget(ROIwidthlineEdit);

        ROIheightlineEdit = new QLineEdit(frame);
        ROIheightlineEdit->setObjectName(QStringLiteral("ROIheightlineEdit"));

        horizontalLayout_2->addWidget(ROIheightlineEdit);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout_4->addWidget(label_3);

        SetROIButton = new QPushButton(frame);
        SetROIButton->setObjectName(QStringLiteral("SetROIButton"));
        SetROIButton->setEnabled(false);
        SetROIButton->setStyleSheet(QLatin1String("QPushButton:pressed{\n"
"    border: 1px solid #5F92B2;\n"
"    background-color:  rgb(255, 255, 255);\n"
"}"));

        verticalLayout_4->addWidget(SetROIButton);


        verticalLayout_3->addLayout(verticalLayout_4);

        infoBrowser = new myTextBrowser(frame);
        infoBrowser->setObjectName(QStringLiteral("infoBrowser"));
        infoBrowser->setContextMenuPolicy(Qt::CustomContextMenu);

        verticalLayout_3->addWidget(infoBrowser);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        PrevButton = new QPushButton(frame);
        PrevButton->setObjectName(QStringLiteral("PrevButton"));

        horizontalLayout_3->addWidget(PrevButton);

        NextButton = new QPushButton(frame);
        NextButton->setObjectName(QStringLiteral("NextButton"));

        horizontalLayout_3->addWidget(NextButton);


        verticalLayout_3->addLayout(horizontalLayout_3);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1573, 26));
        menufile = new QMenu(menuBar);
        menufile->setObjectName(QStringLiteral("menufile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menufile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menufile->addAction(actionOpen);
        menufile->addAction(actionOpenFolder);
        menufile->addAction(actionSetSavePath);
        menuEdit->addAction(actionZoomIn);
        menuEdit->addAction(actionZoomOut);
        mainToolBar->addAction(actionDrag);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open...", nullptr));
        actionOpenFolder->setText(QApplication::translate("MainWindow", "OpenFolder...", nullptr));
        actionSetSavePath->setText(QApplication::translate("MainWindow", "SetSavePath", nullptr));
        actionZoomIn->setText(QApplication::translate("MainWindow", "ZoomIn 50%", nullptr));
        actionZoomOut->setText(QApplication::translate("MainWindow", "ZoomOut 50%", nullptr));
        actionDrag->setText(QApplication::translate("MainWindow", "Drag", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDrag->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>click and translate around the view</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("MainWindow", "Set the Prefix of the File and Type", nullptr));
        SaveROIButton->setText(QApplication::translate("MainWindow", "SaveROI (Space)", nullptr));
#ifndef QT_NO_SHORTCUT
        SaveROIButton->setShortcut(QApplication::translate("MainWindow", "Space", nullptr));
#endif // QT_NO_SHORTCUT
        label->setText(QApplication::translate("MainWindow", "ROI width and height", nullptr));
        ROIheightlineEdit->setPlaceholderText(QString());
        label_3->setText(QApplication::translate("MainWindow", "ROI Size", nullptr));
        SetROIButton->setText(QApplication::translate("MainWindow", "SelectROIWindos", nullptr));
        PrevButton->setText(QApplication::translate("MainWindow", "PrevImage", nullptr));
#ifndef QT_NO_SHORTCUT
        PrevButton->setShortcut(QApplication::translate("MainWindow", "A", nullptr));
#endif // QT_NO_SHORTCUT
        NextButton->setText(QApplication::translate("MainWindow", "NextImage", nullptr));
#ifndef QT_NO_SHORTCUT
        NextButton->setShortcut(QApplication::translate("MainWindow", "D", nullptr));
#endif // QT_NO_SHORTCUT
        menufile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
