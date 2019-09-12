#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H

#include <QString>

class AbstractView
{
public:
    virtual ~AbstractView() = default;

    virtual void AddPersonToFirstQueue(const QString* name) = 0;
    virtual void AddPersonToSecondQueue(const QString* name) = 0;
    virtual void ServePersonInFirstQueue() = 0;
    virtual void ServePersonInSecondQueue() = 0;
    virtual void CompareQueues() = 0;

};

#endif // ABSTRACTVIEW_H
