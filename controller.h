#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "abstractcontroller.h"
#include "iterator.h"

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

    virtual void AddPersonToFirstCrowd(const QString& name) override;
    virtual void AddPersonToSecondCrowd(const QString& name) override;

    virtual void ServePersonInFirstCrowd() override;
    virtual void ServePersonInSecondCrowd() override;

private:
    AbstractView* view_;
    Queue<QString> first_queue_;
    Queue<QString> second_queue_;
    Crowd<QString> first_crowd_;
    Crowd<QString> second_crowd_;
    bool queues_comparison_;
    Cashier<QString> cashier;
    QueueIterator<QString>* first_queue_iterator_;
    QueueIterator<QString>* second_queue_iterator_;
};
#endif // CONTROLLER_H
