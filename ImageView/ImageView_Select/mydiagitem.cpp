#include "mydiagitem.h"

mydiagitem::mydiagitem(QSize roisize, QObject *parent):
    QObject(parent)
{
    changeROISize(roisize);

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    this->setAcceptHoverEvents(true);
//    this->setAcceptDrops(true);
}

void mydiagitem::changeROISize(QSize roisize)
{
//   auto rec = this->polygon().boundingRect();
   myPolygon.clear();
   auto center = myROIRecF.center();
   auto halfwidth = roisize.width() /2;
   auto halfheight = roisize.height() /2;

   /*<< topleft << topright << bottomright << bottomleft*/
   /*it is a clockwise direction */
   myPolygon << QPointF(-halfwidth,-halfheight) << QPointF(halfwidth,-halfheight)
             << QPointF(halfwidth,halfheight) << QPointF(-halfwidth,halfheight);

   setPolygon(myPolygon);
   myROIRecF = this->polygon().boundingRect();

   QRectF rect;
   QPointF newPos;
   qreal  polyhalfWith;
   qreal  polyhalfHeight;
    /*when this function use in the constructor , we dont m*/
   if(this->scene() == 0){
       goto end;
   }
   // value is the new position.
   rect = scene()->sceneRect();
   newPos = this->mapToScene(myROIRecF.center());
   polyhalfWith = myROIRecF.width()/2;
   polyhalfHeight = myROIRecF.height()/2;

   /*adjust the size of rect due to considering the size of polygon*/
   rect.setLeft(rect.left() + polyhalfWith);
   rect.setRight(rect.right() - polyhalfWith);
   rect.setTop(rect.top() + polyhalfHeight);
   rect.setBottom(rect.bottom() - polyhalfHeight);

   if (!rect.contains(newPos)) {
       // Keep the item inside the scene rect.
       newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
       newPos.setY(qMin(rect.bottom(), qMax(newPos.y(), rect.top())));

       /*set the item's pos in the parent scene*/
       this->setPos(newPos);
       /*change the ROI's recf and update it in the mianwindos*/
       changeROIPos(newPos);
       return;
   }
end:changeROIPos(center);
}

void mydiagitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    qDebug()<<"item paint ";

    QGraphicsPolygonItem::paint(painter,option,widget);
    /*when the item is selected*/
    if (option->state & QStyle::State_Selected){

//        const qreal pad = static_cast<QGraphicsPolygonItem *>(this)->pen().widthF() / 2;
//        /*owe to boundary rectangle 's penwidth */
//        QRectF rectf = this->boundingRect().adjusted(pad, pad, -pad, -pad);

        QRectF rectf = this->polygon().boundingRect();
        QPolygonF pointf= this->polygon();
        QPointF center = rectf.center();

        QPointF topcenter = rectf.topLeft();
        topcenter.setX(center.x());

        QPointF leftcenter = rectf.topLeft();
        leftcenter.setY(center.y());

        QPointF rightcenter = rectf.bottomRight();
        rightcenter.setY(center.y());

        QPointF bottomcenter = rectf.bottomRight();
        bottomcenter.setX(center.x());

        /*it is a clockwise direction */
        pointf <<topcenter
              <<rightcenter
             <<bottomcenter
            <<leftcenter;

        surpoint = pointf;

        QRectF* temppoint = &surpointrec[0];
        foreach(QPointF eachpoint,pointf){
            *temppoint = QRectF(0,0,surpointWidth,surpointWidth);
            temppoint->moveCenter(eachpoint);
            temppoint++;
        }

        painter->setPen(QPen(Qt::black,surpointWidth,Qt::SolidLine));
        painter->drawPoints(pointf);
    }
}

void mydiagitem::changeROIPos(QPointF pos)
{
    myROIRecF.moveCenter(pos);
    emit updateROIImage(myROIRecF);
}


void mydiagitem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{ 
//    switch (this->cursor().shape()) {
//            /*cursor points at topleft and bottomright*/
//        case Qt::SizeFDiagCursor:
//            setFlag(QGraphicsItem::ItemIsMovable, false);
//            break;
//            /*cursor points at topright and bottomleft*/
//        case Qt::SizeBDiagCursor:
//            this->setCursor(Qt::SizeBDiagCursor);
//            break;
//            /*cursor points at vertical top and bottom*/
//        case Qt::SizeVerCursor:
//            this->setCursor(Qt::SizeVerCursor);
//            break;
//            /*cursor points at horizontal left and right*/
//        case Qt::SizeHorCursor:
//            this->setCursor(Qt::SizeHorCursor);
//            break;
//        default:
//            break;
//    }

//    QRectF itemrectf = this->boundingRect();
//    qDebug()<<"before"<<itemrectf;
//    itemrectf.setTopLeft(event->pos());

//    this->update(itemrectf);
//    qDebug()<<this->polygon();

    QGraphicsPolygonItem::mousePressEvent(event);

}

