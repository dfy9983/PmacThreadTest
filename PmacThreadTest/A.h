#pragma once
#include<QtCore>

class A:public QObject
{
	Q_OBJECT
public:
	explicit A();
	virtual~A();
	void hello();
};

