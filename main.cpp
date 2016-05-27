#include <QApplication>
#include <time.h>
#include <windows.h>
#include <mainwindow.h>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    srand(time(NULL));
/*
    Target *t=new Target;
    t->show();
*/
    return a.exec();
}
