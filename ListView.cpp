#include "ListView.h"

ListView::ListView(HWND hDlg, unsigned int id, Queue<int>* q) : hdlg(hDlg), listbox_id(id), queue(q) {}

void ListView::Update() {
  SendDlgItemMessage(hdlg, listbox_id, LB_RESETCONTENT, 0, 0);
  std::stringstream ss;
  ss << *queue;
  std::string el;
  while (ss >> el) {
    SendDlgItemMessage(hdlg, listbox_id, LB_ADDSTRING, 0, (LPARAM)el.c_str());
  }
}
