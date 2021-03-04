/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 참조하고있는 주소가 같을 때 그것 리턴. 
        map<ListNode*, bool> m;
        while(headA != NULL) {
            m[headA] = true;
            headA = headA->next;
        }
        while(headB != NULL) {
            if (m[headB] == true) {
                return headB;
            }
            headB = headB->next;
        }
        return headB;
    }
};