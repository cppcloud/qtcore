#include "sports.h"

sports::sports(QObject *parent) : car(parent)
{

}


void sports::drive()
{
    qInfo() << "Max speed 120 mph";
}
