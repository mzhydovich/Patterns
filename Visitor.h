#ifndef VISITOR_H
#define VISITOR_H

#include <iostream>

class ElementInt;

class Visitor {
 public:
  Visitor() = default;

  virtual void VisitConcreteElement(ElementInt*) = 0;
};

#endif  // VISITOR_H
