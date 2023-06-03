#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    h_limit = 1400;
    v_limit = 700;
    scene->setSceneRect(0,0,h_limit,v_limit);
    scene->addRect(scene->sceneRect());
    ui->graphicsView->setScene(scene);

    obj = new bolagraf(50,50,2,0,20,1);
    obj->pos(v_limit);
    scene->addItem(obj);

    obj = new bolagraf(50,350,2,2,20,1);
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
    if(b->getEsfera()->getPx() < b->getEsfera()->getRad() || b->getEsfera()->getPx() > h_limit-b->getEsfera()->getRad()){
        b->getEsfera()->setVx(b->getEsfera()->getVx()*-1.1);
    }

    if(b->getEsfera()->getPy() < b->getEsfera()->getRad() || b->getEsfera()->getPy() > v_limit-b->getEsfera()->getRad()){
        b->getEsfera()->setVy(b->getEsfera()->getVy()*-1.1);
    }

}

void MainWindow::actualizar()
{
    obj->actualizar(DT,v_limit);
    bordercollision(obj);
}

