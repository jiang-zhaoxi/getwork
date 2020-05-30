#include "gamescence.h"
#include"tower.h"
#include<QPainter>
#include<QDebug>
gamescence::gamescence(QWidget *parent) : QMainWindow(parent)
{
    int i,j,k=0;
    this->setFixedSize(1400,875);
   for(i=0;i<5;i++){
       for(j=0;j<5;j++){
           twr[k]=new tower;
           twr[k]->setParent(this);
           twr[k]->pos.setX(100+j*131);
           twr[k]->pos.setY(70+165*i);
           twr[k]->move(100+j*131,70+165*i);
           k++;
       }
   }
   for(i=0;i<25;i++)
   { QPixmap ex(":/tower/build.png");twr[i]->setimg(ex);}
   for(i=0;i<25;i++){
       for(j=0;j<7;j++){
           btn[i][j]=new choosebutton;
           btn[i][j]->setParent(this);
           if(j==0){btn[i][j]->setText("knight");}
           else if(j==1){btn[i][j]->setText("archer");}
           else if(j==2){btn[i][j]->setText("wizard");}
           else if(j==3){btn[i][j]->setText("cannon");}
           else if(j==4){btn[i][j]->setText("close");}
           else if(j==5){btn[i][j]->setText("remove");}
           else {btn[i][j]->setText("update");}
           btn[i][j]->hide();
       }
   }
   for(i=0;i<25;i++)
   {
       connect(twr[i],&QPushButton::clicked,twr[i],[=](){
           int k;
           if(twr[i]->level==0){
           for(k=0;k<5;k++){
           btn[i][k]->move(twr[i]->pos.x(),twr[i]->pos.y()+30*(k+1));
           btn[i][k]->show();
           }
           }
           else{
               for(k=5;k<7;k++){
                   btn[i][k]->move(twr[i]->pos.x(),twr[i]->pos.y()+30*(k-4));
                   btn[i][k]->show();
               }
               btn[i][4]->move(twr[i]->pos.x(),twr[i]->pos.y()+30*3);
               btn[i][4]->show();
           }
       });
       connect(btn[i][0],&QPushButton::clicked,twr[i],[=](){
           btn[i][0]->hide();btn[i][1]->hide();btn[i][2]->hide();btn[i][3]->hide();btn[i][4]->hide();
           QString type("knight");
           twr[i]->update(type);
       });
       connect(btn[i][1],&QPushButton::clicked,twr[i],[=](){
           btn[i][0]->hide();btn[i][1]->hide();btn[i][2]->hide();btn[i][3]->hide();btn[i][4]->hide();
           QString type("archer");
           twr[i]->update(type);
       });
       connect(btn[i][2],&QPushButton::clicked,twr[i],[=](){
           btn[i][0]->hide();btn[i][1]->hide();btn[i][2]->hide();btn[i][3]->hide();btn[i][4]->hide();
           QString type("wizard");
           twr[i]->update(type);
       });
       connect(btn[i][3],&QPushButton::clicked,twr[i],[=](){
           btn[i][0]->hide();btn[i][1]->hide();btn[i][2]->hide();btn[i][3]->hide();btn[i][4]->hide();
           QString type("cannon");
           twr[i]->update(type);
       });
       connect(btn[i][4],&QPushButton::clicked,twr[i],[=](){
           btn[i][0]->hide();btn[i][1]->hide();btn[i][2]->hide();btn[i][3]->hide();btn[i][4]->hide();
           btn[i][5]->hide();btn[i][6]->hide();
       });
       connect(btn[i][5],&QPushButton::clicked,twr[i],[=](){
           btn[i][4]->hide();btn[i][5]->hide();btn[i][6]->hide();
           twr[i]->remove();
       });
       connect(btn[i][6],&QPushButton::clicked,twr[i],[=](){
           btn[i][4]->hide();btn[i][5]->hide();btn[i][6]->hide();
           twr[i]->update();
       });
   }
}
void gamescence::paintEvent(QPaintEvent *)
{
int i;
QPainter paint(this);
QPixmap img(":/scene.png");
paint.drawPixmap(0,0,1400,875,img);
QPainter *pa;
pa = new QPainter();
pa->begin(this);
for(i=0;i<25;i++){
    this->twr[i]->show(pa);
}
pa->end();
}
