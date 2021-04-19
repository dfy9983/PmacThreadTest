#pragma once
#include <QtCore>
#include <QTimer>
#include "A.h"
#include "MyQPmac.h"
class PmacThread: public QObject
{
	Q_OBJECT
public:
	PmacThread(A* a_in, MyQPmac *mypmac_in);
	virtual ~PmacThread();
	void startPmac();
	void startPmacHelloTimer();

private slots:
	void onPmacHelloTimer();
private:
	A * a;
	MyQPmac * mypmac;
	QTimer *pmacHelloTimer;
};

