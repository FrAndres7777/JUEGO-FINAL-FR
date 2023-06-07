#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sceneInicio=new QGraphicsScene(this);
    sceneInicio->setBackgroundBrush(QPixmap(":/imagens/FONDOINICIO.jpg").scaled(1400,700));
    ui->graphicsView->setFixedSize(1400,700);
    h_limit = 1400;
    v_limit = 700;
    ui->graphicsView->setScene(sceneInicio);
    sceneInicio->setSceneRect(0,0,h_limit,v_limit);
    sceneInicio->addRect(sceneInicio->sceneRect());

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->INICIO->setVisible(false);




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
        b->getEsfera()->setVx(b->getEsfera()->getVx()*-1.01);
        playerR->play();
    }

    if(b->getEsfera()->getPy() < b->getEsfera()->getRad() || b->getEsfera()->getPy() > v_limit-b->getEsfera()->getRad()){
        b->getEsfera()->setVy(b->getEsfera()->getVy()*-1.01);
        playerR->play();



    }
    qDebug()<< (b->getEsfera()->getVy())<<"\n";


}

void MainWindow::actualizar()

{
    QList<bolagraf*>::Iterator it;
    for(it=balls.begin();it!= balls.end();it++){
        (*it)->actualizar(DT,v_limit);
        bordercollision(*it);
        qDebug()<< ((*it)->getEsfera()->getVx())<<"\n";

    }
    ChoquesGoma();
    ChoquesBall();


}

void MainWindow::actualizarG()
{
    movimiento->calVelocidad();
    movimiento->calPosicion();
    movimiento->newPosicion();
    Franklin->setPos(Franklin->getPosx(),700 -movimiento->getPosy());
    Franklin->setPosy(700 -movimiento->getPosy());


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
        movimiento= new Movimiento(Franklin->getPosx(),479 ,salto,90);
        timer3G->start(2);
    }



}


void MainWindow::actualizarBala()
{

    movimientoBala->calPosicionBala();
    movimientoBala->calVelocidadBala();
    bala->setPos(1350 -movimientoBala->getPosx(),bala->getPosy());
    if(1350 -movimientoBala->getPosx() < 0){
        bala->setPos(1350,0);
        movimientoBala = new Movimiento(0 , 600 , 200);

        playerB = new QMediaPlayer;
        audioOutputB = new QAudioOutput;
        playerB->setAudioOutput(audioOutputB);
        // ...
        playerB->setSource(QUrl::fromLocalFile("qrc:/Music/SonidoBala.mp3"));
        playerB->play();



    }
}

void MainWindow::ChoquesGoma()
{
    if (vida<=0){
        close();
    }
    QList<bolagraf*>::Iterator it;
    for(it=balls.begin();it!= balls.end();it++){
        if(Franklin->collidesWithItem(*it)){
          (*it)->setPos(1300,500);
          (*it)->getEsfera()->setPx(1300);
           (*it)->getEsfera()->setPy(500);
            playerChoke->play();
            vida= vida-1;




        }
    }
}

void MainWindow::ChoquesBall()
{
    if (Franklin->collidesWithItem(bala)){
        playerChoke->play();
        vida= vida-1;
        bala->setPos(1350,0);
        movimientoBala = new Movimiento(0 , 600 , 200);

    }
    if(Franklin->collidesWithItem(balaProy)){
         playerChoke->play();
        int vel = (abs(Franklin->getPosx()-balaProy->getPosx())*9.8)/sin(90) ;
        vel= sqrt(vel);
        vida= vida-1;


        balaProy->setPos(0,700);
        movimientoProyectiles =new Movimiento(660,2*40,vel+25,140);
        balaProy = new ball(660,0,20);
        scene->addItem(balaProy);
    }
}

void MainWindow::actualizarProyectiles()
{

    movimientoProyectiles->calVelocidad();
    movimientoProyectiles->calPosicion();
    movimientoProyectiles->newPosicion();
    balaProy->setPos(movimientoProyectiles->getPosx(),700 -movimientoProyectiles->getPosy());
    qDebug()<< balaProy->getPosy() <<"\n" ;
    if(700 -movimientoProyectiles->getPosy() > 620){
        //timerProy->stop();
        //movimientoProyectiles->setAngulo(339);
        //movimientoProyectiles->setVelocidad(100);
        //movimientoProyectiles->setPosx(650);
        //movimientoProyectiles->setPosy(80);
        //balaProy->setPosx(600);
        //balaProy->setPosy(0);

        int vel = (abs(Franklin->getPosx()-balaProy->getPosx())*9.8)/sin(90) ;
        vel= sqrt(vel);


        balaProy->setPos(0,700);
       movimientoProyectiles =new Movimiento(660,2*40,vel+25,140);
        balaProy = new ball(660,0,20);
       scene->addItem(balaProy);
        movimientoProyectiles->calVelocidad();
        movimientoProyectiles->calPosicion();
        movimientoProyectiles->newPosicion();
        balaProy->setPos(movimientoProyectiles->getPosx(),700 -movimientoProyectiles->getPosy());

    }

}






void MainWindow::on_INICIO_clicked()
{
    ui->INICIO->setVisible(false);

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



    balls.push_back(new bolagraf(1300,60,-1,4,30,1));
    scene->addItem(balls.back());
    balls.push_back(new bolagraf(1350,80,-1,4,30,1));
    scene->addItem(balls.back());
    balls.push_back(new bolagraf(700,45,-1,4,35,1));
    scene->addItem(balls.back());
    //balls.push_back(new bolagraf(300,30,5,5,35,1));
    //scene->addItem(balls.back());

    //personaje

    scene->addItem(Franklin);

    //GAllos lanzador de balas y  proyectiles parabolicos
    Colorado = new GALLOEnemy(655,300,45);
    scene->addItem(Colorado);


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

    //music Bala
    playerB = new QMediaPlayer;
    audioOutputB = new QAudioOutput;
    playerB->setAudioOutput(audioOutputB);
    // ...
    playerB->setSource(QUrl::fromLocalFile("qrc:/Music/SonidoBala.mp3"));
    playerB->play();
    // MUSIC CHOQUE
    playerChoke = new QMediaPlayer;
    audioOutputChoke = new QAudioOutput;
    playerChoke->setAudioOutput(audioOutputChoke);
    // ...
    playerChoke->setSource(QUrl::fromLocalFile("qrc:/Music/CHOKEFrBALL.mp3"));
    playerChoke->stop();





    //BALA
    bala = new ball (0, 550 ,20);
    scene->addItem(bala);
    movimientoBala = new Movimiento(0 , 0 , 200);


    timer = new QTimer;
    timer->stop();
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizar()));
    timer->start(20);

    //cierre programa
    timerCierre = new QTimer;
    timerCierre->stop();
    connect(timerCierre, SIGNAL(timeout()), this, SLOT(cerrar()));
    timerCierre->start(120000);



    timer3G = new QTimer;
    timer3G->stop();
    connect(timer3G, SIGNAL(timeout()), this, SLOT(actualizarG()));

    connect(timer, SIGNAL(timeout()), this, SLOT(actualizarBala()));
    // Proyectiles     //

    movimientoProyectiles =new Movimiento(600,2*40,110,140);
    balaProy = new ball(600,0,20);
    scene->addItem(balaProy);
    timerProy = new QTimer;
    connect(timerProy,SIGNAL(timeout()),this,SLOT(actualizarProyectiles()));
    timerProy->start(10);

}

void MainWindow::invisible()
{

    ui->INICIO->setVisible(true);
    ui->COLORADO->setVisible(false);
    ui->FERRERO->setVisible(false);
    ui->GUACHARAKO->setVisible(false);
}

void MainWindow::cerrar()
{
    close();
}


void MainWindow::on_FERRERO_clicked()
{
    Franklin = new BOMBER (0,286,50);
    vida = 15;
    invisible();
}


void MainWindow::on_GUACHARAKO_clicked()
{
     Franklin = new BOMBER (0,286,50);
    vida = 9;
     Franklin->setVelocidad(7);
    invisible();
}


void MainWindow::on_COLORADO_clicked()
{
     Franklin = new BOMBER (0,286,50);
    vida = 9;
     salto = 38;
    invisible();
}

