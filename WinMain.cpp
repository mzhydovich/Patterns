#include "Controller.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine,
                      _In_ int nCmdShow) {
  DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, Controller::Manipulate);
  return 0;
}
