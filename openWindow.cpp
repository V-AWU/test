#include <windows.h>

// Window procedure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (uMsg == WM_DESTROY) {
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int) {
    const char CLASS_NAME[] = "BorderlessWindowClass";

    // Register window class
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1); // white background

    RegisterClass(&wc);

    // Create borderless window
    HWND hwnd = CreateWindowEx(
        0,                     // Extended style
        CLASS_NAME,            // Class name
        "",                    // No title
        WS_POPUP,              // Borderless window
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600,              // Size
        NULL, NULL, hInstance, NULL
    );

    ShowWindow(hwnd, SW_SHOW);

    // Message loop
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
