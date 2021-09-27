#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <windows.h>
#include <sstream>

#include "Queue.h"

class ListView {
 public:
  ListView(HWND, unsigned int, Queue<int>*);

  void Update();

 private:
  HWND hdlg;
  unsigned int listbox_id;
  Queue<int>* queue;
};

#endif  // QUEUE_H
