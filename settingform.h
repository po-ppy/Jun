#ifndef SETTINGFORM_H
#define SETTINGFORM_H

#include <QWidget>

namespace Ui {
class SettingForm;
}

class SettingForm : public QWidget
{
    Q_OBJECT

public:
    explicit SettingForm(QWidget *parent = nullptr);
    ~SettingForm();

signals:
    void closeSideBar();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::SettingForm *ui;
};

#endif // SETTINGFORM_H
