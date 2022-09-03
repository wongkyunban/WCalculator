#include <QGridLayout>
#include <QDebug>

#include "wcalculator.h"
#include "./ui_wcalculator.h"

WCalculator::WCalculator(QWidget *parent)
    : QDialog(parent)
{
    num1 = 0.0;
    num2 = 0.0;
    result = 0.0;
    S = "";
    sign = -1;
    mark = 1;

    lineEdit = new QLineEdit("C");

    QGridLayout* Grid = new QGridLayout;

    Grid->addWidget(lineEdit,1,0,1,4,Qt::Alignment());


    for(int i = 0;i<10;i++){
        button_num[i] = new ButtonNum(i);
    }

    QPushButton* button[6];

    button_plus = new QPushButton("+");
    button_minus = new QPushButton("-");
    button_multiply = new QPushButton("*");
    button_devide = new QPushButton("/");
    button_equal = new QPushButton("=");
    button_clear_all = new QPushButton("c");

    button[0] = button_plus;
    button[1] = button_minus;
    button[2] = button_multiply;
    button[3] = button_devide;
    button[4] = button_equal;
    button[5] = button_clear_all;


    for(int i =1;i<5;i++){
        for(int j = 0; j < 4;j++){
            int num_arr_index = (i-1)*4+j;
            qDebug() << (i-1)*4+j << Qt::endl;
            if(num_arr_index < 10){
                Grid->addWidget((QPushButton*)button_num[num_arr_index],i+1,j,Qt::Alignment());
                connect(button_num[num_arr_index],SIGNAL(sendNumber(int)),this,SLOT(receiveNumber(int)));
            } else {
                Grid->addWidget(button[num_arr_index - 10],i+1,j,Qt::Alignment());
            }
        }
    }

    this->setLayout(Grid);

    connect(button_plus,&QPushButton::clicked,this,&WCalculator::on_button_plus_clicked);
    connect(button_minus,SIGNAL(clicked(bool)),this,SLOT(on_button_minus_clicked()));
    connect(button_multiply,SIGNAL(clicked(bool)),this,SLOT(on_button_multiply_clicked()));
    connect(button_devide,SIGNAL(clicked(bool)),this,SLOT(on_button_devide_clicked()));
    connect(button_equal,SIGNAL(clicked(bool)),this,SLOT(on_button_equal_clicked()));
    connect(button_clear_all,SIGNAL(clicked(bool)),this,SLOT(on_button_clear_all_clicked()));

}

void WCalculator::receiveNumber(int number){
    S += QString::number(number);
    lineEdit->setText(S);
    if(mark == 1){
        num1 = num1 * 10 + number;
    } else {
        num2 = num2 * 10 + number;
    }
}

void WCalculator::on_button_plus_clicked(){
    S += "+";
    sign = '+';
    mark = 2;
    lineEdit->setText(S);
}

void WCalculator::on_button_minus_clicked(){
    S += "-";
    sign = '-';
    mark = 2;
    lineEdit->setText(S);
}

void WCalculator::on_button_multiply_clicked(){
    S += "*";
    sign = '*';
    mark = 2;
    lineEdit->setText(S);
}
void WCalculator::on_button_devide_clicked(){
    S += "/";
    sign = '/';
    mark = 2;
    lineEdit->setText(S);
}

void WCalculator::on_button_equal_clicked(){
    S += "=";

    switch (sign) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    default:
        break;
    }
    S += QString("%1").arg(result);
    lineEdit->setText(S);

}

void WCalculator::on_button_clear_all_clicked(){
    num1 = 0.0;
    num2 = 0.0;
    result = 0.0;
    sign = -1;
    mark = 1;
    S = "";
    lineEdit->setText(S);
}

WCalculator::~WCalculator()
{
    delete ui;
}

