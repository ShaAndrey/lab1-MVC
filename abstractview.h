#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H

#include <QString>
#include <vector>

class AbstractView
{
public:
    virtual ~AbstractView() = default;

    virtual void AddPersonToFirstQueue(const QString& name) = 0;
    virtual void AddPersonToSecondQueue(const QString& name) = 0;
    virtual void ServePersonInFirstQueue() = 0;
    virtual void ServePersonInSecondQueue() = 0;
    virtual void CompareQueues(bool queues_comparison_) = 0;

    virtual void GoUpInFirstQueue() = 0;
    virtual void GoDownInFirstQueue() = 0;
    virtual void GoUpInSecondQueue() = 0;
    virtual void GoDownInSecondQueue() = 0;

    virtual void ChangeNameInFirstQueue(const QString& name) = 0;
    virtual void ChangeNameInSecondQueue(const QString& name) = 0;

    virtual void AddPersonToFirstCrowd(const QString& name) = 0;
    virtual void AddPersonToSecondCrowd(const QString& name) = 0;
    virtual void ServePersonInFirstCrowd(const std::vector<QString>& crowd) = 0;
    virtual void ServePersonInSecondCrowd(const std::vector<QString>& crowd) = 0;
};

#endif // ABSTRACTVIEW_H
