unix {
   CONFIG += link_pkgconfig
   PKGCONFIG += ftd2xx
}

win32 {
    INCLUDEPATH += c:/myLib
    LIBS += -Ld:/Libraries/FTDI
    LIBS += -lftd2xx

}
