QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bogosort.cpp \
    fusionsort.cpp \
    graph.cpp \
    heapsort.cpp \
    main.cpp \
    mainwindow.cpp \
    shellsort.cpp \
    sortingalgorithms.cpp \
    timsort.cpp

HEADERS += \
    bogosort.h \
    fusionsort.h \
    graph.h \
    heapsort.h \
    mainwindow.h \
    shellsort.h \
    sortingalgorithms.h \
    timsort.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
