QT += widgets gui core qml

CONFIG += c++17
TARGET = aerostrix-calculator
TEMPLATE = app

INCLUDEPATH += src

SOURCES += \
    src/main.cpp \
    src/calculator.cpp

HEADERS += \
    src/calculator.h

RESOURCES +=

DISTFILES += src/style.qss
