#include <QCoreApplication>

#include "ConsoleUno.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ConsoleUno * console = new ConsoleUno;
    return a.exec();
}
