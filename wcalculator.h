#ifndef WCALCULATOR_H
#define WCALCULATOR_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>

#include "buttonnum.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WCalculator; }
QT_END_NAMESPACE

class WCalculator : public QDialog
{
    Q_OBJECT

public:
    WCalculator(QWidget *parent = nullptr);
    ~WCalculator();


    ButtonNum* button_num[10];

    QPushButton * button_plus;
    QPushButton * button_minus;
    QPushButton * button_multiply;
    QPushButton * button_devide;
    QPushButton * button_equal;
    QPushButton * button_clear_all;

    QLineEdit* lineEdit;

    float num1,num2,result;
    QString S;
    char sign;
    int mark;
    void on_button_plus_clicked();

private slots:
    void on_button_minus_clicked();
    void on_button_multiply_clicked();
    void on_button_devide_clicked();
    void on_button_equal_clicked();
    void on_button_clear_all_clicked();
    void receiveNumber(int i);

private:
    Ui::WCalculator *ui;
};
#endif // WCALCULATOR_H
