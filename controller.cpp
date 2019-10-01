#include "controller.h"

void Controller::SetView(AbstractView* view) {
    view_ = view;
}

Controller::Controller(AbstractView* view) {
    SetView(view);
}

void Controller::AddPersonToFirstQueue(const QString& name) {
    first_queue_.Push(name);
    first_queue_.CreateIterator(first_queue_iterator_);
    view_->AddPersonToFirstQueue(name);
}


void Controller::AddPersonToSecondQueue(const QString& name) {
    second_queue_.Push(name);
    second_queue_.CreateIterator(second_queue_iterator_);
    view_->AddPersonToSecondQueue(name);
}

void Controller::ServePersonInFirstQueue() {
    if(!first_queue_.IsEmpty()) {
        first_queue_.AcceptVisitor(cashier);
        first_queue_.CreateIterator(first_queue_iterator_);
        view_->ServePersonInFirstQueue();
    }
}


void Controller::ServePersonInSecondQueue() {
    if(!second_queue_.IsEmpty()) {
        second_queue_.AcceptVisitor(cashier);
        second_queue_.CreateIterator(second_queue_iterator_);
        view_->ServePersonInSecondQueue();
    }
}

void Controller::CompareQueues() {
    view_->CompareQueues(first_queue_ == second_queue_);
}


void Controller::GoUpInFirstQueue() {
    if(first_queue_iterator_->HasMorePrev()) {
        view_->GoUpInFirstQueue();
    }
    first_queue_iterator_->GetPrev();
}

void Controller::GoDownInFirstQueue() {
    if(first_queue_iterator_->HasMore()) {
        view_->GoDownInFirstQueue();
    }
    first_queue_iterator_->GetNext();
}

void Controller::GoUpInSecondQueue() {
    if(second_queue_iterator_->HasMorePrev()) {
        view_->GoUpInSecondQueue();
    }
    second_queue_iterator_->GetPrev();
}

void Controller::GoDownInSecondQueue() {
    if(second_queue_iterator_->HasMore()) {
        view_->GoDownInSecondQueue();
    }
    second_queue_iterator_->GetNext();
}

void Controller::ChangeNameInFirstQueue(const QString& name) {
    first_queue_iterator_->GetCurrent() = name;
    view_->ChangeNameInFirstQueue(name);
}

void Controller::ChangeNameInSecondQueue(const QString & name) {
    second_queue_iterator_->GetCurrent() = name;
    view_->ChangeNameInSecondQueue(name);
}

void Controller::ServePersonInFirstCrowd() {
    if(!first_crowd_.IsEmpty()) {
//        qDebug("ServePersonInFirstCrowd");
        first_crowd_.AcceptVisitor(cashier);
        view_->ServePersonInFirstCrowd(first_crowd_.CrowdAsVector());
    }
}
void Controller::ServePersonInSecondCrowd() {
    if(!second_crowd_.IsEmpty()) {
        second_crowd_.AcceptVisitor(cashier);
        view_->ServePersonInSecondCrowd(second_crowd_.CrowdAsVector());
    }
}

void Controller::AddPersonToFirstCrowd(const QString& name) {
    first_crowd_.Push(name);
    view_->AddPersonToFirstCrowd(name);
}

void Controller::AddPersonToSecondCrowd(const QString& name) {
    second_crowd_.Push(name);
    view_->AddPersonToSecondCrowd(name);
}

Controller::~Controller() {}
