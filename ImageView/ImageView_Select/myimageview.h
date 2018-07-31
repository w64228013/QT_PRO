#ifndef MYIMAGEVIEW_H
#define MYIMAGEVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QStyle>
#include <QApplication>
#include <QStyleFactory>

class myImageView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit myImageView(QWidget *parent = nullptr);



public:
    QMenu *cmenu;
    QAction *dragAction;
private:

};

#endif // MYIMAGEVIEW_H
