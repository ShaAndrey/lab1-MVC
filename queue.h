#ifndef LAB1_MODEL_H
#define LAB1_MODEL_H

#include "iterator.h"
#include "iterable.h"
#include "peoplegroup.h"

template<typename T>
class Queue : public Iterable<T>, public PeopleGroup<T> {
 public:

  Queue();
  explicit Queue(int max_size);
  Queue(const Queue& other);
  Queue(Queue&&);

  ~Queue();

  void Push(const T& value = "");

  T Front() const;

  bool Pop();

  int Size() const;

  bool operator==(const Queue& other);

  bool operator!=(const Queue& other);

  bool IsEmpty() const;

  void CreateIterator();

  void AcceptVisitor(Visitor<T>& v) override;

 private:
  int head_ = 0;
  int tail_ = 0;
  int size_ = 0;
  int max_size_;

  void Reorginize(int new_size);

  int MaxSize() const;

  bool IsFull() const;

  T* data_;

 public:
  QueueIterator<T>* iterator;
};

template<typename T>
bool Queue<T>::operator==(const Queue& other) {
  if (max_size_ != other.max_size_ || size_ != other.size_) {
    return false;
  }
  for (int i = 0; i < size_; ++i) {
    if (data_[(head_ + i) % max_size_] != other.data_[(i + other.head_) % other.max_size_]) {
      return false;
    }
  }
  return true;
}

template<typename T>
bool Queue<T>::operator!=(const Queue& other) {
  return !(*this == other);
}

template<typename T>
Queue<T>::Queue() : max_size_(4), data_(new T[max_size_]),
                    iterator(new QueueIterator<T>(size_, data_)) {}

template<typename T>
Queue<T>::Queue(int max_size) : max_size_(max_size), data_(new T[max_size_]),
                                iterator(new QueueIterator<T>(size_, data_)) {}

template<typename T>
Queue<T>::Queue(const Queue& other) :
    head_(other.head_),
    tail_(other.tail_),
    size_(other.size_),
    max_size_(other.max_size_),
    data_(new T[max_size_]),
    iterator(new QueueIterator<T>(size_, data_)) {
  for (int i = 0; i < size_; ++i) {
    data_[(head_ + i) % max_size_] = other.data_[(head_ + i) % max_size_];
  }
}

template<typename T>
Queue<T>::Queue(Queue&&) = default;

template<typename T>
Queue<T>::~Queue() {
  delete[] data_;
}

template<typename T>
void Queue<T>::Push(const T& value) {
  if (IsFull()) {
    Reorginize(max_size_ * 2);
  }
  if (!IsEmpty()) {
    tail_ = (tail_ + 1) % max_size_;
  }
  data_[tail_] = value;
  ++size_;
  CreateIterator();
}

template<typename T>
T Queue<T>::Front() const {
  if (!IsEmpty()) {
    return data_[head_];
  } else {
    return 0;
  }
}

template<typename T>
bool Queue<T>::Pop() {
  if (IsEmpty()) {
    return false;
  }
  if (size_ < max_size_ / 4) {
    Reorginize(max_size_ / 2);
  }
  if (size_ != 1) {
    head_ = (head_ + 1) % max_size_;
  }
  --size_;
  CreateIterator();
  return true;
}

template<typename T>
int Queue<T>::Size() const {
  return size_;
}

template<typename T>
int Queue<T>::MaxSize() const {
  return max_size_;
}

template<typename T>
bool Queue<T>::IsEmpty() const {
  return size_ == 0;
}

template<typename T>
bool Queue<T>::IsFull() const {
  return size_ == max_size_;
}

template<typename T>
void Queue<T>::Reorginize(int new_size) {
  auto b = new T[new_size];
  for (int i = 0; i < size_; ++i) {
    b[i] = data_[(head_ + i) % max_size_];
  }
  max_size_ = new_size;
  head_ = 0;
  tail_ = size_;
  delete[] data_;
  data_ = b;
}

template<typename T>
void Queue<T>::CreateIterator() {
  iterator = new QueueIterator<T>(size_, data_);
}


template<typename T>
void Queue<T>::AcceptVisitor(Visitor<T>& v) {
  v.VisitQueue(this);
}


#endif //LAB1_MODEL_H
