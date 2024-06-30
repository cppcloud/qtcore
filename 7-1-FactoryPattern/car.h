#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QMetaEnum>
#include <QDebug>

class car : public QObject
{
    Q_OBJECT
public:
    enum Model{SLOWCAR,SPORTSCAR,RACECAR};
    Q_ENUM(Model);

    explicit car(QObject *parent = nullptr);
    static car* make(Model model);
    virtual void drive() = 0;
signals:

public slots:
};

#endif // CAR_H
