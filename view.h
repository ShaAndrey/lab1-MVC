#ifndef VIEW_H
#define VIEW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>

#include "abstractview.h"
#include "memory"
#include "controller.h"

class View : public AbstractView
{
public:
    View();
    virtual ~View() override;

    virtual void AddPersonToFirstQueue(const QString& name) override;
    virtual void AddPersonToSecondQueue(const QString& name) override;
    virtual void ServePersonInFirstQueue() override;
    virtual void ServePersonInSecondQueue() override;
    virtual void CompareQueues(bool queues_comparison_) override;

private:
    std::shared_ptr<Controller> controller_;
//    Controller* controller_;

    QLabel* label_1_;
    QLabel* label_2_;



};

#endif // VIEW_H
