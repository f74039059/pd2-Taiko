#ifndef BALL_H
#define BALL_H
#include <QtCore>
#include <QMainWindow>
#include <QLabel>
#include <QObject>
#include <QTimer>
#include <QPropertyAnimation>
#include <QMediaPlayer>
#include <QPushButton>

class Ball: public QObject
{
    Q_OBJECT
public:
    QWidget *form=new QWidget;
    Ball();
    QLabel *red[300];
    QPropertyAnimation *red_ani[300];
    QLabel *blue[300];
    QPropertyAnimation *blue_ani[300];
    int red_all=0,blue_all=0;
    int now_red=0,now_blue=0;
    int now_time=120;
    QPushButton *restart;


public slots:
    void countDown();
    void createBall();
    void deleteBall();
    //void replay();
private:
    void stopGame();
    int randomBall();

     QMediaPlayer *music = new QMediaPlayer();
     QTimer *timer_clock;
     QTimer *timer_create;
     QTimer *timer_delete;
     int color;
     QLabel *TL;
     QLabel *remainTime;






};

#endif // BALL_H
