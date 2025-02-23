#include "panel_body.h"
#include "QPushButton"
#include "dict.h"
#include "QDebug"
#include "QLabel"
#include "QScrollArea"
#include "QGridLayout"
#include "QTableWidget"
#include "QVBoxLayout"
#include <QHeaderView>
#include <QDialog>
#include <QMessageBox>
#include <QTimer>
#include <QFile>

Panel_Body::Panel_Body(QWidget *parent) : QWidget(parent)
{
    //初始化程序
    init1();
    stackedWidget = new QStackedWidget(this);
    stackedWidget->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
    stackedWidget->setGeometry(0,0,400,580);
    initPage1(page1);
    initPage2(page2);
    initPage3(page3);
    stackedWidget->addWidget(page1);
    stackedWidget->addWidget(page2);
    stackedWidget->addWidget(page3);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this](){
    initDate();
   });
    timer->start(1000); // 每秒更新一次
}

void Panel_Body::initDate(){
    const std::string endtime =secondsToHMS(totalSeconds).toUtf8().toStdString();
    Od = chuli(count,times,names,endtime);
    int count_x;
    fd=getFood(count_x);
}


//单品
void Panel_Body::initPage1(QWidget *w) {
    w->resize(400, 580);
    w->setObjectName("mySpecialWidget1");  // 设置控件的对象名称
    w->setStyleSheet("#mySpecialWidget1 { background-color: rgba(0, 0, 0, 0.7); }");  // 使用对象名称来限定样式
    // 设置样式
       QString labelStyle = "QLabel {"
                            "color: white;"
                            "font: bold 14px;"
                            "background-color: rgba(255, 255, 255, 0.1);"
                            "border-radius: 10px;"
                            "}";

       QString buttonStyle = "QPushButton {"
                             "color: white;"
                             "font: bold 14px;"
                             "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
                             "stop:0 #66c2ff, stop: 1 #003d99);"
                             "border: none;"
                             "border-radius: 10px;"
                             "padding: 10px;"
                             "margin: 6px;"
                             "}"
                             "QPushButton:hover {"
                             "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
                             "stop:0 #003d99, stop: 1 #66c2ff);"
                             "}";
    int count;
    fd = getFood(count);

    // 创建滚动区域和容器
    QScrollArea *scrollArea = new QScrollArea(w);
    QWidget *container = new QWidget();
    QGridLayout *layout = new QGridLayout(container);

    // 用于跟踪当前行和列
    int row = 0;
    int col = 0;

    for (int i = 0; i < count; i++) {
        QWidget *itemWidget = new QWidget();  // 创建每个食物的容器
        QVBoxLayout *itemLayout = new QVBoxLayout();  // 为每个食物容器创建垂直布局
        QLabel *label = new QLabel();
        QString filePath ="./Images/one" + QString::number(i+1) + ".png";
        label->setStyleSheet(labelStyle);  // 应用标签样式
        QString htmlContent = QString(
            "<img src='%1' width='140' height='140'><br>"  // 图片部分
            "<b>Name:</b> %2<br>"
            "<b>Max Capacity:</b> %3<br>"
            "<b>Stock:</b> %4<br>"
            "<b>Production Time:</b> %5 second<br>")
            .arg(filePath)  // 图片路径
            .arg(fd[i].name)  // 食物名称
            .arg(fd[i].maxCapacity)  // 最大容量
            .arg(fd[i].stock)  // 当前库存
            .arg(fd[i].productionTime); // 生产时间
        label->setText(htmlContent);
        label->setWordWrap(true);
        QPushButton *orderButton = new QPushButton("Order");
         orderButton->setStyleSheet(buttonStyle);  // 应用按钮样式
        // 连接按钮点击信号到适当的槽函数（需要实现）
        connect(orderButton, &QPushButton::clicked, [this,i,filePath,label]() {
            int H =(totalSeconds/3600)%24;
        if(H < 7){QMessageBox::warning(this, "Warning", "无法点餐");}
        else{
            this->times[this->count]=this->secondsToHMS(this->totalSeconds).toUtf8().toStdString();
            this->names[this->count]=fd[i].name;
            this->count++;
            QString htmlContent = QString(
                "<img src='%1' width='140' height='140'><br>"  // 图片部分
                "<b>Name:</b> %2<br>"
                "<b>Max Capacity:</b> %3<br>"
                "<b>Stock:</b> %4<br>"
                "<b>Production Time:</b> %5 second<br>")
                .arg(filePath)  // 图片路径
                .arg(fd[i].name)  // 食物名称
                .arg(fd[i].maxCapacity)  // 最大容量
                .arg(fd[i].stock)  // 当前库存
                .arg(fd[i].productionTime); // 生产时间
            label->setText(htmlContent);
        }
        });
        itemLayout->addWidget(label);
        itemLayout->addWidget(orderButton);
        itemWidget->setLayout(itemLayout);
        layout->addWidget(itemWidget, row, col);  // 将食物容器添加到网格布局

        col++;
        if (col >= 2) {  // 每行显示两个
            col = 0;
            row++;
        }
    }
    // 设置布局和滚动区
    container->setLayout(layout);
    scrollArea->setWidget(container);
    scrollArea->setWidgetResizable(true);
    scrollArea->setGeometry(10, 10, 380, 560);
    w->show();
}


