#include "slow.h"

slow::slow(QObject *parent) : car(parent)
{

}


void slow::drive()
{
    qInfo() << "Max speed 80 mph";
}
