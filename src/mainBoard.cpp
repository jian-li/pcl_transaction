#include "mainBoard.h"

mainBoard::mainBoard()
{
    initVariable();
    createActions();
    createMenus();
    createToolbars();
    setLayout();
}

void mainBoard::initVariable()
{
    fileListPanel = new fileList(this);
    logFilePanel = new QPlainTextEdit(this);
    pointcloudPanel = new pclWidget(this);

    cLib = new coreLib();

    meshParamPanel = new meshParamWidget(this);
    octmapParamPanel = new octmapParamWidget(this);
    filterParamPanel = new filterParamWidget(this);

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

    filteringAct = new QAction(tr("&Filter the point cloud"),this);
    filteringAct->setIcon(QIcon(":/filtering.png"));

    setOctParamAct = new QAction(tr("&Set Octomap parameter"),this);

    setMeshParamAct = new QAction(tr("&Set Mesh parameter"),this);

    setFilteringParamAct = new QAction(tr("Set the filtering Param"),this);

    fitInAct = new QAction(tr("Fit in"),this);
    fitInAct->setIcon(QIcon(":/fitin.png"));

    zoomInAct = new QAction(tr("Zoom in"),this);
    zoomInAct->setIcon(QIcon(":/zoomin.png"));

    zoomOutAct = new QAction(tr("&Zoom in"),this);
    zoomOutAct->setIcon(QIcon(":/zoomout.png"));


    connect(openAct,SIGNAL(triggered()),this,SIGNAL(openSlot()));
//    connect();
//    connect(exitAct,SIGNAL(triggered()),);
    connect(convertToPlyAct,SIGNAL(triggered()),cLib,SIGNAL(pcl2OctreeSlot()));
//    connect(convertToOctAct,SIGNAL(triggered()),);
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
    editMenu->addAction(setOctParamAct);
    editMenu->addAction(setMeshParamAct);
    editMenu->addAction(setFilteringParamAct);

    viewMenu =  menuBar()->addMenu(tr("View"));
    viewMenu->addAction(fitInAct);
    viewMenu->addAction(zoomInAct);
    viewMenu->addAction(zoomOutAct);
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
    rightGridLayout->addWidget(logFilePanel,5,1);

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
}


void mainBoard::convertToPcdSlot()
{

}

void mainBoard::convertToPlySlot()
{

}

void mainBoard::showOctParamSlot()
{

}


