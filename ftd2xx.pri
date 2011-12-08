unix {
   CONFIG += link_pkgconfig
   PKGCONFIG += ftd2xx
}

win32 {
    INCLUDEPATH += d:/Libraries/FTDI
    LIBS += -Ld:/Libraries/FTDI
    LIBS += -lftd2xx
}
