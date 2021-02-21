## Iterator에 대한 배경
- STL 구성요소인 Container / Iterator / Algorithm 중 하나

## Iterator에 대한 정의
- 자료구조를 엑세스 하기 위한 방법
- 포인터와 상당히 비슷하며, 자료구조에 저장되어 있는 원소들을 참조할 때 사용
- (장점) 컨테이너의 내부 자료구조에 상관없이 동일한 방법으로 모든 요소를 접근할 수 있음

## Iterator에 대한 설명
- iterator 객체에서 사용할 수 있는 메서드는 다음과 같음
1. \*iter //원소값을 접근할 때 - cout << \*iter << endl; //iter\[3] 이렇게하면 3번 원소 접근 가능
2. iter++; //v.begin() + 1 이런건 가능
3. iter--; //v.end() - 1 이런건 가능 //iter1 + iter2 이런건 불가능
4. iter1 == iter2; 
5. iter1 != iter2; 
6. begin(객체); //ex. auto iter = begin(v)
7. end(객체); //ex. auto iter = end(v);

- **iterator의 end()는 마지막 원소가 아닌, 마지막 원소의 바로 다음번 원소를 가리킨다**

## 우리는 어떻게 Iterator를 사용하면 될까?
- vector<int>::iterator iter = v.begin(); 또는 auto iter = v.begin()으로 선언 후 사용 가능
  * auto 키워드는 기본 지정자임. 기본 지정자라는 의미는 굳이 지정하지 않아도 자동으로 auto로 지정된다는 의미

- 각 자료구조에는 Iterator를 리턴하는 기본 함수들이 구현되어 있음
  * v.begin(), v.end()
  * MAP : M.find("a") //KEY a가 있는 반복자를 찾아서 리턴
  * 자료구조 사용할 때 보면 하나씩 보일 듯...

- Iterator를 활용 가능한 별도로 find 함수가 있음
  * find(v.begin(), v.end(), "a") //범위 안의 원소들 중 value와 일치하는 첫 번째 원소를 가리키는 반복자를 리턴

