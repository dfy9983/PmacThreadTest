#include "pmacthreadtest.h"

PmacThreadTest::PmacThreadTest(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	qDebug() << "main thread id" << QThread::currentThreadId();
	//新加了这句话
	a = new A();
	a->hello();
	mypmac = new MyQPmac();
	mypmac->creatPmacSelect();

	pmacthread = new PmacThread(a,mypmac);
	qthread_pmac = new QThread();
	pmacthread->moveToThread(qthread_pmac);
	connect(qthread_pmac, &QThread::started, pmacthread, &PmacThread::startPmac);
	connect(qthread_pmac, &QThread::finished, pmacthread, &QObject::deleteLater);
	connect(qthread_pmac, &QThread::finished, qthread_pmac, &QObject::deleteLater);
	qthread_pmac->start();
}
