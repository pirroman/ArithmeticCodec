#include "window_qcodec.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    window_QCodec w;
    w.show();

    return a.exec();
}
