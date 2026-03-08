### 코드 목적
edit 컨트롤 활용

### 주요 코드
- `CEdit m_edit`, `CStatic m_static` 변수 선언
- `m_edit.SetLimitText(20)` : 최대 길이 지정
- `CMy04EditCtrlView::OnEnMaxtextMyedit()` : `EN_MAXTEXT` 메시지 핸들러
- `CMy04EditCtrlView::OnEnChangeMyedit()` : `EN_CHANGE` 메시지 핸들러