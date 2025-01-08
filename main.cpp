#include <windows.h>
#include <shellapi.h>

#define ID_BUTTON 1
#define ID_LABEL 2

class AppWindow {
public:
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        switch (uMsg) {
            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;
            case WM_COMMAND:
                if (LOWORD(wParam) == ID_BUTTON) {
                    // Use ShellExecuteA for ANSI build
                    ShellExecuteA(NULL, "open", "https://www.pfm.com", NULL, NULL, SW_SHOWNORMAL);
                }
                return 0;
            case WM_CREATE:
                // Use CreateWindowExA for ANSI build
                CreateWindowExA(0, "STATIC", "See My Website", WS_VISIBLE | WS_CHILD, 100, 50, 200, 30,
                               hwnd, (HMENU)ID_LABEL, NULL, NULL);
                CreateWindowExA(0, "BUTTON", "See Website", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 100, 100, 200, 30,
                               hwnd, (HMENU)ID_BUTTON, NULL, NULL);
                return 0;
        }
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    int run() {
        // Initialize window class
        WNDCLASS wc = {0};
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = GetModuleHandle(NULL);
        wc.lpszClassName = "MainWindowClass";  // Use narrow character string

        if (!RegisterClassA(&wc)) {
            return -1;
        }

        // Create window using CreateWindowExA for ANSI build
        HWND hwnd = CreateWindowExA(0, wc.lpszClassName, "PFM.COM(APP)", WS_OVERLAPPEDWINDOW,
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
};

int main() {
    AppWindow app;
    return app.run();
}
