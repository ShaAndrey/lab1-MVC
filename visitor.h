#ifndef VISITOR_H
#define VISITOR_H

//#include "queue.h"
//#include "crowd.h"

template <typename T>
class Queue;

template <typename T>
class Crowd;

template <typename T>
class Visitor {

 public:
  virtual void VisitQueue(Queue<T>* queue) = 0;
  virtual void VisitCrowd(Crowd<T>* crowd) = 0;
};


#endif // VISITOR_H