//套餐
void Panel_Body::initPage2(QWidget *w){
    w->resize(400, 580);
    w->setObjectName("mySpecialWidget2");  // 设置控件的对象名称
    w->setStyleSheet("#mySpecialWidget2 { background-color: rgba(0, 0, 0, 0.7); }");  // 使用对象名称来限定样式
    // 设置样式
       QString labelStyle = "QLabel {"
                            "color: white;"
                            "font: bold 14px;"
                            "background-color: rgba(255, 255, 255, 0.1);"
                            "border-radius: 10px;"
                            "}";

       QString buttonStyle = "QPushButton {"
                             "color: white;"
                             "font: bold 14px;"
                             "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
                             "stop:0 #66c2ff, stop: 1 #003d99);"
                             "border: none;"
                             "border-radius: 10px;"
                             "padding: 10px;"
                             "margin: 6px;"
                             "}"
                             "QPushButton:hover {"
                             "background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
                             "stop:0 #003d99, stop: 1 #66c2ff);"
                             "}";
    int countC;
   Combo *Cb = getCombo(countC);
    // 创建滚动区域和容器
    QScrollArea *scrollArea = new QScrollArea(w);
    QWidget *container = new QWidget();
    QGridLayout *layout = new QGridLayout(container);
    // 用于跟踪当前行和列
    int row = 0;
    int col = 0;
    for (int i = 0; i <countC; i++) {
        QWidget *itemWidget = new QWidget();  // 创建每个食物的容器
        QVBoxLayout *itemLayout = new QVBoxLayout();  // 为每个食物容器创建垂直布局
        QLabel *label = new QLabel();
         QString filePath ="./Images/more" + QString::number(i+1) + ".png";
        label->setStyleSheet(labelStyle);  // 应用标签样式
        QString htmlContent = QString(
            "<img src='%1' width='140' height='140'><br>"  // 图片部分
            "<b>Name:</b> %2<br>")
            .arg(filePath)  // 图片路径
            .arg(Cb[i].name);
        label->setText(htmlContent);
        label->setWordWrap(true);
        QPushButton *orderButton = new QPushButton("Order");
         orderButton->setStyleSheet(buttonStyle);  // 应用按钮样式
        // 连接按钮点击信号到适当的槽函数（需要实现）
        connect(orderButton, &QPushButton::clicked, [this,i,Cb]() {
            int H =(totalSeconds/3600)%24;
        if(H < 7){QMessageBox::warning(this, "Warning", "无法点餐");}
        else{
            this->times[this->count]=this->secondsToHMS(this->totalSeconds).toUtf8().toStdString();
            this->names[this->count]=Cb[i].name;
            this->count++;
        }
        });
        itemLayout->addWidget(label);
        itemLayout->addWidget(orderButton);
        itemWidget->setLayout(itemLayout);
        layout->addWidget(itemWidget, row, col);  // 将食物容器添加到网格布局

        col++;
        if (col >= 2) {  // 每行显示两个
            col = 0;
            row++;
        }
    }
    // 设置布局和滚动区
    container->setLayout(layout);
    scrollArea->setWidget(container);
    scrollArea->setWidgetResizable(true);
    scrollArea->setGeometry(10, 10, 380, 560);
    w->show();
}

//订单
void Panel_Body::initPage3(QWidget *w){
    w->resize(500, 500);
    w->setObjectName("mySpecialWidget3");
    w->setStyleSheet("#mySpecialWidget3 { background-color: rgba(0, 0, 0, 0.7); }");

    // 主容器和布局
    QWidget *mainContainer = new QWidget(w);
    QVBoxLayout *mainLayout = new QVBoxLayout(mainContainer);
    mainContainer->resize(400, 580);
    // 创建滚动区域
    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // 创建表格部件
    QTableWidget *table = new QTableWidget(0, 2);
    table->setHorizontalHeaderLabels(QStringList() << "时间" << "产品名字");
    table->horizontalHeader()->setStretchLastSection(true);
    table->setFixedSize(340, 580);
    table->setShowGrid(false);
    table->setStyleSheet("QTableWidget { color: white;background-color:rgba(0, 0, 0, 0.7); }");
    // 分配列宽
    int columnWidth =340 / 2;
    table->setColumnWidth(0, columnWidth);
    table->setColumnWidth(1, columnWidth);

    // 添加数据到表格
    for (int i = 0; i < count; ++i) {
        int row = table->rowCount();
        table->insertRow(row);
        table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(times[i])));
        table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(names[i])));
    }
    // 将表格添加到滚动区的容器中
    QWidget *container = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(container);
    layout->addWidget(table);
    container->setLayout(layout);
    scrollArea->setWidget(container);
    // 将滚动区域添加到主布局
    mainLayout->addWidget(scrollArea);
    // 创建提交按钮
    QString buttonStyle = "QPushButton {"
                          "font-size: 24px;"
                          "background-color: rgba(255, 255, 255, 0.6);"
                          "border-radius: 10px;"
                          "border: 1px solid #ccc;"
                          "color: #333;"
                          "}"
                          "QPushButton:hover {"
                          "background-color: rgba(255, 255, 255, 1);"
                          "border: 1px solid #aaa;"
                          "}";
    QPushButton *submitButton = new QPushButton("提交订单");
    submitButton->setStyleSheet(buttonStyle);
    connect(submitButton, &QPushButton::clicked, [this]() {
    qDebug()<<count;
    showDindanDialog();
    });
    mainLayout->addWidget(submitButton);
    mainContainer->setLayout(mainLayout);
    mainContainer->show();
}

