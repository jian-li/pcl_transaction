#ifndef SHOWPANEL_H
#define SHOWPANEL_H
/*qt sys include*/
#include <QWidget>
#include <QVTKWidget.h>
#include <QTabWidget>
#include <map>
#include <QTreeWidget>
#include <QTreeWidgetItem>

/*external lib include*/
//pcl
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/console/parse.h>
#include <pcl/common/transforms.h>
#include <pcl/visualization/pcl_visualizer.h>
//vtk
#include <vtkRenderWindow.h>
//octomap
#include <octomap/octomap.h>
#include <octomap/AbstractOcTree.h>
#include <octomap/octomap_types.h>
//octovis lib
#include <octovis/OcTreeRecord.h>
#include <octomap/OcTreeBase.h>
#include <octovis/ColorOcTreeDrawer.h>
#include "ViewerWidget.h"

using namespace std;
using namespace octomap;

class pclWidget:public QTabWidget
{
    Q_OBJECT
public:
    pclWidget(QWidget* parent);
    void initVar();
    void showOctree();

    void addOctree(octomap::AbstractOcTree* tree, int id, octomap::pose6d origin);
    bool getOctreeRecord(int id, OcTreeRecord*& otr);
//TODO:zoom in
private slots:
    void freeSpaceSlot(bool checked);
    void refreshWindowSlot(QTreeWidgetItem*,int);
    void firstshowSlot(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud,QString filename);
//    void reshowSlot(QString filename);
    void zoomInSlot();
    void zoomOutSlot();
    void firstOctomapShowSlot(AbstractOcTree *, QString filename);
    void reshowOctomapWindowSlot( QString filename);
    void convert2HeightMapSlot(bool checked);
signals:
    void writeLogFile(QString text);
private:
    QVTKWidget * centralVtkWidget;
    ViewerWidget* m_glwidget;
    std::map<int, OcTreeRecord> m_octrees;
    unsigned int m_max_tree_depth;
//    QVTKWidget * replayqvtkWidget;
//    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud;
    QTabWidget* tabWidget;
/*panel list*/
    map<QString,QWidget*> panelList;
    map<QString,pcl::PointCloud<pcl::PointXYZRGB>::Ptr> pointcloudList;
    map<QString,boost::shared_ptr<pcl::visualization::PCLVisualizer> > viewList;
};

#endif // SHOWPANEL_H
