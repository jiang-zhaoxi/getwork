#ifndef GAMESCENCE_H
#define GAMESCENCE_H

#include <QMainWindow>
#include"tower.h"
#include"choosebutton.h"
class gamescence : public QMainWindow
{
    Q_OBJECT
public:
    explicit gamescence(QWidget *parent = 0);
void  paintEvent(QPaintEvent*);
tower *twr[25];
choosebutton *btn[25][7];
signals:
private slots:
};

#endif // GAMESCENCE_H
