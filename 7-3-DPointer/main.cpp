#include <QCoreApplication>
#include <QDebug>
#include "cat.h"

// PIMPL / D-Pointer
// https://wiki.qt.io/D-Pointer
// http://code.qt.io/cgit/qt/qt.git/tree/src/corelib/io


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Cat cat;
    cat.meow();
    cat.hiss();

    return a.exec();
}
