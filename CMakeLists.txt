#make minimum required
CMAKE_MINIMUM_REQUIRED( VERSION 2.6 FATAL_ERROR )

#set project's name
PROJECT( pcl_transaction_app )

#set the src
SET( PCL_TRANSACTION_SRCS
     ./main.cpp 
     ./mainwindow.cpp
)

#another list
SET( PCL_TRANSACTION_MOC_HDRS
     ./mainwindow.h
)

#set some .ui files
#SET( PCL_TRANSACTION_UIS
#)

# and finally an resource file
#SET( PCL_TRANSACTION_SRCS
#)

#enable warning 
ADD_DEFINITIONS( -Wall )

#enable QtCore and QtGui by default
SET( QT_USE_QT3SUPPORT TRUE )
SET( QT_USE_QTXML TRUE )

#finds Qt4 libraries and sets all required variables
FIND_PACKAGE( Qt4 REQUIRED )
FIND_PACKAGE( PCL 1.7 REQUIRED COMPONENTS common io )

#add some useful macros and variables
INCLUDE( ${QT_USE_FILE} )

#this command will generate rules that will run rcc on all files from src
#in result rc_srcs variable will contain paths to files produced by rcc
QT4_ADD_RESOURCES( PCL_TRANSACTION_RC_SRCS ${PCL_TRANSACTION_RCS} )

#this will run uic on .ui files:
QT4_WRAP_UI( PCL_TRANSACTION_UI_HDRS ${PCL_TRANSACTION_UIS} )

#and finally this will run moc
QT4_WRAP_CPP( PCL_TRANSACTION_MOC_SRCS ${PCL_TRANSACTION_MOC_HDRS} )

#we need this to be able to include header produced by uic in our code
INCLUDE_DIRECTORIES( ${CMAKE_BINARY_DIR} ${PCL_INCLUDE_DIRS})

#add the link directories
LINK_DIRECTORIES( ${PCL_LIBRARY_DIRS} )

#add definitions
ADD_DEFINITIONS( ${PCL_DEFINITIONS} )

#here we instruct CMake to build excutable from all of the source files
ADD_EXECUTABLE( pcl_transaction ${PCL_TRANSACTION_SRCS} ${PCL_TRANSACTION_MOC_SRCS} ${PCL_TRANSACTION_RC_SRCS} ${PCL_TRANSACTION_UI_HDRS} )

#
TARGET_LINK_LIBRARIES( pcl_transaction ${QT_LIBRARIES} ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES})

