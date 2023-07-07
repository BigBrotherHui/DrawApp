QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH+=./Item
INCLUDEPATH+=./Base

SOURCES += \
    Base/itembase.cpp \
    Base/textitembase.cpp \
    Item/boxitem.cpp \
    Item/pathitem.cpp \
    Item/polygonitem.cpp \
    Item/textitem.cpp \
    global.cpp \
    graphicsscene.cpp \
    graphicsview.cpp \
    layer.cpp \
    main.cpp \
    mainwindow.cpp \
    selectionsingleton.cpp

HEADERS += \
    Base/itembase.h \
    Base/textitembase.h \
    Item/boxitem.h \
    Item/pathitem.h \
    Item/polygonitem.h \
    Item/textitem.h \
    global.h \
    graphicsscene.h \
    graphicsview.h \
    layer.h \
    mainwindow.h \
    selectionsingleton.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
