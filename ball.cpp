#include "ball.h"
#include <time.h>
#include <iostream>
#include <windows.h>
#include <string>
#define WIDTH_F   751
#define HEIGHT_F 371
using namespace std;
Ball::Ball()
{
    form->setWindowTitle("Hello, Qt!");
    form->setMinimumSize(WIDTH_F, HEIGHT_F);
    form->setMaximumSize(WIDTH_F, HEIGHT_F);
    form->show();
    TL= new QLabel("Time:", form);
    TL->setFont(QFont("Courier New", 25, QFont::Bold));
    TL->setGeometry(550, 50, 160, 70);
    TL->show();

    remainTime= new QLabel(QString::number(now_time), form);
    remainTime->setFont(QFont("Courier New", 25, QFont::Bold));
    remainTime->setGeometry(650, 50, 160, 70);
    remainTime->show();

    timer_clock = new QTimer(this);
    QObject::connect(timer_clock, SIGNAL(timeout()), this, SLOT(countDown()));
    timer_clock->start(1000);

    timer_create= new QTimer(this);
    QObject::connect(timer_create, SIGNAL(timeout()), this, SLOT(createBall()));
    timer_create->start(300);

    timer_delete= new QTimer(this);
    QObject::connect(timer_delete, SIGNAL(timeout()), this, SLOT(deleteBall()));
    timer_delete->start(100);

    int g=0;
    for(g=0;g<300;g++)
    {
        red[g] = new QLabel("red",form);
        blue[g] = new QLabel("blue",form);
        red[g]->setGeometry(0, 0, 0, 0);//防止一開始沒產生a卻先按的bug
        blue[g]->setGeometry(0, 0, 0, 0);//防止一開始沒產生卻先按的bug
    }




    music->setMedia(QUrl("qrc:/bg/Aimer（エメ）「LAST - STARDUST」.mp3"));
    music->setVolume(50);
    music->play();

}

int Ball::randomBall()
{
    //0=red,1=blue,2=nothing
    int b=0;
    b= rand()%100;
    if(b<=50&&b>=0)
    {
        b=0;
    }
    else if(b>50&&b<=80)
    {
        b=1;
    }
    else
        b=2;
    return b;

}


void Ball::countDown()
{
    int nextTime = remainTime->text().toInt()-1;
    remainTime->setText(QString::number(nextTime));
    remainTime->show();
    if(nextTime==0)
    {
        stopGame();
    }

}
void Ball::createBall()
{
   /* x+=1;
    cout<<x<<endl;*/
    int a;
    a=randomBall();
    if(a==0)
    {
    red[red_all] = new QLabel("red",form);
    red[red_all]->show();
    QPixmap red_pixmap(":/bg/red.JPG");
    red[red_all]->setPixmap(red_pixmap);
    red_ani[red_all] = new QPropertyAnimation(red[red_all], "geometry");
    red_ani[red_all]->setDuration(1800);
    red_ani[red_all]->setStartValue(QRect(100, 100, 70,70));
    red_ani[red_all]->setEndValue(QRect(650, 100, 70,70));
    red_ani[red_all]->start();

    red_all++;

    }
    else if (a==1)
    {
        blue[blue_all] = new QLabel("blue",form);
        blue[blue_all]->show();
        QPixmap blue_pixmap(":/bg/blue.JPG");
        blue[blue_all]->setPixmap(blue_pixmap);
        blue_ani[blue_all] = new QPropertyAnimation(blue[blue_all], "geometry");
        blue_ani[blue_all]->setDuration(1800);
        blue_ani[blue_all]->setStartValue(QRect(100, 100, 70,70));
        blue_ani[blue_all]->setEndValue(QRect(650, 100, 70,70));
        blue_ani[blue_all]->start();
        blue_all++;
    }
}

void Ball::deleteBall()
{
    if(red[now_red]->x()>640)
    {
        red[now_red]->clear();
        now_red++;
    }
    else if(blue[now_blue]->x()>640)
    {
        blue[now_blue]->clear();
        now_blue++;
    }



}

void Ball::stopGame()
{
    timer_clock->stop();
    timer_create->stop();
    timer_delete->stop();
    //將以產生的球刪除
    int g=0;

    for(g=0;g<300;g++)
    {

        red[g]->clear();
        blue[g]->clear();
    }
    music->stop();

}


