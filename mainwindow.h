#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <bomber.h>
#include <galloenemy.h>
#include "bolagraf.h"
#include "movimiento.h"
#include <QTimer>
#include <QKeyEvent>
#include <ball.h>
#include <QSoundEffect>
#include <QAudioOutput>
#include <QMediaPlayer>
#include <QtMultimedia>

#define DT 0.1
QT_BEGIN_NAMESPACE


namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class  QMediaPlayer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int v_limit;
    int h_limit;
    int contIzq=0;
    int contDer=0;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void bordercollision(bolagraf *b);



private slots:
    void actualizar();
    void actualizarG();
    void actualizarBala();
    void ChoquesGoma();
    void ChoquesBall();
    void actualizarProyectiles();
    void invisible();
    void cerrar();


    void on_INICIO_clicked();

    void on_FERRERO_clicked();

    void on_GUACHARAKO_clicked();

    void on_COLORADO_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsScene *sceneInicio;
    QList<bolagraf *> balls;
    BOMBER *Franklin;// jugador principal
    GALLOEnemy  *Colorado;//enemigo

    //balas
    ball *bala;

    ball *balaProy;


    QTimer *timer;
    QTimer *timer2;
     QTimer *timer3G;
     QTimer *timerProy;

    QTimer *timerCierre;

     QTimer *timerMRebote;
     QMediaPlayer *player;
     QAudioOutput *audioOutput ;

     QMediaPlayer *playerR;
     QAudioOutput *audioOutputR ;


     QMediaPlayer *playerB;
     QAudioOutput *audioOutputB ;

     QMediaPlayer *playerChoke;
     QAudioOutput *audioOutputChoke ;







    Movimiento *movimiento;
     Movimiento *movimientoBala;

    Movimiento *movimientoProyectiles;
     int vida =10;
    int salto = 25;





    void keyPressEvent(QKeyEvent *evento);

};
#endif // MAINWINDOW_H
