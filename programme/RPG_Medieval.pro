QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        arme\CBow.cpp\
        arme\CMelee.cpp\
        arme\CStaff.cpp\
        arme\CSword.cpp\
        arme\CWeapon.cpp\
        arme\CRanged.cpp\
        arme\CDagger.cpp\
        Cguerrier.cpp \
        carcher.cpp \
        ccombat.cpp \
        cgame.cpp \
        cmage.cpp \
        cpersonnage.cpp \
        csorcier.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    arme\CBow.h\
    arme\CMelee.h\
    arme\CStaff.h\
   arme\CSword.h\
    arme\CWeapon.h\
    arme\CRanged.h\
    arme\CDagger.h\
    CCombat.h \
    CArcher.h \
    cgame.h \
    cguerrier.h \
    cmage.h \
    cpersonnage.h \
    csorcier.h

RESOURCES += \
    Persos.qrc
