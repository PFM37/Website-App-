#include <windows.h>
#include <shellapi.h>

#define ID_BUTTON 1
#define ID_LABEL 2

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_COMMAND:
            if (LOWORD(wParam) == ID_BUTTON) {
                // Open the website when button is clicked
                ShellExecute(NULL, "open", "https://pfmcodes.tiiny.site", NULL, NULL, SW_SHOWNORMAL);
            }
            return 0;
        case WM_CREATE:
            // Create label
            CreateWindowEx(0, "STATIC", "See My Website", WS_VISIBLE | WS_CHILD, 100, 50, 200, 30,
                           hwnd, (HMENU)ID_LABEL, NULL, NULL);
            // Create button
            CreateWindowEx(0, "BUTTON", "See Website", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 100, 100, 200, 30,
                           hwnd, (HMENU)ID_BUTTON, NULL, NULL);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int main() {
    // Initialize window class
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "MainWindowClass";

    if (!RegisterClass(&wc)) {
        return -1;
    }

    // Create window
    HWND hwnd = CreateWindowEx(0, wc.lpszClassName, "PFM.COM(APP)", WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT, CW_USEDEFAULT, 700, 400, NULL, NULL, wc.hInstance, NULL);

    if (hwnd == NULL) {
        return -1;
    }

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    // Main message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
