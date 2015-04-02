#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

#include <pcl/console/parse.h>
#include <pcl/common/transforms.h>
#include <pcl/visualization/pcl_visualizer.h>

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
    bool readPointCloud(QString filename);
    ~MainWindow();

private slots:
    void open();
    void saveplypointcloud();
    void savepcdpointcloud();
private:
    QMenu *fileMenu;
    QMenu * editMenu;
    QAction * openAct;
    QAction * toplyAct;
    QAction * topcdAct;
    pcl::PointCloud<pcl::PointXYZ> cloud;
};

#endif // MAINWINDOW_H
