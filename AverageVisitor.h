#ifndef AVERAGEVISITOR_H
#define AVERAGEVISITOR_H

#include "Visitor.h"

class AverageVisitor : public Visitor {
 public:
  AverageVisitor() = default;

  void VisitConcreteElement(ElementInt*);

  float getAverage();

 private:
  int sum = 0;
  int amount_of_elements = 0;
};

void AverageVisitor::VisitConcreteElement(ElementInt* el) {
  sum += el->getValue();
  ++amount_of_elements;
}

float AverageVisitor::getAverage() { 
	return sum / amount_of_elements; 
}

#endif  // AVERAGEVISITOR_H
