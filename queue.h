#ifndef LAB1_MODEL_H
#define LAB1_MODEL_H

#include <string>
class Queue {
 public:
  Queue();
  explicit Queue(int max_size);
  Queue(const Queue& other);
  Queue(Queue&&);
  ~Queue();

  void Push(const std::string& value = "");

  std::string Front(std::string default_value = "") const;

  bool Pop();

  int Size() const;

 private:
  int head_ = 0;
  int tail_ = 0;
  int size_ = 0;
  int max_size_;

  std::string* data_;

  void Reorginize(int new_size);

  int MaxSize() const;

  bool IsEmpty() const;

  bool IsFull() const;

  friend bool operator==(const Queue& l, const Queue& r);
  friend bool operator!=(const Queue& l, const Queue& r);
};


#endif //LAB1_MODEL_H
