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
               comparison_result_(new QLabel())
{
    setMinimumSize(1280, 720);

//    auto items_size_policy =
//        QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

//    label_1_->setSizePolicy(items_size_policy);
//    label_2_->setSizePolicy(items_size_policy);
//    serve_from_first_queue_->setSizePolicy(items_size_policy);
//    serve_from_second_queue_->setSizePolicy(items_size_policy);
//    name_to_first_queue_->setSizePolicy(items_size_policy);
//    name_to_second_queue_->setSizePolicy(items_size_policy);
//    add_to_first_queue_->setSizePolicy(items_size_policy);
//    add_to_second_queue_->setSizePolicy(items_size_policy);
//    quantity_in_first_queue_->setSizePolicy(items_size_policy);
//    quantity_in_second_queue_->setSizePolicy(items_size_policy);
//    queue_1_->setSizePolicy(items_size_policy);
//    queue_2_->setSizePolicy(items_size_policy);
//    compare_queues_->setSizePolicy(items_size_policy);
//    comparison_result_->setSizePolicy(items_size_policy);

    window_layout_->addWidget(label_1_, 0, 1, Qt::AlignCenter);
    window_layout_->addWidget(label_2_, 0, 4, Qt::AlignCenter);
    window_layout_->addWidget(serve_from_first_queue_, 1, 0, Qt::AlignCenter);
    window_layout_->addWidget(serve_from_second_queue_, 1, 5, Qt::AlignCenter);
    window_layout_->addWidget(name_to_first_queue_, 2, 0, Qt::AlignCenter);
    window_layout_->addWidget(name_to_second_queue_, 2, 5, Qt::AlignCenter);
    window_layout_->addWidget(add_to_first_queue_, 3, 0, Qt::AlignCenter);
    window_layout_->addWidget(add_to_second_queue_, 3, 5, Qt::AlignCenter);
    window_layout_->addWidget(quantity_in_first_queue_, 1, 1, Qt::AlignCenter);
    window_layout_->addWidget(quantity_in_second_queue_, 1, 4, Qt::AlignCenter);
    window_layout_->addWidget(queue_1_, 2, 1, Qt::AlignCenter);
    window_layout_->addWidget(queue_2_, 2, 4, Qt::AlignCenter);
    window_layout_->addWidget(compare_queues_, 0, 2, Qt::AlignCenter);
    window_layout_->addWidget(comparison_result_, 1, 2, Qt::AlignCenter);


    auto widget = new QWidget();
    widget->setLayout(window_layout_);
    setCentralWidget(widget);

    for (int i = 0; i < num_of_rows_; ++i) {
        window_layout_->setRowStretch(i, 1);
    }

    for (int i = 0; i < num_of_coulumns_; ++i) {
        window_layout_->setRowStretch(i, 1);
    }

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
        comparison_result_->setText(QString("Equal"));
    }
    else {
        comparison_result_->setText(QString("Not equal"));
    }
}

View::~View() {
    delete controller_;
}
