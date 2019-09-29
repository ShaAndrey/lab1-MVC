#ifndef LAB1_PEOPLE_GROUP_H
#define LAB1_PEOPLE_GROUP_H

#include "visitor.h"

template <typename T>
class PeopleGroup {
public:
  virtual void AcceptVisitor(Visitor<T>& v) = 0;
};




#endif //LAB1_PEOPLE_GROUP_H
