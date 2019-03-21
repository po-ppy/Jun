#ifndef CHARTFORM_H
#define CHARTFORM_H

#include <QWidget>
#include <QLabel>
#include <QFile>
#include <QFileDialog>
#include <QImage>
#include <QMessageBox>
//#include <QtDataVisualization/Q3DScatter>
//using namespace QtDataVisualization;
namespace Ui {
class ChartForm;
}

class ChartForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChartForm(QWidget *parent = nullptr);
    ~ChartForm();

private:
    Ui::ChartForm *ui;
    QLabel *imgLabel;

public slots:
    void showImg();
    void saveFile();
};

#endif // CHARTFORM_H
