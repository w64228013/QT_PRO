#include "imlabel.h"

ImLabel::ImLabel(QWidget *parent):
    QLabel(parent)
{
    qDebug()<<frameGeometry();
}


void ImLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);//先调用父类的paintEvent为了显示'背景'!!

    QPainter painter(this);
    painter.setPen(QPen(Qt::red,2));
    painter.drawRect(localPoint.x()-(rec_width>>1),localPoint.y()-(rec_height>>1),rec_width,rec_height);
}

void ImLabel::mousePressEvent(QMouseEvent *event)
{
    int y = event->y();
    int x = event->x();
    int frameheight = frameSize().height();
    int frameWidth = frameSize().width();
    QPoint framestartpoint(pos().x(),pos().y());

    /*y under bottom of the frame*/
    if(y > (frameheight-(rec_height>>1))){
        y = frameheight-(rec_height>>1);
    }
    else if(y < (framestartpoint.y() + (rec_height>>1))){
        y = framestartpoint.y() + (rec_height>>1);
    }
    /*x at the right of the frame*/
    if(x > frameWidth - (rec_width>>1)){
        x = frameWidth - (rec_width>>1);
    }
    /*x at the left of the frame*/
    else if(x < (framestartpoint.x() + (rec_width>>1))){
        x = framestartpoint.x() + (rec_width>>1);
    }

    localPoint.setX(x);
    localPoint.setY(y);
    update();
}

void ImLabel::mouseMoveEvent(QMouseEvent *event)
{
    int y = event->y();
    int x = event->x();
    int frameheight = frameSize().height();
    int frameWidth = frameSize().width();
    QPoint framestartpoint(pos().x(),pos().y());

    /*y under bottom of the frame*/
    if(y > (frameheight-(rec_height>>1))){
        y = frameheight-(rec_height>>1);
    }
    else if(y < (framestartpoint.y() + (rec_height>>1))){
        y = framestartpoint.y() + (rec_height>>1);
    }
    /*x at the right of the frame*/
    if(x > frameWidth - (rec_width>>1)){
        x = frameWidth - (rec_width>>1);
    }
    /*x at the left of the frame*/
    else if(x < (framestartpoint.x() + (rec_width>>1))){
        x = framestartpoint.x() + (rec_width>>1);
    }

    localPoint.setX(x);
    localPoint.setY(y);
    update();
}
