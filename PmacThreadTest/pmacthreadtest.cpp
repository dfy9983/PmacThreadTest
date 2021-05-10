#include "pmacthreadtest.h"

PmacThreadTest::PmacThreadTest(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	qDebug() << "main thread id" << QThread::currentThreadId();
	//�¼�����仰
	a = new A();
	a->hello();

	
	/************************************************************************/
	/*����̵߳�����Ҫ���źŲ۷�ʽ�����ź����ƶ��̵߳ĺ�����ֱ����1�������û��ǻ������߳�*/
	/************************************************************************/
	

}

void PmacThreadTest::on_getMotorDispBtn_clicked()
{
	//pmacthread->mypmac->getMotorDisp();//ִ���������߳�
	//pmacthread->helloPmacthread();//ִ���������߳�
	//emit sig_getMotorDisp1();//ִ���������߳�
	emit sig_getMotorDisp2();//������ִ�������߳�
}

void PmacThreadTest::on_startThread_clicked()
{
	qDebug() << "clicked";
	if (threadIsStared)
	{
		qthread_pmac->quit();
		qthread_pmac->wait();
		threadIsStared = false;
		ui.startThread->setText("startThread");
	}
	else
	{
		mypmac = new MyQPmac();
		//mypmac->creatPmacSelect();
		pmacthread = new PmacThread(a, mypmac);
		qthread_pmac = new QThread();
		pmacthread->mypmac->creatPmacSelect();
		pmacthread->moveToThread(qthread_pmac);
		connect(qthread_pmac, &QThread::started, pmacthread, &PmacThread::startPmac);
		connect(qthread_pmac, &QThread::finished, pmacthread, &QObject::deleteLater);
		connect(qthread_pmac, &QThread::finished, qthread_pmac, &QObject::deleteLater);

		connect(this, &PmacThreadTest::sig_getMotorDisp1, pmacthread->mypmac, &MyQPmac::getMotorDisp);//1
		connect(this, &PmacThreadTest::sig_getMotorDisp2, pmacthread, &PmacThread::onGetMotorDisp);//������ִ�������߳�
		qthread_pmac->start();
		threadIsStared = true;
		ui.startThread->setText("stopThread");
	}
}
