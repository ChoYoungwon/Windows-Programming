#include "pch.h"
#include "framework.h"
#include "Console.h"
#include <afxtempl.h>

/*맵 생성과 초기화 및 검색, 순회, 삭제*/
void non_template_map_1() {
	_tsetlocale(LC_ALL, _T(""));

	CMapStringToString map;
	map[_T("사과")] = _T("Apple");
	map[_T("딸기")] = _T("Strawberry");
	map[_T("포도")] = _T("Grape");
	map[_T("우유")] = _T("Milk");

	CString str;
	if (map.Lookup(_T("딸기"), str))
		_tprintf(_T("딸기 -> %s\n"), (LPCTSTR)str);

	/*맵 순회*/
	_tprintf(_T("\n"));

	/*맵 데이터 삽입, 삭제*/
	map.RemoveKey(_T("우유"));
	map[_T("수박")] = _T("Watermelon");

	POSITION pos = map.GetStartPosition();
	while (pos != NULL) {
		CString strKey, strValue;
		map.GetNextAssoc(pos, strKey, strValue);
		_tprintf(_T("%s -> %s \n"), (LPCTSTR)strKey, (LPCTSTR)strValue);
	}
}

/*템플릿 맵 클래스 사용*/
template<>
inline UINT AFXAPI HashKey<LPCTSTR>(LPCTSTR str)
{
	LPCTSTR key = (LPCTSTR)str;
	return HashKey((unsigned __int64)key);
}

/*템플릿 맵 클래스 사용하기*/
void template_map() {
	_tsetlocale(LC_ALL, _T(""));

	CMap<CString, LPCTSTR, UINT, UINT&> map;

	map[_T("사과")] = 10;
	map[_T("딸기")] = 25;
	map[_T("포도")] = 40;
	map[_T("수박")] = 15;

	UINT nCount;
	if (map.Lookup(_T("수박"), nCount))
		_tprintf(_T("수박 %d 상자가 남아 있습니다.\n"), nCount);
}