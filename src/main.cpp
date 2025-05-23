#include <QApplication>
#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QWidget>
#include "main.moc"

class Calculator : public QMainWindow {
    Q_OBJECT
public:
    Calculator(QWidget *parent = nullptr) : QMainWindow(parent) {
        QWidget *central = new QWidget(this);
        setCentralWidget(central);

        auto *layout = new QGridLayout(central);

        // Display
        display = new QLineEdit();
        display->setReadOnly(true);
        display->setAlignment(Qt::AlignRight);
        display->setFixedHeight(40);
        layout->addWidget(display, 0, 0, 1, 4);

        // Buttons text (like classic calculator)
        const char *buttons[4][4] = {
            {"7", "8", "9", "/"},
            {"4", "5", "6", "*"},
            {"1", "2", "3", "-"},
            {"0", "C", "=", "+"}
        };

        for (int row = 0; row < 4; ++row) {
            for (int col = 0; col < 4; ++col) {
                QPushButton *btn = new QPushButton(buttons[row][col]);
                btn->setFixedSize(60, 40);
                layout->addWidget(btn, row + 1, col);
                connect(btn, &QPushButton::clicked, this, [=](){ buttonClicked(btn->text()); });
            }
        }

        setWindowTitle("Aerostrix Calculator");
        setFixedSize(sizeHint());
    }

private slots:
    void buttonClicked(const QString &text) {
        if (text == "C") {
            display->clear();
        } else if (text == "=") {
            // TODO: Add expression evaluation here
            display->setText("Not implemented");
        } else {
            display->setText(display->text() + text);
        }
    }

private:
    QLineEdit *display;
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Calculator w;
    w.show();
    return a.exec();
}
