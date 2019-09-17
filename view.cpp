#include "view.h"


View::View() : controller_(new Controller(this)),
               window_layout_(new QGridLayout()),
               label_1_(new QLabel("Касса 1")),
               label_2_(new QLabel("Касса 2")),
               name_to_first_queue_(new QLineEdit()),
               name_to_second_queue_(new QLineEdit()),
               serve_from_first_queue_(new QPushButton("Обслужить")),
               serve_from_second_queue_(new QPushButton("Обслужить")),
               quantity_in_first_queue_(new QLCDNumber(2)),
               quantity_in_second_queue_(new QLCDNumber(2)),
               add_to_first_queue_(new QPushButton("В очередь")),
               add_to_second_queue_(new QPushButton("В очередь")),
               queue_1_(new QListWidget()),
               queue_2_(new QListWidget()),
               compare_queues_(new QPushButton("Сравнить очереди")),
               comparison_result_(new QLabel()),
               up_1_queue_(new QPushButton("Вверх")),
               up_2_queue_(new QPushButton("Вверх")),
               down_1_queue_(new QPushButton("Вниз")),
               down_2_queue_(new QPushButton("Вниз")),
               new_name_1_queue_(new QLineEdit()),
               new_name_2_queue_(new QLineEdit()),
               change_name_1_queue_(new QPushButton("Поменяться")),
               change_name_2_queue_(new QPushButton("Поменяться"))
{
    setFixedSize(700, 400);

    window_layout_->addWidget(label_1_, 0, 2, Qt::AlignCenter);
    window_layout_->addWidget(label_2_, 0, num_of_coulumns_ - 3, Qt::AlignCenter);
    window_layout_->addWidget(serve_from_first_queue_, 1, 1);
    window_layout_->addWidget(serve_from_second_queue_, 1, num_of_coulumns_ - 2);
    window_layout_->addWidget(name_to_first_queue_, 2, 1);
    window_layout_->addWidget(name_to_second_queue_, 2, num_of_coulumns_ - 2);
    window_layout_->addWidget(add_to_first_queue_, 3, 1);
    window_layout_->addWidget(add_to_second_queue_, 3, num_of_coulumns_ - 2);
    window_layout_->addWidget(quantity_in_first_queue_, 1, 2);
    window_layout_->addWidget(quantity_in_second_queue_, 1, num_of_coulumns_ - 3);
    window_layout_->addWidget(queue_1_, 2, 2, 4, 1);
    window_layout_->addWidget(queue_2_, 2, num_of_coulumns_ - 3, 4, 1);
    window_layout_->addWidget(compare_queues_, 0, 3, 1, 2);
    window_layout_->addWidget(comparison_result_, 1, 3, 1, 2);

    window_layout_->addWidget(new_name_1_queue_, 4, 0, Qt::AlignCenter);
    window_layout_->addWidget(new_name_2_queue_, 4, num_of_coulumns_ - 1, Qt::AlignCenter);
    window_layout_->addWidget(up_1_queue_, 4, 1);
    window_layout_->addWidget(up_2_queue_, 4, num_of_coulumns_ - 2);
    window_layout_->addWidget(down_1_queue_, 5, 1);
    window_layout_->addWidget(down_2_queue_, 5, num_of_coulumns_ - 2);
    window_layout_->addWidget(change_name_1_queue_, 5, 0);
    window_layout_->addWidget(change_name_2_queue_, 5, num_of_coulumns_ - 1);

    auto widget = new QWidget();
    widget->setLayout(window_layout_);
    setCentralWidget(widget);

    connect(add_to_first_queue_, &QPushButton::clicked, [&]() {
        controller_->AddPersonToFirstQueue(name_to_first_queue_->text());
        name_to_first_queue_->setText("");
    });

    connect(add_to_second_queue_, &QPushButton::clicked, [&]() {
        controller_->AddPersonToSecondQueue(name_to_second_queue_->text());
        name_to_second_queue_->setText("");
    });
    connect(serve_from_first_queue_, &QPushButton::clicked, [&]() {
        controller_->ServePersonInFirstQueue();
    });
    connect(serve_from_second_queue_, &QPushButton::clicked, [&]() {
        controller_->ServePersonInSecondQueue();
    });
    connect(compare_queues_, &QPushButton::clicked, [&](){
        controller_->CompareQueues();
    });
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
        comparison_result_->setText(QString("Равны"));
    }
    else {
        comparison_result_->setText(QString("Не равны"));
    }
}

View::~View() {
    delete controller_;
}
