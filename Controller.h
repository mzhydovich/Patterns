#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "resource.h"
#include "ListView.h"

class Controller {
 public:
  static INT_PTR CALLBACK Manipulate(HWND, UINT, WPARAM, LPARAM);
};


#endif  // CONTROLLER_H
