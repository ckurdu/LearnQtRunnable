#include "runnableone.h"
#include <QDebug>
#include <QThreadPool>
#include <QCoreApplication>
#include <QThread>
#include <QObject>
#include <QEventLoop>
#include <QDebug>
#include <QMetaObject>

RunnableOne::RunnableOne(int p_id):id(p_id)
{
}

void RunnableOne::run()
{
   this->worker = new Worker(this->id);
   qDebug()<<"thread : "<<QThread::currentThread()<<endl;
   QObject::connect(this,&RunnableOne::timeout,worker,&Worker::onTimeOut);
   QMetaObject::invokeMethod(worker,&Worker::longProcess,Qt::QueuedConnection);
   this->worker->exec();
}

void RunnableOne::onTimeOut()
{
   if(this->worker == nullptr)
   {
       qDebug()<<"wrong usage";
       return;
   }
   emit timeout();
}
