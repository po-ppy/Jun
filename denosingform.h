#ifndef DENOSINGFORM_H
#define DENOSINGFORM_H

#include <QWidget>

namespace Ui {
class DenosingForm;
}

class DenosingForm : public QWidget
{
    Q_OBJECT

public:
    explicit DenosingForm(QWidget *parent = nullptr);
    ~DenosingForm();

signals:
    void closeSideBar();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::DenosingForm *ui;
};

#endif // DENOSINGFORM_H
