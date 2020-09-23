QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14
LIBS += -lws2_32
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    battlefiled.cpp \
    bw.cpp \
    dialog.cpp \
    dialogg.cpp \
    main.cpp \
    mainwindow.cpp \
    res.cpp \
    userinit.cpp \
    viewinfo.cpp

HEADERS += \
    ../../Pokemon_Game/battle.hpp \
    ../../Pokemon_Game/poke.hpp \
    ../../Pokemon_Game/pokemon.hpp \
    ../../Pokemon_Game/pokemondict.hpp \
    ../../Pokemon_Game/pwd.hpp \
    ../../Pokemon_Game/rand.hpp \
    ../../Pokemon_Game/socket.hpp \
    ../../Pokemon_Game/user.hpp \
    battle.hpp \
    battlefiled.h \
    bw.hpp \
    dialog.h \
    dialogg.h \
    mainwindow.hpp \
    poke.hpp \
    pokemon.hpp \
    pokemondict.hpp \
    pwd.hpp \
    rand.hpp \
    res.hpp \
    socket.hpp \
    user.hpp \
    userinit.h \
    viewinfo.h

FORMS += \
    battlefiled.ui \
    bw.ui \
    dialog.ui \
    dialogg.ui \
    mainwindow.ui \
    res.ui \
    userinit.ui \
    viewinfo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
