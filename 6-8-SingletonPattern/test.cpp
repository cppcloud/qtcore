#include "test.h"

test *test::createInstance()
{
    return new test();
}

test::test(QObject *parent) : QObject(parent)
{

}

test *test::instance()
{
    return  Singleton<test>::instance(test::createInstance);
}
