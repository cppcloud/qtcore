#ifndef RACE_H
#define RACE_H

#include <QObject>
#include <QDebug>
#include "car.h"

class race : public car
{
    Q_OBJECT
public:
    explicit race(QObject *parent = nullptr);

signals:

public slots:

    // car interface
public:
    void drive();
};

#endif // RACE_H
