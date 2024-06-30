#include <QCoreApplication>
#include <QDebug>
#include <QSharedPointer>
#include "test.h"
#include "consumer.h"

//QSharedPointer will delete the pointer it is holding when it goes out of scope,
//provided no other QSharedPointer objects are referencing it.


void doDeleteLater(test *obj) {
    qInfo() << "Deleting: " << obj;
    obj->deleteLater();
}

QSharedPointer<test> createPointer() {
    test *t = new test(); // the bad way!!!
    t->setObjectName("Test Object");
    QSharedPointer<test> p(t,doDeleteLater); //&QObject::deleteLater
    return p;
}

void doStuff(QSharedPointer<consumer> ptr) {
    qInfo() << "In function: " << ptr.data()->tester;

    ptr.clear(); //Does not actually delete!, just removes the reference
}


QSharedPointer<consumer> makeConsumer() {
    QSharedPointer<consumer> c(new consumer, &QObject::deleteLater);
    QSharedPointer<test> t = createPointer();

    c.data()->tester.swap(t);
    doStuff(c);

    return c;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSharedPointer<consumer> consume = makeConsumer();
    qInfo() << "In main: " << consume.data()->tester;

    consume.clear(); //Does not actually delete!, just removes the reference



    return a.exec();
}
