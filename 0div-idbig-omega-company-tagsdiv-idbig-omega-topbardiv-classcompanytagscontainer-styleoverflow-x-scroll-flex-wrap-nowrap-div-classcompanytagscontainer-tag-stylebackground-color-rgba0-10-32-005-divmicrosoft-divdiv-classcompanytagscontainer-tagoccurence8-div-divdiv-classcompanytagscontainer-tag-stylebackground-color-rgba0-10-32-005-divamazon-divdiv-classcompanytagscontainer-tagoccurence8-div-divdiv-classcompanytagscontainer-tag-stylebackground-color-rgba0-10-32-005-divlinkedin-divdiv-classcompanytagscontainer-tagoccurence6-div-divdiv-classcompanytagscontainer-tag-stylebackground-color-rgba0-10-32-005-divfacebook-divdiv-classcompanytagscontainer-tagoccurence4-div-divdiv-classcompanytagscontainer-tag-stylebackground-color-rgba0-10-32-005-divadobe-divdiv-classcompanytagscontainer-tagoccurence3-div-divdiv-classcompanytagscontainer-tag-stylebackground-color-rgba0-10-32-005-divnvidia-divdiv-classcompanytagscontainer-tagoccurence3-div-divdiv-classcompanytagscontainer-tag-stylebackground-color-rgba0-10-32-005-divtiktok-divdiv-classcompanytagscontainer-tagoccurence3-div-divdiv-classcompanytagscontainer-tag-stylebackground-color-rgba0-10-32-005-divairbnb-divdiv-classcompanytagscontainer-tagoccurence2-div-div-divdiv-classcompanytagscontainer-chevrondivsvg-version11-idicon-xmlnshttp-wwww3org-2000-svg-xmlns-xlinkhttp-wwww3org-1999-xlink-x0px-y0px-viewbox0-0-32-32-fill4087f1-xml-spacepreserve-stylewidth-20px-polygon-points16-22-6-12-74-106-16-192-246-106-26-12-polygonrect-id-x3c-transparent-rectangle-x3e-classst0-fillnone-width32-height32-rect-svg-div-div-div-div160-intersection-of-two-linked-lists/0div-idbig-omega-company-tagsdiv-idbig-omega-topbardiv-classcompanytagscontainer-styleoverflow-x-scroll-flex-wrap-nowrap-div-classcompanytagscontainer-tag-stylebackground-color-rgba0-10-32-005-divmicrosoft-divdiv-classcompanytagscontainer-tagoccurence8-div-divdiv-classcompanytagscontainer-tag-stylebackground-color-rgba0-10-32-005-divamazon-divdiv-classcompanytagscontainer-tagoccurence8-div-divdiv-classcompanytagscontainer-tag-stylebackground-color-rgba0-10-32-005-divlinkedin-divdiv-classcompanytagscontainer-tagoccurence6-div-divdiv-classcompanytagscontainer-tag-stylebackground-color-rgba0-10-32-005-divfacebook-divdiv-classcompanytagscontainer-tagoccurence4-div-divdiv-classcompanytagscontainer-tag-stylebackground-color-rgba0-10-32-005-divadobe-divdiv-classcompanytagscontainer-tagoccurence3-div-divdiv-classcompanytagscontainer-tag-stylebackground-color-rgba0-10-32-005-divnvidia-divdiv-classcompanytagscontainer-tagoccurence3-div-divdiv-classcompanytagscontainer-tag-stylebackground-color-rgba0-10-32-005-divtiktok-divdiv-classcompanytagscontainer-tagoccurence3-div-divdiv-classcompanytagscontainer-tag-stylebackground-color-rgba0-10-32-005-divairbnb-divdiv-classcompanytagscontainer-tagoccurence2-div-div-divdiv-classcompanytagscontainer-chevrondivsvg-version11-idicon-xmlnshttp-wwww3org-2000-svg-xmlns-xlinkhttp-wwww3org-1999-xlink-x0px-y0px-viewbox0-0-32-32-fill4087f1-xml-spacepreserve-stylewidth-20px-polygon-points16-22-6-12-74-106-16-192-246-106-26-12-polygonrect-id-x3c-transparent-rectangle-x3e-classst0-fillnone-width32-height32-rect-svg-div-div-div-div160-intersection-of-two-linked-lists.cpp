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
        map<ListNode*, int>memo;
        ListNode* temp1 = headA;
        while(temp1!=NULL){
            memo[temp1] = 1;
            temp1 = temp1->next;
        }
        ListNode* temp2 = headB;
        while(temp2!=NULL){
            if(memo.find(temp2)!=memo.end()){
                return temp2;
            }
            temp2 = temp2->next;
        }
        return NULL;
    }
};