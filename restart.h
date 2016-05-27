#ifndef RESTART_H
#define RESTART_H
#include "ball.h"
#include <QPushButton>

class Restart:public Ball
{
public:
    Restart();
    QPushButton *restart;
};

#endif // RESTART_H
