### 코드 목적
스태틱 컨트롤 활용하기
- 텍스트, 프레임(색이 채워지지 않은 직사각형), 직사각형(색이 채워진), 아이콘, 비트맵, 확장 메타파일을 화면에 표시할 수 있는 윈도우

### 주요 코드
- `CMy03StaticView::OnInitialUpdate()` 부분 : 메타피일 핸들러 가져와(`GetEnhMetaFile()`) 스태틱 컨트롤과 연결(`SetEnhMetaFile()`)
- `CMy03StaticView::OnStnClickedMetafile()` : `STN_CLICKED` 통지 메시지 핸들러(메타파일 그림 클릭시의 동작) 추가 
