#include "mainBoard.h"

using namespace octomap;

mainBoard::mainBoard()
{
    initVariable();
    createActions();
    createMenus();
    createToolbars();
    setLayout();
    connectSignalsAndSlots();
}

void mainBoard::initVariable()
{
    fileListPanel = new fileList(this);
    logFilePanel = new QPlainTextEdit(this);
    pointcloudPanel = new pclWidget(this);

    cLib = new coreLib();

    meshParamPanel = new meshParamWidget(NULL);
    octmapParamPanel = new octmapParamWidget(NULL);
    filterParamPanel = new filterParamWidget(NULL);

    meshParamPanel->hide();
    octmapParamPanel->hide();
    filterParamPanel->hide();


    widget = new QWidget(this);
}

void mainBoard::createActions()
{
    openAct = new QAction(tr("&Open"),this);
    openAct->setShortcut(QKeySequence::Open);
    openAct->setIcon(QIcon(":/open.png"));

    recentFilesAct = new QAction(tr("&Recent files"),this);

    exitAct = new QAction(tr("&Exit"),this);
    exitAct->setShortcut(QKeySequence::Close);
//    exitAct->setIcon();
    convertToPlyAct = new QAction(tr("Convert to Ply format"),this);
//    convert
    convertToPcdAct = new QAction(tr("Convert to Pcd format"),this);


    convertToOctAct = new QAction(tr("Convert to Octomap format"),this);
    convertToOctAct->setIcon(QIcon(":/mesh.png"));

    convertToMeshAct = new QAction(tr("Convert to Mesh format"),this);
    convertToMeshAct->setIcon(QIcon(":/mesh.png"));

    filteringAct = new QAction(tr("&Filter the point cloud"),this);
    filteringAct->setIcon(QIcon(":/filtering.png"));

    freeSpaceAct = new QAction(tr("&View freespace"),this);
//    setOctParamAct = new QAction(tr("&Set Octomap parameter"),this);

//    setMeshParamAct = new QAction(tr("&Set Mesh parameter"),this);

//    setFilteringParamAct = new QAction(tr("Set the filtering Param"),this);

    fitInAct = new QAction(tr("Fit in"),this);
    fitInAct->setIcon(QIcon(":/fitin.png"));

    zoomInAct = new QAction(tr("Zoom in"),this);
    zoomInAct->setIcon(QIcon(":/zoomin.png"));

    zoomOutAct = new QAction(tr("&Zoom in"),this);
    zoomOutAct->setIcon(QIcon(":/zoomout.png"));

    heightColorAct = new QAction(tr("Height color"),this);

    heightColorAct->setCheckable(true);
    freeSpaceAct->setCheckable(true);

    connect(fitInAct,SIGNAL(triggered()),this,SLOT(fitInSlot()));
    connect(openAct,SIGNAL(triggered()),this,SLOT(openSlot()));
//    connect();
//    connect(exitAct,SIGNAL(triggered()),);
    connect(convertToPcdAct,SIGNAL(triggered()),this,SLOT(convertToPcdSlot()));
    connect(convertToPlyAct,SIGNAL(triggered()),this,SLOT(convertToPlySlot()));
    connect(convertToOctAct,SIGNAL(triggered()),this,SLOT(showOctomapSettingSlot()));

//    connect(filteringAct,SIGNAL(triggered()),);
//    connect(setOctParamAct,SIGNAL(triggered()),);
}


void mainBoard::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(recentFilesAct);
    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("Edit"));
    editMenu->addAction(convertToPlyAct);
    editMenu->addAction(convertToPcdAct);
    editMenu->addAction(convertToOctAct);
    editMenu->addAction(convertToMeshAct);
    editMenu->addAction(filteringAct);

    viewMenu =  menuBar()->addMenu(tr("View"));
    viewMenu->addAction(fitInAct);
    viewMenu->addAction(zoomInAct);
    viewMenu->addAction(zoomOutAct);
    viewMenu->addAction(heightColorAct);
    viewMenu->addAction(freeSpaceAct);
}

void mainBoard::createToolbars()
{
    openToolBar = addToolBar(tr("&Open"));
    openToolBar->addAction(openAct);

    fitInToolBar = addToolBar(tr("&Fit in"));
    fitInToolBar->addAction(fitInAct);

    convertToOctToolBar = addToolBar(tr("&Convert to Octomap"));
    convertToOctToolBar->addAction(convertToOctAct);

    convertToMeshToolBar = addToolBar(tr("&Convert to Mesh"));
    convertToMeshToolBar->addAction(convertToMeshAct);

    filteringToolBar = addToolBar(tr("&Filter the point cloud"));
    filteringToolBar->addAction(filteringAct);

    zoomInToolBar = addToolBar("&Zoom in");
    zoomInToolBar->addAction(zoomInAct);

    zoomOutToolBar = addToolBar(tr("&Zoom out"));
    zoomOutToolBar->addAction(zoomOutAct);

}

