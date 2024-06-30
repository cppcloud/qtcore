#ifndef CAT_P_H
#define CAT_P_H

#include <QObject>
#include <QDebug>

class Cat;
class CatPrivate
{
    Q_DECLARE_PUBLIC(Cat)
    Q_Q(Cat);

    CatPrivate(Cat *q) : q_ptr(q) {}
    ~CatPrivate() {}
    Cat *q_ptr;

    void meow();
    void hiss();
};

#endif // CAT_P_H
