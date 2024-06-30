#include <QCoreApplication>
#include <QVector>
#include <QDebug>
#include <QRandomGenerator>

void randoms(QVector<int> *list, int max) {

    list->reserve(max);

    for(int i = 0; i < max; i++){
        int value = QRandomGenerator::global()->bounded(100);
        list->append(value);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int> list1;
    randoms(&list1,10);

    QVector<int> list2;
    randoms(&list2,10);

    qInfo() << list1;
    qInfo() << list2;

    //qInfo() << "Equal: " << qEqual(list1.begin(), list1.end(), list2.begin());
    //qCopy(list1.begin(),list1.end(), list2.begin());
    //qInfo() << "Equal: " << qEqual(list1.begin(), list1.end(), list2.begin());

    qInfo() << "Equal: " << std::equal(list1.begin(), list1.end(), list2.begin());
    std::copy(list1.begin(),list1.end(), list2.begin());
    qInfo() << "Equal: " << std::equal(list1.begin(), list1.end(), list2.begin());


    return a.exec();
}
