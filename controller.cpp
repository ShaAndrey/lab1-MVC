#include "controller.h"


Controller::Controller(AbstractView* view) {
    SetView(view);
}

void Controller::CheckViewExistance() {
    if(view_ == nullptr) {
        throw std::runtime_error("View is not initialized");
    }
}

void Controller::AddPersonToFirstQueue(const QString& name) {
    first_queue_.Push(name);
    CheckViewExistance();
    view_->AddPersonToFirstQueue(name);
}


void Controller::AddPersonToSecondQueue(const QString& name) {
    second_queue_.Push(name);
    CheckViewExistance();
    view_->AddPersonToSecondQueue(name);
}

void Controller::ServePersonInFirstQueue() {
    first_queue_.Pop();
    CheckViewExistance();
    if(!first_queue_.IsEmpty()) {
     view_->ServePersonInFirstQueue();
    }
}


void Controller::ServePersonInSecondQueue() {
    second_queue_.Pop();
    CheckViewExistance();
    if(!second_queue_.IsEmpty()) {
    view_->ServePersonInSecondQueue();
    }
}

void Controller::CompareQueues() {
    CheckViewExistance();
    view_->CompareQueues(first_queue_ == second_queue_);
}

Controller::~Controller() {}
