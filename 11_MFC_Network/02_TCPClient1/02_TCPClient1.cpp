// 02_TCPClient1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "framework.h"
#include "02_TCPClient1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

void ErrQuit(int err) {
    LPVOID lpMsgBuf;
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
        NULL, err,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf, 0, NULL);
    MessageBox(NULL, (LPCTSTR)lpMsgBuf, _T("오류 발생"), MB_ICONERROR);
    LocalFree(lpMsgBuf);
    exit(1);
}

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // initialize MFC and print and error on failure
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: code your application's behavior here.
            wprintf(L"Fatal Error: MFC initialization failed\n");
            nRetCode = 1;
        }
        else
        {
            _tsetlocale(LC_ALL, _T(""));
            AfxSocketInit();

            CSocket sock;
            if (!sock.Create())
                ErrQuit(sock.GetLastError());

            if (!sock.Connect(_T("127.0.0.1"), 8000))
                ErrQuit(sock.GetLastError());

            TCHAR buf[256];
            int nbytes;

            for (int i = 0; i < 5; i++) {
                wsprintf(buf, _T("%d번째 테스트 메시지\r\n"), i);
                nbytes = sock.Send(buf, 256);
                if (nbytes == SOCKET_ERROR)
                    ErrQuit(sock.GetLastError());
                else {
                    _tprintf(_T("<%d> %d바이트 전송\n"), i, nbytes);
                    Sleep(1000);
                }
            }
            sock.Close();
        }
    }
    else
    {
        // TODO: change error code to suit your needs
        wprintf(L"Fatal Error: GetModuleHandle failed\n");
        nRetCode = 1;
    }

    system("pause");
    return nRetCode;
}
