#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    scene->setBackgroundBrush(QPixmap(":/imagens/FONDOMARIOFRjpg").scaled(1400,700));
    ui->graphicsView->setFixedSize(1400,700);
    h_limit = 1400;
    v_limit = 700;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,h_limit,v_limit);
    scene->addRect(scene->sceneRect());

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    obj = new bolagraf(50,50,2,0,30,1);
    obj->pos(v_limit);
    scene->addItem(obj);

    obj = new bolagraf(1300,650,-5,2,30,1);
    obj->pos(v_limit);
    scene->addItem(obj);

    timer = new QTimer;
    timer->stop();
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizar()));
    timer->start(10);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::bordercollision(bolagraf *b)
{
    if(b->getEsfera()->getVy()==1){
        b->getEsfera()->setVy(40);
    }
    if(b->getEsfera()->getPx() < b->getEsfera()->getRad() || b->getEsfera()->getPx() > h_limit-b->getEsfera()->getRad()){
        b->getEsfera()->setVx(b->getEsfera()->getVx()*-1.1);
    }

    if(b->getEsfera()->getPy() < b->getEsfera()->getRad() || b->getEsfera()->getPy() > v_limit-b->getEsfera()->getRad()){
        b->getEsfera()->setVy(b->getEsfera()->getVy()*-1.1);

    }
    //qDebug()<< (b->getEsfera()->getVy())<<"\n";


}

void MainWindow::actualizar()
{
    obj->actualizar(DT,v_limit);
    bordercollision(obj);
}

