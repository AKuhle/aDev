#include "mainWin.h"

#include <QApplication>


/*******************************************************************************
* main
*******************************************************************************/
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setWindowIcon(QIcon(":/qLights/appIcon.png"));

    MainWin w;
    w.show();
    w.updateAll();

    return app.exec();
} // main
