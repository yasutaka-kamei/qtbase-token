CONFIG += testcase
TARGET = tst_qfontdialog

QT += widgets widgets-private testlib
QT += core-private gui-private

SOURCES  += tst_qfontdialog.cpp

mac:!qpa {
    OBJECTIVE_SOURCES += tst_qfontdialog_mac_helpers.mm
    LIBS += -framework Cocoa
}

