// 01_TCPServer1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "framework.h"
#include "01_TCPServer1.h"

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
            if (!sock.Create(8000))
                ErrQuit(sock.GetLastError());

            // 서버 동작
            if (!sock.Listen())
                ErrQuit(sock.GetLastError());

            TCHAR buf[256 + 1];
            int nbytes;

            while (1) {
                CSocket newsock;
                if (!sock.Accept(newsock))
                    ErrQuit(sock.GetLastError());

                CString PeerAddress;
                UINT PeerPort;
                newsock.GetPeerName(PeerAddress, PeerPort);
                _tprintf(_T("### IP 주소: %s, 포트 번호: %d ###\n"), (LPCTSTR)PeerAddress, PeerPort);

                while (1) {
                    nbytes = newsock.Receive(buf, 256);
                    if (nbytes == 0 || nbytes == SOCKET_ERROR) {
                        break;
                    }
                    else {
                        buf[nbytes] = _T('\0');
                        _tprintf(_T("%s"), buf);
                    }
                }
                newsock.Close();
                _tprintf(_T("### 접속 종료 ### \n\n"));
            }
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
