#include "pch.h"
#include "framework.h"
#include "Console.h"
#include <afxtempl.h>

const TCHAR* szFruits[] = {
		_T("사과"), _T("딸기"), _T("포도"), _T("오렌지"), _T("자두")
};

/*리스트 생성, 순회*/
void non_template_list() {
	
	CStringList list;
	for (int i = 0; i < 5; i++) {
		list.AddTail(szFruits[i]);
	}

	_tsetlocale(LC_ALL, _T(""));

	// 리스트 맨 앞에서부터 순회
	POSITION pos = list.GetHeadPosition();
	while (pos != NULL) {
		CString str = list.GetNext(pos);
		_tprintf(_T("%s "), (LPCTSTR)str);
	}
	_tprintf(_T("\n"));

	// 리스트 맨 뒤에서부터 순회
	pos = list.GetTailPosition();
	while (pos != NULL) {
		CString str = list.GetPrev(pos);
		_tprintf(_T("%s "), (LPCTSTR)str);
	}
	_tprintf(_T("\n"));

}

/* 리스트 항목 삽입과 삭제 */
void non_template_list_2() {
	_tsetlocale(LC_ALL, _T(""));
	CStringList list;
	for (int i = 0; i < 5; i++) {
		list.AddTail(szFruits[i]);
	}

	POSITION pos = list.Find(_T("포도"));
	list.InsertBefore(pos, _T("살구"));
	list.InsertAfter(pos, _T("바나나"));
	list.RemoveAt(pos);

	pos = list.GetHeadPosition();
	while (pos != NULL) {
		CString str = list.GetNext(pos);
		_tprintf(_T("%s "), (LPCTSTR)str);
	}
	_tprintf(_T("\n"));
}

struct Point3D {
	int x, y, z;
	Point3D() { x = 0; y = 0; z = 0; }
	Point3D(int x0, int y0, int z0) { x = x0; y = y0; z = z0; }
};

/*템플릿 리스트 클래스 사용하기*/
void template_list() {
	CList<Point3D, Point3D&> list;

	for (int i = 0; i < 5; i++) {
		Point3D pt(i, i * 10, i * 100);
		list.AddTail(pt);
	}
	POSITION pos = list.GetHeadPosition();

	while (pos != NULL) {
		Point3D pt = list.GetNext(pos);
		_tprintf(_T("%d, %d, %d\n"), pt.x, pt.y, pt.z);
	}
		
}