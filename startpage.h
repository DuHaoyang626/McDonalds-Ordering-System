#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QWidget>
#include <QPushButton>

class StartPage : public QWidget
{
    Q_OBJECT
public:
    QPushButton *button_close;
    QPushButton *button_start;
    explicit StartPage(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    signals:

    };

#endif // STARTPAGE_H
