#ifndef MESHPARAM_H
#define MESHPARAM_H

/*qt sys include*/
#include <QWidget>
#include "dataTypes.h"

class meshParamWidget:public QWidget
{
    Q_OBJECT
public:
    meshParamWidget(QWidget* parent);
signals:
private slots:
    void hideWindowSlot();
    void showWindowSlot();
private:
    meshParamType * meshParam;

};

#endif // MESHPARAM_H
