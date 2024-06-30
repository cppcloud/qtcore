#include "race.h"

race::race(QObject *parent) : car(parent)
{

}


void race::drive()
{
    qInfo() << "Max speed 200 mph";
}
