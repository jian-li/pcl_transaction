#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

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
    bool readPointCloud();

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
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
};

#endif // MAINWINDOW_H
