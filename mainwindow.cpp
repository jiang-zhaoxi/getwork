#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include"button.h"
#include"gamescence.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::FramelessWindowHint);//ÎÞ±ß¿ò
    setAttribute(Qt::WA_TranslucentBackground);//±³¾°Í¸Ã÷

    this->setFixedSize(1400,875);
    ui->setupUi(this);
    gamescence *scene=new gamescence;
    button *btn=new button(":/bu.png");
    btn->setParent(this);
    btn->move(150,120);
    connect(btn,&QPushButton::clicked,this,[=](){
        this->close();
        scene->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    QPixmap img(":/bac.jpg");
    paint.drawPixmap(0,0,1400,875,img);
}
