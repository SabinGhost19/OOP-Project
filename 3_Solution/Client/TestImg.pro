QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

win32: LIBS += -lws2_32

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    TCPClient.cpp \
    adminlogin.cpp \
    clientlogin.cpp \
    companylogin.cpp \
    dashboard.cpp \
    main.cpp \
    APPClient.cpp\
    mainwindow.cpp \
    signinwindow.cpp

HEADERS += \
    TCPClient.h \
    APPClient.h\
    adminlogin.h \
    clientlogin.h \
    companylogin.h \
    dashboard.h \
    mainwindow.h \
    signinwindow.h

FORMS += \
    adminlogin.ui \
    clientlogin.ui \
    companylogin.ui \
    dashboard.ui \
    mainwindow.ui \
    signinwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    QtResources.qrc

