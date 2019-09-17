#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H

#include <memory>
#include <QString>

#include <queue.h>
#include "abstractview.h"

class AbstractController {
public:
    virtual ~AbstractController() = default;
    virtual void SetView(AbstractView* view) = 0;

    virtual void AddPersonToFirstQueue(const QString& name) = 0;
    virtual void AddPersonToSecondQueue(const QString& name) = 0;
    virtual void ServePersonInFirstQueue() = 0;
    virtual void ServePersonInSecondQueue() = 0;
    virtual void CompareQueues() = 0;

};

#endif // ABSTRACTCONTROLLER_H
