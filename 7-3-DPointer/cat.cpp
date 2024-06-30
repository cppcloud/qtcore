#include "cat.h"
#include "cat_p.h"

Cat::Cat(QObject *parent) : QObject(parent)
{
    qInfo() << "Created in public" << this;
    qInfo() << "d_func: " << this->d_func();
    qInfo() << "d_ptr: " << this->d_ptr;
    qInfo() << "d: " << this->d;

}

void Cat::meow()
{
    this->d_func()->meow();
}

void Cat::hiss()
{
   this->d_func()->hiss();
}

void CatPrivate::meow()
{
    qInfo() << "meow";
}

void CatPrivate::hiss()
{
    qInfo() << "his";
}
