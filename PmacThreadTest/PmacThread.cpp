#include "PmacThread.h"

PmacThread::PmacThread(A * a_in, MyQPmac *mypmac_in)
{
	a = a_in;
	mypmac = mypmac_in;
}

PmacThread::PmacThread()
{

}

PmacThread::~PmacThread()
{
	//delete a;
	delete mypmac;
}

void PmacThread::startPmac()
{
	qDebug() << "startpmac thread id:" << QThread::currentThreadId();
	a->hello();
	mypmac->getMotorDisp();
	qDebug() << "start timer";
	//startPmacHelloTimer();
	//mypmac->creatPmacSelect();//测试是否可以在多线程创建!widget不可以在非ui线程创建
}

void PmacThread::startPmacHelloTimer()
{
	pmacHelloTimer = new QTimer(this);
	connect(pmacHelloTimer, &QTimer::timeout, this, &PmacThread::onPmacHelloTimer);
	pmacHelloTimer->start(1000);
}

void PmacThread::helloPmacthread()
{
	qDebug() << "hello Pmacthread:" << QThread::currentThreadId();
}

void PmacThread::onGetMotorDisp()
{
	mypmac->getMotorDisp();
}

void PmacThread::onPmacHelloTimer()
{
	mypmac->getMotorDisp();
}
