QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculatecal.cpp \
    diabeteprod.cpp \
    diabetesrisktest.cpp \
    diabetetest.cpp \
    diabetewin.cpp \
    dialog.cpp \
    kategwin.cpp \
    main.cpp \
    mainwindow.cpp \
    product.cpp \
    sportprod.cpp \
    sporttest.cpp \
    sportwin.cpp

HEADERS += \
    calculatecal.h \
    diabeteprod.h \
    diabetesrisktest.h \
    diabetetest.h \
    diabetewin.h \
    dialog.h \
    kategwin.h \
    mainwindow.h \
    product.h \
    sportprod.h \
    sporttest.h \
    sportwin.h

FORMS += \
    diabeteprod.ui \
    diabetetest.ui \
    diabetewin.ui \
    dialog.ui \
    kategwin.ui \
    mainwindow.ui \
    sportprod.ui \
    sporttest.ui \
    sportwin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc
