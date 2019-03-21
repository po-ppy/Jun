#include "normalform.h"
#include "ui_normalform.h"

NormalForm::NormalForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NormalForm)
{
    ui->setupUi(this);
}

NormalForm::~NormalForm()
{
    delete ui;
}

void NormalForm::on_pushButton_4_clicked()
{
    emit closeSideBar();
}
