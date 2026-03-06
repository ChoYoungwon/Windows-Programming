### 코드 목적
대화 상자 리소스에 포함하여 다양한 버튼 만들기

### 주요 코드
- `CMyButton2View::OnInitialUpdate()` : 뷰가 화면에 보이기 전에 MFC 내부 코드에서 자동으로 호출됨, 컨트롤 초기화
- `CMyButton2View::OnBnClickedButton1()` : 버튼 클릭시 발생하는 BN_CLICKED 통지 메시지 핸들러 추가_