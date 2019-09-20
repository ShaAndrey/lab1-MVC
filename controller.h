#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "abstractcontroller.h"

class Controller : public AbstractController {
public:
    Controller(AbstractView* view);
    virtual ~Controller() override;

    void SetView(AbstractView* view) override;

    virtual void AddPersonToFirstQueue(const QString& name) override;
    virtual void AddPersonToSecondQueue(const QString& name) override;
    virtual void ServePersonInFirstQueue() override;
    virtual void ServePersonInSecondQueue() override;
    virtual void CompareQueues() override;

    virtual void GoUpInFirstQueue() override;
    virtual void GoDownInFirstQueue() override;
    virtual void GoUpInSecondQueue() override;
    virtual void GoDownInSecondQueue() override;


    virtual void ChangeNameInFirstQueue(const QString& name) override;
    virtual void ChangeNameInSecondQueue(const QString& name) override;

private:
    AbstractView* view_;
    Queue<QString> first_queue_;
    Queue<QString> second_queue_;
    bool queues_comparison_;
};
#endif // CONTROLLER_H
