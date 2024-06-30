#include <QCoreApplication>
#include <QDebug>
#include <QMetaObject>
#include <QMetaProperty>
#include <QMetaClassInfo>
#include <QMetaMethod>
#include <QTimer>
#include <QVariant>

void listProperties(QObject *obj) {
    for(int i = 0; i < obj->metaObject()->propertyCount(); i++) {
        QMetaProperty p = obj->metaObject()->property(i);
        qInfo() << "Property: " << p.name() << " is a " << p.typeName() << " = " << p.read(obj);
    }
}

void listMethods(QObject *obj) {
    for(int i = 0; i < obj->metaObject()->methodCount(); i++) {
        QMetaMethod m = obj->metaObject()->method(i);
        qInfo() << "Method: " << m.methodSignature();
    }
}

void listChildren(QObject *obj) {
    qInfo () << "Object: " << obj;
    foreach(QObject *child, obj->children()) {
        qInfo () << child;
        listMethods(child);
        listProperties(child);
        qInfo("");
    }

}

void testProp(QObject *parent, QString name, QVariant value) {
    foreach(QObject *child, parent->children()) {
        child->setProperty(name.toLatin1(), value);
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject parent;
    QTimer *t = new QTimer(&parent);

    testProp(&parent, "interval", 3000);

    listChildren(&parent);

    return a.exec();
}
