#include "view.h"


View::View() : controller_(std::make_shared<Controller>(this)),
               window_layout_(new QGridLayout()),
               label_1_(new QLabel("Queue 1")),
               label_2_(new QLabel("Queue 2"))
{

    auto items_size_policy =
        QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    label_1_->setSizePolicy(items_size_policy);

    window_layout_->addWidget(label_1_, 0, 0, Qt::AlignLeft);
}

void View::AddPersonToFirstQueue(const QString& name) {

}
void View::AddPersonToSecondQueue(const QString& name) {

}
void View::ServePersonInFirstQueue() {

}
void View::ServePersonInSecondQueue() {

}
void View::CompareQueues(bool queues_comparison_) {

}

View::~View() {}
