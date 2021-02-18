## QUEUE
QUEUE 선언
```c
queue<int> Q;
queue<pair<int, string>> Q;
```

QUEUE 메서드
```c
Q.push(2); //맨 뒤 2 삽입
Q.front(); //맨 앞 원소 출력
Q.pop(); //맨 앞 원소 삭제

Q.empty(); //비었는지 확인(비어있다면 True 리턴)
Q.size(); //큐의 크기 출력
Q.back(); //큐의 맨 뒤 원소 출력
```
참고 링크
https://coding-factory.tistory.com/598?category=767224

---
## VECTOR
VECTOR 선언
```c
vector<int> V;
vector<pair<int, string>> V;
```
VECTOR 구조
```c
V.front(); //맨 앞 원소 출력
V.back(); //맨 뒤 원소 출력
V.size(); //벡터의 크기 출력
```
VECTOR 값 추가
```c
V.push_back(2); //맨 뒤 2 삽입
V.insert(5. 2); //인덱스 5에 2 삽입 -> index, value
```
VECTOR 값 삭제
```c
V.pop_back(); //맨 뒤 값을 삭제
V.erase(V.begin() + 5) //인덱스 5의 값을 삭제
V.erase(V.begin(), V.begin() + 5) //인덱스 0~5의 값을 삭제
V.clear() //전체 값을 삭제
```
VECTOR 메서드
```c
V.size() //벡터의 크기 출력
V.empty() //벡터가 비었는 지 확인(비었으면 True 리턴)
```

참고 링크
<https://coding-factory.tistory.com/596?category=767224/>

---
## MAP
- MAP의 내부 구현은 검색, 삽입, 삭제가 **O(logN)** 인 **레드블랙트리**로 구성되어 있음
- MAP은 자료를 저장할 때 내부에서 자동으로 정렬한다. MAP은 **key**를 기준으로 **오름차순** 정렬한다.

MAP 선언
```c
map<int, string> M; //<Key Type, Value Type>
```
MAP 구조 - Front, Back 이런건 없음. Key를 이용해서 찾아야하는 듯

MAP 값 추가
```c
M.insert(make_pair<2, "kihong"); //Key = 2 / Value = "kihong" 삽입
- pair<iterator, bool> 리턴 //이걸 이용해서 추가 성공 여부 확인 가능
```
MAP 값 삭제
```c
M.erase(M.begin() + 1) //Iterator 기준으로 삭제 -> 범위를 넣어서 범위 삭제도 가능
M.erase(2) //Key값을 기준으로 삭제
M.clear() //모든 값을 삭제
```
MAP 메서드
```c
M.find(Key) //map에 찾고자 하는 데이터(Key)가 있는지 확인, 없으면 M.end() Iterator 리턴
M.empty() //맵이 비었는 지 확인(비었으면 True 리턴)
M[key] = value //추가 생성 혹은 Overwrite
```
