#include "Controller.h"

INT_PTR CALLBACK Controller::Manipulate(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
  
  static Queue<int> model;
  static ListView listview(hDlg, IDC_LIST1, &model);

  UNREFERENCED_PARAMETER(lParam);

  switch (message) {
    case WM_INITDIALOG:
      return (INT_PTR)TRUE;

    case WM_COMMAND:
      if (LOWORD(wParam) == IDC_BUTTON_PUSH1) {
        int value = GetDlgItemInt(hDlg, IDC_EDIT1, NULL, TRUE);
        model.enQueue(value);
      } else if (LOWORD(wParam) == IDC_BUTTON_POP1) {
        model.deQueue();
      } else if (LOWORD(wParam) == IDC_BUTTON_CLEAR1) {
        model.Clear();
      }
      listview.Update();

      if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
        EndDialog(hDlg, LOWORD(wParam));
        return (INT_PTR)TRUE;
      }
      break;
  }

  return (INT_PTR)FALSE;
}
