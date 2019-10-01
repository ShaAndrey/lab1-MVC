#ifndef LAB1_ITERABLE_H
#define LAB1_ITERABLE_H

#include "iterator.h"

template <typename T>
class Iterable {
 public:
  virtual Iterator<T>* CreateIterator () = 0;
};

#endif //LAB1_ITERABLE_H
