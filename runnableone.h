#ifndef RUNNABLEONE_H
#define RUNNABLEONE_H
#include <QRunnable>
#include <QThread>
#include <QObject>
#include "worker.h"


class RunnableOne : public QObject,public QRunnable
{
   Q_OBJECT
   Worker* worker = nullptr;
   int id = -1;
public:
    RunnableOne(int id);
    void run();
public slots:
    void onTimeOut();
signals:
    void timeout();
};

#endif // RUNNABLEONE_H
