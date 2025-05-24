#include <QApplication>
#include <QFile>
#include "calculator.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QFile styleFile("src/style.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        app.setStyleSheet(styleFile.readAll());
    }

    Calculator calculator;
    calculator.show();
    return app.exec();
}
