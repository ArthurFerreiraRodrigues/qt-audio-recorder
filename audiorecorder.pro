TEMPLATE = app
TARGET = audiorecorder

QT += multimedia

win32:INCLUDEPATH += $$PWD

HEADERS = \
    audiorecorder.h \
    audiolevel.h

SOURCES = \
    main.cpp \
    audiorecorder.cpp \
    audiolevel.cpp

FORMS += audiorecorder.ui

target.path = $$[QT_INSTALL_EXAMPLES]/multimedia/audiorecorder
INSTALLS += target

QT+=widgets
QT+=
include(../shared/shared.pri)

DISTFILES += \
    assets/WhatsApp Image 2022-06-01 at 02.06.33.jpeg \
    assets/WhatsApp Image 2022-06-01 at 02.06.33.jpeg

RESOURCES += \
    Resources.qrc
