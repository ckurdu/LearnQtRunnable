#include "threadapp.h"

ThreadApp::ThreadApp(int& argc,char ** argv):QCoreApplication(argc,argv)
{

}

void ThreadApp::exit(int returnCode)
{
   QCoreApplication::exit(returnCode);
}
