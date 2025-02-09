#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    int second=1;

    signals:

    };

#endif // HOMEPAGE_H
