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
    ListNode* collisionPoint(ListNode* temp1, ListNode* temp2, int diff){
        while(diff){
            diff--;
            temp2 = temp2->next;
        }
        while(temp1!=temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        int n1=0;
        int n2=0;
        
        while(t1!=NULL){
            n1++;
            t1 = t1->next;
        }
        while(t2!=NULL){
            n2++;
            t2 = t2->next;
        }
        
        if(n1<n2){
            return collisionPoint(headA, headB, n2-n1);
        }
        return collisionPoint(headB, headA, n1-n2);
    }
};