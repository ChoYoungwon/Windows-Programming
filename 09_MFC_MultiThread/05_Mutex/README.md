![실행 화면](../../images/Mutex.png)

### 코드 목적
뮤텍스 활용하기

### 주요 코드
- `CMy05MutexDlg::OnBnClickedStart()` : 버튼 클릭시 세 개의 스레드 생성
- `MyThread(LPVOID pParam)` : 1~100 까지 출력(뮤텍스 있을시 하나의 스레드씩 순차적으로 실행)