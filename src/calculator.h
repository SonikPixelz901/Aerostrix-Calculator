#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>

class Calculator : public QMainWindow {
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);

private slots:
    void buttonClicked(const QString &text);
    void evaluateExpression();

private:
    QLineEdit *display;
};

#endif // CALCULATOR_H
