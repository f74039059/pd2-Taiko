#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QWidget *first=new QWidget;
    QLabel *bg;
    QPushButton *start;

private slots:
    void open();

};

#endif // MAINWINDOW_H
