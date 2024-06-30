#include <QCoreApplication>
#include <QHash>
#include <QDebug>

// QHash - QHash<Key, T> is one of Qt's generic container classes.
// It stores (key, value) pairs and provides very fast lookup of the value associated with a key.

// Works great with static info that wont change much


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHash<QString, int> ages;
    ages.insert("Bryan", 44);
    ages.insert("Tammy", 49);
    ages.insert("Heather", 25);
    ages.insert("Chris", 27);
    ages.insert("Rango", 15);

    qInfo() << "Bryan is " << ages["Bryan"] << "years old";
    qInfo() << "Keys: " << ages.keys();
    qInfo() << "Size: " << ages.size();

    foreach(QString key, ages.keys()) {
        qInfo() << key << " = " << ages[key];
    }


    return a.exec();
}
