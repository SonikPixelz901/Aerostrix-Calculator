#include "calculator.h"
#include <QRegularExpression>
#include <QtMath>
#include <QJSEngine>

Calculator::Calculator(QWidget *parent) : QMainWindow(parent) {
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    auto *layout = new QGridLayout(central);

    display = new QLineEdit();
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setFixedHeight(50);
    display->setObjectName("display");
    layout->addWidget(display, 0, 0, 1, 4);

    const char *buttons[4][4] = {
        {"7", "8", "9", "/"},
        {"4", "5", "6", "*"},
        {"1", "2", "3", "-"},
        {"0", "C", "=", "+"}
    };

    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            QPushButton *btn = new QPushButton(buttons[row][col]);
            btn->setFixedSize(70, 50);
            layout->addWidget(btn, row + 1, col);
            connect(btn, &QPushButton::clicked, this, [=]() {
                buttonClicked(btn->text());
            });
        }
    }

    setWindowTitle("Aerostrix Calculator");
    setFixedSize(320, 360);
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
}

void Calculator::buttonClicked(const QString &text) {
    if (text == "C") {
        display->clear();
    } else if (text == "=") {
        evaluateExpression();
    } else {
        display->setText(display->text() + text);
    }
}

void Calculator::evaluateExpression() {
    QJSEngine engine;
    QString expr = display->text();
    QJSValue result = engine.evaluate(expr);
    display->setText(result.toString());

}
