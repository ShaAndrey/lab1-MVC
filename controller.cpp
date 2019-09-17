#include "controller.h"


void Controller::SetView(AbstractView* view) {
    view_ = view;
}

Controller::Controller(AbstractView* view) {
    SetView(view);
}

void Controller::AddPersonToFirstQueue(const QString& name) {
    first_queue_.Push(name);
    view_->AddPersonToFirstQueue(name);
}


void Controller::AddPersonToSecondQueue(const QString& name) {
    second_queue_.Push(name);
    view_->AddPersonToSecondQueue(name);
}

void Controller::ServePersonInFirstQueue() {
    if(!first_queue_.IsEmpty()) {
     view_->ServePersonInFirstQueue();
     first_queue_.Pop();
    }
}


void Controller::ServePersonInSecondQueue() {
    if(!second_queue_.IsEmpty()) {
    second_queue_.Pop();
    view_->ServePersonInSecondQueue();
    }
}

void Controller::CompareQueues() {
    view_->CompareQueues(first_queue_ == second_queue_);
}

Controller::~Controller() {}
