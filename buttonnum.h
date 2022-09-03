#ifndef BUTTONNUM_H
#define BUTTONNUM_H

#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class ButtonNum; }
QT_END_NAMESPACE

class ButtonNum : public QPushButton
{
    Q_OBJECT
public:
    ButtonNum(int i);
    int index;
private slots:
    void clickButton();
signals:
    void sendNumber(int number);
};

#endif // BUTTONNUM_H
