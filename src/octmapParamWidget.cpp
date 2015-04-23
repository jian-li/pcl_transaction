/*user defined include*/
#include "octmapParamWidget.h"

using namespace std;
using namespace pcl::io;

octmapParamWidget::octmapParamWidget(QWidget* parent)
    : QWidget(parent)
{
    initAll();
    setWidgetLayout();
    connectSignalAndSlot();
}

void octmapParamWidget::initAll()
{
//    octmapParam = new octmapParamType;
    paramTypeLabel = new QLabel(this);
    paramTypeBox = new QComboBox(this);
    pointResolutionLabel = new QLabel(this);
    pointResolutionEdit = new QLineEdit(this);
    octreeResolutionLabel = new QLabel(this);
    octreeResolutionEdit = new QLineEdit(this);
    doVoxelGridDownSamplingLabel = new QLabel(this);
    doVoxelGridDownSamplingBox = new QComboBox(this);
    iFrameRateLabel = new QLabel(this);
    iFrameRateEdit =  new QLineEdit(this);
    colorBitResolutionLabel = new QLabel(this);
    colorBitResolutionEdit = new QLineEdit(this);
    doColorEncodingLabel = new QLabel(this);
    doColorEncodingBox =  new QComboBox(this);
    dialogButtonBox = new QDialogButtonBox(this);

    paramTypeLabel->setText("Profile Type:");
    pointResolutionLabel->setText("Point Resolution:");
    octreeResolutionLabel->setText("Octree Resolution:");
    doVoxelGridDownSamplingLabel->setText("Voxel Grid Downsampling:");
    iFrameRateLabel->setText("Frame Rate:");
    colorBitResolutionLabel->setText("Color Bit Resolution:");
    doColorEncodingLabel->setText("Do Color Encoding:");

    paramTypeBox->insertItem(0,"LOW_RES_ONLINE_COMPRESSION_WITHOUT_COLOR");
    paramTypeBox->insertItem(1,"LOW_RES_ONLINE_COMPRESSION_WITH_COLOR");
    paramTypeBox->insertItem(2,"MED_RES_ONLINE_COMPRESSION_WITHOUT_COLOR");
    paramTypeBox->insertItem(3,"MED_RES_ONLINE_COMPRESSION_WITH_COLOR");
    paramTypeBox->insertItem(4,"HIGH_RES_ONLINE_COMPRESSION_WITHOUT_COLOR");
    paramTypeBox->insertItem(5,"HIGH_RES_ONLINE_COMPRESSION_WITH_COLOR");
    paramTypeBox->insertItem(6,"LOW_RES_OFFLINE_COMPRESSION_WITHOUT_COLOR");
    paramTypeBox->insertItem(7,"LOW_RES_OFFLINE_COMPRESSION_WITH_COLOR");
    paramTypeBox->insertItem(8,"MED_RES_OFFLINE_COMPRESSION_WITHOUT_COLOR");
    paramTypeBox->insertItem(9,"MED_RES_OFFLINE_COMPRESSION_WITH_COLOR");
    paramTypeBox->insertItem(10,"HIGH_RES_OFFLINE_COMPRESSION_WITHOUT_COLOR");
    paramTypeBox->insertItem(11,"HIGH_RES_OFFLINE_COMPRESSION_WITH_COLOR");
    paramTypeBox->insertItem(12,"Manul Configuration");

    setParam(0);

    doVoxelGridDownSamplingBox->insertItem(0,"True");
    doVoxelGridDownSamplingBox->insertItem(1,"No");
    doColorEncodingBox->insertItem(0,"Yes");
    doColorEncodingBox->insertItem(1,"No");

    dialogButtonBox->addButton("Ok",QDialogButtonBox::YesRole);
    dialogButtonBox->addButton("Cancel",QDialogButtonBox::NoRole);


}

void octmapParamWidget::setWidgetLayout()
{
    QGridLayout * gridLayout = new QGridLayout;
    gridLayout->addWidget(paramTypeLabel,0,0);
    gridLayout->addWidget(paramTypeBox,0,1,1,3);
    gridLayout->addWidget(pointResolutionLabel,1,0);
    gridLayout->addWidget(pointResolutionEdit,1,1);
    gridLayout->addWidget(octreeResolutionLabel,1,2);
    gridLayout->addWidget(octreeResolutionEdit,1,3);
    gridLayout->addWidget(doVoxelGridDownSamplingLabel,2,0);
    gridLayout->addWidget(doVoxelGridDownSamplingBox,2,1);
    gridLayout->addWidget(iFrameRateLabel,2,2);
    gridLayout->addWidget(iFrameRateEdit,2,3);
    gridLayout->addWidget(colorBitResolutionLabel,3,0);
    gridLayout->addWidget(colorBitResolutionEdit,3,1);
    gridLayout->addWidget(doColorEncodingLabel,3,2);
    gridLayout->addWidget(doColorEncodingBox,3,3);
    gridLayout->addWidget(dialogButtonBox,4,3,1,2);
    this->setLayout(gridLayout);
}

void octmapParamWidget::connectSignalAndSlot()
{
    connect(paramTypeBox,SIGNAL(currentIndexChanged(int)),this,SLOT(rePaintPanelSlot(int)));
    connect(this,SIGNAL(accepted()),this,SLOT(setParamSlot()));

}


void octmapParamWidget::setParam(int type)
{
    pointResolutionEdit->setText(QString::number( compressionProfiles_[type].pointResolution));
    octreeResolutionEdit->setText(QString::number( compressionProfiles_[type].octreeResolution));
    iFrameRateEdit->setText(QString::number( compressionProfiles_[type].iFrameRate));
    colorBitResolutionEdit->setText(QString::number( compressionProfiles_[type].colorBitResolution));
    if(compressionProfiles_[type].doVoxelGridDownSampling)
    {
        doVoxelGridDownSamplingBox->setCurrentIndex(0);
    }
    else
    {
        doVoxelGridDownSamplingBox->setCurrentIndex(1);
    }
    if(compressionProfiles_[type].doColorEncoding)
    {
        doColorEncodingBox->setCurrentIndex(0);
    }
    else
    {
        doColorEncodingBox->setCurrentIndex(1);
    }
}

void octmapParamWidget::rePaintPanelSlot(int type)
{
    if(type != 12)
    {
        //show the parameter in the panel
        setParam(type);
    }
    else
    {
//        octmapParam->confProfileParam = new compressionProfiles_t;
    }
}

void octmapParamWidget::setParamSlot(int type)
{
//    octmapParam->confProfileParam = new configurationProfile_t(compressionProfiles[type]);
}

void octmapParamWidget::showWindowSlot()
{
    writeLogFileSlot("Please set the octomap parameter!");
    QMessageBox::information(this,"","");
}

void octmapParamWidget::hideWindowSlot()
{
    this->hide();
}
//void octmapParamWidget::writeLogFileSlot(QString text)
