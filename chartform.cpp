#include "chartform.h"
#include "ui_chartform.h"

ChartForm::ChartForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChartForm)
{
    ui->setupUi(this);
    Q3DScatter *graph = new Q3DScatter();
    QWidget *container = QWidget::createWindowContainer(graph);
    //ScatterDataModifier *modifier = new ScatterDataModifier(graph);
    QScatter3DSeries *series = new QScatter3DSeries;
    QScatterDataArray data;
    data << QVector3D(0.5f, 0.5f, 0.5f) << QVector3D(-0.3f, -0.5f, -0.4f) << QVector3D(0.0f, -0.3f, 0.2f);
    series->dataProxy()->addItems(data);
    graph->addSeries(series);
    ui->verticalLayout->addWidget(container);

}

ChartForm::~ChartForm()
{
    delete ui;
}
