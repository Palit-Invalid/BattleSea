TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        battlefield.cpp \
        main.cpp

HEADERS += \
    battlefield.h

unix:!macx: LIBS += -L$$PWD/../../../coding/SFML-2.5.1/lib/ -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

INCLUDEPATH += $$PWD/../../../coding/SFML-2.5.1/include/
DEPENDPATH += $$PWD/../../../coding/SFML-2.5.1/include/
