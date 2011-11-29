unix {
   CONFIG += link_pkgconfig
   PKGCONFIG += ftd2xx
}

win32 {
    INCLUDEPATH += c:/myLib
    LIBS += -Lc:/myLib/i386
    LIBS += -lftd2xx
}
