#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include <QtAlgorithms>

//qFill

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int> list;
    list << 1 << 2 << 3 << 4;

    //Note this is depreciated, use STD::fill instead...or....save yourself some headace and use QVector
    //qFill(list,0);

    list.fill(0);
    qInfo() << list;

    return a.exec();
}
