cmake_minimum_required (VERSION 2.6 )
project      (pcl_transaction)

#
SET (OCTOMAP_PROJECT_PATH "${HOME}/octomap")
SET (OCTOVIS_PROJECT_PATH "${HOME}/octomap")
SET (BASE_DIR "${CMAKE_SOURCE_DIR}")
SET (octovis_DIR "${HOME}/octomap/lib/cmake/octovis/")
MESSAGE("----------------------------------------")
MESSAGE("          Only for test!                ")
MESSAGE(${octovis_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")
MESSAGE(${CMAKE_MODULE_PATH})
MESSAGE("----------------------------------------")

#octomap
MESSAGE("----------------------------------------")
find_package(octomap ${OCTOVIS_MAJOR_VERSION}.${OCTOVIS_MINOR_VERSION} REQUIRED
HINTS ${OCTOMAP_PROJECT_PATH}/lib/cmake/octomap
${OCTOMAP_PROJECT_PATH}/../octomap/lib/cmake/octomap
)
IF(octomap_FOUND)
	MESSAGE(STATUS "Found octomap version: " ${octomap_VERSION})
	INCLUDE_DIRECTORIES (${OCTOMAP_INCLUDE_DIRS})
	link_directories    (${OCTOMAP_LIBRARY_DIRS})
ELSE()
	MESSAGE(STATUS "Can't found octomap!" )
ENDIF()
MESSAGE("----------------------------------------")

#octovis
MESSAGE("----------------------------------------")
find_package (octovis REQUIRED)
IF(octovis_FOUND)
	MESSAGE(STATUS "Octovis found!")
	INCLUDE_DIRECTORIES (${OCTOVIS_INCLUDE_DIRS})
	LINK_DIRECTORIES    (${OCTOVIS_LIBRARY_DIRS})
ELSE()
	MESSAGE(STATUS "Octovis not found!")
	set(OCTOVIS_INCLUDE_DIRS "/usr/include/QGLViewer" "/home/jian-li/octomap/octovis/include")
	MESSAGE(${OCTOVIS_INCLUDE_DIRS})
	set(OCTOVIS_LIBRARY_DIRS "/usr/lib/i386-linux-gnu" "/home/jian-li/octomap/octovis/lib")
	set(OCTOVIS_LIBRARIES 
	"qglviewer-qt4"
  	"optimized;/usr/lib/i386-linux-gnu/libQtOpenGL.so;debug;/usr/lib/i386-linux-gnu/libQtOpenGL.so;optimized;/usr/lib/i386-linux-gnu/libQtGui.so;debug;/usr/lib/i386-linux-gnu/libQtGui.so;optimized;/usr/lib/i386-linux-gnu/libQtXml.so;debug;/usr/lib/i386-linux-gnu/libQtXml.so;optimized;/usr/lib/i386-linux-gnu/libQtCore.so;debug;/usr/lib/i386-linux-gnu/libQtCore.so"
  	"/home/jian-li/octomap/lib/liboctovis.so")
	INCLUDE_DIRECTORIES (${OCTOVIS_INCLUDE_DIRS})
#	LINK_DIRECTORIES    (${OCTOVIS_LIBRARY_DIRS})
ENDIF()
MESSAGE("----------------------------------------")

#dynamicedit3d
MESSAGE("----------------------------------------")
FIND_PACKAGE(dynamicedt3d REQUIRED )
IF(dynamicedt3d_FOUND)
	MESSAGE(STATUS "Dynamicedit3d found!")
	INCLUDE_DIRECTORIES(${DYNAMICEDT3D_INCLUDE_DIRS})
ELSE()
	MESSAGE(STATUS "dynamicedit3d not found!")
	set(DYNAMICEDT3D_INCLUDE_DIRS "/home/jian-li/octomap/dynamicEDT3D/include")
	set(DYNAMICEDT3D_LIBRARY_DIRS "/home/jian-li/octomap/lib")
	set(DYNAMICEDT3D_LIBRARIES "/home/jian-li/octomap/lib/libdynamicedt3d.so")
	INCLUDE_DIRECTORIES(${DYNAMICEDT3D_INCLUDE_DIRS})
ENDIF()
MESSAGE("----------------------------------------")


#QT4 vtk pcl

FIND_PACKAGE(Qt4 REQUIRED)
set(QT_USE_QTOPENGL TRUE)
set(QT_USE_QTXML TRUE)
find_package (VTK REQUIRED)
find_package (PCL 1.7 REQUIRED)
find_package (QGLViewer)
find_package (OpenGL)
include_directories (${PCL_INCLUDE_DIRS})

link_directories    (${PCL_LIBRARY_DIRS})

add_definitions     (${PCL_DEFINITIONS})

#project
#INCLUDE (CMakeList_src.txt)

set  (project_HEADERS
	src/coreLib.h
	src/dataPanel.h
	src/dataTypes.h
	src/fileList.h
	src/filterParamWidget.h
	src/mainBoard.h
	src/meshParamWidget.h
	src/octmapParamWidget.h
	src/pclWidget.h
	src/ViewerWidget.h
)
set ( project_FORMS
)
set (project_SOURCES
	src/coreLib.cpp
	src/dataPanel.cpp
	src/fileList.cpp
	src/filterParamWidget.cpp
	src/mainBoard.cpp
	src/meshParamWidget.cpp
	src/octmapParamWidget.cpp
	src/pclWidget.cpp
	src/main.cpp
	src/ViewerWidget.cpp
)
set(project_RESOURCES src/images/images.qrc)
set  (VTK_LIBRARIES   vtkRendering vtkGraphics vtkHybrid QVTK)
QT4_WRAP_CPP (project_HEADERS_MOC   ${project_HEADERS})
QT4_WRAP_UI  (project_FORMS_HEADERS ${project_FORMS})
QT4_ADD_RESOURCES(project_RESOURCES_RCC ${project_RESOURCES})

INCLUDE         (${QT_USE_FILE})
ADD_DEFINITIONS (${QT_DEFINITIONS})

ADD_EXECUTABLE  (pcl_transaction ${project_SOURCES}
                                ${project_FORMS_HEADERS}
                                ${project_HEADERS_MOC}
				${project_RESOURCES_RCC}
)

TARGET_LINK_LIBRARIES (pcl_transaction ${QT_LIBRARIES} 
				       ${PCL_LIBRARIES} 
				       ${VTK_LIBRARIES}
				       ${OCTOMAP_LIBRARIES} 
				       ${OCTOVIS_LIBRARIES}
				       ${QT_XML_LIBRARY}
				       ${DYNAMICEDT3D_LIBRARIES}
)
