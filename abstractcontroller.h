#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H

#include <memory>
#include <QString>

#include <queue.h>
#include "abstractview.h"

class AbstractController {
public:
    virtual ~AbstractController() = default;
    virtual void SetView(const std::shared_ptr<AbstractView> view) {
        view_ = view;
    }

    virtual void AddPersonToFirstQueue(const QString* name) = 0;
    virtual void AddPersonToSecondQueue(const QString* name) = 0;
    virtual void ServePersonInFirstQueue() = 0;
    virtual void ServePersonInSecondQueue() = 0;
    virtual void CompareQueues() = 0;

protected:
    std::shared_ptr<AbstractView> view_;
    Queue<QString> first_queue_;
    Queue<QString> second_queue_;
    bool queues_comparison_;
};

#endif // ABSTRACTCONTROLLER_H
