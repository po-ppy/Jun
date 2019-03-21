#include "denosingform.h"
#include "ui_denosingform.h"

DenosingForm::DenosingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DenosingForm)
{
    ui->setupUi(this);
}

DenosingForm::~DenosingForm()
{
    delete ui;
}

void DenosingForm::on_pushButton_4_clicked()
{
    emit closeSideBar();
}
