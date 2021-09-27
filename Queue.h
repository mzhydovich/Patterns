#ifndef QUEUE_H
#define QUEUE_H

#include <algorithm>
#include <memory>
#include <iostream>

template <class Item>
class QueueIterator;

template <class Item>
class IteratorPtr;

template <class Item>
class Queue {
 public:
  Queue();
  Queue(int);
  Queue(const std::initializer_list<Item>&);
  Queue(const Queue<Item>&);
  Queue(Queue<Item>&&) noexcept;
  ~Queue();

  Queue& operator=(const Queue<Item>&);
  Queue& operator=(Queue<Item>&&) noexcept;

  template <class Item>
  friend std::ostream& operator<<(std::ostream&, const Queue<Item>&);
  template <class Item>
  friend std::istream& operator>>(std::istream&, Queue<Item>&);
  template <class Item>
  friend Queue<Item>& operator+=(Queue<Item>&, const Queue<Item>&);
  template <class Item>
  friend Queue<Item> operator+(const Queue<Item>&, const Queue<Item>&);
  bool operator==(const Queue<Item>&);
  bool operator!=(const Queue<Item>&);

  bool isEmpty() const;
  int Size() const;
  void Clear();
  Item Front();
  Item Back();
  void enQueue(Item);
  void deQueue();
  void Swap(Queue<Item>&);
  void addAll(int);

  QueueIterator<Item>* CreateIterator() const;

  friend class QueueIterator<Item>;
 private:
  Item* array_;
  int length_ = 1;
  int amount_of_elements_ = 0;
  int first_index_ = 0;
  int last_index_ = -1;
};

template <class Item>
Queue<Item>::Queue() : array_(new Item[1]) {}

template <class Item>
Queue<Item>::Queue(int size) : length_(size), array_(new Item[size]) {}

template <class Item>
Queue<Item>::Queue(const Queue<Item>& queue)
    : array_(new Item[queue.length_]),
      length_(queue.length_),
      amount_of_elements_(queue.amount_of_elements_),
      first_index_(queue.first_index_),
      last_index_(queue.last_index_) {
  std::uninitialized_copy(queue.array_, queue.array_ + queue.length_, array_);
  std::cout << "\nCopy\n";
}

template <class Item>
Queue<Item>::Queue(Queue&& queue) noexcept
    : array_(nullptr),
      length_(0),
      amount_of_elements_(0),
      first_index_(0),
      last_index_(-1) {
  Swap(queue);
  std::cout << "\nMove\n";
}

template <class Item>
Queue<Item>& Queue<Item>::operator=(const Queue<Item>& queue) {
  Queue<Item> q{queue};
  Swap(q);
  std::cout << "\nCopy\n";
  return *this;
}

template <class Item>
Queue<Item>& Queue<Item>::operator=(Queue<Item>&& queue) noexcept {
  Swap(queue);
  std::cout << "\nMove\n";
  return *this;
}

template <class Item>
Queue<Item>::Queue(const std::initializer_list<Item>& list)
    : Queue(list.size()) {
  for (const auto& el : list) {
    enQueue(el);
  }
  std::cout << "\nInitializerList\n";
}

template <class Item>
Queue<Item>::~Queue() {
  delete[] array_;
}

template <class Item>
void Queue<Item>::enQueue(Item new_element) {
  if (amount_of_elements_ == length_) {
    addAll(2 * length_);
  }
  last_index_ = (last_index_ + 1) % length_;
  array_[last_index_] = new_element;
  ++amount_of_elements_;
}

template <class Item>
void Queue<Item>::deQueue() {
  if (!isEmpty()) {
    if (amount_of_elements_ == length_ / 4) {
      addAll(length_ / 2);
    }
    first_index_ = (first_index_ + 1) % length_;
    --amount_of_elements_;
  }
}

