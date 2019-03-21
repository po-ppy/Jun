#include "chartform.h"
#include "ui_chartform.h"

ChartForm::ChartForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChartForm)
{
    ui->setupUi(this);
    imgLabel = new QLabel();
    ui->verticalLayout->addWidget(imgLabel);
//    Q3DScatter *graph = new Q3DScatter();
//    QWidget *container = QWidget::createWindowContainer(graph);
//    //ScatterDataModifier *modifier = new ScatterDataModifier(graph);
//    QScatter3DSeries *series = new QScatter3DSeries;
//    QScatterDataArray data;
//    data << QVector3D(0.5f, 0.5f, 0.5f) << QVector3D(-0.3f, -0.5f, -0.4f) << QVector3D(0.0f, -0.3f, 0.2f);
//    series->dataProxy()->addItems(data);
//    graph->addSeries(series);
//    ui->verticalLayout->addWidget(container);

}

ChartForm::~ChartForm()
{
    delete ui;
}

void ChartForm::showImg(){
    QString fileName = QFileDialog::getOpenFileName(this,"选择文件");
    if(!fileName.isEmpty()){
        QImage image;
        image.load(fileName);
        imgLabel->setPixmap(QPixmap::fromImage(image));
    }

}

void ChartForm::saveFile(){
    QString fileName = QFileDialog::getSaveFileName(this,"保存文件");
    if(!fileName.isNull() && !fileName.isEmpty()){
        QMessageBox::information(this,"提示","文件已保存。");
    }
}
