 HEADERS       = \
    mainBoard.h \
    coreLib.h \
    dataPanel.h \
    dataTypes.h \
    meshParamWidget.h \
    octmapParamWidget.h \
    filterParamWidget.h \
    pclWidget.h \
    fileList.h \
    ViewerWidget.h
 SOURCES       = \
                 main.cpp \
    fileList.cpp \
    mainBoard.cpp \
    coreLib.cpp \
    dataPanel.cpp \
    filterParamWidget.cpp \
    meshParamWidget.cpp \
    octmapParamWidget.cpp \
    pclWidget.cpp \
    ViewerWidget.cpp

 # install
 target.path = $$[QT_INSTALL_EXAMPLES]/mainwindows/menus
 sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS menus.pro
 sources.path = $$[QT_INSTALL_EXAMPLES]/mainwindows/menus
 INSTALLS += target sources

RESOURCES += \
    images/images.qrc
