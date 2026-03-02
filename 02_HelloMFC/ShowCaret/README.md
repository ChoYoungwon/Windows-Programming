### 코드 목적
캐럿을 이용한 키보드 포커스 테스트

### 주요 코드
- `WM_SETFOCUS`발생시 `OnSetFocus()`핸들러 실행
- 캐럿을 생성한다.
- `WM_KILLFOCUS`발생시 `OnKillFocus()`핸들러 실행
- 캐럿을 파괴한다.