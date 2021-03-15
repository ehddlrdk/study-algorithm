/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        vector<int> V;
        
        int cnt = 0;
        ListNode* cur = head;
        
        while(cur != nullptr) {
            cnt++;
            V.push_back(cur->val);
            cur = cur->next;
        }
        
        int temp = V[k-1];
        V[k-1] = V[cnt-k];
        V[cnt-k] = temp;
        
        ListNode* pos = new ListNode(V[0]);
        head = pos;
        for(int i=1; i<V.size(); i++) {
            ListNode* node = new ListNode(V[i]);
            pos->next = node;
            pos = pos->next;
        }
        
        return head;
    }
};