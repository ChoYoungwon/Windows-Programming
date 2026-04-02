![실행 코드](../../images/WorkerThread1.png)

### 코드 목적
작업자 스레드 구현하기1

### 주요 코드
- 뷰의 `OnLButtonDown` : 좌클릭 핸들러(함수 일반 실행, 스레드 생성후 실행)
- 뷰의 `CalcIt` : 1부터 arg까지 증가하며 더하는 함수(Sleep(10)로 시간 늦춤)