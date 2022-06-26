TEMPLATE = app
TARGET = audiorecorder

QT += multimedia

win32:INCLUDEPATH += $$PWD

HEADERS = \
    audioplayer.h \
    audiorecorder.h \
    audiolevel.h

SOURCES = \
    audioplayer.cpp \
    main.cpp \
    audiorecorder.cpp \
    audiolevel.cpp

FORMS += audiorecorder.ui

target.path = $$[QT_INSTALL_EXAMPLES]/multimedia/audiorecorder
INSTALLS += target

QT+=widgets
QT+=core
include(../shared/shared.pri)

DISTFILES += \
    assets/WhatsApp Image 2022-06-01 at 02.06.33.jpeg \
    assets/WhatsApp Image 2022-06-01 at 02.06.33.jpeg

RESOURCES += \
    Resources.qrc
