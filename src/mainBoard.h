#ifndef MAINBOARD_H
#define MAINBOARD_H

/*qt sys include*/
#include <QMainWindow>
#include <iostream>
#include <QString>
#include <QVTKWidget.h>
#include <QFileDialog>
#include <QAction>
#include <QActionGroup>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <map>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QLabel>
#include <QLineEdit>
#include <QDesktopWidget>
#include <QApplication>

/*external lib include*/
//pcl lib
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/console/parse.h>
#include <pcl/common/transforms.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/console/print.h>
#include <pcl/console/parse.h>
#include <pcl/console/time.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/pcl_visualizer.h>

//vtk lib
#include <vtkRenderWindow.h>
#include <octomap/AbstractOcTree.h>


/*user defined widget*/
#include "fileList.h"
#include "pclWidget.h"
#include "coreLib.h"
#include "meshParamWidget.h"
#include "octmapParamWidget.h"
#include "filterParamWidget.h"

class mainBoard:public QMainWindow
{
    Q_OBJECT
public:
    mainBoard();
    void createActions();
    void createMenus();
    void createToolbars();
    void initVariable();
    void setLayout();
//    void createQVTKWidget();
    void connectSignalsAndSlots();
private slots:
    void openSlot();
    void convertToPcdSlot();
    void convertToPlySlot();
    void showOctomapSettingSlot();
    void octomapParamSetted();
    void fitInSlot();
signals:
    void showMeshSettingSignal();
    void showFilteringSettingSignal();
    void hideMeshSettingSignal();
    void hideOctomapSettingSignal();
    void hideFilteringSettingSignal();
    void savePlySignal(QString fullPath);
    void savePcdSignal(QString fullPath);
    void addPointCloudSignal(QString filename);
    void newPanelSignal();
    void writeLogFileSignal(QString text);

    void startOctomapConvertingSignal();
private:
/*qt sys defined widget*/
/******** menu list*************/
    QMenu *fileMenu;
    QMenu * editMenu;
    QMenu * viewMenu;
    QMenu * settingMenu;
    QMenu * helpMenu;
/******** toobar list*************/
    QToolBar *openToolBar;
//    QToolBar *ToolBar;
    QToolBar *fitInToolBar;
    QToolBar *convertToOctToolBar;
    QToolBar *convertToMeshToolBar;
    QToolBar *filteringToolBar;
    QToolBar *zoomInToolBar;
    QToolBar *zoomOutToolBar;
//    QToolBar *dataToolBar;

/******** action list*************/
    //file menu action
    QAction * openAct;
    QAction * recentFilesAct;
    QAction * exitAct;
    //edit menu action
    QAction * convertToPlyAct;
    QAction * convertToPcdAct;
    QAction * convertToOctAct;
    QAction * convertToMeshAct;
    QAction * filteringAct;
    QAction * setOctParamAct;
    QAction * setMeshParamAct;
    QAction * setFilteringParamAct;

    //view menu action
    QAction * fitInAct;
    QAction * zoomInAct;
    QAction * zoomOutAct;
    QAction * heightColorAct;
    QAction * freeSpaceAct;
    //
/******** panel list*************/
    fileList * fileListPanel;
    QPlainTextEdit * logFilePanel;
    pclWidget * pointcloudPanel;

/*core*/
    coreLib * cLib;
    meshParamWidget * meshParamPanel;
    octmapParamWidget * octmapParamPanel;
    filterParamWidget * filterParamPanel;

    QWidget * widget;

};

#endif // MAINBOARD_H
