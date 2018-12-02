#include "worker.h"
#include <QTime>

void Worker::longProcess()
{
    QTime time;
    time.start();
   for(int i=0;i<380000;i++)
   {
       if(time.elapsed() > 2000)
       {
           qDebug()<<"Thread working "<<"\n-------\n"<<"Worker id :"<<this->id<<"\n Thread info : "<<QThread::currentThread()<<"\n------"<<endl;
           this->processEvents();
           if(this->m_exit)
           {
               this->quit();
               return;
           }
           time.restart();
       }
   }
   this->quit();
}

Worker::Worker(int p_id, QObject *parent) : QEventLoop(parent),id(p_id)
{

}

void Worker::onTimeOut()
{
   qDebug()<<"Ending from outside"<<endl;
   qDebug()<<" Worker id :"<<this->id<<" thread : "<<QThread::currentThread()<<endl;
   this->m_exit = true;
}
