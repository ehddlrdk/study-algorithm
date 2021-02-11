/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
*/

class Solution {
public:
	Node* copyRandomList(Node* head) {
		//새로 생성할 노드와 기존의 노드를 pair로 구성
		map<Node*, Node*> m;
		Node* first = head;

		while (first != NULL) {
			Node* new_node = new Node(first->val);
			m[first] = new_node;
			first = first->next;
		}

		first = head;
		//map에서 넣은 새 노드를 기존 연결과 똑같이 연결
		while (first != NULL) {
			m[first]->next = m[first->next];
			m[first]->random = m[first->random];
			first = first->next;
		}
		//첫 노드를 리턴
		return m[head];
	}
};