#ifndef TEST_H
#define TEST_H

#include <QObject>
#include "singleton.h"

class test : public QObject
{
    Q_OBJECT
    static test *createInstance();

public:
    explicit test(QObject *parent = nullptr);

    QString name;
    static test* instance();

signals:

public slots:
};

#endif // TEST_H
