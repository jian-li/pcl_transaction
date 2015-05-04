#include "pclWidget.h"
/*qt sys include*/
#include <QWidget>
#include <QLabel>

using namespace pcl;

pclWidget::pclWidget(QWidget* parent)
    :QTabWidget(parent)
{
    initVar();

}

void pclWidget::initVar()
{
    QLabel * markPage = new QLabel;
    panelList.insert(pair<QString,QWidget *>("logo",markPage));
    markPage->setPixmap(QPixmap(":/logo.png"));
    markPage->setScaledContents(true);
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

void pclWidget::firstOctomapShowSlot(OcTree* octoTree, QString filename)
{
    m_glwidget = new ViewerWidget;
    OcTreeRecord otr;
    otr.octree_drawer = new OcTreeDrawer();
    otr.octree = octoTree;
    octomap::pose6d o;
    otr.origin = o;
    m_octrees[0] = otr;
    m_glwidget->addSceneObject(otr.octree_drawer);
    this->addTab(m_glwidget,filename);
    showOctree();
}

void pclWidget::showOctree()
{
    // update viewer stat
      double minX, minY, minZ, maxX, maxY, maxZ;
      minX = minY = minZ = -10; // min bbx for drawing
      maxX = maxY = maxZ = 10;  // max bbx for drawing
      double sizeX, sizeY, sizeZ;
      sizeX = sizeY = sizeZ = 0.;
      size_t memoryUsage = 0;
      size_t num_nodes = 0;
      size_t memorySingleNode = 0;


      for (std::map<int, OcTreeRecord>::iterator it = m_octrees.begin(); it != m_octrees.end(); ++it)
      {
        // get map bbx
        double lminX, lminY, lminZ, lmaxX, lmaxY, lmaxZ;
        it->second.octree->getMetricMin(lminX, lminY, lminZ);
        it->second.octree->getMetricMax(lmaxX, lmaxY, lmaxZ);
        // transform to world coords using map origin
        octomap::point3d pmin(lminX, lminY, lminZ);
        octomap::point3d pmax(lmaxX, lmaxY, lmaxZ);
        pmin = it->second.origin.transform(pmin);
        pmax = it->second.origin.transform(pmax);
        lminX = pmin.x(); lminY = pmin.y(); lminZ = pmin.z();
        lmaxX = pmax.x(); lmaxY = pmax.y(); lmaxZ = pmax.z();
        // update global bbx
      // update viewer stat
      double minX, minY, minZ, maxX, maxY, maxZ;
      minX = minY = minZ = -10; // min bbx for drawing
      maxX = maxY = maxZ = 10;  // max bbx for drawing
      double sizeX, sizeY, sizeZ;
      sizeX = sizeY = sizeZ = 0.;
      size_t memoryUsage = 0;
      size_t num_nodes = 0;
      size_t memorySingleNode = 0;


      for (std::map<int, OcTreeRecord>::iterator it = m_octrees.begin();it != m_octrees.end(); ++it)
      {
        if (lminX < minX) minX = lminX;
        if (lminY < minY) minY = lminY;
        if (lminZ < minZ) minZ = lminZ;
        if (lmaxX > maxX) maxX = lmaxX;
        if (lmaxY > maxY) maxY = lmaxY;
        if (lmaxZ > maxZ) maxZ = lmaxZ;
        double lsizeX, lsizeY, lsizeZ;
        // update map stats
        it->second.octree->getMetricSize(lsizeX, lsizeY, lsizeZ);
        if (lsizeX > sizeX) sizeX = lsizeX;
        if (lsizeY > sizeY) sizeY = lsizeY;
        if (lsizeZ > sizeZ) sizeZ = lsizeZ;
        memoryUsage += it->second.octree->memoryUsage();
        num_nodes += it->second.octree->size();
        memorySingleNode = std::max(memorySingleNode, it->second.octree->memoryUsageNode());
      }

      m_glwidget->setSceneBoundingBox(qglviewer::Vec(minX, minY, minZ), qglviewer::Vec(maxX, maxY, maxZ));

      //if (m_octrees.size()) {
      QString size = QString("%L1 x %L2 x %L3 m^3; %L4 nodes").arg(sizeX).arg(sizeY).arg(sizeZ).arg(unsigned(num_nodes));
      QString memory = QString("Single node: %L1 B; ").arg(memorySingleNode)
                + QString ("Octree: %L1 B (%L2 MB)").arg(memoryUsage).arg((double) memoryUsage/(1024.*1024.), 0, 'f', 3);
//      m_mapMemoryStatus->setText(memory);
//      m_mapSizeStatus->setText(size);
      //}

      m_glwidget->updateGL();

      // generate cubes -> display
      // timeval start;
      // timeval stop;
      // gettimeofday(&start, NULL);  // start timer
      for (std::map<int, OcTreeRecord>::iterator it = m_octrees.begin(); it != m_octrees.end(); ++it) {
        it->second.octree_drawer->setMax_tree_depth(m_max_tree_depth);
        it->second.octree_drawer->setOcTree(*it->second.octree, it->second.origin, it->second.id);
      }
      //    gettimeofday(&stop, NULL);  // stop timer
      //    double time_to_generate = (stop.tv_sec - start.tv_sec) + 1.0e-6 *(stop.tv_usec - start.tv_usec);
      //    fprintf(stderr, "setOcTree took %f sec\n", time_to_generate);
      m_glwidget->updateGL();
    }
}

void pclWidget::reshowOctomapWindowSlot(QString filename)
{

}

void pclWidget::zoomInSlot()
{

}

void pclWidget::zoomOutSlot()
{

}
