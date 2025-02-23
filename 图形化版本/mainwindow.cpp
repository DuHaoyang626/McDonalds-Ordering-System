#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStackedWidget"
#include "startpage.h"
#include "homepage.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize(400,800);
    this->setWindowTitle("McDonaLds");
    QStackedWidget *stackedWidget = new QStackedWidget(this);
    StartPage *startpage=new StartPage(this);
    HomePage  *homepage = new HomePage(this);
    stackedWidget->addWidget(startpage);
    stackedWidget->addWidget(homepage);
    stackedWidget->setFixedSize(400,800);
    stackedWidget->setCurrentIndex(0);
    connect(startpage->button_start, &QPushButton::clicked,[stackedWidget](){
    stackedWidget->setCurrentIndex(1);
    });
}
MainWindow::~MainWindow()
{
    delete ui;
}

