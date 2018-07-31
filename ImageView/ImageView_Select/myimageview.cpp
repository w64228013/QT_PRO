#include "myimageview.h"

myImageView::myImageView(QWidget *parent) :
    QGraphicsView(parent),
    cmenu(new QMenu()),
    dragAction(new QAction("DragMode",this))
{
//    dragAction->setToolTip("<html><head/><body><p>click and translate around the view</p></body></html>");
//    cmenu->addAction(dragAction);
}
