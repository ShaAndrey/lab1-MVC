#include "view.h"


View::View() : controller_(new Controller(this)),
               window_layout_(new QGridLayout()),
               label_1_(new QLabel("Касса 1")),
               label_2_(new QLabel("Касса 2")),
               name_to_first_queue_(new QLineEdit()),
               name_to_second_queue_(new QLineEdit()),
               serve_from_first_queue_(new QPushButton("Обслужить из очереди")),
               serve_from_second_queue_(new QPushButton("Обслужить из очереди")),
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
               change_name_2_queue_(new QPushButton("Поменяться")),
               crowd_1_(new QListWidget()),
               crowd_2_(new QListWidget()),
               add_to_crowd_1_(new QPushButton("В толпу")),
               add_to_crowd_2_(new QPushButton("В толпу")),
               serve_from_crowd_1_(new QPushButton("Обслужить из толпы")),
               serve_from_crowd_2_(new QPushButton("Обслужить из толпы"))
{
    setFixedSize(1000, 500);

    window_layout_->addWidget(label_1_, 0, 2, Qt::AlignCenter);
    window_layout_->addWidget(label_2_, 0, num_of_coulumns_ - 3,
                              Qt::AlignCenter);
    window_layout_->addWidget(serve_from_first_queue_, 1, 1);
    window_layout_->addWidget(serve_from_second_queue_, 1,
                              num_of_coulumns_ - 2);
    window_layout_->addWidget(name_to_first_queue_, 2, 0, 1, 2);
    window_layout_->addWidget(name_to_second_queue_, 2, num_of_coulumns_ - 2, 1, 2);
    window_layout_->addWidget(add_to_first_queue_, 3, 1);
    window_layout_->addWidget(add_to_second_queue_, 3, num_of_coulumns_ - 2);
    window_layout_->addWidget(quantity_in_first_queue_, 1, 2);
    window_layout_->addWidget(quantity_in_second_queue_, 1,
                              num_of_coulumns_ - 3);
    window_layout_->addWidget(queue_1_, 2, 2, 4, 1);
    window_layout_->addWidget(queue_2_, 2, num_of_coulumns_ - 3, 4, 1);
    window_layout_->addWidget(compare_queues_, 0, 3, 1, 2);
    window_layout_->addWidget(comparison_result_, 1, 3, 1, 2, Qt::AlignCenter);

    window_layout_->addWidget(new_name_1_queue_, 4, 0, Qt::AlignCenter);
    window_layout_->addWidget(new_name_2_queue_, 4, num_of_coulumns_ - 1,
                              Qt::AlignCenter);
    window_layout_->addWidget(up_1_queue_, 4, 1);
    window_layout_->addWidget(up_2_queue_, 4, num_of_coulumns_ - 2);
    window_layout_->addWidget(down_1_queue_, 5, 1);
    window_layout_->addWidget(down_2_queue_, 5, num_of_coulumns_ - 2);
    window_layout_->addWidget(change_name_1_queue_, 5, 0);
    window_layout_->addWidget(change_name_2_queue_, 5, num_of_coulumns_ - 1);

    window_layout_->addWidget(crowd_1_, 2, 3, 4, 1);
    window_layout_->addWidget(crowd_2_, 2, num_of_coulumns_ - 4, 4, 1);

    window_layout_->addWidget(add_to_crowd_1_, 3, 0);
    window_layout_->addWidget(add_to_crowd_2_, 3, num_of_coulumns_ - 1);
    window_layout_->addWidget(serve_from_crowd_1_, 1, 0);
    window_layout_->addWidget(serve_from_crowd_2_, 1,
                              num_of_coulumns_ - 1);



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

    connect(up_1_queue_, &QPushButton::clicked, [&]() {
        controller_->GoUpInFirstQueue();
    });

    connect(down_1_queue_, &QPushButton::clicked, [&]() {
        controller_->GoDownInFirstQueue();
    });

    connect(up_2_queue_, &QPushButton::clicked, [&]() {
        controller_->GoUpInSecondQueue();
    });

    connect(down_2_queue_, &QPushButton::clicked, [&]() {
        controller_->GoDownInSecondQueue();
    });

    connect(change_name_1_queue_, &QPushButton::clicked, [&]() {
        controller_->ChangeNameInFirstQueue(new_name_1_queue_->text());
    });

    connect(change_name_2_queue_, &QPushButton::clicked, [&]() {
        controller_->ChangeNameInSecondQueue(new_name_2_queue_->text());
    });

    connect(add_to_crowd_1_, &QPushButton::clicked, [&]() {
        controller_->AddPersonToFirstCrowd(name_to_first_queue_->text());
        name_to_first_queue_->setText("");
    });

    connect(add_to_crowd_2_, &QPushButton::clicked, [&]() {
        controller_->AddPersonToSecondCrowd(name_to_second_queue_->text());
        name_to_second_queue_->setText("");
    });
    connect(serve_from_crowd_1_, &QPushButton::clicked, [&]() {
        controller_->ServePersonInFirstCrowd();
    });
    connect(serve_from_crowd_2_, &QPushButton::clicked, [&]() {
        controller_->ServePersonInSecondCrowd();
    });
}

void View::AddPersonToFirstQueue(const QString& name) {
    queue_1_->addItem(name);
    queue_1_->setCurrentRow(0);
    quantity_in_first_queue_->display(queue_1_->count());
}
void View::AddPersonToSecondQueue(const QString& name) {
    queue_2_->setCurrentRow(0);
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

void View::GoUpInFirstQueue() {
    queue_1_->setCurrentRow(queue_1_->currentRow() - 1);
}

void View::GoDownInFirstQueue() {
    queue_1_->setCurrentRow(queue_1_->currentRow() + 1);
}

void View::GoUpInSecondQueue() {
    queue_2_->setCurrentRow(queue_2_->currentRow() - 1);
}

void View::GoDownInSecondQueue() {
    queue_2_->setCurrentRow(queue_2_->currentRow() + 1);
}

void View::ChangeNameInFirstQueue(const QString &name) {
    queue_1_->currentItem()->setData(0, name);
}

void View::ChangeNameInSecondQueue(const QString &name) {
    queue_2_->currentItem()->setData(0, name);
}

void View::ServePersonInFirstCrowd(const std::vector<QString>& crowd) {
    crowd_1_->clear();
    for (size_t i = 0; i < crowd.size(); ++i) {
    crowd_1_->addItem(crowd[i]);
    }
}


void View::ServePersonInSecondCrowd(const std::vector<QString>& crowd) {
    crowd_2_->clear();
    for (size_t i = 0; i < crowd.size(); ++i) {
    crowd_2_->addItem(crowd[i]);
    }
}


void View::AddPersonToFirstCrowd(const QString& name) {
    crowd_1_->addItem(name);
    crowd_1_->setCurrentRow(0);
}

void View::AddPersonToSecondCrowd(const QString& name) {
    crowd_2_->addItem(name);
    crowd_2_->setCurrentRow(0);
}

View::~View() {
    delete controller_;
}
