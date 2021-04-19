#include "MyQPmac.h"

MyQPmac::MyQPmac()
{
	Pmac0 = new PCOMMSERVERLib::PmacDevice();
	this->pDeviceNumber = 0;
	this->pbSuccess_open = false;
	this->pbSuccess_select = false;
	this->pbSucess_download = false;
	this->pAnswer = "";
	this->bAddLF = true;
	this->pstatus = 0;
}

MyQPmac::~MyQPmac()
{
	if (pbSuccess_open)
	{
		Pmac0->Close(pDeviceNumber);
		qDebug() << "Pmac0->Close";
	}
	delete Pmac0;
}

bool MyQPmac::creatPmacSelect()
{
	qDebug() << "creatPmac thread id:"<<QThread::currentThreadId();
	pbSuccess_open = false;
	pbSuccess_select = false;
	Pmac0->SelectDevice(NULL, pDeviceNumber, pbSuccess_select);
	Pmac0->Open(pDeviceNumber, pbSuccess_open);
	if (pbSuccess_open)
	{
		qDebug() << "open success";
		QMessageBox::information(NULL, "提示", "连接成功,请初始化Pmac！");
		return  true;
	}
	else
	{
		qDebug() << "open failed";
		QMessageBox::information(NULL, "提示", "连接失败，检查是否以管理员身份运行！");
		return false;
	}
}

double MyQPmac::getMotorDisp()
{
	Pmac0->GetResponse(pDeviceNumber, "M162", pAnswer);//获取位移mm
	double disp = pAnswer.left(pAnswer.length() - 1).toDouble() / 3072 / 8192 * 16;//位移换算
	qDebug() << "Disp = "<<disp <<"  ,response thread id:" << QThread::currentThreadId();
	return disp;
}

