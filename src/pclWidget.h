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


using namespace std;

class pclWidget:public QTabWidget
{
    Q_OBJECT
public:
    pclWidget(QWidget* parent);
//TODO:zoom in
private slots:
    void refreshWindowSlot(QTreeWidgetItem*,int);
    void firstshowSlot(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud,QString filename);
//    void reshowSlot(QString filename);
    void zoomInSlot();
    void zoomOutSlot();
signals:
    void writeLogFile(QString text);
private:
    QVTKWidget * centralVtkWidget;
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
