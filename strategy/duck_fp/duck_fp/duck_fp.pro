TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        SimUDuck.cpp \


HEADERS += \
    lib/Duck/DecoyDuck.h \
    lib/Duck/Duck.h \
    lib/Duck/DuckStrategy.h \
    lib/Duck/MallardDuck.h \
    lib/Duck/ModelDuck.h \
    lib/Duck/RedheadDuck.h \
    lib/Duck/RubberDuck.h \
    lib/DuckFunctions.h
