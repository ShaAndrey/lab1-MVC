#include "view.h"


View::View() : controller_(std::make_shared<Controller>(this)),
               label_1_(new QLabel("Queue 1")),
               label_2_(new QLabel("Queue 2"))
{

    auto items_size_policy =
        QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    label_1_->setSizePolicy(items_size_policy);
}

void AddPersonToFirstQueue(const QString& name) {

}
void AddPersonToSecondQueue(const QString& name) {

}
void ServePersonInFirstQueue() {

}
void ServePersonInSecondQueue() {

}
void CompareQueues() {

}

View::~View() {}
