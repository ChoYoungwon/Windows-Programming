### 코드 목적
마우스 커서 좌표를 상태바에 표시

### 주요 코드
- String Table 변경(`IDR_INDICATOR_POS` 문자열 추가)
- `WM_MOUSEMOVE`핸들러 생성(마우스 이동시 상태바 POS값 변경)
- `CMainFrame::OnUpdatePos()` : 상태바 갱신 핸들러