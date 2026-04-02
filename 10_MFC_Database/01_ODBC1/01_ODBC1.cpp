// 01_ODBC1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "framework.h"
#include "01_ODBC1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

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
            _tsetlocale(LC_ALL, _T(""));    // 유니코드 한국어 출력에 필요

            // 데이터베이스 객체 생성
            CDatabase db;
            db.OpenEx(_T("DSN=student"), 0);

            // 레코드셋 객체 생성
            CRecordset rs(&db);
            rs.Open(CRecordset::dynaset, _T("SELECT * FROM 테이블1"));

            // 데이터 출력
            CString str;
            while (!rs.IsEOF()) {
                rs.GetFieldValue(short(0), str);
                _tprintf(_T("%s "), (LPCTSTR)str);
                rs.GetFieldValue(short(1), str);
                _tprintf(_T("%s "), (LPCTSTR)str);
                rs.GetFieldValue(short(2), str);
                _tprintf(_T("%s "), (LPCTSTR)str);
                rs.GetFieldValue(short(3), str);
                _tprintf(_T("%s\n"), (LPCTSTR)str);
                rs.MoveNext();
            }

            // 종료 처리
            rs.Close();
            db.Close();
        }
    }
    else
    {
        // TODO: change error code to suit your needs
        wprintf(L"Fatal Error: GetModuleHandle failed\n");
        nRetCode = 1;
    }

    return nRetCode;
}
