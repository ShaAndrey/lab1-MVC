#ifndef ITERATOR_H
#define ITERATOR_H

#include <iterator>

template<typename T>
class Iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
 public:
  virtual bool HasMore() = 0;
  virtual bool HasMorePrev() = 0;
  virtual T GetNext() = 0;
  virtual T GetPrev() = 0;
  virtual T& GetCurrent() = 0;
};

template<typename T>
class QueueIterator : public Iterator<T> {
 public:
  QueueIterator(int size, T* data);

  ~QueueIterator();

  bool HasMore() override;
  bool HasMorePrev() override;
  T GetNext() override;
  T GetPrev() override;
  T& GetCurrent() override;

 private:
  uint64_t position_ = 0;
  int size_;
  T* data_;
};



template<typename T>
QueueIterator<T>::QueueIterator(int size, T* data) : size_(size),
                                                     data_(data) {}


template<typename T>
bool QueueIterator<T>::HasMore() {
  return position_ < size_ - 1;
}

template<typename T>
bool QueueIterator<T>::HasMorePrev() {
  return position_ > 0;
}

template<typename T>
T QueueIterator<T>::GetNext() {
  if(HasMore()) {
    ++position_;
  }
  return data_[position_];
}

template<typename T>
T QueueIterator<T>::GetPrev() {
    if(HasMorePrev()) {
      --position_;
    }
    return data_[position_];
}

template<typename T>
T& QueueIterator<T>::GetCurrent() {
    return data_[position_];
}

template<typename T>
QueueIterator<T>::~QueueIterator() {
  delete [] data_;
}


#endif // ITERATOR_H
