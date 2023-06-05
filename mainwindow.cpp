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



    balls.push_back(new bolagraf(1300,60,-2,4,30,1));
    scene->addItem(balls.back());
    balls.push_back(new bolagraf(1350,80,-2,4,30,1));
    scene->addItem(balls.back());
    balls.push_back(new bolagraf(700,45,-1,4,35,1));
    scene->addItem(balls.back());
    //balls.push_back(new bolagraf(300,30,5,5,35,1));
    //scene->addItem(balls.back());

    //personaje
     Franklin = new BOMBER (0,286,50);
     scene->addItem(Franklin);


     //music
     player = new QMediaPlayer;
     audioOutput = new QAudioOutput;
     player->setAudioOutput(audioOutput);
     // ...
     player->setSource(QUrl::fromLocalFile("qrc:/Music/BASEJuego.mp3"));
     player->play();

     playerR = new QMediaPlayer;
     audioOutputR = new QAudioOutput;
     playerR->setAudioOutput(audioOutputR);
     // ...
     playerR->setSource(QUrl::fromLocalFile("qrc:/Music/rebote_o1ZAQ5Tk.mp3"));
     playerR->stop();





    timer = new QTimer;
    timer->stop();
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizar()));
    timer->start(20);

    timer3G = new QTimer;
    timer3G->stop();
    connect(timer3G, SIGNAL(timeout()), this, SLOT(actualizarG()));


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
    if(50  > abs(b->getEsfera()->getVx())){
        if(b->getEsfera()->getVx() <0){
          b->getEsfera()->setVx(-40);
        }else{
          b->getEsfera()->setVx(40);
        }
    }
    if(b->getEsfera()->getPx() < b->getEsfera()->getRad() || b->getEsfera()->getPx() > h_limit-b->getEsfera()->getRad()){
        b->getEsfera()->setVx(b->getEsfera()->getVx()*-1.1);
        playerR->play();
    }

    if(b->getEsfera()->getPy() < b->getEsfera()->getRad() || b->getEsfera()->getPy() > v_limit-b->getEsfera()->getRad()){
        b->getEsfera()->setVy(b->getEsfera()->getVy()*-1.1);
        playerR->play();



    }
    //qDebug()<< (b->getEsfera()->getVy())<<"\n";


}

void MainWindow::actualizar()

{
    QList<bolagraf*>::Iterator it;
    for(it=balls.begin();it!= balls.end();it++){
        (*it)->actualizar(DT,v_limit);
        bordercollision(*it);
        qDebug()<< ((*it)->getEsfera()->getVx())<<"\n";

    }


}

void MainWindow::actualizarG()
{
    movimiento->calVelocidad();
    movimiento->calPosicion();
    movimiento->newPosicion();
    Franklin->setPos(Franklin->getPosx(),700 -movimiento->getPosy());


    if(700 -movimiento->getPosy() > 286 ){

        timer3G->stop();
    }
    qDebug()<<700 -movimiento->getPosy()<<"\n";
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{






    if(evento->key()==Qt::Key_D)
    {
        Franklin->MoveRight();
        if(timer3G->isActive()){
          Franklin->MoveRight();
          Franklin->MoveRight();
          contDer+=3;

        }
    }
    else if(evento->key()==Qt::Key_A)
    {
        Franklin->MoveLeft();
        if(timer3G->isActive()){
          Franklin->MoveLeft();
          Franklin->MoveLeft();
          contIzq+=3;

        }
    }
    else if(evento->key()== Qt::Key_M){


        if(timer->isActive()) {timer->stop();
        }else {timer->start(20);
        }



    }else if(evento->key()== Qt::Key_Space and !timer3G->isActive()){
        movimiento= new Movimiento(Franklin->getPosx(),479 ,55,90);
        timer3G->start(1);
    }



}

