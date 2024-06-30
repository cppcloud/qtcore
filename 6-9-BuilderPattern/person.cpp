#include "person.h"

person *person::build(person::persontype type)
{
    person *p = new person(nullptr);
    p->m_type = type;

    return p;
}

person::persontype person::role()
{
    return m_type;
}

person::person(QObject *parent) : QObject(parent)
{

}
