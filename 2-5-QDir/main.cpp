#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <QString>
#include <QFileInfo>

bool createDir(QString path) {
    QDir dir(path);

    if(dir.exists()) {
        qInfo() << "Already exists!";
        return true;
    }

    if(dir.mkpath(path)) {
        qInfo() << "Created!";
        return true;
    } else {
        qInfo() << "Could not create!";
        return false;
    }
}

bool rename(QString path, QString name) {
    QDir dir(path);

    if(!dir.exists()) {
        qInfo() << "Path does not exist!";
        return false;
    }

    int pos = path.lastIndexOf(QDir::separator());
    QString parent = path.mid(0,pos);
    QString newpath = parent + QDir::separator() + name;

    qInfo() << "Absolute: " << dir.absolutePath();
    qInfo() << "Parent: " << parent;
    qInfo() << "New: " << newpath;

    return  dir.rename(path,newpath);

}

bool remove(QString path) {
    qInfo() << "Removing: " << path;
    QDir dir(path);

    if(!dir.exists()) {
        qInfo() << "Path does not exist!";
        return false;
    }

    //DANGER!!!
    return dir.removeRecursively();

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = QDir::currentPath();
    QString test = path + QDir::separator() + "test";
    QString tmp = path + QDir::separator() + "tmp";

    qInfo() << path;
    qInfo() << test;
    qInfo() << tmp;


    QDir current(QDir::currentPath());
    if(current.exists()) {
        foreach(QFileInfo fi, current.entryInfoList()) {
            qInfo() << fi.fileName();
        }
    }

    if(createDir(test)) {
        qInfo() << "Created test!";
        if(rename(test,"tmp")) {
            qInfo() << "Renamed!";
            if(remove(tmp)) {
                qInfo() << "Removed";
            } else {
                qInfo() << "Could not remove";
            }
        }
    }

    return a.exec();
}









