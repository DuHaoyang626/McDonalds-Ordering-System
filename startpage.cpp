#include "startpage.h"
#include "QPainter"
#include "QPushButton"
StartPage::StartPage(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(400,800);
    button_start = new QPushButton("开始点餐", this);
    button_start->resize(150,40);
    button_start->move(140,600);
    button_start->setStyleSheet("QPushButton { font-size: 16px;"
                                "background-color: rgba(255, 255, 255, 0.2);"
                         "border-radius: 5px; border: none; color: black; }");
    button_close = new QPushButton("退出系统", this);
    button_close->resize(150,40);
    button_close->move(140,650);
    button_close->setStyleSheet("QPushButton {font-size: 16px;"
                                " background-color: rgba(255, 255, 255, 0.2);"
                                "border-radius: 5px; border: none; color: black; }");
    connect(button_close, &QPushButton::clicked, parent, &QWidget::close);
}

//绘图事件
void StartPage::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pixmap;
    pixmap.load("./Images/background.png");
    pixmap=pixmap.scaled(this->size());
    painter.drawPixmap(0,0,pixmap);
}
