#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QEventLoop>
#include <QThreadPool>
#include <QDebug>

class Worker : public QEventLoop
{
    Q_OBJECT
    bool m_exit=false;
    int id=-1;
public:
    explicit Worker(int p_id,QObject *parent = nullptr);

signals:

public slots:
    void onTimeOut();
    void longProcess();
};

#endif // WORKER_H
