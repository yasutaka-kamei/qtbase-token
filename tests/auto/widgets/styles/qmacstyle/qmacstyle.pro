CONFIG += testcase
TARGET = tst_qmacstyle
QT += widgets testlib
SOURCES += tst_qmacstyle.cpp


mac*:CONFIG+=insignificant_test # QTBUG-25296
