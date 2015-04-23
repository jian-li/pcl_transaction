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
    void setParamSlot();
    void setParam(int type);
signals:
    void writeLogFileSlot(QString text);
    void setCoreLibOctMapSignal(octmapParamType *);
private slots:
    void showWindowSlot();
    void hideWindowSlot();
    void rePaintPanelSlot(int type);

private:
    QLabel * paramTypeLabel;
    QComboBox * paramTypeBox;
    QLabel * pointResolutionLabel;
    QLineEdit * pointResolutionEdit;
    QLabel * octreeResolutionLabel;
    QLineEdit * octreeResolutionEdit;
    QLabel * doVoxelGridDownSamplingLabel;
    QComboBox * doVoxelGridDownSamplingBox;
    QLabel * iFrameRateLabel;
    QLineEdit * iFrameRateEdit;
    QLabel * colorBitResolutionLabel;
    QLineEdit * colorBitResolutionEdit;
    QLabel * doColorEncodingLabel;
    QComboBox * doColorEncodingBox;
    QDialogButtonBox * dialogButtonBox;
//    octmapParamType * octmapParam;
};
#endif // OCTMAPPARAM_H
