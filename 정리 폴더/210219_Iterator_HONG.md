## Iterator에 대한 배경
- STL 구성요소인 Container / Iterator / Algorithm 중 하나

## Iterator에 대한 정의
- 자료구조를 엑세스 하기 위한 방법
- 포인터와 상당히 비슷하며, 자료구조에 저장되어 있는 원소들을 참조할 때 사용

## Iterator에 대한 설명
- iterator 객체에서 사용할 수 있는 메서드는 다음과 같이 7개
1. *iter //원소값을 접근할 때 - cout << *iter << endl;
2. iter++; 
3. iter--; 
4. iter1 == iter2; 
5. iter1 != iter2; 
6. begin(객체); //ex. auto iter = begin(v)
7. end(객체); //ex. auto iter = end(v);

- _iterator의 end()는 마지막 원소가 아닌, 마지막 원소의 바로 다음번 원소를 가리킨다_
  0 1 2 3 4 5 6
  ^             ^
  begin()       end()

## 우리는 어떻게 Iterator를 사용하면 될까?


