#include <QCoreApplication>
#include <QDebug>
#include <QMetaObject>
#include <QMetaProperty>
#include <QMetaClassInfo>
#include <QMetaMethod>
#include <QTimer>
#include "test.h"

void listProperties(QObject *obj) {
    for(int i = 0; i < obj->metaObject()->propertyCount(); i++) {
        QMetaProperty p = obj->metaObject()->property(i);
        qInfo() << "Property: " << p.name() << " is a " << p.typeName();
    }
}


void listMethods(QObject *obj) {
    for(int i = 0; i < obj->metaObject()->methodCount(); i++) {
        QMetaMethod m = obj->metaObject()->method(i);
        qInfo() << "Method: " << m.methodSignature();
    }
}

void listChildren(QObject *obj) {
    qInfo() << "Object: " << obj;

    foreach(QObject *child,obj->children()){
        qInfo() << child;
        listMethods(child);
        listProperties(child);
        qInfo("");
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject parent;
    QTimer *t = new QTimer(&parent);

    for(int i = 0; i < 5; i++) {
        test *child = new test(&parent);
        child->setObjectName("Child " + QString::number(i));
    }

    listChildren(&parent);

    return a.exec();
}
