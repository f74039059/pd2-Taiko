#include "mainwindow.h"
#define WIDTH  581
#define HEIGHT 311
#include "target.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    this->setWindowTitle("Taiko");
    this->setMinimumSize(WIDTH,HEIGHT);
    this->setMaximumSize(WIDTH,HEIGHT);
    this->setStyleSheet("background-image:url(:/bg/pic2.jpg);");
    start = new QPushButton("Start",this);
    start->setFont(QFont("Courier New", 25, QFont::Bold));
    start->setGeometry(250, 200, 100, 70);
    start->show();
    QObject::connect(start, SIGNAL(clicked()), this, SLOT(open()));


}

MainWindow::~MainWindow()
{

}

void MainWindow::open()
{
    this->close();
    Target *t=new Target;
    t->show();
}
