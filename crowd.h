#ifndef LAB1_CROWD_H
#define LAB1_CROWD_H

#include "peoplegroup.h"
#include <random>
#include "visitor.h"

template <typename T>
class PeopleGroup;

template <typename T>
class Visitor;

template <typename T>
class Crowd : public PeopleGroup<T> {
 private:
  std::vector<T> crowd;
 public:
  Crowd();
  void Push(T);
  void Erase(int);
  int RandomCustomerPosition() const;
  void AcceptVisitor(Visitor<T>& v) override;
  bool IsEmpty() const;
  const std::vector<T>& CrowdAsVector() const;
};

template<typename T>
Crowd<T>::Crowd() {}

template<typename T>
void Crowd<T>::Push(T el) {
  crowd.push_back(el);
}

template<typename T>
void Crowd<T>::Erase(int customer_pos) {
    if (customer_pos < crowd.size()) {
//        crowd.erase(crowd.begin() + customer_pos);
        std::swap(crowd[customer_pos], crowd[crowd.size() - 1]);
        crowd.pop_back();
    }
}
template<typename T>
int Crowd<T>::RandomCustomerPosition() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, crowd.size() - 1);
    return dis(gen);
}

template<typename T>
void Crowd<T>::AcceptVisitor(Visitor<T>& v) {
  v.VisitCrowd(this);
}

template <typename T>
bool Crowd<T>::IsEmpty() const {
    return !crowd.size();
}


template <typename T>
const std::vector<T>& Crowd<T>::CrowdAsVector() const {
    return crowd;
}


#endif //LAB1_CROWD_H
