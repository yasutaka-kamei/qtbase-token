CONFIG += testcase parallel_test
contains(QT_CONFIG, c++11):CONFIG += c++11 c++14
TARGET = tst_qversionnumber
QT = core testlib
SOURCES = tst_qversionnumber.cpp
