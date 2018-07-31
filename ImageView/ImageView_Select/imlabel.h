#ifndef IMLABEL_H
#define IMLABEL_H

#include <QLabel>
#include <QPainter>
#include <QRect>
#include <QDebug>
#include <QMouseEvent>
#include <QPoint>

#include "rectangle.h"

class ImLabel : public QLabel,public rectangle
{
    Q_OBJECT
public:
    ImLabel(QWidget *parent=0);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private:
    QPoint localPoint = QPoint(-200,-200);
//    QPainter *painter = Q_NULLPTR;
};

#endif // IMLABEL_H
