#include <QtGui>
#include "mainwindow.h"
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/console/print.h>
#include <pcl/console/parse.h>
#include <pcl/console/time.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <iostream>

using namespace pcl;
using namespace pcl::io;
using namespace pcl::console;
using namespace std;

//constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);
    createActions();
    createMenus();
}

//read the point cloud
bool MainWindow::readPointCloud(QString filename)
{
    //TODO:read the point cloud according to the point cloud type
    //get the format of point cloud
    QStringList pieces = filename.split(".");
    QString format = pieces.value(pieces.length());
    std::string name = filename.toStdString();
    if(QString::compare(format,"ply") == 0)
    {
        if(loadPLYFile(name, cloud) == -1)
        {
            PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
            return false;
        }
        else
            return true;
    }
    else if(QString::compare(format,"pcd") == 0)
    {
        if(loadPCDFile(name, cloud) == -1)
        {
            PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
            return false;
        }
        else
            return true;
    }
    //TODO: compare more point cloud type
}

//open the point cloud file
void MainWindow::open()
{
    QString filename = QFileDialog::getOpenFileName(this,
         tr("Open PCL"), "/home/jana", tr("PCL Files (*.pcd *.ply)"));
    if( !filename.isNull())
    {
       qDebug( filename.toAscii() );
    }
    // read the point cloud
    readPointCloud(filename);

}
//save point cloud in ply format
void MainWindow::saveplypointcloud()
{

}
//save point cloud in pcd format
void MainWindow::savepcdpointcloud()
{

}

//add action to widget
void MainWindow::createActions()
{
    //create the open action
    openAct = new QAction(tr("&Open"),this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
    //change format to ply
    toplyAct = new QAction(tr("&-->ply"),this);
    connect(toplyAct,SIGNAL(triggered()),this,SLOT(saveplypointcloud));
    //change format to pcd
    topcdAct = new QAction(tr("&-->pcd"),this);
    connect(topcdAct,SIGNAL(triggered()),this,SLOT(savepcdpointcloud));
}
//create menus
void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(toplyAct);
    editMenu->addAction(topcdAct);
}
//deconstructor
MainWindow::~MainWindow()
{

}
