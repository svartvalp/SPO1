#include <stdio.h>
#include <windows.h>
#include <string.h>

LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);
char szWinName[] = "MyWin";
char szWinName2[] = "SecondWin";
char szWinName3[] = "ThirdWin";
char str[255] = "";


int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode) {
    HWND  hwnd;
    MSG msg;
    WNDCLASSEX wcl, wcl2, wcl3;

    wcl.hInstance = hThisInst;
    wcl.lpszClassName = szWinName;
    wcl.lpfnWndProc = WindowFunc;
    wcl.style = 0;
    wcl.cbSize = sizeof(WNDCLASSEX);

    wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcl.hIconSm = LoadIcon(NULL, IDI_WINLOGO);

    wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcl.lpszMenuName = NULL;
    wcl.cbClsExtra = 0;
    wcl.cbWndExtra = 0;
    wcl.hbrBackground = CreateSolidBrush(RGB(125,32,125));

    if (!RegisterClassEx(&wcl)) return 0;



    hwnd = CreateWindow(szWinName,
                        "API application",
                        WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        600,
                        600,
                        HWND_DESKTOP,
                        NULL,
                        hThisInst,
                        NULL
    );

    ShowWindow(hwnd, nWinMode);
    UpdateWindow(hwnd);


    HWND childWind;



    wcl2.style = 0;
    wcl2.lpfnWndProc = WindowFunc;
    wcl2.cbClsExtra = 0;
    wcl2.cbWndExtra = 0;
    wcl2.cbSize = sizeof(WNDCLASSEX);
    wcl2.hInstance = hThisInst;
    wcl2.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcl2.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
    wcl2.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcl2.hbrBackground = CreateSolidBrush(RGB(240,255,91));
    wcl2.lpszClassName = szWinName2;
    wcl2.lpszMenuName = NULL;

    if (!RegisterClassEx (&wcl2)) {
        MessageBox(NULL, "Shit happens", szWinName2, MB_ICONERROR);
        return 0;
    }

    childWind = CreateWindow(szWinName2,
                             "API",
                             WS_CHILDWINDOW,
                             150,
                             150,
                             300,
                             300,
                             hwnd,
                             NULL,
                             hThisInst,
                             NULL);

    ShowWindow(childWind, nWinMode);
    UpdateWindow(childWind);



    HWND thirdWind;

    wcl3.style = 0;
    wcl3.lpfnWndProc = WindowFunc;
    wcl3.cbClsExtra = 0;
    wcl3.cbWndExtra = 0;
    wcl3.cbSize = sizeof(WNDCLASSEX);
    wcl3.hInstance = hThisInst;
    wcl3.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcl3.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
    wcl3.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcl3.hbrBackground = CreateSolidBrush(RGB(208,208,208));
    wcl3.lpszClassName = szWinName3;
    wcl3.lpszMenuName = NULL;


    if (!RegisterClassEx (&wcl3)) {
        MessageBox(NULL, "Shit happens", szWinName3, MB_ICONERROR);
        return 0;
    }

    thirdWind = CreateWindow(szWinName3,
                             "API",
                             WS_CHILDWINDOW,
                             200,
                             0,
                             100,
                             100,
                             childWind,
                             NULL,
                             hThisInst,
                             NULL);

    ShowWindow(thirdWind, nWinMode);
    UpdateWindow(thirdWind);


    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WindowFunc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) {
    HDC hdc;
    switch (message) {
        case WM_CHAR:
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, message, wparam, lparam);
    }
    return 0;
}
