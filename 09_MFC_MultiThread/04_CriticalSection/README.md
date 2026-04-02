![실행 화면](../../images/CriticalSection.png)

### 코드 목적
임계 영역 활용하기

### 주요 코드
- `CMy04CriticalSectionDlg::OnInitDialog()` : 프로그레스 컨트롤 초기화
- `CMy04CriticalSectionDlg::OnBnClickedStart()` : 스레드를 생성하는 코드 (비슷한 확률로 둘 중 하나가 먼지 시작하도록 설정)
- `Thread1(LPVOID pParam)`, `Thread2(LPVOID pParam)` : 두 스레드가 공유 자원을 사용하면서 각각 자신의 프로그레스 컨트롤을 일정 간격으로 증가 시킨다.
	- 임계영역을 사용하는 코드를 추가해 순차적으로 진행된다.