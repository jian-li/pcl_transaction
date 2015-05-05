// **************Version QT4************************
/*qt sys include*/
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

//octomap lib
#include <octomap/math/Utils.h>

/*user defined lib include */
#include "coreLib.h"

using namespace pcl;
using namespace pcl::io;
using namespace pcl::console;
using namespace pcl::visualization;
using namespace std;
using namespace octomap;

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
void coreLib::convertpclToOctree()
{
    emit writeLogFileSignal("Converting to octomap structure...");

    point3d origin(0.00f,0.00f,0.00f);
    Pointcloud octomapCloud;
    QString filename = curfile+".bt";
    if(octmapParam->heightColor)
    {
        ColorOcTree * tree = new ColorOcTree(octmapParam->resolution);
        pointcloudPcltoOctomap(cloud,octomapCloud);
        tree->insertPointCloud(octomapCloud,origin);
        emit firstOctomapShowSignal(tree,filename);
    }
    else
    {
        OcTree * tree = new OcTree(octmapParam->resolution);
        pointcloudPcltoOctomap(cloud,octomapCloud);
        tree->insertPointCloud(octomapCloud,origin);
        emit firstOctomapShowSignal(tree,filename);
    }
    emit addFileNameSignal(filename);
    emit writeLogFileSignal("Converting to Octree finished!");
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
            fullPath.append(".pcd");
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

void coreLib::setOctomapParamSlot(octmapParamType * data)
{
    octmapParam->resolution = data->resolution;
    octmapParam->heightColor = data->heightColor;
    convertpclToOctree();
}

void coreLib::setFilteringParamSlot()
{

}

void coreLib::pointcloudPcltoOctomap(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud,Pointcloud &  octCloud)
{
    for (size_t i = 0; i < cloud->points.size(); i++)
    {
        float x = cloud->points[i].x;
        float y = cloud->points[i].y;
        float z = cloud->points[i].z;
        octCloud.push_back(x,y,z);
    }
}
