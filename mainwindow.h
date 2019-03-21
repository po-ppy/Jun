#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <normalform.h>
#include <chartform.h>
#include <denosingform.h>
#include <settingform.h>
#include <QProgressDialog>
#include <QThread>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    //void toggleSideBar();//无用
    void hideSideBar();
    void toggleNormalForm();
    void toggleDenosingForm();
    void toggleSettingForm();
    void showProgressDialog();
private:
    Ui::MainWindow *ui;
    NormalForm *normalForm;
    ChartForm *chartForm;
    DenosingForm *denosingForm;
    SettingForm *settingForm;

    QLabel *downLabel;
    QLabel *downNumLabel;

    QLabel *iterateLabel;
    QLabel *iteratenumLabel;

    QLabel *movementLabel;
    QLabel *movementNumLabel;

    QLabel *radiusLabel;
    QLabel *radiusNumLabel;

    QLabel *originalLabel;
    QLabel *originalNumLabel;

    QLabel *sampleLabel;
    QLabel *sampleNumLabel;

    QWidget *statusWidget;
    QHBoxLayout *lay;

    QPushButton *closeSideButton;


    //初始化状态栏
    void initStatusBar();
    void initAllForms();
};

#endif // MAINWINDOW_H
