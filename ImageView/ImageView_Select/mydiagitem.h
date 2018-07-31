#ifndef MYDIAGITEM_H
#define MYDIAGITEM_H

#include <QObject>
#include <QGraphicsPolygonItem>
#include <QDebug>
#include <QGraphicsScene>
#include <QSize>
#include <QPolygonF>
#include <QCursor>
#include <QKeyEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneHoverEvent>
#include <QMap>
#include <QVector>

#include <stdlib.h>

class mydiagitem : public QObject,public QGraphicsPolygonItem
{
    Q_OBJECT

public:
    enum { Type = UserType + 3 };
    enum cursorPos{
        Topleft = 0,
        Topright,
        Bottomright,
        Bottomleft,
        Topcenter,
        Rightcenter,
        Bottomcenter,
        Leftcenter,
        OtherPos
    };

    explicit mydiagitem(QSize roisize,QObject *parent = 0);

    void changeROIPos(QPointF pos);
    void changeROISize(QSize roisize);
    QRectF getROIRecF() const {return myROIRecF;}
    inline QRect getROIRec() const {return getROIRecF().toRect();}

    QPointF getROIPosF() const {return QPointF(myROIRecF.x(),myROIRecF.y());}
    inline QPoint getROIPos() const {return getROIPosF().toPoint();}

    int type() const override { return Type;}
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
signals:
    void updateROIImage(QRectF rectangle);
private:
    QPolygonF myPolygon;
    QRectF myROIRecF;
    QSize myROISize;
    QPolygonF surpoint;
    cursorPos currentCursorPos{OtherPos};
//    QVector<QRectF> surpointrec = QVector<QRectF>(8);
    QRectF surpointrec[8];
    int surpointWidth{5};
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void keyPressEvent(QKeyEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
//    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
};

#endif // MYDIAGITEM_H
