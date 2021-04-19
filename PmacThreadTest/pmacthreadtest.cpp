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

	connect(this, &PmacThreadTest::sig_getMotorDisp1,pmacthread->mypmac, &MyQPmac::getMotorDisp);
	connect(this, &PmacThreadTest::sig_getMotorDisp2, pmacthread, &PmacThread::onGetMotorDisp);//！！！执行在子线程
	qthread_pmac->start();
	/************************************************************************/
	/*想多线程调用需要用信号槽方式连接信号与移动线程的函数，直接像1那样调用还是会在主线程*/
	/************************************************************************/
	

}

void PmacThreadTest::on_getMotorDispBtn_clicked()
{
	//pmacthread->mypmac->getMotorDisp();//执行在了主线程
	//pmacthread->helloPmacthread();//执行在了主线程
	//emit sig_getMotorDisp1();//执行在了主线程
	emit sig_getMotorDisp2();//！！！执行在子线程
}
