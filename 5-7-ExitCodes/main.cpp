#include <QCoreApplication>
#include <QDebug>
#include<QProcess>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Starting...";
    QProcess proc;
    proc.execute("xed",QStringList() << "http://www.voidrealms.com");
    qInfo() << "Exit code: " << proc.exitCode();

    return a.exec();
}
