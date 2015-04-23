#ifndef CORELIB_H
#define CORELIB_H

/*qt sys include*/
#include <QMainWindow>
#include <iostream>
#include <QString>
#include <QVTKWidget.h>
#include <QFileDialog>
#include <QAction>
#include <QActionGroup>
#include <QMenu>
#include <QToolBar>
#include <map>
#include <QTreeWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include "dataTypes.h"

/*external lib include*/
//pcl lib
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/console/parse.h>
#include <pcl/common/transforms.h>
#include <pcl/visualization/pcl_visualizer.h>
//vtk lib
#include <vtkRenderWindow.h>

using namespace std;

class coreLib:public QObject
{
    Q_OBJECT//use signals and slots
public:
    coreLib();
    ~coreLib();
    void convertpclToOctree();
    void filteringPointCloud();
    void convertPclToMesh();
    void initVariable();
private slots:
    void addPointCloudSlot(QString filename);
    void savePlySlot(QString );
    void savePcdSlot(QString );
    void pclIndexChangedSlot(QTreeWidgetItem *item,int);
    void setOctomapParamSlot(int ,octmapParamType *);
    void setFilteringParamSlot();
signals:
    void fileSletectedSignal(QString filename);
    void writeLogFileSignal(const QString& filename);
    void reshowSignal(QString filename);
    void firstShowSignal(pcl::PointCloud<pcl::PointXYZRGB>::Ptr,QString filename);
    void addFileNameSignal(QString filename);
private:
/*variable*/
    QString curfile;
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud;

    octmapParamType * octmapParam;
    int compressionType;
    //maintain the point cloud pointer lists
    map<QString,pcl::PointCloud<pcl::PointXYZRGB>::Ptr> pclList;
    //maintain the octomap pointer lists
    map<QString,pcl::PointCloud<pcl::PointXYZRGB>::Ptr> octomapList;
    map<QString,QString> pathList;


    //maintain the mesh pointer lists
//    map<QString,pcl::> meshList;

};

#endif // MAINWINDOW_H
