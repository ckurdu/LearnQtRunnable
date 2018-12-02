#ifndef THREADAPP_H
#define THREADAPP_H

#include <QObject>
#include <QCoreApplication>

class ThreadApp:QCoreApplication
{
public:
    ThreadApp(int &argc, char **argv);
    void exit(int returnCode=0);
};

#endif // THREADAPP_H
