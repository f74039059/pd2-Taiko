#include "target.h"
#include <iostream>
using namespace std;


Target::Target()
{

    button->setFont(QFont("Courier New", 25, QFont::Bold));
    button->setGeometry(595, 100, 70, 70);
    button->show();
    QPixmap button_pixmap(":/bg/button.JPG");
    button->setPixmap(button_pixmap);
    button->setFocusPolicy(Qt::StrongFocus);
    button->setGeometry(595, 100, 70, 70);


    score->setFont(QFont("Courier New", 25, QFont::Bold));
    score->setGeometry(50, 50, 300, 70);
    score->show();

    //123
    myLabel = new QLabel("LABEL");
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(myLabel);
    mainLayout->addWidget(form);
    setLayout(mainLayout);//have reaction to keypress



}

void Target::show_score()
{
    score->setText("Score:"+QString::number(now_score));

}

void Target::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_A)
    {
        int red_pos = red[now_red]->x();
        int red_posy= red[now_red]->y();
        cout<<red_pos<<endl;
        red_hit->stop();
        if(red_pos<610&&red_pos>550)
        {
            red_ani[now_red]->stop();
            red_ani[now_red]->setDuration(700);
            red_ani[now_red]->setStartValue(QRect(red_pos, red_posy, 70,70));
            red_ani[now_red]->setEndValue(QRect(680, 15, 0,0));
            red_ani[now_red]->start();


            blue_hit->setMedia(QUrl("qrc:/bg/small_drum1.mp3"));
            blue_hit->setVolume(150);
            blue_hit->play();




            //red[now_red]->clear();
            now_red++;
            now_score+=20;
            show_score();

        }

    }
    else  if(event->key() == Qt::Key_S)
    {
        int blue_pos = blue[now_blue]->x();
        int blue_posy= blue[now_blue]->y();
        cout<<blue_pos<<endl;
        if(blue_pos<610&&blue_pos>550)
        {
            blue_ani[now_blue]->stop();
            blue_ani[now_blue]->setDuration(700);
            blue_ani[now_blue]->setStartValue(QRect(blue_pos, blue_posy, 70,70));
            blue_ani[now_blue]->setEndValue(QRect(680, 15, 0,0));
            blue_ani[now_blue]->start();

            blue_hit->setMedia(QUrl("qrc:/bg/small_drum1.mp3"));
            blue_hit->setVolume(150);
            blue_hit->play();



            //blue[now_blue]->clear();
            now_blue++;
            now_score+=10;
            show_score();
        }
    }
    else  if(event->key() == Qt::Key_D)
    {
        //test->setText(QString::number(red->x()));
        myLabel->setText("You pressed ESC");
    }
}

