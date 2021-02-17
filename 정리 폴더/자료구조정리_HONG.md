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
ㅁㄴㅇㄹ
