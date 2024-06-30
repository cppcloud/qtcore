#ifndef SLOW_H
#define SLOW_H

#include <QObject>
#include <QDebug>
#include "car.h"

class slow : public car
{
    Q_OBJECT
public:
    explicit slow(QObject *parent = nullptr);

signals:

public slots:

    // car interface
public:
    void drive();
};

#endif // SLOW_H
