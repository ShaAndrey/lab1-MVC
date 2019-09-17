#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>

#include "abstractview.h"
#include "memory"
#include "controller.h"

#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QLCDNumber>


class View : public QMainWindow, public AbstractView
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

    QGridLayout* window_layout_;

    QLabel* label_1_;
    QLabel* label_2_;

    QLineEdit* name_to_first_queue_;
    QLineEdit* name_to_second_queue_;

    QPushButton* serve_from_first_queue_;
    QPushButton* serve_from_second_queue_;

    QLCDNumber* quantity_in_first_queue_;
    QLCDNumber* quantity_in_second_queue_;

    QPushButton* add_to_first_queue_;
    QPushButton* add_to_second_queue_;

    QListWidget* queue_1_;
    QListWidget* queue_2_;
};

#endif // VIEW_H
