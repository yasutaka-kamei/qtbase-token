TARGET = qglgraphicssystem
include(../../qpluginbase.pri)

QT += opengl

DESTDIR = $$QT.gui.plugins/graphicssystems

SOURCES = main.cpp

target.path += $$[QT_INSTALL_PLUGINS]/graphicssystems
INSTALLS += target

symbian: TARGET.UID3 = 0x2002131B
