#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "mainwindow.h"

#include <qapplication.h>

int main(int argc, char *argv[])
{
    // Unit testing
    doctest::Context context;
    int doctest_result = context.run();

    // App execution
    QApplication app = QApplication(argc, argv);
    MainWindow window;
    window.buildUI();
    window.show();
    int app_result = app.exec();

    return app_result + doctest_result;
}
