#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initStatusBar();
    initAllForms();
    QObject::connect(normalForm,SIGNAL(closeSideBar()),this,SLOT(hideSideBar()));
    connect(ui->actionNormal,SIGNAL(triggered(bool)),this,SLOT(toggleNormalForm()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initAllForms(){
    normalForm = new NormalForm(this);
    chartForm = new ChartForm(this);

    ui->rightStackedWidget->addWidget(normalForm);
    ui->leftStackedWidget->addWidget(chartForm);
    ui->leftStackedWidget->setCurrentWidget(chartForm);
    ui->rightStackedWidget->setCurrentWidget(normalForm);
}

void MainWindow::initStatusBar(){
    //状态栏label创建
    downLabel = new QLabel("Down:",this);
    downNumLabel = new QLabel("1000",this);

    iterateLabel = new QLabel("Iterate:",this);
    iteratenumLabel = new QLabel("0",this);

    movementLabel = new QLabel("Movememt:",this);
    movementNumLabel = new QLabel("0",this);

    radiusLabel = new QLabel("Radius:",this);
    radiusNumLabel = new QLabel("0",this);

    originalLabel = new QLabel("Original points:",this);
    originalNumLabel = new QLabel("0",this);

    sampleLabel = new QLabel("Sample points:",this);
    sampleNumLabel = new QLabel("0",this);

    //closeSideButton = new QPushButton();
   //closeSideButton->setIcon(QIcon(":/rightArrow.png"));

    QWidget *statusWidget = new QWidget(this);
    QHBoxLayout *lay = new QHBoxLayout();


    QList<QLabel*> labelList;

    labelList << downLabel << downNumLabel;
    labelList << iterateLabel << iteratenumLabel;
    labelList << movementLabel << movementNumLabel;
    labelList << radiusLabel << radiusNumLabel;
    labelList << originalLabel << originalNumLabel;
    labelList << sampleLabel << sampleNumLabel;

    for(int i = 0; i < labelList.count(); i++){
        if(i % 2 == 0){
            labelList.at(i)->setAlignment(Qt::AlignRight);//文字靠右
        }else{
            labelList.at(i)->setMinimumWidth(60);//数值最小宽度60
        }
        lay->addWidget(labelList.at(i));
    }

    for(int i = 0; i < lay->count(); i++){
            lay->setStretch(i,1);
    }
    statusWidget->setLayout(lay);

    ui->statusBar->addWidget(statusWidget);
    //ui->statusBar->addPermanentWidget(closeSideButton);
}

//void MainWindow::toggleSideBar(){
//    if(ui->rightStackedWidget->isVisible()){
//        closeSideButton->setIcon(QIcon(":/leftArrow.png"));
//        ui->rightStackedWidget->hide();
//    }else{
//        closeSideButton->setIcon(QIcon(":/rightArrow.png"));
//        ui->rightStackedWidget->show();
//    }
//}

void MainWindow::hideSideBar(){
    ui->rightStackedWidget->hide();
}

void MainWindow::toggleNormalForm(){

    if(ui->rightStackedWidget->isVisible()){
        ui->rightStackedWidget->hide();
    }else{
        ui->rightStackedWidget->setCurrentWidget(normalForm);
        ui->rightStackedWidget->show();
    }
}
