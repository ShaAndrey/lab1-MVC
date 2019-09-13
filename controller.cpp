#include "controller.h"



void Controller::AddPersonToFirstQueue(const QString& name) {
    first_queue_.Push(name);
    // view.
}


void Controller::AddPersonToSecondQueue(const QString& name) {
    second_queue_.Push(name);
    // view.
}

void Controller::ServePersonInFirstQueue() {
    first_queue_.Pop();
    // view.
}

void Controller::ServePersonInSecondQueue() {
    second_queue_.Pop();
    // view.
}

void Controller::CompareQueues() {

}
