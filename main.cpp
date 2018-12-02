#include <QCoreApplication>
#include <QTimer>
#include <runnableone.h>
#include <QThreadPool>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    RunnableOne* run1 = new RunnableOne(1);
    RunnableOne* run2 = new RunnableOne(2);
    RunnableOne* run3 = new RunnableOne(3);

    QTimer timer1, timer2, timer3, timer4;

    timer1.singleShot(5000,run1,&RunnableOne::onTimeOut); //true usage for this example
    QObject::connect(&timer2,&QTimer::timeout,run2,&RunnableOne::onTimeOut);
    QObject::connect(&timer3,&QTimer::timeout,run3,&RunnableOne::onTimeOut);

    QObject::connect(&timer4,&QTimer::timeout,[=](){
        qDebug()<<"Active Thread : "<<QThreadPool::globalInstance()->activeThreadCount()<<endl;
        if(QThreadPool::globalInstance()->activeThreadCount()!=0)
        {
            return;
        }
        QCoreApplication::quit();
    });
    QObject::connect(&a,&QCoreApplication::aboutToQuit,[=](){
            qDebug()<<"about to quit"<<endl;
    });

    QThreadPool::globalInstance()->start(run1,0);
    QThreadPool::globalInstance()->start(run2,0);
    QThreadPool::globalInstance()->start(run3,0);


    //timer1.start(5000);
    timer2.start(6000);
    timer3.start(8000);
    timer4.start(5000);



    return a.exec();
}
