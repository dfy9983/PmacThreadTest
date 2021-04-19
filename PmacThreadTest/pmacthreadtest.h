#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_pmacthreadtest.h"
#include "PmacThread.h"
class PmacThreadTest : public QMainWindow
{
    Q_OBJECT

public:
    PmacThreadTest(QWidget *parent = Q_NULLPTR);

private:
    Ui::PmacThreadTestClass ui;
	A *a;
	MyQPmac *mypmac;
	PmacThread * pmacthread;
	QThread * qthread_pmac;
};
