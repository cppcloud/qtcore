#include "pool.h"

pool::pool(QObject *parent) : QObject(parent)
{
    for(int i = 0; i < 5; i++) {
        worker *w = new worker(this);
        w->setObjectName("Worker: " + QString::number(i));
        connect(w,&worker::started,this, &pool::started);
        connect(w,&worker::finished,this, &pool::finished);

        m_workers.append(w);
        qInfo() << "Worker ready: " << w->objectName();
    }

    connect(&m_timer,&QTimer::timeout,this, &pool::checkwork);
    m_timer.setInterval(200);
    m_timer.start();
}

pool::~pool()
{
    m_timer.stop();
    qDeleteAll(m_workers);
    m_workers.clear();
}

void pool::work(int value)
{
    m_work.append(value);
    checkwork();
}

void pool::started()
{
    worker *w = qobject_cast<worker*>(sender());
    qInfo() << "Started: " << w->objectName();
}

void pool::finished()
{
    worker *w = qobject_cast<worker*>(sender());
    qInfo() << "Finished: " << w->objectName();
}

void pool::checkwork()
{
    if(m_work.isEmpty()) return;
    foreach(worker *w, m_workers) {
        if(!w->isBusy()) {
            w->work(m_work.takeFirst());
            if(m_work.isEmpty()) return;
        }
    }
}
