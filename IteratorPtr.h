#ifndef ITERATORPTR_H
#define ITERATORPTR_H

#include "QueueIterator.h"

template <class Item>
class IteratorPtr {
 public:
  IteratorPtr(Iterator<Item>* i) : _i(i) {}
  ~IteratorPtr() { delete _i; }
  Iterator<Item>* operator->() { return _i; }
  Iterator<Item>& operator*() { return *_i; }

 private:
  Iterator<Item>* _i;

  IteratorPtr(const IteratorPtr&);
  IteratorPtr& operator=(const IteratorPtr&);
};

#endif  // ITERATORPTR_H
