
#include "myscene.h"
#include "mainwindow.h"

myScene::myScene(QSize roiSize, QObject *parent)
            :QGraphicsScene(parent)
             ,myROISize(roiSize)
{    

}


void myScene::setROISize(QSize roiSize)
{
    myROISize = roiSize;

    QList<QGraphicsItem *> itemlist = this->items();
    if(itemlist.count() > 1){
        mydiagitem *item = qgraphicsitem_cast<mydiagitem* >(itemlist.at(0));
        item->changeROISize(roiSize);
    }
}

void myScene::setMode(myScene::Mode Mode)
{
    myMode = Mode;
}

void myScene::deleteImage()
{
    clear();
}

void myScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{   
    if (event->button() != Qt::LeftButton){
//         qDebug()<<"scene press return";
        return;
    }

    switch (myMode) {
        case InsertItem:{
                createROI(event->scenePos(),myROISize);
                myMode = Sleep;
                break;
            }
        default:
            break;
    }
    QGraphicsScene::mousePressEvent(event);
}

void myScene::createROI(QPointF pos,QSize roisize)
{
    mydiagitem *item = new mydiagitem(roisize,this);
    this->addItem(item);
    item->setPos(pos);
    connect(item,&mydiagitem::updateROIImage,(MainWindow*)parent(),&MainWindow::updateROIImage);
    item->changeROIPos(pos);
}

void myScene::deleteROI()
{
    QList<QGraphicsItem *> itemlist = this->items();
    if(itemlist.empty() || (itemlist.count() == 1)){
        return;
    }
    mydiagitem *item = qgraphicsitem_cast<mydiagitem* >(itemlist.at(0));

    item->deleteLater();
}
