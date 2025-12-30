// Console.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "framework.h"
#include "Console.h"
#include <afxtempl.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 유일한 애플리케이션 개체입니다.

CWinApp theApp;

using namespace std;

void CString_Initial();
void CString_Format();
void CString_LoadString();
void CPoint_Class();
void CRect_Class();
void CSize_Class();
void CTime_Class();
void CTimeSpan_Class();
void non_template_array_1();
void non_template_array_2();
void non_template_array_3();
void template_array_1();
void non_template_list();
void non_template_list_2();
void template_list();
void non_template_map_1();
void template_map();


int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // MFC를 초기화합니다. 초기화하지 못한 경우 오류를 인쇄합니다.
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: 여기에 애플리케이션 동작을 코딩합니다.
            wprintf(L"심각한 오류: MFC 초기화 실패\n");
            nRetCode = 1;
        }
        else
        {
            //CString str;
            //str.LoadStringW(IDS_APP_TITLE);
            //_tprintf(_T("Hello from %s!\n"), (LPCTSTR)str);
            //getchar();

            /* CString 객체 생성과 초기화 */
            //CString_Initial();

            /* CString::Format() 함수 */
            //CString_Format();

            /* CString::LoadString() 함수 */
            //CString_LoadString();

            /* CPoint 객체 생성과 다루기 */
            //CPoint_Class();

            /* CRect 객체 생성과 다루기(left, top, right, bottom) */
            //CRect_Class();

            /* CSize 객체 생성과 다루기 */
            //CSize_Class();

            /*CTime 객체 생성과 다루기*/
            //CTime_Class();

            /* CTimeSpan 객체 생성과 다루기 */
            //CTimeSpan_Class();

            /*3. 집합 클래스*/
            /* 비템플릿 클래스 배열 생성과 초기화 */
            //non_template_array_1();

            /* 비템플릿 CString 객체 배열 저장 */
            //non_template_array_2();

            /* 배열 원소 삽입과 삭제 */
            //non_template_array_3();

            /*템플릿 배열 클래스 사용하기*/
            //template_array_1();

            /*리스트 생성, 순회*/
            //non_template_list();

            /* 리스트 항목 삽입과 삭제 */
            //non_template_list_2();

            /*템플릿 리스트 클래스 사용하기*/
            //template_list();

            /*맵 생성과 초기화 및 검색*/
            //non_template_map_1();

            /*템플릿 맵 클래스 사용하기*/
            template_map();
        }
    }
    else
    {
        // TODO: 오류 코드를 필요에 따라 수정합니다.
        wprintf(L"심각한 오류: GetModuleHandle 실패\n");
        nRetCode = 1;
    }

    return nRetCode;
}

/* CString 객체 생성과 초기화 */
void CString_Initial() {

    _tsetlocale(LC_ALL, _T(""));            // 유니코드 한국어 출력에 필요
    CString str1;
    str1 = _T("안녕하세요.");               // 문자열을 직접 대입한다.
    CString str2(_T("오늘은"));             // 문자열을 생성자 인자로 전달한다.
    CString str3(str2);                     // CString 객체를 생성자 인자로 전달한다.
    
    // CString 객체와 문자열을 붙인다.
    CString str4 = str1 + _T(" ") + str2 + _T(" 즐거운 날입니다. ");
    _tprintf(_T("%s\n"), (LPCTSTR)str1);
    _tprintf(_T("%s\n"), (LPCTSTR)str2);
    _tprintf(_T("%s\n"), (LPCTSTR)str3);
    _tprintf(_T("%s\n"), (LPCTSTR)str4);
    
    // += 연산자를 이용하여 기존 문자열에 새로운 문자열을 덧 붙인다.
    str4 += _T(" 하하 ");
    _tprintf(_T("%s\n"), (LPCTSTR)str4);
}

/* CString::Format() 함수 */
void CString_Format() {
    CString str;
    str.Format(_T("x=%d, y=%d"), 100, 200);
    MessageBox(NULL, str, _T("CString::Format() 연습"), MB_OK);
}

/* CString::LoadString() 함수 */
void CString_LoadString() {
    CString str;
    str.LoadString(IDS_APP_TITLE);              // 문자열 리소스를 로드한다.
    str.Insert(0, _T("Hello from "));           // 맨 앞에 문자열을 삽입한다.
    str.Append(_T("!"));                        // 맨 끝에 문자열을 덧붙인다.
    MessageBox(NULL, str, _T("CString::LoadString() 연습"), MB_OK);
}

/* CPoint 객체 생성과 다루기 */
void CPoint_Class() {
    _tsetlocale(LC_ALL, _T(""));
    CPoint pt1(10, 20);                 // x, y 좌표를 생성자 인자로 전달
    POINT pt = { 30, 40 };
    CPoint pt2(pt);
    _tprintf(_T("%d, %d\n"), pt1.x, pt1.y);
    _tprintf(_T("%d, %d\n"), pt2.x, pt2.y);

    pt1.Offset(40, 30);                 // x, y 좌표에 40, 30을 더한다.
    pt2.Offset(20, 10);

    _tprintf(_T("%d, %d\n"), pt1.x, pt1.y);
    _tprintf(_T("%d, %d\n"), pt2.x, pt2.y);
    if (pt1 == pt2)
        _tprintf(_T("두 점의 좌표가 같습니다. \n"));
    else
        _tprintf(_T("두 점의 좌표가 다릅니다. \n"));
}

