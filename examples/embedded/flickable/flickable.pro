SOURCES = flickable.cpp main.cpp
HEADERS = flickable.h

target.path = $$[QT_INSTALL_EXAMPLES]/qtbase/embedded/flickable
sources.files = $$SOURCES $$HEADERS $$RESOURCES *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/qtbase/embedded/flickable
INSTALLS += target sources
QT += widgets widgets
