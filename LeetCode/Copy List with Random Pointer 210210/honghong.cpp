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
        
        if(head == NULL) {
            return NULL;
        }
        
        map<Node*, int> m;
        vector<Node*> v;
        
        //head 탐색하면서 MAP에 <주소, 몇 번째 인지> 저장
        Node* cur = head;
        int count = 0;
        while(cur != NULL) {
            m.insert(make_pair(cur, count));
            
            cur = cur->next;
            count++;
        }
        
        //copy에 1)Val 저장 2)Next 저장 + Vector에 순서대로 Node 주소값 저장
        Node* copy = new Node(head->val);
        v.push_back(copy);
        Node* pre_node = copy;
        cur = head->next;
        while(cur != NULL) {
            Node* node = new Node(cur->val);
            v.push_back(node);
            pre_node->next = node;
            
            pre_node = node;
            cur = cur->next;
        }
        pre_node = NULL;

        //head 탐색하면서 random이 가리키는 주소(key)찾고, 순서값(value)으로 copy의 random에 각각 저장
        Node* cur_head = head;
        Node* cur_copy = copy;
        
        while(cur_head != NULL) {
        
            if(cur_head->random == NULL) {
                cur_copy->random = NULL;
            }
            else {
                int ind = m.find(cur_head->random)->second;
                cur_copy->random = v[ind];
            }

            cur_head = cur_head->next;
            cur_copy = cur_copy->next;
        }
    
        return copy;
    }
};