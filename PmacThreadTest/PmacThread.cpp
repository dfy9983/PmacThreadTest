#include "PmacThread.h"

PmacThread::PmacThread(A * a_in, MyQPmac *mypmac_in)
{
	a = a_in;
	mypmac = mypmac_in;
}

PmacThread::~PmacThread()
{
	delete a;
	delete mypmac;
}

void PmacThread::startPmac()
{
	qDebug() << "startpmac thread id:" << QThread::currentThreadId();
	a->hello();
	mypmac->getMotorDisp();
	qDebug() << "start timer";
	startPmacHelloTimer();
}

void PmacThread::startPmacHelloTimer()
{
	pmacHelloTimer = new QTimer(this);
	connect(pmacHelloTimer, &QTimer::timeout, this, &PmacThread::onPmacHelloTimer);
	pmacHelloTimer->start(1000);
}

void PmacThread::onPmacHelloTimer()
{
	mypmac->getMotorDisp();
}
