## MFC 프로젝트 개요

### HelloMFC
간단한 MFC 프로그램
#### 환경 구축법(Visual Studio)
1. Windows 데스크톱 마법사 -> 데스크톱 애플리케이션, 빈 프로젝트
2. 프로젝트 속성 -> 고급 -> MFC 사용(공유 DLL에서 MFC 사용)
#### 출력 결과
Hello MFC 창 위에 출력,<br>
좌 클릭시 마우스 클릭 메시지 박스 출력 
<br><br>

### Console
메시지 구동 방식, 알고리즘 테스트 유용
데이터 타입 정리
- CString, CPoint, CRect, CSize
- CTime, CTimeSpan
#### 환경 구축법(Visual Studio)
Windows 데스크톱 마법사 -> 콘솔 애플리케이션, MFC 헤더
#### 출력 결과
Hello From Console!
### 코드 설명
- `CString_Initial();` -> CString 객체 생성과 초기화
- `CString_Format();`  -> CString::Format() 함수
- `CString_LoadString()`  -> CString::LoadString() 함수
- `CPoint_Class()`        -> CPoint 객체 생성과 다루기
- `CRect_Class()`         -> CRect 객체 생성과 다루기(left, top, right, bottom)
- `CSize_Class()`        -> CSize 객체 생성과 다루기