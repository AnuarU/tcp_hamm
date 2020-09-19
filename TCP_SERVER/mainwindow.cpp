#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myserver.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyServer server(2323);
}

MainWindow::~MainWindow()
{
    delete ui;
}
