include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
#CONFIG -= qt

HEADERS += \
    tst_testvoitureconstructor.h \
    tst_testvoitureroule.h

SOURCES += \
        main.cpp

include(../VoitureAppli/voiture.pri)
INCLUDEPATH += ../VoitureAppli
