#include "fileList.h"

fileList::fileList(QWidget* parent)
 : QWidget(parent)
{
    initAll();
//    connectSignalAndSlot();
}

void fileList::initAll()
{
    treeWidget = new QTreeWidget;
    treeWidget->setColumnCount(1);
    treeWidget->setHeaderLabels(QStringList()<<"File Navigator");
    addTreeRoot("logo");
    QVBoxLayout * vLayout = new QVBoxLayout;
    vLayout->addWidget(treeWidget);
    this->setLayout(vLayout);
}

void fileList::addTreeRoot(QString filename)
{
    QTreeWidgetItem * treeItem = new QTreeWidgetItem(treeWidget);
    treeItem->setText(0,filename);
}

void fileList::addTreeChild(QTreeWidgetItem * parent,QString filename)
{
    QTreeWidgetItem * treeItem = new QTreeWidgetItem;
    treeItem->setText(0,filename);
    parent->addChild(treeItem);
}

void fileList::addPointCloudNameSlot(QString fullPath)
{
    QFileInfo fileInfo(fullPath);
    QString fileName(fileInfo.fileName());
    addTreeRoot(fileName);
}

void fileList::connectSignalAndSlot()
{
//    connect(treeWidget,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(treeItemDoubleClickedSlot(QTreeWidgetItem*,int)));
//    connect(treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(treeItemClickedSlot(QTreeWidgetItem*,int)));
}

void fileList::treeItemDoubleClickedSlot(QTreeWidgetItem* item,int)
{
    emit writeLogFileSignal("TreeItem double clicked!");
    QString filename;
    filename = item->text(0);

}

//void fileList::treeItemClickedSlot(QTreeWidgetItem * item, int)
//{
////    emit writeLogFileSignal("TreeItem clicked!");
////    QString fileName;
////    fileName = item->text(0);
//}

