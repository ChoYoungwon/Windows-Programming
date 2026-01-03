## MFC 프로젝트 개요

### <span style="background-color:green"> HelloMFC </span>
간단한 MFC 프로그램
#### 환경 구축법(Visual Studio)
1. Windows 데스크톱 마법사 -> 데스크톱 애플리케이션, 빈 프로젝트
2. 프로젝트 속성 -> 고급 -> MFC 사용(공유 DLL에서 MFC 사용)
#### 출력 결과
Hello MFC 창 위에 출력,<br>
좌 클릭시 마우스 클릭 메시지 박스 출력 
<br><br>

### <span style="background-color:green"> Console </span>
메시지 구동 방식, 알고리즘 테스트 유용
데이터 타입 정리
- CString, CPoint, CRect, CSize
- CTime, CTimeSpan
#### 환경 구축법(Visual Studio)
Windows 데스크톱 마법사 -> 콘솔 애플리케이션, MFC 헤더
#### 코드 설명
- `CString_Initial();`    &emsp;&emsp;&emsp;&emsp;&emsp; -> CString 객체 생성과 초기화
- `CString_Format();`     &emsp;&emsp;&emsp;&emsp;&emsp; -> CString::Format() 함수
- `CString_LoadString()`  &emsp;&emsp;&emsp; -> CString::LoadString() 함수
- `CPoint_Class()`        &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; -> CPoint 객체 생성과 다루기
- `CRect_Class()`   &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; -> CRect 객체 생성과 다루기(left, top, right, bottom)
- `CSize_Class()`         &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; -> CSize 객체 생성과 다루기
- `CTime_Class()`         &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; -> CTime 객체 생성과 다루기
- `CTimeSpan_Class()`     &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; -> CTimeSpan 객체 생성과 다루기
- `non_template_array_1()` &emsp;&emsp;&emsp;&emsp; -> 비템플릿 클래스 배열 생성과 초기화
- `non_template_array_2() ` &emsp;&emsp;&emsp;&emsp; -> 비템플릿 CString 객체 배열 저장
- `non_template_array_3()`  &emsp;&emsp;&emsp;&emsp; -> 배열 원소 삽입과 삭제
- `template_array_1()`      &emsp;&emsp;&emsp;&emsp; -> 템플릿 배열 클래스 사용하기
    - `struct Point3D` : x, y, z를 가지는 구조체
- `non_template_list()`     &emsp;&emsp;&emsp;&emsp;  -> 리스트 생성, 순회
- `non_template_list_2()`   &emsp;&emsp;&emsp;&emsp;  -> 리스트 항목 삽입과 삭제
- `template_list()`         &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;  -> 템플릿 리스트 클래스 사용하기
- `non_template_map_1()`    &emsp;&emsp;&emsp;&emsp;  -> 맵 생성과 초기화 및 검색, 순회, 삭제
- `template_map()`          &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;  -> 템플릿 맵 클래스 사용하기

### <span style="background-color:green"> Simple </span>
- MFC 응용프로그램 마법사를 이용한 MFC 응용 프로그램 생성
- MFC 응용 프로그램 코드 기본 구조 탐색