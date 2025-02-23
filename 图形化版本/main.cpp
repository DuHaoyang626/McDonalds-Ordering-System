#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//应用程序类，用于接收事件处理
    MainWindow w;//创建窗口对象
    w.show();//显示窗口
    return a.exec();//阻塞函数，进入事件循环
}
