#ifndef MYSCENE_H
#define MYSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QSize>
#include <QRectF>

#include "mydiagitem.h"

class myScene : public QGraphicsScene
{
    Q_OBJECT

public:
    enum Mode { InsertItem, InsertLine, InsertText, MoveItem,Sleep };

    explicit myScene(QSize roiSize,QObject *parent = 0);
    void setROISize(QSize roiSize);
    void setMode(Mode Mode);
    bool hasImage();
    QSize getROISize() const {return myROISize;}


    void deleteImage();
    void deleteROI();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void updateROI();
private:
    QPolygonF myPloygon;
    QSize myROISize;
    Mode myMode{Sleep};
//    mydiagitem *mypolyitem;
    void createROI(QPointF pos,QSize roisize);


};

#endif // MYSCENE_H
