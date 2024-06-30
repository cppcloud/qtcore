#ifndef CAT_H
#define CAT_H

#include <QObject>
#include <QScopedPointer>

class CatPrivate;
class Cat : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Cat)
    Q_D(Cat);

public:
    explicit Cat(QObject *parent = nullptr);

    void meow();
    void hiss();

signals:

public slots:
};

#endif // CAT_H
