#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "bolagraf.h"
#include <QTimer>

#define DT 0.1
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int v_limit;
    int h_limit;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void bordercollision(bolagraf *b);

private slots:
    void actualizar();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    bolagraf *obj;
    QTimer *timer;

};
#endif // MAINWINDOW_H
