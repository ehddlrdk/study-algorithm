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

# Hash Table
* Key에 Value를 저장하는 데이터 구조이다. 
* 내부적으로 배열을 사용하여 데이터를 저장하기 때문에 빠른 검색 속도를 가진다. Average case에 대해서는 시간복잡도가 O(1)이다.
* Hash Function이라는 특별한 알고리즘을 이용하여 key값에 대한 고유한 숫자를 만들어 낸 뒤 이를 인덱스로 사용한다.
* 특정 데이터가 저장되는 그 데이터만의 고유한 위치이기 때문에 삽입, 삭제 연산에서 추가적인 비용이 없도록 만들어진 구조이다.
* Hash Table은 Key, Hash Function, Hashcode, Value, Bucket(저장소)로 이루어져 있다.

## Hash Function
* 저장되는 값들의 Key값을 Hash Function을 통해 인덱스의 값들로 바꿔준다.
* Hash Function에 의해 반환된 데이터의 고유 숫자 값을 Hashcode라고 한다.
* 서로 다른 Key가 같은 Hashcode가 되는 경우를 Hash Collision이라고 한다.

### Hash Function의 조건
* Collision을 최소화하는 방향으로 설계한다.
* 1:1 대응되도록 만드는 것보다 발생하는 Collision에 대비해 어떻게 대응할 것인가가 더 중요하다.

## Resolve Conflict
* Hash Function으로 Hashcode를 산출하는 과정에서 서로 다른 Key가 같은 Hash로 변경되는 문제가 발생할 수 있는데 이는 Key와 Value가 1:1로 매칭 되어야 한다는 규칙을 위배하는 것을 Hash Collision이라고 한다.
### 1. Chaining (Separate Chaining)
* 자료 저장 시, 저장소(Bucket)에서 충돌이 일어나면 해당 값을 기존 값과 연결시키는 기법이다.
#### 1. Liked List를 이용한 구현방식
* 각 저장소(bucket)들을 Linked List로 만들어 Collision이 발생하면 해당 저장소의 list에 추가하는 방식이다.
* 삭제 또는 삽입이 간단한 장점이 있으며, 작은 데이터들을 저장할 때는 Linked List의 오버헤드가 단점이 있다.
#### 2. Tree를 이용한 구현방식(Red-Black Tree)
* Linked List 대신 Tree를 사용하는 방식이다. 
* Tree는 기본적으로 메모리 사용량이 많기에 Key-Value 쌍의 개수가 적다면 Linked List를 사용한다.

* 한정된 저장소를 효율적으로 사용할 수 있고, 해시함수를 선택하는 중요성이 상대적으로 적으며 미리 공간을 할당해 놓을 필요가 없기에 적은 메모리를 사용한다는 장점이 있다.
* 한 Hashcode로 자료들이 계속 연결된다면(쏠림현상) 검색 효율이 낮아지며, 외부 저장 공간을 사용하기에 외부 저장공간에 대한 작업을 추가로 해야된다는 단점이 있다.

### 2. Open Addressing(개방주소법)
* 데이터의 Hashcode가 변경되지 않았던 Chaining과는 달리 비어있는 해시를 찾아 데이터를 저장하는 기법이다.
* Open Addressing에서는 Hash Table은 1개의 Hashcode와 1개의 Value가 매칭되어 있는 형태로 유지된다.
* 또 다른 저장공간 없이 Hash Table 내에서 데이터 저장 및 처리가 가능해 공간적 효율이 높다는 장점이 있다.
* Hash Function의 성능에 의해 전체 Hash Table의 성능이 좌우되며, 데이터의 길이가 늘어나면 늘어난 만큼의 Table을 확장해야 하는 단점이 있다. 
* 비어있는 Hashcode를 찾는 규칙이 몇가지 있다.
  1. 선형탐색(Linear Probing): 순차적으로 탐색하여 비어있는 버킷을 찾을 때까지 계속 진행한다.
  2. 제곱탐색(Quadratic Probing): 충돌이 일어난 Hashcode의 제곱을 한 Hashcode에 데이터를 저장한다.
  3. 이중해시(Double hasing): 다른 Hash Function을 한번 더 적용한 Hashcode에 데이터를 저장한다. 많은 연산량을 요구하게 된다.


#### Open Address VS Chaining
* 두 방식 모두 Worst Case에서 O(M)이다.
* Open Address 방식은 연속된 공간에 데이터를 저장하기 때문에 Chaining에 비해 캐시 효율이 높다. 데이터의 개수가 충분히 적다면 Open Address 방식이 Chaining 방식보다 성능이 더 좋다. 
* Open Address 방식은 Chaining에 비해 저장소를 계속 사용하기 때문에 Chaining 방식은 Table의 확장을 늦출 수 있다. 

# Graph
* 정점과 간선의 집합
* 정점과 간선의 연결관계에 있어서 방향성이 없는 그래플ㄹ Undirected Graph, 간선에 방향성이 포함되어 있는 그래프를 Directed Graph
* Degree: Undirected Graph에서 각 정점에 연결된 Edge의 개수를 Degree라고 한다. Directed Graph에서는 각 정점으로부터 나가는 간선의 개수를 Outdegree 들어오는 간선의 개수를 Indegree라고 한다.
### 가중치 그래프(Weight Graph), 부분 그래프(Sub Graph)
* 가중치 그래프는 간선에 가중치 정보를 두어서 구성한 그래프를 말한다. 
* 부분 그래프는 본래의 그래프의 일부 정점 및 간선으로 이루어진 그래프를 말한다.
## 그래프를 구현하는 두 방법
1. 인접 행렬(Adjacent Matrix): 정방 행렬을 사용하는 방법
해당하는 위치의 Value 값을 통해 정점간의 연결 관계를 O(1)로 파악할 수 있다. Edge 개수와는 무관하게 V^2의 공간 복잡성을 갖고 Dense Graph를 표현할 때 적절한 방법이다.

2. 인접 리스트(Adjacent List): Linked List를 사용하는 방법
정점의 인접 리스트를 확인해봐야 하므로 정점간 연결되어있는지 확인하는데 오래 걸린다. 공간 복잡도는 O(E + V)이다. Sparse Graph를 표현하는데 적당한 방법이다.

## 그래프 탐색
### 깊이 우선 탐색(Depth First Search DFS)
* 임의의 한 정점으로부터 연결되어 있는 한 정점으로만 나아간다라는 방법을 우선으로 탐색한다. 연결할 수 있는 정점이 있을 때까지 계속 연결 후 더이상 연결할것이 없으면 전 단계의 정점으로 돌아가서 연결할 수 있는 정점을 찾는것이다. 갔던 길을 되돌아 오는 상황이 존재하는 미로찾기처럼 구성하면 된다. 
* Stack을 사용하여 구현할 수 있으며 시간복잡도는 O(V + E)이다.
### 너비 우선 탐색(Breadth First Search BFS)
* 임의의 한 정점으로부터 연결되어 있는 모든 정점으로 나아간다. 
* 탐색을 시작하는 정점을 Queue에 넣고 dequeue를 하면서 dequeue한 정점과 간선으로 연결되어 있는 정점들을 enqueue하여 정점들을 방문한 순서대로 queue에 저장하는 방법을 사용한다.
* Queue를 사용하여 구현할 수 있으며 시간복잡도는 O(V + E)이다.

## Minimum Spanning Tree(최소 비용 신장 트리)
### Kruskal Algorithm
* Greedy Method를 이용하여 가중치를 간선에 할당한 그래프의 모든 정점을 최소 비용으로 연결하는 최적 해답을 구하는 것이다.
### Prim Algorithm
