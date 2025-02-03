#ifndef PANEL_BODY_H
#define PANEL_BODY_H

#include <QWidget>
#include <QStackedWidget>
#include "dict.h"

class Panel_Body : public QWidget
{
    Q_OBJECT
public:
    explicit Panel_Body(QWidget *parent = nullptr);
    void showDindanDialog();
    void initDate();
    void initPage1(QWidget *w);
    void initPage2(QWidget *w);
    void initPage3(QWidget *w);
    void exchange(int index);
    void saveOrdersToFile();
    int count=0;
    Order *Od;
    Food  *fd ;
    std::string times[1000];
    std::string names[1000];
    QString secondsToHMS(long long totalSeconds);
    long long totalSeconds=25200;
    int second=1;

    signals:

    private:
    QStackedWidget *stackedWidget;
    QWidget *page1 =new QWidget();
    QWidget *page2 =new QWidget();
    QWidget *page3 =new QWidget();
};

#endif // PANEL_BODY_H
