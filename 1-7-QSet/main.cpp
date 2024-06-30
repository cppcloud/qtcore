#include <QCoreApplication>
#include <QSet>
#include <QDebug>
#include <QString>

//QSet<T> is one of Qt's generic container classes.
//It stores values in an unspecified order and provides very fast lookup of the values.

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSet<QString> people;
    people << "Bryan" << "Heather" << "Tammy" << "Chris";
    people.insert("Rango");

    //Notice this is out of order!!!
    foreach(QString person, people) {
        qInfo() << person;
    }

    //Very Fast
    qInfo() << "Bryan in collection: " << people.contains("Bryan");


    return a.exec();
}
