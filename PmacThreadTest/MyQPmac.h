#pragma once
#pragma execution_character_set("utf-8")
#include <QtCore>
#include <QMessageBox>
#include "PmacDeviceLib.h"
class MyQPmac :public QObject
{
	Q_OBJECT
public:
	explicit MyQPmac();
	virtual ~MyQPmac();

public slots:
	bool creatPmacSelect();
	double getMotorDisp();
private:
	PCOMMSERVERLib::PmacDevice *Pmac0;
	
	int pDeviceNumber;
	bool pbSuccess_select;
	bool pbSuccess_open;
	bool pbSucess_download;
	QString pAnswer;
	bool bAddLF;
	int pstatus;
};

