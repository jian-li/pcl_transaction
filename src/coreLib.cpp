// **************Version QT4************************
/*qt sys include*/
#include <QtGui>
#include <iostream>
#include <QWidget>
#include <QVTKWidget.h>
#include <QFileDialog>
#include <QMessageBox>

/*external lib include*/
//pcl
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/console/print.h>
#include <pcl/console/parse.h>
#include <pcl/console/time.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/compression/octree_pointcloud_compression.h>
//vtk
#include <vtkRenderWindow.h>

/*user defined lib include */
#include "coreLib.h"

using namespace pcl;
using namespace pcl::io;
using namespace pcl::console;
using namespace pcl::visualization;
using namespace std;

//constructor
//read the point cloud
coreLib::coreLib()
{
    initVariable();
}

void coreLib::initVariable()
{
    octmapParam = new octmapParamType;
}

void coreLib::addPointCloudSlot(QString fullPath)
{
    map<QString,QString>::iterator it = pathList.find(fullPath);
    if(it != pathList.end())
    {
        emit writeLogFileSignal("File already read!");
        return ;
    }
    //TODO:read the point cloud according to the point cloud type
    emit writeLogFileSignal("Reading file...");
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr temp(new pcl::PointCloud<pcl::PointXYZRGB>);
    cloud = temp;
    QString text = "";
    if(fullPath.endsWith(".ply",Qt::CaseSensitive))
    {
        if(loadPLYFile(fullPath.toStdString(), *cloud) < 0)
        {
            text = "Can't read file!";
            emit writeLogFileSignal(text);
        }
        else
        {
            text = "File type: ply!";
            emit writeLogFileSignal(text);
        }
    }
    else if(fullPath.endsWith(".pcd",Qt::CaseSensitive))
    {
        if(loadPCDFile(fullPath.toStdString(), *cloud) < 0)
        {
            text = "Can't read file!";
            emit writeLogFileSignal(text);        }
        else
        {
            text = "File type:pcd!";
            emit writeLogFileSignal(text);
        }
    }
    QFileInfo fileInfo(fullPath);
    QString fileName(fileInfo.fileName());
    pathList.insert(pair<QString,QString>(fullPath,fileName));
    pclList.insert(pair<QString,pcl::PointCloud<pcl::PointXYZRGB>::Ptr>(fileName,cloud));
    curfile = fileName;
    emit firstShowSignal(cloud,fileName);
    emit writeLogFileSignal("Reading finished!");
}

//pcl to octree
void coreLib::pcl2OctreeSlot()
{
    emit writeLogFileSignal("Converting to octomap structure...");
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr decompressedCloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    OctreePointCloudCompression<pcl::PointXYZRGB> octreeCompression(pcl::io::MED_RES_ONLINE_COMPRESSION_WITH_COLOR, true);
    std::stringstream compressedData;
    octreeCompression.encodePointCloud(cloud, compressedData);
    octreeCompression.decodePointCloud(compressedData, decompressedCloud);
    emit firstShowSignal(decompressedCloud,"octmap_"+curfile);
    emit addFileNameSignal("octmap_"+curfile);
    emit writeLogFileSignal("Converting finished!");
}

void coreLib::pclIndexChangedSlot(QTreeWidgetItem* item,int)
{

    QString selectedFile = item->text(0);
    emit writeLogFileSignal("Selected "+selectedFile);
    if(selectedFile == curfile)
    {
//        emit reshowSignal(selectedFile);
    }
    else
    {
        curfile = selectedFile;
        cloud = pclList.find(selectedFile)->second;
    }
}

void coreLib::savePcdSlot(QString fullPath)
{
    writeLogFileSignal("Writing pcd file to disk...");
    PCDWriter pcdwriter;
    if(!fullPath.isNull())
    {
        if(fullPath.endsWith (".pcd", Qt::CaseInsensitive))
            pcdwriter.write(fullPath.toStdString(),*cloud);
        else
        {
            fullPath.append(".ply");
            pcdwriter.write(fullPath.toStdString(),*cloud);
        }
    }
    writeLogFileSignal("Writing finished!");
}

void coreLib::savePlySlot(QString fullPath)
{
    writeLogFileSignal("Writing ply file to disk...");
    PLYWriter plywriter;
    if(!fullPath.isNull())
    {
        if(fullPath.endsWith (".pcd", Qt::CaseInsensitive))
            plywriter.write(fullPath.toStdString(),*cloud);
        else
        {
            fullPath.append(".ply");
            plywriter.write(fullPath.toStdString(),*cloud);
        }
    }
    writeLogFileSignal("Writing finished!");
}

//deconstructor
coreLib::~coreLib()
{

}
