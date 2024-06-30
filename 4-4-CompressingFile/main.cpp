#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QBuffer>
#include <QTextStream>

//Our own custom file format, will not work with anything else!!

bool makeFile(QString path) {

    QFile file(path);
    if(file.open(QIODevice::WriteOnly)) {

        QByteArray data;
        for(int i = 0; i < 1000; i++) {
            data.append(QString::number(i) + "\r\n");
        }

        file.write(data);

        file.close();
        return true;
    }

    return false;
}

QByteArray getHeader() {
    QByteArray header;
    header.append("@!~!@");
    return header;
}

bool compressFile(QString originalFile, QString newFile) {
    QFile ofile(originalFile);
    QFile nfile(newFile);
    QByteArray header = getHeader();

    if(!ofile.open(QIODevice::ReadOnly)) return false;
    if(!nfile.open(QIODevice::WriteOnly)) return  false;
    int size = 1024;

    while (!ofile.atEnd()) {
        QByteArray buffer = ofile.read(size);
        QByteArray compressed = qCompress(buffer);
        qInfo() << "Header at:" << nfile.pos();
        nfile.write(header);
        qInfo() << "Size: " << nfile.write(compressed); // unknown size

    }
    ofile.close();
    nfile.close();
    return true;
}

bool decompressFile(QString originalFile, QString newFile) {
    QFile ofile(originalFile);
    QFile nfile(newFile);
    QByteArray header = getHeader();
    int size = 1024;

    if(!ofile.open(QIODevice::ReadOnly)) return false;
    if(!nfile.open(QIODevice::WriteOnly)) return false;

    //Double check that WE compressed the file
    QByteArray buffer = ofile.peek(size);
    if(!buffer.startsWith(header)) {
        qCritical() << "We did not create this file!";
        ofile.close();
        nfile.close();
        return false;
    }

    //Find the header positions
    ofile.seek(header.length());
    qInfo() << "Starting at: " << ofile.pos();

    while (!ofile.atEnd()) {
        buffer = ofile.peek(size);
        qint64 index = buffer.indexOf(header);
        qInfo() << "Header found at:" << index;

        if(index > -1) {
            //Have the header!
            qint64 maxbytes = index;
            qInfo() << "Reading: " << maxbytes;
            buffer = ofile.read(maxbytes);
            ofile.read(header.length());
        } else {
            //Do not have the header!
            qInfo() << "Read all, no header";
            buffer = ofile.readAll();
        }

        QByteArray decompressed = qUncompress(buffer);
        qInfo() << "Decompressed: " << nfile.write(decompressed);
        nfile.flush();
    }

    ofile.close();
    nfile.close();

    return true;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString orginalFile = QDir::currentPath() + QDir::separator() + "orginal.txt";
    QString compressedFile = QDir::currentPath() + QDir::separator() + "compressed.txt";
    QString decompressedFile = QDir::currentPath() + QDir::separator() + "decompressed.txt";

    if(makeFile(orginalFile)) {
        qInfo() << "Original created";

        if(compressFile(orginalFile, compressedFile)) {
            qInfo() << "File compressed";
            if(decompressFile(compressedFile,decompressedFile)) {
                qInfo() << "File decompressed!";
            } else {
                qInfo() << "Could not decompress file!";
            }
        } else {
            qInfo() << "File not compressed";
        }


    }

    return a.exec();
}
