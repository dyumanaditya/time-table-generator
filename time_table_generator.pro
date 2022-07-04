QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20
QMAKE_CXXFLAGS += -std=c++2a

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += include/

SOURCES += \
    src/class.cpp \
    src/csv_parser.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/student.cpp \
    src/teacher.cpp \
    src/time_table_generator.cpp \
    src/utils.cpp

HEADERS += \
    include/time-table-generator/class.h \
    include/time-table-generator/courses.h \
    include/time-table-generator/csv_parser.h \
    include/time-table-generator/days.h \
    include/time-table-generator/mainwindow.h \
    include/time-table-generator/sections.h \
    include/time-table-generator/student.h \
    include/time-table-generator/teacher.h \
    include/time-table-generator/time_table_generator.h \
    include/time-table-generator/utils.h \

FORMS += \
    forms/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
