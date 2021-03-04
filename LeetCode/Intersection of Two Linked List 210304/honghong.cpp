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
        
        ListNode* answer = NULL;
        
        ListNode* curA = headA;
        ListNode* curB = headB;
        
        int cntA = 0;
        int cntB = 0;
        
        while(curA != NULL) {
            curA = curA->next;
            cntA = cntA + 1;
        }
        
        while(curB != NULL) {
            curB = curB->next;
            cntB++;
        }
        
        ListNode* smaller = NULL;
        ListNode* larger = NULL;
        int sub = 0;
        
        if(cntA >= cntB) {
            larger = headA;
            smaller = headB;
            sub = cntA - cntB;
        }
        else {
            larger = headB;
            smaller = headA;
            sub = cntB - cntA;
        }
        
        int cntS = 0;
        int cntL = 0;

        while(larger != NULL) {
            
            if(larger == smaller) {
                answer = larger;
                break;
            }
            
            larger = larger->next;
            cntL++;
            
            if(cntL > sub) {
                smaller = smaller->next;
            }
        }
        
        return answer;
    }
};