#pragma once
#include <QtCore>
#include <QTimer>
#include "A.h"
#include "MyQPmac.h"
class PmacThread: public QObject
{
	Q_OBJECT
public:
	explicit PmacThread(A* a_in, MyQPmac *mypmac_in);
	explicit PmacThread();
	virtual ~PmacThread();
	void startPmac();
	void startPmacHelloTimer();
	void helloPmacthread();
public slots:
	void onGetMotorDisp();
private slots:
	void onPmacHelloTimer();
	
public:
	MyQPmac * mypmac;
private:
	A * a;

	QTimer *pmacHelloTimer;
};

