#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class person : public QObject
{
    Q_OBJECT
public:
    enum persontype{PRINCIPAL,TEACHER,STUDENT};
    Q_ENUM(persontype)

    static person *build(persontype type);
    persontype role();

    explicit person(QObject *parent = nullptr);

signals:

public slots:
private:
    persontype m_type;
};

#endif // PERSON_H