void mainBoard::setLayout()
{
    QGridLayout * rightGridLayout = new QGridLayout;
    rightGridLayout->setRowStretch(0,5);
    rightGridLayout->addWidget(pointcloudPanel,0,0,5,1);
    rightGridLayout->addWidget(logFilePanel,5,0);

    QGridLayout * leftGridLayout = new QGridLayout;
    leftGridLayout->addWidget(fileListPanel);

    QGridLayout * renderGridLayout =  new QGridLayout;
    renderGridLayout->setColumnStretch(0,1);
    renderGridLayout->setColumnStretch(1,4);
    renderGridLayout->addLayout(leftGridLayout,0,0,1,1);
    renderGridLayout->addLayout(rightGridLayout,0,1,1,4);

    widget->setLayout(renderGridLayout);

    this->setCentralWidget(widget);

}

void mainBoard::openSlot()
{
    QString fullPath =  QFileDialog::getOpenFileName(this,tr("Open point cloud"), "/home/jian-li", tr("Pcl Files (*.ply *.pcd)"));
    emit addPointCloudSignal(fullPath);
}

void mainBoard::connectSignalsAndSlots()
{
    /*mainBoard signals*/
    connect(this,SIGNAL(addPointCloudSignal(QString)),cLib,SLOT(addPointCloudSlot(QString)));
    connect(this,SIGNAL(addPointCloudSignal(QString)),fileListPanel,SLOT(addPointCloudNameSlot(QString)));
    connect(this,SIGNAL(savePcdSignal(QString)),cLib,SLOT(savePcdSlot(QString)));
    connect(this,SIGNAL(savePlySignal(QString)),cLib,SLOT(savePlySlot(QString)));
    connect(this,SIGNAL(writeLogFileSignal(QString)),logFilePanel,SLOT(appendPlainText(QString)));
    connect(this,SIGNAL(startOctomapConvertingSignal()),octmapParamPanel,SLOT(setParamSlot()));
    connect(this->heightColorAct,SIGNAL(toggled(bool)),pointcloudPanel,SLOT(convert2HeightMapSlot(bool)));
    connect(this->freeSpaceAct,SIGNAL(toggled(bool)),pointcloudPanel,SLOT(freeSpaceSlot(bool)));
    /*core lib signals*/
    connect(cLib,SIGNAL(firstShowSignal(pcl::PointCloud<pcl::PointXYZRGB>::Ptr,QString)),pointcloudPanel,SLOT(firstshowSlot(pcl::PointCloud<pcl::PointXYZRGB>::Ptr,QString)));
    connect(cLib,SIGNAL(addFileNameSignal(QString)),fileListPanel,SLOT(addPointCloudNameSlot(QString)));
    connect(cLib,SIGNAL(writeLogFileSignal(QString)),logFilePanel,SLOT(appendPlainText(QString)));
    connect(cLib,SIGNAL(firstOctomapShowSignal(AbstractOcTree* ,QString)),pointcloudPanel,SLOT(firstOctomapShowSlot(AbstractOcTree*,QString)));
    connect(cLib,SIGNAL(reshowSignal(QString)),pointcloudPanel,SLOT(reshowOctomapWindowSlot(QString)));

    /*file list panel signals*/
    connect(fileListPanel->getTreeWidget(),SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),pointcloudPanel,SLOT(refreshWindowSlot(QTreeWidgetItem*,int)));
    connect(fileListPanel->getTreeWidget(),SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),cLib,SLOT(pclIndexChangedSlot(QTreeWidgetItem*,int)));
    connect(fileListPanel,SIGNAL(writeLogFileSignal(QString)),logFilePanel,SLOT(appendPlainText(QString)));

    /*octomap parameter setting panel signals*/
    connect(octmapParamPanel,SIGNAL(writeLogFileSignal(QString)),logFilePanel,SLOT(appendPlainText(QString)));
    connect(octmapParamPanel,SIGNAL(setCoreLibOctMapSignal(octmapParamType *)),cLib,SLOT(setOctomapParamSlot(octmapParamType *)));
    connect(octmapParamPanel->getDialogButtonBoxPtr(),SIGNAL(accepted()),this,SLOT(octomapParamSetted()));
    connect(octmapParamPanel->getDialogButtonBoxPtr(),SIGNAL(rejected()),octmapParamPanel,SLOT(hide()));

    /**/
    connect(pointcloudPanel,SIGNAL(writeLogFile(QString)),logFilePanel,SLOT(appendPlainText(QString)));
}

void mainBoard::octomapParamSetted()
{
    octmapParamPanel->hide();
    emit startOctomapConvertingSignal();
}

void mainBoard::showOctomapSettingSlot()
{
    octmapParamPanel->move(QApplication::desktop()->screen()->rect().center() - octmapParamPanel->rect().center());
    octmapParamPanel->show();

}

void mainBoard::convertToPcdSlot()
{
    QString fullPath = QFileDialog::getSaveFileName(this,tr("Save Document"),QDir::currentPath(),tr("Documents (*.pcd)") );
    emit savePcdSignal(fullPath);
}

void mainBoard::convertToPlySlot()
{
    QString fullPath = QFileDialog::getSaveFileName(this,tr("Save Document"),QDir::currentPath(),tr("Documents (*.ply)") );
    emit savePlySignal(fullPath);
}

void mainBoard::fitInSlot()
{

}





