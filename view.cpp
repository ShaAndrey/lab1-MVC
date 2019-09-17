#include "view.h"


View::View() : controller_(std::make_shared<Controller>(this)),
               window_layout_(new QGridLayout()),
               label_1_(new QLabel("Касса 1")),
               label_2_(new QLabel("Касса 2")),
               name_to_first_queue_(new QLineEdit()),
               name_to_second_queue_(new QLineEdit()),
               serve_from_first_queue_(new QPushButton()),
               serve_from_second_queue_(new QPushButton()),
               quantity_in_first_queue_(new QLCDNumber()),
               quantity_in_second_queue_(new QLCDNumber()),
               add_to_first_queue_(new QPushButton()),
               add_to_second_queue_(new QPushButton()),
               queue_1_(new QListWidget()),
               queue_2_(new QListWidget()),
               compare_queues_(new QPushButton()),
               comparison_result_(new QLabel())
{

    auto items_size_policy =
        QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    label_1_->setSizePolicy(items_size_policy);
    label_2_->setSizePolicy(items_size_policy);

    window_layout_->addWidget(label_1_, 0, 0, Qt::AlignLeft);
    window_layout_->addWidget(label_1_, 0, 5, Qt::AlignLeft);

    auto widget = new QWidget();
    widget->setLayout(window_layout_);
    setCentralWidget(widget);


    auto add_to_first_queue_slot = [&]() {
        controller_->AddPersonToFirstQueue(name_to_first_queue_->text());
        name_to_first_queue_->setText("");
    };
    auto add_to_second_queue_slot = [&]() {
        controller_->AddPersonToSecondQueue(name_to_second_queue_->text());
        name_to_second_queue_->setText("");
    };

    connect(add_to_first_queue_, &QPushButton::clicked, add_to_first_queue_slot);
    connect(add_to_second_queue_, &QPushButton::clicked, add_to_second_queue_slot);
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
    if(queues_comparison_) {
        comparison_result_->setText(QString("Equal"));
    }
    else {
        comparison_result_->setText(QString("Not equal"));
    }
}

View::~View() {}
