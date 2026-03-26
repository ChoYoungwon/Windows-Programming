!(실행 화면)[../../images/MDITest.png]

### 코드 목적
간단한 MDI 응용프로그램 작성(두 개의 도큐먼트 타입 지원하기)

### 주요 코드
- 여러문서로 애플리케이션 생성
- `CMy02MDITestView` : 글자 출력
- `CCircleView` : 좌클릭 부분 원 생성
- `CMy02MDITestApp::InitInstance()` : CCircle 도큐먼트 템플릿을 생성하고 등록