//改变页面函数
void Panel_Body::exchange(int index){
    stackedWidget->setCurrentIndex(index);
    if(index==2){
    initPage3(stackedWidget->widget(index));
    };
}

QString Panel_Body::secondsToHMS(long long totalSeconds) {
    int hours = (totalSeconds / 3600) % 24;  // 计算小时数，并取余24
    int minutes = (totalSeconds % 3600) / 60;  // 计算分钟数
    int seconds = totalSeconds % 60;  // 剩余的秒数
    return QString("%1:%2:%3")
        .arg(hours, 2, 10, QChar('0'))  // 格式化小时，保证至少两位，小时超过24时从零开始
        .arg(minutes, 2, 10, QChar('0'))  // 格式化分钟，保证至少两位
        .arg(seconds, 2, 10, QChar('0'));  // 格式化秒，保证至少两位
}

void Panel_Body::showDindanDialog() {
     for (size_t i = 0; i < count; ++i) {
         qDebug()<<QString::fromStdString(times[i])<<" "<<QString::fromStdString(names[i]);
     }
     const std::string endtime =secondsToHMS(totalSeconds).toUtf8().toStdString();
    Od = chuli(count,times,names,endtime);

    QDialog *dialog = new QDialog(this);  // 创建对话框
    dialog->setWindowTitle("Order Details");
    dialog->resize(600, 400);  // 设置对话框大小

    // 创建表格部件
    QTableWidget *table = new QTableWidget(0,4, dialog);
    table->setHorizontalHeaderLabels({"Name","Arrival Time","Status","Finish Time"});
    table->horizontalHeader()->setStretchLastSection(true);
    table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);  // 自动调整大小
    // 填充表格数据
     Order *current = Od;
    for(int i=0;i<count;i++)
    {
        int row = table->rowCount();
        table->insertRow(row);  // 插入新行
        table->setItem(row, 0, new QTableWidgetItem(QString::fromLatin1(current[i].name)));
        table->setItem(row, 1, new QTableWidgetItem(QString::number(current[i].tr.hour)+":"+QString::number(current[i].tr.minute)+":"+QString::number(current[i].tr.second)));
        QString text("");
        if(current[i].isCompleted==0)
        {
            text="success";
        }
        else if(current[i].isCompleted==1)
        {
            text="pending";
        }
        else text="Fail";
        table->setItem(row, 2, new QTableWidgetItem(text));
        /////
        QString finish("");
        if(current[i].isCompleted==0)
        {
            finish=QString::number(Od[i].tr2.hour)+":"+QString::number(Od[i].tr2.minute)+":"+QString::number(Od[i].tr2.second);
        }
        else if(current[i].isCompleted==1)
        {
            finish="Pending";
        }
        else finish="Fail";
        table->setItem(row, 3, new QTableWidgetItem(finish));
        /////
    }

    // 创建布局并添加部件
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(table);  // 将表格添加到布局

    // 添加关闭按钮
    QPushButton *closeButton = new QPushButton("Close", dialog);
    layout->addWidget(closeButton);
    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);
    dialog->setLayout(layout);  // 设置布局
    dialog->exec();  // 执行对话框
    saveOrdersToFile();
    free(Od);
}

void Panel_Body::saveOrdersToFile() {
    const QString& filePath="output.txt";
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing.";
        return;
    }
    QTextStream out(&file);
        for (int i = 0; i < count; ++i) {
            if (Od[i].isCompleted == 0)
               out<<QString::number(Od[i].tr.hour)+":"+QString::number(Od[i].tr.minute)+":"+QString::number(Od[i].tr.second)<<"\n";
            else
                out<<"Fail"<<"\n";
        }
        file.close();
        qDebug() << "Orders saved to file successfully.";
}