/* CRect 객체 생성과 다루기(left, top, right, bottom) */
void CRect_Class() {
    _tsetlocale(LC_ALL, _T(""));
    CRect rect1(0, 0, 200, 100);
    CRect rect2;
    rect2.SetRect(0, 0, 200, 100);
    if (rect1 == rect2)
        _tprintf(_T("두 직사각형의 좌표가 같습니다. \n"));
    else
        _tprintf(_T("두 직사각형의 좌표가 다릅니다. \n"));
    RECT rect = { 100, 100, 300, 200 };
    CRect rect3(rect);
    _tprintf(_T("%d, %d\n"), rect3.Width(), rect3.Height());
    CPoint pt(200, 150);
    if (rect3.PtInRect(pt))
        _tprintf(_T("점이 직사각형 내부에 있습니다. \n"));
    else
        _tprintf(_T("점이 직사각형 외부에 있습니다. \n"));
}

/* CSize 객체 생성과 다루기 */
void CSize_Class() {
    _tsetlocale(LC_ALL, _T(""));
    CSize size1(100, 200);
    SIZE size = { 100, 200 };
    CSize size2(size);
    _tprintf(_T("%d, %d\n"), size2.cx, size2.cy);
    if (size1 == size2)
        _tprintf(_T("크기가 같습니다. \n"));
    else
        _tprintf(_T("크기가 다릅니다. \n"));
}

/*CTime 객체 생성과 다루기*/
void CTime_Class() {
    _tsetlocale(LC_ALL, _T(""));
    CTime tm;
    tm = CTime::GetCurrentTime();                               // 현재 시각
    CString str = tm.Format(_T("%A, %B %d, %Y"));
    _tprintf(_T("%s\n"), (LPCTSTR)str);
    str.Format(_T("현재 시각은 %d시 %d분 %d초입니다."), tm.GetHour(), tm.GetMinute(), tm.GetSecond());
    _tprintf(_T("%s\n"), (LPCTSTR)str);
}


/* CTimeSpan 객체 생성과 다루기 */
void CTimeSpan_Class() {
    _tsetlocale(LC_ALL, _T(""));
    CTime startTime = CTime::GetCurrentTime();
    Sleep(2000);
    CTime endTime = CTime::GetCurrentTime();
    
    CTimeSpan elapsedTime = endTime - startTime;
    CString str;
    str.Format(_T("%d초 지남!"), elapsedTime.GetTotalSeconds());
    _tprintf(_T("%s\n"), (LPCTSTR)str);
}

/* 비템플릿 클래스 배열 생성과 초기화 */
void non_template_array_1() {
    CUIntArray array;                       // 객체 생성
    array.SetSize(10);                      // 배열 크기 설정
    for (int i = 0; i < 10; i++) 
        array[i] = i * 10;
    for (int i = 0; i < 10; i++)
        _tprintf(_T("%d "), array[i]);
    _tprintf(_T("\n"));
}

/* 비템플릿 CString 객체 배열 저장 */
void non_template_array_2() {
    _tsetlocale(LC_ALL, _T(""));
    CStringArray array;
    array.SetSize(5);

    for (int i = 0; i < 5; i++) {
        CString string;
        string.Format(_T("%d년이 지났습니다."), (i + 1) * 10);
        array[i] = string;
    }
    for (int i = 0; i < 5; i++)
        _tprintf(_T("%s\n"), (LPCTSTR)array[i]);
}

/* 배열 원소 삽입과 삭제 */
void non_template_array_3() {
    CUIntArray array;
    array.SetSize(5);
    for (int i = 0; i < 5; i++) {
        array[i] = i;
    }
    array.InsertAt(3, 77);

    for (int i = 0; i < array.GetSize(); i++) {
        _tprintf(_T("%d "), array[i]);
    }
    _tprintf(_T("\n"));
    array.RemoveAt(4);
    for (int i = 0; i < array.GetSize(); i++) {
        _tprintf(_T("%d "), array[i]);
    }
    _tprintf(_T("\n"));
}

/*템플릿 배열 클래스 사용하기*/
struct Point3D {
    int x, y, z;
    Point3D() { x = 0; y = 0; z = 0; }
    Point3D(int x0, int y0, int z0) { x = x0; y = y0; z = z0; }
};

void template_array_1() {
    CArray<Point3D, Point3D&> array;
    array.SetSize(5);
    for (int i = 0; i < 5; i++) {
        Point3D pt(i, i * 10, i * 100);
        array[i] = pt;
    }

    for (int i = 0; i < 5; i++) {
        _tprintf(_T("%d, %d, %d\n"), array[i].x, array[i].y, array[i].z);
    }
}