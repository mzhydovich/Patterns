#ifndef ELEMENTINT_H
#define ELEMENTINT_H

#include "Element.h"

class ElementInt : public Element {
 public:
  ElementInt() = default;
  ElementInt(int);

  void Accept(Visitor&);

  int getValue();

  private:
	  int value_;
};

ElementInt::ElementInt(int value) : value_(value) {}

void ElementInt::Accept(Visitor& v) { 
	v.VisitConcreteElement(this); 
}

int ElementInt::getValue() { 
	return value_; 
}

#endif  // ELEMENTINT_H
