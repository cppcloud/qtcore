#include "commander.h"

commander::commander(QObject *parent) : QObject(parent)
{
#ifdef Q_OS_WIN
    //Windows
    app = "cmd";
    endl = "\r\n";
#else
    //Not windows
    app = "bash";
    endl = "\n";
#endif

    proc.setProgram(app);
    proc.start();
    proc.setReadChannelMode(QProcess::MergedChannels);
    connect(&proc,&QProcess::readyRead, this, &commander::readyRead);
    connect(&proc,&QProcess::readyReadStandardOutput, this, &commander::readyRead);
    connect(&proc,&QProcess::readyReadStandardError, this, &commander::readyRead);

}

commander::~commander()
{
    if(proc.isOpen()) proc.close();
}

void commander::readyRead()
{
    qint64 value = 0;
    do {
        QByteArray line = proc.readAll();
        qInfo() << line.trimmed();
        value = line.length();
    }while(value > 0);
}

void commander::action(QByteArray data)
{
    if(!data.endsWith(endl.toLatin1())) data.append(endl);
    proc.write(data);
    proc.waitForBytesWritten(1000);
}
