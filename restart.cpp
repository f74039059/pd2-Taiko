#include "restart.h"
#include <QPushButton>

Restart::Restart()
{
    restart = new QPushButton("Restart",form);
    restart->setFont(QFont("Courier New", 25, QFont::Bold));
    restart->setGeometry(250, 250, 180, 70);

    //QObject::connect(restart, SIGNAL(clicked()), this, SLOT(replay()));

}