template <class Item>
void Queue<Item>::addAll(int amount) {
  Item* tmp = new Item[amount]; 
  size_t q = 0;
  if (last_index_ >= first_index_) {
    for (size_t i = first_index_; i <= last_index_; ++i) {
      tmp[q] = array_[i];
      ++q;
    }
  } else if (!isEmpty()) {
    for (size_t i = first_index_; i < length_; i++) {
      tmp[q] = array_[i];
      ++q;
    }
    for (size_t i = 0; i <= last_index_; ++i) {
      tmp[q] = array_[i];
      ++q;
    }
  }
  length_ = amount;
  first_index_ = 0;
  last_index_ = amount_of_elements_ - 1;
  delete[] array_;
  array_ = tmp;
}

template <class Item>
bool Queue<Item>::isEmpty() const {
  return amount_of_elements_ == 0;
}

template <class Item>
int Queue<Item>::Size() const {
  return amount_of_elements_;
}

template <class Item>
Item Queue<Item>::Front() {
  if (!isEmpty()) {
    return array_[first_index_];
  }
}

template <class Item>
Item Queue<Item>::Back() {
  if (!isEmpty()) {
    return array_[last_index_];
  }
}

template <class Item>
void Queue<Item>::Clear() {
  while (amount_of_elements_ != 0) {
    deQueue();
  }
  first_index_ = 0;
  last_index_ = -1;
}

template <class Item>
std::ostream& operator<<(std::ostream& out, const Queue<Item>& queue) {
  if (queue.last_index_ >= queue.first_index_) {
    for (size_t i = queue.first_index_; i <= queue.last_index_; ++i) {
      out << queue.array_[i] << " ";
    }
  } else if (!queue.isEmpty()) {
    for (size_t i = queue.first_index_; i < queue.length_; ++i) {
      out << queue.array_[i] << " ";
    }
    for (size_t i = 0; i <= queue.last_index_; ++i) {
      out << queue.array_[i] << " ";
    }
  }

  out << '\n';
  return out;
}

template <class Item>
std::istream& operator>>(std::istream& in, Queue<Item>& queue) {
  size_t size;
  in >> size;
  for (size_t i = 0; i < size; ++i) {
    Item new_element;
    in >> new_element;
    queue.enQueue(new_element);
  }

  return in;
}

template <class Item>
Queue<Item>& operator+=(Queue<Item>& first, const Queue<Item>& second) {
  if (second.last_index_ >= second.first_index_) {
    for (size_t i = second.first_index_; i <= second.last_index_; ++i) {
      first.enQueue(second.array_[i]);
    }
  } else if (!second.isEmpty()) {
    for (size_t i = second.first_index_; i < second.length_; i++) {
      first.enQueue(second.array_[i]);
    }
    for (size_t i = 0; i <= second.last_index_; ++i) {
      first.enQueue(second.array_[i]);
    }
  }
  return first;
}

template <class Item>
QueueIterator<Item>* Queue<Item>::CreateIterator() const {
  return new QueueIterator<Item>(this);
}

template <class Item>
bool Queue<Item>::operator==(const Queue<Item>& second) {
  if (amount_of_elements_ != second.amount_of_elements_) {
    return false;
  }

  IteratorPtr<Item> it(CreateIterator());
  IteratorPtr<Item> it1(second.CreateIterator());
  for (it->First(), it1->First(); !it->IsDone(); it->Next(), it1->Next()) {
    if (it->CurrentItem() != it1->CurrentItem()) {
      return false;
    }
  }
  return true;
}

template <class Item>
bool Queue<Item>::operator!=(const Queue<Item>& second) {
  return !(this == second);
}

template <class Item>
Queue<Item> operator+(const Queue<Item>& first, const Queue<Item>& second) {
  Queue<Item> result = first;
  result += second;
  return result;
}

template <class Item>
void Queue<Item>::Swap(Queue<Item>& q) {
  std::swap(array_, q.array_);
  std::swap(length_, q.length_);
  std::swap(amount_of_elements_, q.amount_of_elements_);
  std::swap(first_index_, q.first_index_);
  std::swap(last_index_, q.last_index_);
}



#endif  // QUEUE_H
