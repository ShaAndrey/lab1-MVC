#ifndef VIEW_H
#define VIEW_H


#include "abstractview.h"

class View : public AbstractView
{
public:
    virtual ~View() override;

    virtual void AddPersonToFirstQueue(const QString& name) override;
    virtual void AddPersonToSecondQueue(const QString& name) override;
    virtual void ServePersonInFirstQueue() override;
    virtual void ServePersonInSecondQueue() override;
    virtual void CompareQueues() override;
};

#endif // VIEW_H
