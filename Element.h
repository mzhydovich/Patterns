#ifndef ELEMENT_H
#define ELEMENT_H

#include"Visitor.h"

class Element {
 public:
  Element() = default;

  virtual void Accept(Visitor&) = 0;
  virtual int getValue() = 0;
};

#endif  // ELEMENT_H
