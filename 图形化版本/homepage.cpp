#include "homepage.h"
#include "QLabel"
#include "QPushButton"
#include "QTimer"
#include "QDebug"
#include "panel_body.h"

HomePage::HomePage(QWidget *parent) : QWidget(parent)
{
    setFixedSize(400,800);
    QString buttonStyle = "QPushButton {"
                          "font-size: 24px;"
                          "background-color: rgba(255, 255, 255, 0.8);"
                          "border-radius: 10px;"
                          "border: 1px solid #ccc;"
                          "color: #333;"
                          "}"
                          "QPushButton:hover {"
                          "background-color: rgba(255, 255, 255, 1);"
                          "border: 1px solid #aaa;"
                          "}";
    //页面
   Panel_Body *panel=new Panel_Body(this);
   panel->setGeometry(0,120,400,580);
    //logo
    QLabel *label = new QLabel(this);
            label->setPixmap(QPixmap("./Images/logo.png").scaled(400,120));  // 将图片路径替换为实际路径
            label->setGeometry(0, 0,400,120);  // 设置 QLabel 大小和位置
            // 适应图片大小
            label->setScaledContents(true);
    //按钮组
     QLabel *label2 = new QLabel(this);
             label2->setPixmap(QPixmap("./Images/bottomBar.png").scaled(400,120));  // 将图片路径替换为实际路径
             label2->setGeometry(0,700,400,100);  // 设置 QLabel 大小和位置
              // 适应图片大小
             label2->setScaledContents(true);
    //按钮
    QPushButton *button1=new QPushButton("单品",this);
    button1->setStyleSheet(buttonStyle);
    button1->setGeometry(20,715,70,70);
    connect(button1,&QPushButton::clicked,[panel](){
    panel->exchange(0);
    });
    QPushButton *button2=new QPushButton("套餐",this);;
    button2->setStyleSheet(buttonStyle);
    button2->setGeometry(120,715,70,70);
    connect(button2,&QPushButton::clicked,[panel](){
    panel->exchange(1);
    });

    QPushButton *button3=new QPushButton("订单",this);;
    button3->setStyleSheet(buttonStyle);
    button3->setGeometry(220,715,70,70);
    connect(button3,&QPushButton::clicked,[panel](){
    panel->exchange(2);
    });

    QPushButton *button4=new QPushButton("时间倍数\nx1",this);;
    button4->setStyleSheet(buttonStyle.replace("font-size: 24px;", "font-size: 16px;"));
    button4->setGeometry(320,715,70,70);
    connect(button4,&QPushButton::clicked,[this,button4](){
    if(second==100000){second=1;}
    else{second=second*10;}
    QString test = "时间倍数\nx";
    button4->setText(test.append(QString::number(second)));
    });
    //时钟
    QTimer *timer = new QTimer(this);
    QLabel *timeLable=new QLabel(this);
    timeLable->setStyleSheet("QLabel{background-color: rgba(255,255,255,0.3);border-radius: 5px;"
                             "border: none; color: black;"
                             "font-size: 24px;color: white;}");
    timeLable->setGeometry(200,80,160,30);
    connect(timer, &QTimer::timeout, [this,timeLable,panel](){
    panel->totalSeconds+=second;
    QString timeTitle="时间:";
    timeTitle = timeTitle.append(panel->secondsToHMS(panel->totalSeconds));
    timeLable->setText(timeTitle);
    });
    timer->start(1000); // 每秒更新一次
}

