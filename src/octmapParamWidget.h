#ifndef OCTMAPPARAM_H
#define OCTMAPPARAM_H

/*qt sys include*/
#include <QWidget>
#include "dataTypes.h"
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QMessageBox>


class octmapParamWidget:public QWidget
{
    Q_OBJECT
public:
    octmapParamWidget(QWidget* parent);
    void initAll();
    void setWidgetLayout();
    void connectSignalAndSlot();
    void setParam(double resolution = 0.05,bool heightColor = false);
    QWidget* getDialogButtonBoxPtr(){return dialogButtonBox;}
signals:
    void writeLogFileSignal(QString text);
    void setCoreLibOctMapSignal(octmapParamType * octmapParam);

private slots:
    void setParamSlot();
    void rePaintPanelSlot(int type);

private:
    QLabel * resolutionLabel;
    QLineEdit * resolutionEdit;
    QLabel * heightColorLabel;
    QComboBox * heightColorBox;
    octmapParamType * octmapParam;
    QDialogButtonBox * dialogButtonBox;
};
#endif // OCTMAPPARAM_H
