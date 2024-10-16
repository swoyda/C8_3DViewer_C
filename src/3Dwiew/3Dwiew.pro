QT       += core gui opengl widgets printsupport

include(QtGifImage-master/src/gifimage/qtgifimage.pri)
greaterThan(QT_MAJOR_VERSION, 5): QT += openglwidgets
isEqual(QT_MAJOR_VERSION, 5): LIBS += openglwidgets
CONFIG += c++17
win32 {
    LIBS += -lopengl32
}
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    affine_transformations.c \
    glview.cpp \
    main.cpp \
    mainwindow.cpp \
    parcer.c

HEADERS += \
    affine_transformations.h \
    glview.hpp \
    mainwindow.h \
    parcer.h \
    s21_3dviewer.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
