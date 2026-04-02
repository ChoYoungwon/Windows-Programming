![실행화면](../../images/WorkerThread2)

### 코드 목적
작업자 스레드 구현하기2

### 주요 코드
- App의 `InitInstance()` : 스레드를 생성하여 여유 CPU가 한 개만 남도록 만든다.
- View의 `OnLButtonDown` : 좌클릭시 스레드를 생성하고 실행한다. (2번째 스레드가 높은 우선순위)
- View의 `MyDraw` : 막대 출력함수