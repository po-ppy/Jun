#ifndef CHARTFORM_H
#define CHARTFORM_H

#include <QWidget>
#include <QtDataVisualization/Q3DScatter>
using namespace QtDataVisualization;
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
};

#endif // CHARTFORM_H
