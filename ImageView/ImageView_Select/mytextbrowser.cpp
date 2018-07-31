#include "mytextbrowser.h"

myTextBrowser::myTextBrowser(QWidget *parent) :
    QTextBrowser(parent),
    cmenu(new QMenu(this)),
    action1(new QAction("ClearWindos",this))
{
//    action1 = cmenu->addAction("ClearWindos");

    cmenu->addAction(action1);
    connect(action1, QAction::triggered,[=](){
        this->clear();
    });

}

