#ifndef LAB1_ITERABLE_H
#define LAB1_ITERABLE_H

#include "iterator.h"

template <typename T>
class Iterable {
 public:
  virtual void CreateIterator (Iterator<T>* iterator) = 0;
};

#endif //LAB1_ITERABLE_H
