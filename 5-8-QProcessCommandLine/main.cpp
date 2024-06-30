#include <QCoreApplication>
#include "commander.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    commander cmd;
    cmd.action(QByteArray("pwd"));
    cmd.action(QByteArray("ls -l"));

    // system("pwd")
    // system("ls -l")

    return a.exec();
}
