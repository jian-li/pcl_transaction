#ifndef FILELISTITEM_H
#define FILELISTITEM_H


#include <QList>
#include <QVariant>

class fileListItem
{
public:
    fileListItem(const QList<QVariant> &data, fileListItem *parent = 0);
    ~fileListItem();

    void appendChild(fileListItem *child);

    fileListItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    fileListItem *parent();

private:
    QList<fileListItem*> childItems;
    QList<QVariant> itemData;
    fileListItem *parentItem;
};


#endif // FILELISTITEM_H
