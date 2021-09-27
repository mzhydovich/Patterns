#include <iostream>

#include "Queue.h"
#include "IteratorPtr.h"
#include "ElementInt.h"
#include "AverageVisitor.h"

int main() {
  
  Queue<int> q1{1, 2, 3, 4, 5};
  std::cout << "Queue1: " << q1;

  Queue<int> q2(q1);
  std::cout << "Queue1: " << q1;
  std::cout << "Queue2: " << q2;

  Queue<int> q3(std::move(q1));
  std::cout << "Queue1: " << q1;
  std::cout << "Queue2: " << q2;
  std::cout << "Queue3: " << q3;
  std::cout << "Queue2 == Queue3: " << (q2 == q3) << '\n';

  std::cout << "\nQueue2 + Queue3: " << q2 + q3;
  std::cout << "Queue2: " << q2;
  std::cout << "Queue3: " << q3;
  std::cout << "Queue2 == Queue3: " << (q2 == q3) << '\n';

  q2 += q3;
  std::cout << "\nQueue2 += Queue3:\n";
  std::cout << "Queue2: " << q2;
  std::cout << "Queue3: " << q3;
  std::cout << "Queue2 == Queue3: " << (q2 == q3) << '\n';

  q2.Swap(q3);
  std::cout << "\nSwap(Queue2, Queue3):\n";
  std::cout << "Queue2: " << q2;
  std::cout << "Queue3: " << q3;

  Queue<Element*> q4;
  for (size_t i = 1; i <= 10; ++i) {
    ElementInt* el = new ElementInt(i);
    q4.enQueue(el);
  }

  AverageVisitor* v = new AverageVisitor();
  IteratorPtr<Element*> it(q4.CreateIterator());
  std::cout << "\nQueue4: ";
  for (it->First(); !it->IsDone(); it->Next()) {
    std::cout << it->CurrentItem()->getValue() << ' ';
    it->CurrentItem()->Accept(*v);
  }
  std::cout << "\nAverage: " << v->getAverage();


  return 0;
}