#include "buttonnum.h"


ButtonNum::ButtonNum(int i):QPushButton(QString::number(i)),index(i){
    connect(this,SIGNAL(clicked(bool)),this,SLOT(clickButton()));
};


void ButtonNum::clickButton(){
    emit sendNumber(index);
}
