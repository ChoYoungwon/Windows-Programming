!(실행 화면)[../../images/FindReplace.png]

### 코드 목적
찾기/바꾸기 대화 상자 만들기 (공용 대화 상자)

### 주요 코드
- `CFindReplaceDialog* pDlg` : 대화 상자 객체를 가리키는 포인터 변수
- `cFindReplaceView::OnLButtonDown()`: 좌클릭시 찾기 상자 생성
- `LRESULT CFindReplaceView::OnFindReplaceCmd(WPARAM wParam, LPARAM lParam)` : 대화상자 컨트롤 메서드