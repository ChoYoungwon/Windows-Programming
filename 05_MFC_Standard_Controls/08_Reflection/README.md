![실행 화면](../../images/reflection.png)

### 코드 목적
메시지 반사 구현하기

### 주요 코드
- `CListBox`를 상속하는 `CMyListBox` 클래스를 추가
- `CMyListBox`클래스에서 `LBN_DBLCLK` 통지 메시지 핸들러를 추가한다.(`CMyListBox::OnLbnDBlclk()`)
(`=`표시가 리스트 박스 자신이 발생시키는 통지 메시지임을 나타낸다.)