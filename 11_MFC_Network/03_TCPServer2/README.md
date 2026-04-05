![실행 화면](../../images/TCP2.png)

### 코드 목적
TCP Server(GUI)

### 주요 코드
- View.cpp
- `AddMessage(LPCTSTR message)` : 뷰의 에디트 컨트롤에 현재 표시된 문자열에 새로운 문자열을 덧붙인다.
  
- Doc.cpp
- `OnNewDocument()` : 서버 초기화, CListenSocket 객체를 동적으로 생성하고, 8000번 포트 번호로 클라이언트가 접속하기를 기다린다.
- `DeleteContents()` : 소멸자 역할로 소켓 객체를 정리한다.
- `PrintMessage(LPCTSTR message)` : 에디트 컨트롤에 문자열을 출력한다.
- `ProcessAccept(int nErrorCode)` : 접속 여부를 `PrintMessage()`를 통해 화면에 문자열을 출력한다.
- `ProcessReceive(CDataSocket* pSocket, int nErrorCode)` : 클라이언트로부터 받은 데이터를 화면에 출력한다.
- `ProcessClose(CDataSocket* pSocket, int nErrorCode)` : 소켓을 닫고 소켓 객체에 할당된 메모리를 해제한다.
  
- CListenSocket.cpp
- `OnAccept(int nErrorCode)` : 도큐먼트 클래스의 `ProcessAccept()`함수를 호출하여 도큐먼트 객체가 모든 소켓  입출력 작업을 처리
  
- CDataSocket.cpp
- `OnReceive(int nErrorCode)` : 도큐먼트 클래스의 `ProcessReceive` 함수를 호출한다.
- `OnClose(int nErrorCode)` : 도큐먼트 클래스의 `ProcessClose` 함수를 호출한다.