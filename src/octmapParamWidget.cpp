/*user defined include*/
#include "octmapParamWidget.h"

using namespace std;


octmapParamWidget::octmapParamWidget(QWidget* parent)
    : QWidget(parent)
{
    initAll();
    setWidgetLayout();
    connectSignalAndSlot();
}

void octmapParamWidget::initAll()
{
    octmapParam = new octmapParamType;
    resolutionLabel = new QLabel(this);
    resolutionEdit = new QLineEdit(this);
    heightColorLabel = new QLabel(this);
    heightColorBox = new QComboBox(this);
    dialogButtonBox = new QDialogButtonBox(this);

    resolutionLabel->setText("Resolution:");
    heightColorLabel->setText("Height Color Coding:");

    heightColorBox->insertItem(0,"Yes");
    heightColorBox->insertItem(1,"No");

    dialogButtonBox->addButton("Ok",QDialogButtonBox::AcceptRole);
    dialogButtonBox->addButton("Cancel",QDialogButtonBox::RejectRole);
}

void octmapParamWidget::setWidgetLayout()
{
    QGridLayout * gridLayout = new QGridLayout;
    gridLayout->addWidget(resolutionLabel,0,0,1,2);
    gridLayout->addWidget(resolutionEdit,0,2,1,2);
    gridLayout->addWidget(heightColorLabel,1,0,1,2);
    gridLayout->addWidget(heightColorBox,1,2,1,2);
    gridLayout->addWidget(dialogButtonBox,2,2,1,2);
    this->setLayout(gridLayout);
}

void octmapParamWidget::connectSignalAndSlot()
{
//    connect(paramTypeBox,SIGNAL(currentIndexChanged(int)),this,SLOT(rePaintPanelSlot(int)));
    connect(dialogButtonBox,SIGNAL(accepted()),this,SLOT(setParamSlot()));
}


void octmapParamWidget::setParam(double resolution, bool heightColor)
{
    octmapParam->resolution = resolution;
    octmapParam->heightColor = heightColor;
}

void octmapParamWidget::rePaintPanelSlot(int type)
{

}

void octmapParamWidget::setParamSlot()
{
    writeLogFileSignal("Ok button pressed!");
    octmapParam->resolution = resolutionEdit->text().toDouble();
    if( heightColorBox->currentIndex() == 0)
    {
        octmapParam->heightColor = true;
    }
    else
    {
        octmapParam->heightColor = false;
    }
    emit setCoreLibOctMapSignal(octmapParam);
}


