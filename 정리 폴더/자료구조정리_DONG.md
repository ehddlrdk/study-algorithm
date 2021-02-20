# Array, LinkedList 구조 

## Array 
### |70|40|50|60|90|80|

* 논리적 저장순서와 물리적 저장 순서가 일치한다. 
* index로 해당 원소에 접근이 가능하다. random access가 가능하다.
* 배열의 중간 원소에 대해 삽입, 삭제시 shift를 해줘서 공간을 만들거나 빈공간을 채워야한다. 이때 O(n)의 시간이 소요됨.
* Array의 size는 선언 시점에 지정되어있어야함(정적 메모리 할당). Stack영역에 메모리 할당이 이루어진다.


## LinkedList
### null -> 70 -> 40 -> A -> null

* 자료의 주소 값으로 노드를 이용해 서로 연결되어 있는 구조를 갖는다.
* 삽입과 삭제의 경우 연결되어있는 노드를 서로 재연결 해주면 되기에 삽입 삭제 그 자체에 대해서는 Array에 비해서 속도가 빠르다.
* 원하는 값을 찾기 위해서는 리스트를 순회해야하기에 O(n)의 복잡도를 가지기에 크게 보면 삽입, 삭제시 Array와 속도가 비슷하다.
* Tree구조의 근간이 되는 자료구조이다.
* 새로운 node가 추가될 때 메모리 할당이 이루어진다(동적 메모리 할당). Heap영역에 메모리 할당이 이루어진다.
<br>

### 삽입과 삭제가 빈번하다면 LinkedList를 사용하는것이, 데이터의 접근이 더 중요하다면 Array를 사용하는것이 좋다.
<br>

# Stack, Queue 구조
## Stack
* 선형 자료구조의 일종으로 Last In First Out(LIFO) 구조를 가진다. 나중에 들어간 원소가 먼저 나온다.
* 깊이 우선 탐색(DFS Depth first Search)를 할 때 많이 이용된다. ex) 택배 상하차

## Queue
* 선형 자료구조의 일종으로 First In First Out(FIFO) 구조를 가진다. 먼저 들어간 원소가 먼저 나온다.
* 너비 우선 탐색(BFS Breadth First Search)를 할 때 많이 이용된다. ex) 최단길이, 은행 창구
<br>

# Tree
* 스택, 큐와 같은 선형 구조가 아닌 비선형 자료구조이다.
* 계층적 관계(Hierarchical Relationship)을 표현하는 자료구조이다. 
* 노드들의 집합으로 각 노드들은 서로 다른 자식을 가지며 반드시 하나의 root가 존재한다.

## Tree 용어
* Node(노드): 트리는 노드들의 집합으로 트리를 구성하는 것이다. Value값과 부모 자식의 정보를 가지고 있다.
* Edge(간선): 노드들을 연결하는 간선으로 부모 노드와 자식 노드를 연결하게 된다.
* Root Node(루트노드): 가장 최상위 노드로 부모를 가지지 않는다.
* Terminal Node(leaf node, 단말노드): 가장 하위 노드로 자식을 가지지 않는다.
* 깊이(depth): tree에서 부모에서 자식으로 이동할 때 depth가 1증가. 형제 노드 간의 depth는 동일, root node는 depth 0이다.

## Tree 종류
### Binary Tree (이진 트리)
* 루트노드를 중심으로 두개의 서브 트리로 나위어 진다. 모든 서브 트리도 이진 트리이어야 한다.
* level: 각 층별로 숫자를 매긴것. 레벨의 값은 0부터 시작하고 루트 노드의 레벨은 0이다.
* height: 트리의 최고 레벨을 가리킴. 
#### 이진 트리 종류- Perfect Binary Tree (포화 이진 트리), Complete Binary Tree (완전 이진 트리), Full Binary Tree(정 이진 트리)
* 배열로 구성된 Binary Tree는 노드의 개수가 n개이고 root가 1인 index로 시작할 때, i번째 노드에 대해서 parent(i) = i/2, left_child(i) = 2i, right_child(i) = 2i + 1의 index를 가진다.
### Binary Search Tree (이진 탐색 트리)
* 효율적인 탐색을 위해 일련의 규칙을 따르는 트리.
* 규칙 
  1. 이진 탐색 트리의 노드에 저장된 키는 유일하다.
  2. 부모의 키가 왼쪽 자식 노드의 키보다 크다.
  3. 부모의 키가 오른쪽 자식 노드의 키보다 작다.
  4. 왼쪽과 오른쪽 서브트리도 이진 탐색 트리이다.
* 탐색 연산은 O(log n) 시간 복잡도를 가진다.

 *배열보다 많은 메모리를 사용하며 데이터를 저장했지만 탐색에 필요한 시간 복잡도가 같게 되는 비효율적인 상황이 발생할 수 있음. 이를 해결하기 위해 Rebalancing기법이 등장하였다. 이 기법을 구현한 트리에는 여러 종류가 존재하며 가장 대표적으로 Red-Black Tree가 있다.*

# Binary Heap
* Tree 형식이며 배열에 기반한 Complete Binary Tree이다.
* Heap에는 Max Heap, Min Heap 두 종류가 있다.
## Max Heap
* 각 노드의 값이 해당 children의 값보다 크거나 같은 Complete Binary Tree를 말한다.
* Root Node에 있는 값이 제일 크므로, 최대값을 찾는데 소요되는 연산의 시간 복잡도가 O(1)이다. 
* Complete Binary Tree이기에 배열을 사용하여 효율적인 관리가 가능하다.
## Min Heap
* 각 노드의 값이 해당 children의 값보다 작거나 같은 Complete Binary Tree를 말한다.
* 최소값을 찾는데 소요되는 연산의 시간 복잡도가 O(1)이다

### Max Heap, Min Heap은 노드가 제거되거나 추가되었을때 Heap구조를 유지하기 위해서 Heapify과정을 거친다. 
* Heapify연산을 통해 깨진 Heap구조를 바로잡기위해 각 노드들의 위치를 조정하는 과정을 말한다.  
