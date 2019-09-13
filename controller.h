#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "abstractcontroller.h"

class Controller : public AbstractController {
    virtual ~Controller() override;

    virtual void AddPersonToFirstQueue(const QString& name) override;
    virtual void AddPersonToSecondQueue(const QString& name) override;
    virtual void ServePersonInFirstQueue() override;
    virtual void ServePersonInSecondQueue() override;
    virtual void CompareQueues() override;
    void CheckViewExistance();

};
#endif // CONTROLLER_H
