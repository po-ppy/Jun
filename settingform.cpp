#include "settingform.h"
#include "ui_settingform.h"

SettingForm::SettingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingForm)
{
    ui->setupUi(this);
}

SettingForm::~SettingForm()
{
    delete ui;
}

void SettingForm::on_pushButton_4_clicked()
{
    emit closeSideBar();
}
