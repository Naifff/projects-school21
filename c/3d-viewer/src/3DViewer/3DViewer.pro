QT       += core gui opengl openglwidgets widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    glwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    qtgifimage/src/3rdParty/giflib/dgif_lib.c \
    qtgifimage/src/3rdParty/giflib/egif_lib.c \
    qtgifimage/src/3rdParty/giflib/gif_err.c \
    qtgifimage/src/3rdParty/giflib/gif_font.c \
    qtgifimage/src/3rdParty/giflib/gif_hash.c \
    qtgifimage/src/3rdParty/giflib/gifalloc.c \
    qtgifimage/src/3rdParty/giflib/quantize.c \
    qtgifimage/src/gifimage/qgifimage.cpp \
    ./transform/s21_affine_transform.c \
    ./parser/s21_parser_file.c

HEADERS += \
    glwidget.h \
    mainwindow.h \
    qtgifimage/src/3rdParty/giflib/gif_hash.h \
    qtgifimage/src/3rdParty/giflib/gif_lib.h \
    qtgifimage/src/3rdParty/giflib/gif_lib_private.h \
    qtgifimage/src/gifimage/qgifglobal.h \
    qtgifimage/src/gifimage/qgifimage.h \
    qtgifimage/src/gifimage/qgifimage_p.h \
    ./transform/s21_affine_transform.h \
    ./parser/s21_parser_file.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
