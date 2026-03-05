### 코드 목적
직렬화 구현

### 주요 코드
- `OnChar()` : 글자 입력시 동적 배열에 글자를 추가 또는 삭제, 데이터  수정, 뷰 화면 갱신
- `CMy02InputSaveLoadView::OnDraw()` : 데이터 화면 출력
- doc 코드 부분에 명령 핸들러, 명령 갱신 핸들러 추가(이탤릭, 밑글)
- `CMy02InputSaveLoadDoc::Serialize()` : 직렬화 수행 코드