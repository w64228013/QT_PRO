#-------------------------------------------------
#
# Project created by QtCreator 2018-05-01T20:23:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = cvtest
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QCUSTOMPLOT_USE_LIBRARY

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    filter.cpp \
    cv2qt.cpp \
    D:/QT_3rdLib/qcustomplot/qcustomplot.cpp

HEADERS += \
        mainwindow.h \
    filter.h \
    cv2qt.h \
    D:/QT_3rdLib/qcustomplot/qcustomplot.h

FORMS += \
        mainwindow.ui

INCLUDEPATH += D:\opencv\build\include

LIBS += D:\opencv\cv_build\install\x86\mingw\bin\libopencv_core340.dll
LIBS += D:\opencv\cv_build\install\x86\mingw\bin\libopencv_highgui340.dll
LIBS += D:\opencv\cv_build\install\x86\mingw\bin\libopencv_imgcodecs340.dll
LIBS += D:\opencv\cv_build\install\x86\mingw\bin\libopencv_imgproc340.dll
LIBS += D:\opencv\cv_build\install\x86\mingw\bin\libopencv_features2d340.dll
LIBS += D:\opencv\cv_build\install\x86\mingw\bin\libopencv_calib3d340.dll


INCLUDEPATH += D:\QT_3rdLib\qcustomplot\MinGW_Lib\DeBug

#LIBS += D:\QT_3rdLib\qcustomplot\MinGW_Lib\DeBug\libQCustomPlot.a

