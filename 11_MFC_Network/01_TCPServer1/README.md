![실행 화면](../../images/TCP1.png)

### 코드 목적
TCP Server(콘솔)

### 주요 코드
- `ErrQuit(int err)` : 오류 문자열 화면 출력
- `main 부분`
	- `if (!sock.Create(8000))`  : 소켓 생성
	- `if (!sock.Listen())` : TCP 서버 동작
	- 첫 번째 while문의 `if (!sock.Accept(newsock))` : 클라이언트와 통신할 수 있는 새로운 소켓을 생성하여 인자로 넘겨준다.
	- `GetPeerName(PeerAddress, PeerPort);` : 클라이언트의 IP주소와 포트번호를 알고 싶을때
	- 두 번째 while문의 `nbytes = newsock.Receive(buf, 256);` : 클라이언트가 보낸 데이터를 받는다.
	- `newsock.Close();` : 접속 종료