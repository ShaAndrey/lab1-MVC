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
    queue_1_->addItem(name);
    quantity_in_first_queue_->display(queue_1_->count());
}
void View::AddPersonToSecondQueue(const QString& name) {
    queue_2_->addItem(name);
    quantity_in_second_queue_->display(queue_2_->count());
}
void View::ServePersonInFirstQueue() {
    queue_1_->takeItem(0);
    quantity_in_first_queue_->display(queue_1_->count());
}
void View::ServePersonInSecondQueue() {
    queue_2_->takeItem(0);
    quantity_in_second_queue_->display(queue_2_->count());
}
void View::CompareQueues(bool queues_comparison_) {

}

View::~View() {}
