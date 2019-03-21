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
    QObject::connect(denosingForm,SIGNAL(closeSideBar()),this,SLOT(hideSideBar()));
    QObject::connect(settingForm,SIGNAL(closeSideBar()),this,SLOT(hideSideBar()));
    connect(ui->actionNormal,SIGNAL(triggered(bool)),this,SLOT(toggleNormalForm()));
    connect(ui->actionDenoising,SIGNAL(triggered(bool)),this,SLOT(toggleDenosingForm()));
    connect(ui->actionSetting,SIGNAL(triggered(bool)),this,SLOT(toggleSettingForm()));
    connect(ui->actionRegistration,SIGNAL(triggered(bool)),this,SLOT(showProgressDialog()));

    connect(ui->actionOpen,SIGNAL(triggered(bool)),chartForm,SLOT(showImg()));
    connect(ui->actionSave,SIGNAL(triggered(bool)),chartForm,SLOT(saveFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initAllForms(){
    normalForm = new NormalForm(this);
    chartForm = new ChartForm(this);
    denosingForm = new DenosingForm(this);
    settingForm = new SettingForm(this);

    ui->rightStackedWidget->addWidget(normalForm);
    ui->rightStackedWidget->addWidget(denosingForm);
    ui->rightStackedWidget->addWidget(settingForm);
    ui->leftStackedWidget->addWidget(chartForm);
    ui->leftStackedWidget->setCurrentWidget(chartForm);
    ui->rightStackedWidget->setCurrentWidget(normalForm);
//    ui->rightStackedWidget->hide();
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

void MainWindow::showProgressDialog(){
    QProgressDialog progressDialog(tr("配准中"),tr("取消"),0,5000,this);
    progressDialog.setWindowTitle(tr("配准"));
        progressDialog.setWindowModality(Qt::WindowModal);
        progressDialog.show();
        for(int i = 0; i < 5000; i++)//已知最大值不超过50000
        {
            QThread::msleep(1);
            progressDialog.setValue(i);
            QCoreApplication::processEvents();
            if(progressDialog.wasCanceled())
                break;
        }
        progressDialog.setValue(5000);
        progressDialog.close();
        QMessageBox::information(this,"配准","已完成！");
}

void MainWindow::toggleNormalForm(){

    if(ui->rightStackedWidget->isVisible()){
        if(ui->rightStackedWidget->currentWidget() == normalForm){
            ui->rightStackedWidget->hide();
        }else{
            ui->rightStackedWidget->setCurrentWidget(normalForm);
        }
    }else{
        ui->rightStackedWidget->setCurrentWidget(normalForm);
        ui->rightStackedWidget->show();
    }
}

void MainWindow::toggleSettingForm(){

    if(ui->rightStackedWidget->isVisible()){
        if(ui->rightStackedWidget->currentWidget() == settingForm){
            ui->rightStackedWidget->hide();
        }else{
            ui->rightStackedWidget->setCurrentWidget(settingForm);
        }
    }else{
        ui->rightStackedWidget->setCurrentWidget(settingForm);
        ui->rightStackedWidget->show();
    }
}

void MainWindow::toggleDenosingForm(){

    if(ui->rightStackedWidget->isVisible()){
        if(ui->rightStackedWidget->currentWidget() == denosingForm){
            ui->rightStackedWidget->hide();
        }else{
            ui->rightStackedWidget->setCurrentWidget(denosingForm);
        }
    }else{
        ui->rightStackedWidget->setCurrentWidget(denosingForm);
        ui->rightStackedWidget->show();
    }
}
