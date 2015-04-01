#include <QtGui>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);
    createActions();
    createMenus();
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Open PCL"), "/home/jana", tr("PCL Files (*.pcd *.ply)"));
    if( !fileName.isNull())
    {
       qDebug( fileName.toAscii() );
    }
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open"),this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
}

MainWindow::~MainWindow()
{

}
