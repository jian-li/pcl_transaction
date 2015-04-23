#ifndef FILTERPARAM_H
#define FILTERPARAM_H

#include <QWidget>
#include "dataTypes.h"

class filterParamWidget:public QWidget
{
    Q_OBJECT
public:
    filterParamWidget(QWidget * parent);
signals:
private slots:
    void hideWindowSlot();
    void showWindowSlot();
private:
    filterParamType * filterParam;
};

#endif // FILTERPARAM_H
