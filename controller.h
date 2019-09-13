#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "abstractcontroller.h"

class Controller : public AbstractController {
    virtual ~Controller() = default;

    virtual void AddPersonToFirstQueue(const QString* name) override;
    virtual void AddPersonToSecondQueue(const QString* name) override;
    virtual void ServePersonInFirstQueue() override;
    virtual void ServePersonInSecondQueue() override;
    virtual void CompareQueues() override;

};

#endif // CONTROLLER_H
