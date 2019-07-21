#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contact.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.begin(this);
    ui->
    painter.drawLine(QPoint(50,60), QPoint(100,100));

    painter.setBrush(Qt::BDiagPattern);
    painter.drawRect(QRect(150,120,80,30));

}

void MainWindow::on_contactBtn_clicked()
{
    contact* c = new contact();
    c->show();
}

void MainWindow::on_pushButton_clicked()
{

}
