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
    CompanyAddRequest.cpp \
    DataRequest.cpp \
    DescriptionRequest.cpp \
    FactoryUser.cpp \
    ImageRequest.cpp \
    LogInRequest.cpp \
    Product.cpp \
    ProductBuilder.cpp \
    RegisterRequest.cpp \
    SignInRequest.cpp \
    TCPClient.cpp \
    addProduct.cpp \
    clientlogin.cpp \
    companylogin.cpp \
    companywindow.cpp \
    dashboard.cpp \
    iRequest.cpp \
    iuser.cpp \
    main.cpp \
    mainwindow.cpp \
    signinwindow.cpp \
    user.cpp \
    userClient.cpp \
    userCompany.cpp \
    userRequest.cpp

HEADERS += \
    APPClient.h \
    CommentsRequest.h \
    CompanyAddRequest.h \
    DataRequest.h \
    DescriptionRequest.h \
    FactoryUser.h \
    ImageRequest.h \
    LogInRequest.h \
    Product.h \
    ProductBuilder.h \
    RegisterRequest.h \
    SignInRequest.h \
    TCPClient.h \
    addProduct.h \
    clientlogin.h \
    companylogin.h \
    companywindow.h \
    dashboard.h \
    iRequest.h \
    iuser.h \
    mainwindow.h \
    signinwindow.h \
    user.h \
    userClient.h \
    userCompany.h \
    userRequest.h

FORMS += \
    addproduct.ui \
    clientlogin.ui \
    companylogin.ui \
    companywindow.ui \
    dashboard.ui \
    mainwindow.ui \
    signinwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    QtResource.qrc
