#include <QCoreApplication>
#include <QDebug>
#include <QMetaObject>
#include <QMetaEnum>
#include "person.h"

/*
 * Builder design pattern
 * Build things in a uniform way - millions of ways to do this.
 */

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject classroom;
    QMetaEnum metaEnum = QMetaEnum::fromType<person::persontype>();

    for(int i = 0; i < 10; i++) {
        person::persontype type = person::persontype::STUDENT;
        if(i == 0) type = person::persontype::PRINCIPAL;
        if(i == 1) type = person::persontype::TEACHER;

        person *p = person::build(type);
        p->setParent(&classroom);
    }

    foreach(QObject *child, classroom.children()) {
        person *p = qobject_cast<person*>(child);
        if(p) qInfo() << p << " is a " << metaEnum.valueToKey(p->role());
    }


    return a.exec();
}
