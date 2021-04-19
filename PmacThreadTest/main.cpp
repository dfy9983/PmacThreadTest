#include "pmacthreadtest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PmacThreadTest w;
    w.show();
    return a.exec();
}
