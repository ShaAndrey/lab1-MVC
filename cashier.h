#ifndef CASHIER_H
#define CASHIER_H

#include "visitor.h"

template <typename T>
class Cashier : public Visitor<T> {
public:
  void VisitQueue(Queue<T>* queue) override;
  void VisitCrowd(Crowd<T>* crowd) override;
};

template <typename T>
void Cashier<T>::VisitQueue(Queue<T>* queue) {
  queue->Pop();
}

template <typename T>
void Cashier<T>::VisitCrowd(Crowd<T>* crowd) {
  int random_customer = crowd->RandomCustomerPosition();
  crowd->Erase(random_customer);
}

#endif // CASHIER_H
