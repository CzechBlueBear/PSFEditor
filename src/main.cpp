#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // on Linux, better respect what the user has set;
    // otherwise set a known working Qt style
#if !defined(linux)
    a.setStyle("fusion");
#endif

    w.show();

    // if an exactly one extra arg is given, interpret it as a filename to open
    if (argc == 2)  {
        w.loadFile(argv[1]);
    }

    return a.exec();
}
