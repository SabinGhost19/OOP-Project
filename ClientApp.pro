QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


win32: LIBS += -lws2_32

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    APPClient.cpp \
    CommentsRequest.cpp \
    DataRequest.cpp \
    DescriptionRequest.cpp \
    FactoryUser.cpp \
    ImageRequest.cpp \
    Product.cpp \
    ProductBuilder.cpp \
    RegisterRequest.cpp \
    SignInRequest.cpp \
    TCPClient.cpp \
    UserClientRequest.cpp \
    clientlogin.cpp \
    dashboard.cpp \
    iRequest.cpp \
    iuser.cpp \
    main.cpp \
    mainwindow.cpp \
    signinwindow.cpp \
    user.cpp \
    userClient.cpp \
    userRequest.cpp

HEADERS += \
    APPClient.h \
    CommentsRequest.h \
    DataRequest.h \
    DescriptionRequest.h \
    FactoryUser.h \
    ImageRequest.h \
    Product.h \
    ProductBuilder.h \
    RegisterRequest.h \
    SignInRequest.h \
    TCPClient.h \
    UserClientRequest.h \
    clientlogin.h \
    dashboard.h \
    iRequest.h \
    iuser.h \
    mainwindow.h \
    signinwindow.h \
    user.h \
    userClient.h \
    userRequest.h

FORMS += \
    clientlogin.ui \
    dashboard.ui \
    mainwindow.ui \
    signinwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    QtResource.qrc
