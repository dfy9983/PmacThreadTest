#include "A.h"
A::A()
{

}

void A::hello()
{
	qDebug() << "hello thread id is:  " << QThread::currentThreadId();
}

A::~A()
{

}
