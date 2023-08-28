#-------------------------------------------------
#
# Project created by QtCreator 2015-06-13T23:45:28
#
#-------------------------------------------------

QT       += core gui xml svg concurrent opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../qtpropertybrowser/src/qtpropertybrowser.pri)
TARGET = DrawBoard
TEMPLATE = app
INCLUDEPATH+=./layer
INCLUDEPATH+=./command
INCLUDEPATH+=./map
INCLUDEPATH+=./group
INCLUDEPATH+=./widgets
INCLUDEPATH+=./items
INCLUDEPATH+=./common
INCLUDEPATH+=./gds

SOURCES += main.cpp\
    command/receiverbase.cpp \
    common/globalsignalinstance.cpp \
    common/util.cpp \
    gds/gdsCpp.cpp \
    gds/gdsForge.cpp \
    gds/gdsImport.cpp \
    gds/gdsParser.cpp \
    gds/gdsimporter.cpp \
    group/group.cpp \
    items/graphicsbezier.cpp \
    items/graphicsinstanceitem.cpp \
    items/graphicsitem.cpp \
    items/graphicsitemgroup.cpp \
    items/graphicslineitem.cpp \
    items/graphicspolygonitem.cpp \
    items/graphicsrectitem.cpp \
    items/graphicstextitem.cpp \
    layer/layer.cpp \
    layer/layermanager.cpp \
    command/commandwidget.cpp \
    mainwindow.cpp \
    drawobj.cpp \
    drawscene.cpp \
    drawtool.cpp \
    map/boxtool.cpp \
    map/mapscene.cpp \
    map/mapview.cpp \
    sizehandle.cpp \
    objectcontroller.cpp \
    customproperty.cpp \
    rulebar.cpp \
    drawview.cpp \
    commands.cpp \
    document.cpp \
    widgets/ruler.cpp \
    widgets/scalarruler.cpp

HEADERS  += \
    command/receiverbase.h \
    common/globalsignalinstance.h \
    common/util.h \
    gds/gdsCpp.hpp \
    gds/gdsForge.hpp \
    gds/gdsParser.hpp \
    gds/gdsimporter.h \
    group/group.h \
    items/graphicsbezier.h \
    items/graphicsinstanceitem.h \
    items/graphicsitem.h \
    items/graphicsitemgroup.h \
    items/graphicslineitem.h \
    items/graphicspolygonitem.h \
    items/graphicsrectitem.h \
    items/graphicstextitem.h \
    layer/layer.h \
    layer/layermanager.h \
    command/commandwidget.h \
    mainwindow.h \
    drawobj.h \
    drawscene.h \
    drawtool.h \
    map/boxtool.h \
    map/mapscene.h \
    map/mapview.h \
    sizehandle.h \
    objectcontroller.h \
    customproperty.h \
    rulebar.h \
    drawview.h \
    commands.h \
    document.h \
    widgets/ruler.h \
    widgets/scalarruler.h

RESOURCES += \
    app.qrc

FORMS += \
    command/commandwidget.ui \
    widgets/ruler.ui

