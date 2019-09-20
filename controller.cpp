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


void Controller::GoUpInFirstQueue() {
    if(first_queue_.iterator->HasMorePrev()) {
        view_->GoUpInFirstQueue();
    }
    first_queue_.iterator->GetPrev();
}

void Controller::GoDownInFirstQueue() {
    if(first_queue_.iterator->HasMore()) {
        view_->GoDownInFirstQueue();
    }
    first_queue_.iterator->GetNext();
}

void Controller::GoUpInSecondQueue() {
    if(second_queue_.iterator->HasMorePrev()) {
        view_->GoUpInSecondQueue();
    }
    second_queue_.iterator->GetPrev();
}

void Controller::GoDownInSecondQueue() {
    if(second_queue_.iterator->HasMore()) {
        view_->GoDownInSecondQueue();
    }
    second_queue_.iterator->GetNext();
}

void Controller::ChangeNameInFirstQueue(const QString& name) {
    first_queue_.iterator->GetCurrent() = name;
    view_->ChangeNameInFirstQueue(name);
}

void Controller::ChangeNameInSecondQueue(const QString & name) {
    second_queue_.iterator->GetCurrent() = name;
    view_->ChangeNameInSecondQueue(name);
}


Controller::~Controller() {}
