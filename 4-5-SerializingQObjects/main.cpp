//Updated code thanks to Tom Betka points out that Qt versioning can cause issues - when in doubt define the version

#include <QCoreApplication>
#include <QDebug>
#include <QDataStream>
#include <QFile>

static const QDataStream::Version myQtVersion = QDataStream::Qt_5_8;

bool saveFile(QString path, QDataStream::Version v)
{
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }

    QString title = "The answer is 42";
    qint64 num = 42;

    // This will be a serialized binary data file, not an ASCII file
    QDataStream out(&file);
    out.setVersion(v);

    out << title << num;
    file.flush();
    file.close();

    return true;
}

bool readFile(QString path, QDataStream::Version v)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }

    // This will be a serialized binary data file, not an ASCII file
    QDataStream in(&file);
    in.setVersion(v);

    // This check is no long needed because we just set the version
    //
    //    NOTE: in.version() would NOT return the enum value for Qt_5_8, because the
    //            latest version on my machine is Qt_5_13.
    //    if (in.version() != myQtVersion) {
    //        qCritical() << "Bad Qt version";
    //        file.close();
    //        return false;
    //    }

    QString title;
    qint64 num;

    in >> title >> num;

    qInfo() << "Title: " << title;
    qInfo() << "Number: " << num;
    file.close();

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString file = "test.txt";
    if(saveFile(file, myQtVersion)) {
        qInfo() << "Saved!\r\n";

        if (readFile(file, myQtVersion)) {
            qInfo() << "Read!\r\n";
        } else {
            qInfo() << "Could not read file";
        }
    } else {
        qInfo() << "Could not save the file";
    }

    return a.exec();
}


/*

Original code

#include <QCoreApplication>
#include <QDebug>
#include <QDataStream>
#include <QFile>

//Serialization

bool saveFile(QString path) {
    QFile file(path);

    if(!file.open(QIODevice::WriteOnly)) return false;

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_11);

    QString title = "The answer is 42";
    qint64 num = 42;

    out << title;
    out << num;

    file.flush();
    file.close();

    return true;
}

bool readFile(QString path) {
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) return false;

    QDataStream in(&file);
    if(in.version() != QDataStream::Qt_5_11) {
        qCritical() << "Bad version!";
        file.close();
        return false;
    }

    QString title;
    qint64 num;


    in >> title;
    in >> num;

    qInfo() << title;
    qInfo() << num;

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString file = "test.txt";

    if(saveFile(file)) {
        qInfo() << "Saved!";
        readFile(file);
    }

    return a.exec();
}
*/
