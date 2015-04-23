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
    void setParam(int type);
signals:
    void writeLogFileSignal(QString text);
    void setCoreLibOctMapSignal(int type,octmapParamType *);
//    void convertToOctSignal();
private slots:
    void showWindowSlot();
    void hideWindowSlot();
    void setParamSlot();
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
