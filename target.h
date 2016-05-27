#ifndef TARGET_H
#define TARGET_H
#include <QLabel>
#include "ball.h"
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QWidget>
#include <QSoundEffect>



class Target:public QWidget,public Ball{

public:
    Target();
    //void keyPressEvent(QKeyEvent *event);
    QLabel *button= new QLabel("Q", form);
    QLabel *score=new QLabel("Score:0",form);
    void show_score();


protected:
    void keyPressEvent(QKeyEvent *);
private:
    QLabel *myLabel;
    QVBoxLayout *mainLayout;
    int now_score=0;



    QMediaPlayer *red_hit = new QMediaPlayer();
    QMediaPlayer *blue_hit = new QMediaPlayer();
};

#endif // TARGET_H
