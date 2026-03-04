### 코드 목적
1. 메뉴 명령 처리하기
2. 메뉴 항목 갱신하기
3. 컨텍스트 메뉴
4. 시스템 메뉴 변경하기
5. 툴바 사용(툴바 리소스를 변경 -> 상태바 아이디와 동일하게)

### 주요 코드
- `CChildView`의 Events -> `COMMAND`, `UPDATE_COMMAND_UI`
- `COMMAND`핸들러 : 메뉴 항목 변경시 핸들러 (메뉴 클릭시 UI의 글자색 변경)
- `UPDATE_OMAND_UI` : 메뉴 항목 갱신 (메뉴에 체크표시 갱신)
- `OnContextMenu()` : 우 클릭시 컨텍스트 메뉴를 표시한다. 
- `CMainFrame::OnCreate`부분 : 시스템 메뉴 수정