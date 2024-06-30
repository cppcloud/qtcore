#include "widget.h"

widget::widget(QObject *parent) : QObject(parent)
{

}

void widget::makeChanges(QString value)
{
    test::instance()->name = value;
}
