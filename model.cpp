#include "model.h"

Queue::Queue() : max_size_(4) {
  data_ = new std::string[max_size_];
}
Queue::Queue(int max_size) : max_size_(max_size) {
  data_ = new std::string[max_size_];
}
Queue::Queue(const Queue& other) = default;

Queue::Queue(Queue&&) = default;

Queue::~Queue() = default;

void Queue::Push(const std::string& value) {
  if (IsFull()) {
    Reorginize(max_size_ * 2);
  }
  if (!IsEmpty()) {
    tail_ = (tail_ + 1) % max_size_;
  }
  data_[tail_] = value;
  ++size_;

}
std::string Queue::Front(std::string default_value) const {
  if(!IsEmpty()) {
    return data_[head_];
  } else {
    return default_value;
  }
}
bool Queue::Pop() {
  if (IsEmpty()) {
    return false;
  }
  if(size_ < max_size_ / 4) {
    Reorginize(max_size_ / 2);
  }
  if(size_ != 1) {
    head_ = (head_ + 1) % max_size_;
  }
  --size_;
  return true;
}
int Queue::Size() const {
  return size_;
}
int Queue::MaxSize() const {
  return max_size_;
}
bool Queue::IsEmpty() const {
  return size_ == 0;
}
bool Queue::IsFull() const {
  return size_ == max_size_;
}

void Queue::Reorginize(int new_size) {
  auto b = new std::string[new_size];
  for (int i = 0; i < size_; ++i) {
    b[i] = data_[(head_ + i) % max_size_];
  }
  max_size_ = new_size;
  head_ = 0;
  tail_ = size_;
  delete [] data_;
  data_ = b;
}

bool operator==(const Queue& l, const Queue& r) {
  if (l.max_size_ != r.max_size_ || l.size_ != r.size_) {
    return false;
  }
  for (int i = 0; i < l.size_; ++i) {
    if (l.data_[(l.head_ + i) % l.max_size_] != r.data_[(i + r.head_) % r.max_size_]) {
      return false;
    }
  }
  return true;
}

bool operator!=(const Queue& l, const Queue& r) {
  return !(l == r);
}