**QUEUE : FIFO(First In First Out) 방식으로 동작하는 cotainer**

#include<queue> 에 존재

기본 선언 형식  
queue<data type>  q;  
ex) queue<int> q;  

**queue 멤버 함수**  
1. front() - queue에 담겨있는 첫번째 원소에 접근. 들어간지 가장 오래된 원소, pop하면 나올 원소
2. empty() - 비어있으면 true 반환
3. size() - 원소의 개수 반환
4. push(value) - queue맨뒤에 원소를 넣음
5. pop() - 담겨있는 첫번째 원소 삭제, 반환은 void
