#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_pmacthreadtest.h"
#include "PmacThread.h"
class PmacThreadTest : public QMainWindow
{
    Q_OBJECT

public:
    PmacThreadTest(QWidget *parent = Q_NULLPTR);
private slots:
	void on_getMotorDispBtn_clicked();
	void on_startThread_clicked();
signals:
	void sig_getMotorDisp1();
	void sig_getMotorDisp2();
private:
    Ui::PmacThreadTestClass ui;
	A *a;
	PmacThread * pmacthread;
	QThread * qthread_pmac;
	MyQPmac *mypmac;
	bool threadIsStared = false;
};
