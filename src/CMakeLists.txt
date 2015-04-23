cmake_minimum_required (VERSION 2.6 FATAL_ERROR)

project      (pcl-transaction)
find_package (Qt4 REQUIRED)
find_package (VTK REQUIRED)
find_package (PCL 1.7 REQUIRED)

include_directories (${PCL_INCLUDE_DIRS})
link_directories    (${PCL_LIBRARY_DIRS})
add_definitions     (${PCL_DEFINITIONS})

set  (project_HEADERS
	coreLib.h
	dataPanel.h
	dataTypes.h
	fileList.h
	filterParamWidget.h
	mainBoard.h
	meshParamWidget.h
	octmapParamWidget.h
	pclWidget.h
	renderWindow.h
)
set ( project_FORMS
)
set (project_SOURCES
	coreLib.cpp
	dataPanel.cpp
	fileList.cpp
	filterParamWidget.cpp
	mainBoard.cpp
	meshParamWidget.cpp
	octmapParamWidget.cpp
	pclWidget.cpp
	renderWindow.cpp
	main.cpp
)
set(project_RESOURCES images/images.qrc)
set  (VTK_LIBRARIES   vtkRendering vtkGraphics vtkHybrid QVTK)

QT4_WRAP_CPP (project_HEADERS_MOC   ${project_HEADERS})
QT4_WRAP_UI  (project_FORMS_HEADERS ${project_FORMS})
QT4_ADD_RESOURCES(project_RESOURCES_RCC ${project_RESOURCES})

INCLUDE         (${QT_USE_FILE})
ADD_DEFINITIONS (${QT_DEFINITIONS})

ADD_EXECUTABLE  (pcl_visualizer ${project_SOURCES}
                                ${project_FORMS_HEADERS}
                                ${project_HEADERS_MOC}
				${project_RESOURCES_RCC}
)

TARGET_LINK_LIBRARIES (pcl_visualizer ${QT_LIBRARIES} ${PCL_LIBRARIES} ${VTK_LIBRARIES})

