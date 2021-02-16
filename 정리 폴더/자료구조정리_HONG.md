### QUEUE

QUEUE 선언
```c
queue<int> Q;
queue<pair<int, string> Q;
```

맨 뒤 삽입
```c
Q.push();
```

맨 앞 원소 읽기
```c
Q.front();
```

맨 앞 원소 삭제

```c
Q.pop();
```

기타 메서드
```c
Q.empty() //비었는지 확인(비어있다면 True 리턴)
Q.size() //큐의 크기 출력
Q.back() //큐의 맨 뒤 원소 읽기
```

