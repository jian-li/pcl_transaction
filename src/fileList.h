#ifndef FILELIST_H
#define FILELIST_H

#include <QString>
#include <QVector>
#include <QTreeWidget>
#include <QTreeView>
#include <QFileSystemModel>
#include <QVBoxLayout>
#include <QStandardItem>
#include <QStringList>
#include <QDialog>
#include <QBrush>

class fileList:public QWidget
{
    Q_OBJECT
public:
    fileList(QWidget* parent);
    void addTreeRoot(QString filename);
    void addTreeChild(QTreeWidgetItem * parent,QString filename);
    void connectSignalAndSlot();
    void initAll();
    QWidget * getTreeWidget(){return treeWidget;}
signals:
    void showChangedSignal();
    void writeLogFileSignal(QString text);
    void pclSelectedSignal(QString filename);
private slots:
    void addPointCloudNameSlot(QString filename);
    void treeItemDoubleClickedSlot(QTreeWidgetItem*,int);
//    void treeItemClickedSlot(QTreeWidgetItem*, int);
//    void DoubleClickedCallback(QTreeWidgetItem*,int);
private:
//    QVector<QString> pclFile;
    QTreeWidget * treeWidget;
    QStandardItemModel * standardModel;
};

#endif // FILELIST_H
