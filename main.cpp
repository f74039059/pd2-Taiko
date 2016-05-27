#include <QApplication>
#include <time.h>
#include <windows.h>
#include "target.h"

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    srand(time(NULL));
    //Ball *test=new Ball;
    Target *t=new Target;
    t->show();
    return a.exec();
}
