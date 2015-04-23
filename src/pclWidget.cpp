#include "pclWidget.h"
/*qt sys include*/
#include <QWidget>
#include <QLabel>

using namespace pcl;

pclWidget::pclWidget(QWidget* parent)
    :QTabWidget(parent)
{
    QLabel * markPage = new QLabel;
    panelList.insert(pair<QString,QWidget *>("logo",markPage));
    markPage->setPixmap(QPixmap(":/logo.png"));
    this->addTab(markPage,"logo");
}

void pclWidget::refreshWindowSlot(QTreeWidgetItem* item,int)
{
    writeLogFile("File:"+item->text(0)+ " "+"double clicked!");
    QString fileName = item->text(0);
    QWidget * nextTab = panelList.find(fileName)->second;
    setCurrentWidget(nextTab);
}

void pclWidget::firstshowSlot(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud,QString filename)
{
    QVTKWidget * widget = new QVTKWidget;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    viewer.reset (new pcl::visualization::PCLVisualizer(filename.toStdString(), false));
    viewList.insert(pair<QString,boost::shared_ptr<pcl::visualization::PCLVisualizer> >(filename,viewer));
    panelList.insert(pair<QString,QWidget *>(filename,widget));

    widget->SetRenderWindow(viewer->getRenderWindow());
    viewer->setupInteractor(widget->GetInteractor(),widget->GetRenderWindow());

    widget->update();

    viewer->addPointCloud(cloud,filename.toStdString());
    viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, filename.toStdString());
    viewer->addCoordinateSystem (1.0);
    viewer->initCameraParameters();

    widget->update();
    this->addTab(widget,filename);

}


void pclWidget::zoomInSlot()
{

}

void pclWidget::zoomOutSlot()
{

}


