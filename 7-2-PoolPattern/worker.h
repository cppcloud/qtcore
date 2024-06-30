#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QTimer>
#include <QRandomGenerator>
#include <QDebug>

class worker : public QObject
{
    Q_OBJECT
public:
    explicit worker(QObject *parent = nullptr);
    bool isBusy();

signals:
    void started();
    void finished();


public slots:
    void timeout();
    void work(int value);

private:
    QTimer m_timer;
    bool m_busy;
};

#endif // WORKER_H
