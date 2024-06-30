#include <QCoreApplication>
#include <QMetaEnum>
#include "car.h"

//Factory method
/*
    A framework needs to standardize the architectural model for a range of applications,
    but allow for individual applications to define their own domain objects and provide for their instantiation.
 */

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMetaEnum metaEnum = QMetaEnum::fromType<car::Model>();
    for(int i = 0; i < metaEnum.keyCount(); i++) {
        QString key = metaEnum.key(i);
        qInfo() << "Attempting to create: " << key;
        car::Model model = static_cast<car::Model>(metaEnum.keysToValue(key.toLatin1()));
        car *c = car::make(model);
        c->drive();
        qInfo("");
    }


    return a.exec();
}
