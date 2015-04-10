#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QFileDialog>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

#include <pcl/console/parse.h>
#include <pcl/common/transforms.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <vtkRenderWindow.h>
#include <QVTKWidget.h>

class QAction;
class QActionGroup;
class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    void createMenus();
    void createActions();
    void createQVTKWidget();
    bool readPointCloud(QString filename);
    ~MainWindow();

private slots:
    void open();
    void saveplypointcloud();
    void savepcdpointcloud();
    void pcl2octree();
//    void pcl2octreeslot();
private:
    QMenu *fileMenu;
    QMenu * editMenu;
    QAction * openAct;
    QAction * toplyAct;
    QAction * topcdAct;
    QAction * tooctAct;
    QVTKWidget * cloudqvtkWidget;
    QVTKWidget * replayqvtkWidget;
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> rightviewer;
};

#endif // MAINWINDOW_H