void mydiagitem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    static int i = 0;
//    qDebug()<<"mouseMove"<<i++;
//    qDebug()<<"current Pos "<<event->pos();

//    QPointF delta = event->pos() - event->lastPos();
//    qDebug()<<delta;
//    QRectF itemrectf = this->boundingRect();
//    QPolygonF itempolygon = this->polygon();
//    qDebug()<<"before"<<itempolygon;
//    switch (this->cursor().shape()) {
//            /*cursor points at topleft and bottomright*/
//        case Qt::SizeFDiagCursor:
//            setFlag(QGraphicsItem::ItemIsMovable, false);
//            if(currentCursorPos == cursorPos::Topleft){
//                itempolygon[0] = event->pos();
//                itempolygon[1] += QPointF(0,delta.y());
//                itempolygon[3] += QPointF(delta.x(),0);
//                this->setPolygon(itempolygon);
//            }
//            else{
//                itemrectf.setBottomRight(event->pos());
//            }
//            this->update(itemrectf);
//            break;
//            /*cursor points at topright and bottomleft*/
//        case Qt::SizeBDiagCursor:
//            this->setCursor(Qt::SizeBDiagCursor);
//            break;
//            /*cursor points at vertical top and bottom*/
//        case Qt::SizeVerCursor:
//            this->setCursor(Qt::SizeVerCursor);
//            break;
//            /*cursor points at horizontal left and right*/
//        case Qt::SizeHorCursor:
//            this->setCursor(Qt::SizeHorCursor);
//            break;
//        default:
//            break;
//    }

    QGraphicsItem::mouseMoveEvent(event);
}

QVariant mydiagitem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
//    qDebug()<<"GraphicsItemChange"<<change;
    if (change == ItemPositionChange && scene()) {
          // value is the new position.
          QPointF newPos = value.toPointF();
          QRectF rect = scene()->sceneRect();

//          qDebug()<<"itemchange newpos ="<<newPos;
//          qDebug()<<"itemchange center ="<<this->boundingRect().center();

          auto polyhalfWith = polygon().boundingRect().width()/2;
          auto polyhalfHeight = polygon().boundingRect().height()/2;

          /*adjust the size of rect due to considering the size of polygon*/
          rect.setLeft(rect.left() + polyhalfWith);
          rect.setRight(rect.right() - polyhalfWith);
          rect.setTop(rect.top() + polyhalfHeight);
          rect.setBottom(rect.bottom() - polyhalfHeight);

          if (!rect.contains(newPos)) {
              // Keep the item inside the scene rect.
              newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
              newPos.setY(qMin(rect.bottom(), qMax(newPos.y(), rect.top())));

              changeROIPos(newPos);
              return newPos;
          }

          changeROIPos(newPos);
      }
    return QGraphicsItem::itemChange(change, value);
}

void mydiagitem::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Up:{
            QPointF newpos = this->pos() + QPointF(0,-1);
            this->setPos(newpos);
            changeROIPos(newpos);
            break;
        }
        case Qt::Key_Down:{
            QPointF newpos = this->pos() + QPointF(0,1);
            this->setPos(newpos);
            changeROIPos(newpos);
            break;
        }
        case Qt::Key_Left:{
            QPointF newpos = this->pos() + QPointF(-1,0);
            this->setPos(newpos);
            changeROIPos(newpos);
            break;
        }
        case Qt::Key_Right:{
            QPointF newpos = this->pos() + QPointF(1,0);
            this->setPos(newpos);
            changeROIPos(newpos);
            break;
        }
        default:
            break;
    }
    QGraphicsItem::keyPressEvent(event);
}

void mydiagitem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
//    static int a = 0;
//    qDebug()<<"hover move count"<<a++;
    if(!this->isSelected()){
        return;
    }
    int i{0};
    for(i=0;i<8;i++){
        if(surpointrec[i].contains(event->pos())){
          break;
        }
    }
    currentCursorPos = cursorPos(i);
    switch (i) {
        case cursorPos::Topleft:
            this->setCursor(Qt::SizeFDiagCursor);
            break;
        case cursorPos::Topright:
            this->setCursor(Qt::SizeBDiagCursor);
            break;
        case cursorPos::Bottomright:
            this->setCursor(Qt::SizeFDiagCursor);
            break;
        case cursorPos::Bottomleft:
            this->setCursor(Qt::SizeBDiagCursor);
            break;
        case cursorPos::Topcenter:
            this->setCursor(Qt::SizeVerCursor);
            break;
        case cursorPos::Rightcenter:
            this->setCursor(Qt::SizeHorCursor);
            break;
        case cursorPos::Bottomcenter:
            this->setCursor(Qt::SizeVerCursor);
            break;
        case cursorPos::Leftcenter:
            this->setCursor(Qt::SizeHorCursor);
            break;
        default:
            this->setCursor(Qt::SizeAllCursor);
            break;
    }
}

//void mydiagitem::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
//{
//    static int i = 0;
//    qDebug()<<"dragmove"<<i++;
//    QGraphicsItem::dragMoveEvent(event);
//}
