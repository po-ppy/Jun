#ifndef NORMALFORM_H
#define NORMALFORM_H

#include <QWidget>

namespace Ui {
class NormalForm;
}

class NormalForm : public QWidget
{
    Q_OBJECT

public:
    explicit NormalForm(QWidget *parent = nullptr);
    ~NormalForm();
signals:
    void closeSideBar();
private slots:
    void on_pushButton_4_clicked();

private:
    Ui::NormalForm *ui;
};

#endif // NORMALFORM_H
