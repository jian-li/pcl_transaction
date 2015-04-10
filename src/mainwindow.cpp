#include <QtGui>
#include "mainwindow.h"
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/console/print.h>
#include <pcl/console/parse.h>
#include <pcl/console/time.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <iostream>
#include <pcl/visualization/pcl_visualizer.h>
#include <vtkRenderWindow.h>
#include <QVTKWidget.h>
#include <QWidget>
#include <pcl/compression/octree_pointcloud_compression.h>

using namespace pcl;
using namespace pcl::io;
using namespace pcl::console;
using namespace pcl::visualization;
using namespace std;

//constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    initialize the variables
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr pcloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    cloud = pcloud;
//    setup layout
    this->resize(800,540);
    QWidget * renderWidget = new QWidget(this);
    setCentralWidget(renderWidget);
    QHBoxLayout * hblayout = new QHBoxLayout(renderWidget);
//    hblayout->addWidget(cloudqvtkWidget);
//    hblayout->addWidget(replayqvtkWidget);
//    set central widget

    QWidget *widget = new QWidget(this);

//    setCentralWidget(widget);
    cloudqvtkWidget = new QVTKWidget(widget,Qt::Widget);
    replayqvtkWidget = new QVTKWidget(widget,Qt::Widget);
    createActions();
    createMenus();
    //TODO:
    viewer.reset (new pcl::visualization::PCLVisualizer("viewer", false));
    rightviewer.reset(new pcl::visualization::PCLVisualizer("rightviewer",false));

    cloudqvtkWidget->SetRenderWindow (viewer->getRenderWindow ());
    replayqvtkWidget->SetRenderWindow(rightviewer->getRenderWindow());

    viewer->setupInteractor (cloudqvtkWidget->GetInteractor (),cloudqvtkWidget->GetRenderWindow ());
    rightviewer->setupInteractor(replayqvtkWidget->GetInteractor(),replayqvtkWidget->GetRenderWindow());

    //    set the cloudqvtkwidget layout
    hblayout->addWidget(cloudqvtkWidget);
    hblayout->addWidget(replayqvtkWidget);
    renderWidget->setLayout(hblayout);
    cloudqvtkWidget->update ();
    replayqvtkWidget->update();
}


//read the point cloud
bool MainWindow::readPointCloud(QString filename)
{
    //TODO:read the point cloud according to the point cloud type
    //get the format of point cloud
//    QStringList pieces = filename.split(".");
//    QString format = pieces.value(pieces.lenth());
//    std::string name = filename.toStdString();
    std::cout<<filename.toStdString().data()<<endl;
    if(filename.endsWith(".ply",Qt::CaseSensitive))
    {
        std::cout<<filename.toStdString().data()<<endl;
        if(loadPLYFile(filename.toStdString(), *cloud) < 0)
        {
            std::cout<<"Couldn't read file test.ply \n"<<endl;
            return false;
        }
        else
        {
            std::cout<<"read file test.ply \n";
        }
    }
    else if(filename.endsWith(".pcd",Qt::CaseSensitive))
    {
        std::cout<<filename.toStdString().data()<<endl;
        if(loadPCDFile(filename.toStdString(), *cloud) < 0)
        {
            PCL_ERROR ("Couldn't read file test.pcd \n");
            return false;
        }
        else
        {
            std::cout<<"read file test.pcd \n";
            pcl::PCDWriter writer;
            writer.write ("out.pcd", *cloud);
        }
    }
//    if(!cloud)
//    {
    std::cout<<"read file \n";
    viewer->addPointCloud (cloud, "cloud");
    cloudqvtkWidget->update();
    return true;
//    }//TODO: compare more point cloud type
//    else
//    {
//        std::cout<<"point cloud doesn't load!\n";
//        return false;
//    }
}

//open the point cloud file
void MainWindow::open()
{
//    std::cout<<"filename.toStdString().data()"<<endl;
    QString filename = QFileDialog::getOpenFileName(this,
         tr("Open PCL"), "/home/jana", tr("PCL Files (*.pcd *.ply)"));
    if( !filename.isNull())
    {
       qDebug( filename.toAscii() );
    }
//    print the filename
//    std::cout<<filename.toStdString().data()<<endl;
    // read the point cloud
    readPointCloud(filename);
}

//save point cloud in ply format
void MainWindow::saveplypointcloud()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("Save Document"),QDir::currentPath(),tr("Documents (*.ply)") );
    PLYWriter plywriter;
//    std::string name = filename.toStdString();
    if(!filename.isNull())
    {
        if(filename.endsWith (".pcd", Qt::CaseInsensitive))
            plywriter.write(filename.toStdString(),*cloud);
        else
        {
            filename.append(".ply");
            plywriter.write(filename.toStdString(),*cloud);
        }
    }
    else
        return;
}

//save point cloud in pcd format
void MainWindow::savepcdpointcloud()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("Save Document"),QDir::currentPath(),tr("Documents (*.ply)") );
    PCDWriter pcdwriter;
//    std::string name = filename.toStdString();
    PCL_INFO("File chosen: %s\n",filename.toStdString().c_str());
    if(!filename.isNull())
    {
        if(filename.endsWith (".pcd", Qt::CaseInsensitive))
            pcdwriter.write(filename.toStdString(),*cloud);
        else
        {
            filename.append(".ply");
            pcdwriter.write(filename.toStdString(),*cloud);
        }
    }
    else
        return;
}

//pcl to octree
void MainWindow::pcl2octree()
{
    //
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr decompressedCloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    OctreePointCloudCompression<pcl::PointXYZRGB> octreeCompression(pcl::io::MED_RES_ONLINE_COMPRESSION_WITH_COLOR, true);
    std::stringstream compressedData;
    octreeCompression.encodePointCloud(cloud, compressedData);
    octreeCompression.decodePointCloud(compressedData, decompressedCloud);
    rightviewer->addPointCloud(decompressedCloud,"compressedData");
    replayqvtkWidget->update();
//    octreeCompression.decodePointCloud(compressedData, decompressedCloud);
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
    connect(toplyAct,SIGNAL(triggered()),this,SLOT(saveplypointcloud()));
    //change format to pcd
    topcdAct = new QAction(tr("&-->pcd"),this);
    connect(topcdAct,SIGNAL(triggered()),this,SLOT(savepcdpointcloud()));
    //pcl to octree
    tooctAct = new QAction(tr("&pcl-->octree"),this);
    connect(tooctAct,SIGNAL(triggered()),this,SLOT(pcl2octree()));
}
//create menus
void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(toplyAct);
    editMenu->addAction(topcdAct);
    editMenu->addAction(tooctAct);

}
//deconstructor
MainWindow::~MainWindow()
{

}
