#include <QCoreApplication>

#include "AntzConsole.h"

//Q_COREAPP_STARTUP_FUNCTION(AntzConsole.run())

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    AntzConsole * console = new AntzConsole;
    return a.exec();
}
