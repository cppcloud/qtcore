#ifndef TEST_H
#define TEST_H

#include <QObject>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);

    void dostuff();
    void dostuff(QString param);

signals:
    void mysignal();
public slots:
    void myslot();
};

#endif // TEST_H
