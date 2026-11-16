#include <windows.h>

#define ID_TIMER 1
#define ID_EDIT 2

HWND hEdit;
int colorIndex = 0;

COLORREF colors[] = {RGB(255,0,0), RGB(0,0,255), RGB(0,255,0), RGB(0,0,0), RGB(128,0,128)};

const wchar_t* fonts[] = {L"Arial", L"Times New Roman", L"Courier New", L"Tahoma", L"Verdana"};


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE:
            
            hEdit = CreateWindowEx(0, L"EDIT", L"C++ Timer Test",
                                   WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER | ES_READONLY,
                                   50, 50, 200, 40,
                                   hwnd, (HMENU)ID_EDIT, NULL, NULL);
            
            
            SetTimer(hwnd, ID_TIMER, 1000, NULL);
            break;

        case WM_TIMER: {
            
            colorIndex = (colorIndex + 1) % 5;

            
            HFONT hFont = CreateFont(24, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
                                     OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                                     DEFAULT_PITCH | FF_SWISS, fonts[colorIndex]);
            SendMessage(hEdit, WM_SETFONT, (WPARAM)hFont, TRUE);

            
            InvalidateRect(hEdit, NULL, TRUE);
            break;
        }

        case WM_CTLCOLORSTATIC: {
            if ((HWND)lParam == hEdit) {
                HDC hdcStatic = (HDC)wParam;
                SetTextColor(hdcStatic, colors[colorIndex]);
                SetBkColor(hdcStatic, GetSysColor(COLOR_WINDOW));
                return (INT_PTR)GetSysColorBrush(COLOR_WINDOW);
            }
            break;
        }

        case WM_DESTROY:
            KillTimer(hwnd, ID_TIMER); 
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"Lab1Class";
    
    WNDCLASS wc = { };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(0, CLASS_NAME, L"Лабораторна робота №1",
                               WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 320, 200,
                               NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) return 0;

    ShowWindow(hwnd, nCmdShow);

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}