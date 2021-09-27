#ifndef QUEUEITERATOR_H
#define QUEUEITERATOR_H

#include "Iterator.h"
#include "Queue.h"

template <class Item>
class QueueIterator : public Iterator<Item> {
 public:
  QueueIterator(const Queue<Item>*);
  virtual void First();
  virtual void Next();
  virtual bool IsDone() const;
  virtual Item CurrentItem() const;

 private:
  const Queue<Item>* queue_;
  int current_ = 0;
  int amount_of_queue_elements_ = 0;
};

template <class Item>
QueueIterator<Item>::QueueIterator(const Queue<Item>* aQueue) : queue_(aQueue) {}

template <class Item>
void QueueIterator<Item>::First() {
  current_ = queue_->first_index_;
  ++amount_of_queue_elements_;
}

template <class Item>
void QueueIterator<Item>::Next() {
  current_ = (current_ + 1) % queue_->length_;
  ++amount_of_queue_elements_;
}

template <class Item>
bool QueueIterator<Item>::IsDone() const {
  return amount_of_queue_elements_ == queue_->amount_of_elements_ + 1;
}

template <class Item>
Item QueueIterator<Item>::CurrentItem() const {
  try {
    if (IsDone()) {
      throw std::exception();
    }
    return queue_->array_[current_];
  } catch (const std::exception& e) {
    std::cout << "Iterator out of range";
  }
}

#endif  // QUEUEITERATOR_H
