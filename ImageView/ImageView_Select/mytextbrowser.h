#ifndef MYTEXTBROWSER_H
#define MYTEXTBROWSER_H

#include <QObject>
#include <QTextBrowser>
#include <QMenu>
#include <QAction>
#include <QDebug>

class myTextBrowser : public QTextBrowser
{
    Q_OBJECT
public:
    explicit myTextBrowser(QWidget *parent = nullptr);

    QMenu *cmenu;
    QAction *action1;

signals:

public slots:

protected:
//    void mousePressEvent(QMouseEvent *e);

};

#endif // MYTEXTBROWSER_H
