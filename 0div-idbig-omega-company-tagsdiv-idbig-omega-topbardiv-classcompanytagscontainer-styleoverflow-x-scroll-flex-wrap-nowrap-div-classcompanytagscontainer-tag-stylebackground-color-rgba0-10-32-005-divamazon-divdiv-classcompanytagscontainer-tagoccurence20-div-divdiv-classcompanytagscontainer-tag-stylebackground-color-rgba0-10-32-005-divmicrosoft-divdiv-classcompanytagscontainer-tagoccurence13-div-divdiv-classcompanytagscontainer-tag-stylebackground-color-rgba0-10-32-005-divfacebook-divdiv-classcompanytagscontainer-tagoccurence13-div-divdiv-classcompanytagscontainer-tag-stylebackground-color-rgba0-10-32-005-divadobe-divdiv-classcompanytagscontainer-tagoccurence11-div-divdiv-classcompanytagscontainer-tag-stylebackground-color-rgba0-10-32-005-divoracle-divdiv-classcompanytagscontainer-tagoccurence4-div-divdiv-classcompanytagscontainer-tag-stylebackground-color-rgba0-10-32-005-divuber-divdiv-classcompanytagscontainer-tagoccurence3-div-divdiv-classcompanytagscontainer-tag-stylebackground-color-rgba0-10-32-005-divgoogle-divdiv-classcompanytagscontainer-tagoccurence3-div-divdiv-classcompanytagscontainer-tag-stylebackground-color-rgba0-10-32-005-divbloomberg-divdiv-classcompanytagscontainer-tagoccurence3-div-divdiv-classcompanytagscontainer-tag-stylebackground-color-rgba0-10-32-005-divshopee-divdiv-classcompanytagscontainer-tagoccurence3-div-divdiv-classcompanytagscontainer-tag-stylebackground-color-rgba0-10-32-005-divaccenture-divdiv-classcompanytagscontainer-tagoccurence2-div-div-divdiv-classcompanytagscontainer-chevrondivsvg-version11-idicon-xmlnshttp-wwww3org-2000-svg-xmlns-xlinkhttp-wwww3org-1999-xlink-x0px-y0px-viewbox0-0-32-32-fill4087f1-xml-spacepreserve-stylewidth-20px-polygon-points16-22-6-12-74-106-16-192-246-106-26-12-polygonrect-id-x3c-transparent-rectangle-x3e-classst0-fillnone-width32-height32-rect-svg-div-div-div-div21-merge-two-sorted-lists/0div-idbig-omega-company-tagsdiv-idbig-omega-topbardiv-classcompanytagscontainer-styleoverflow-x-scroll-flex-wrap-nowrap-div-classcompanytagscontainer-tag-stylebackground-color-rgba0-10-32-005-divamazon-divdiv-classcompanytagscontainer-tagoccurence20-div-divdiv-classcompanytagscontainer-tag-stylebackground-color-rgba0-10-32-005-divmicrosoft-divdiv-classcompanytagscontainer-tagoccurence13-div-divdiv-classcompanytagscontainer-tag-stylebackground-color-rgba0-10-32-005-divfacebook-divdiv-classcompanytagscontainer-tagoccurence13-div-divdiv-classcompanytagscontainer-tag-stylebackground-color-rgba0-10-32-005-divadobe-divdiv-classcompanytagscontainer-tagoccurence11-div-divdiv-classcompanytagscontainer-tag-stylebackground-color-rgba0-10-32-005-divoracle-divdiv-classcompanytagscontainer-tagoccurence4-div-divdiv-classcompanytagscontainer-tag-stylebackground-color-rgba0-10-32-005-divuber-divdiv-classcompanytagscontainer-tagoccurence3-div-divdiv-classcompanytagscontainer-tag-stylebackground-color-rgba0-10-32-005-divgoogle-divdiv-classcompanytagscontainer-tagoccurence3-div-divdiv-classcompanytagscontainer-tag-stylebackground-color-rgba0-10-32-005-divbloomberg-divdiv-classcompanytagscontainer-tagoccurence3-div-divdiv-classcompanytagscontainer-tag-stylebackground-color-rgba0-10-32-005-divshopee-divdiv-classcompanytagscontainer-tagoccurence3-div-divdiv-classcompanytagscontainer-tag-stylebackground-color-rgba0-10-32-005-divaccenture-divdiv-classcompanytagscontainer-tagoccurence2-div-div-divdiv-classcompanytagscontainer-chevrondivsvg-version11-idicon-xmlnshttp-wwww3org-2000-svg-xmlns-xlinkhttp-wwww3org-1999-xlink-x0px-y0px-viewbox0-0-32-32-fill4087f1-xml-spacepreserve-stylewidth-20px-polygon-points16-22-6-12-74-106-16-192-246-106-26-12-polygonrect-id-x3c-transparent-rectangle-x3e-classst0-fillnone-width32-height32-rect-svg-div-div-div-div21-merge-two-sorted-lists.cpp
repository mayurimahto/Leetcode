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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* t1 = head1;
        ListNode* t2 = head2;
        ListNode* temp = dummyNode;
        
        while(t1!=NULL && t2!=NULL){
            if(t1->val < t2->val){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }
        
        if(t1) {
            temp->next = t1;
        }
        else{
            temp->next = t2;
        }
        
        return dummyNode->next;
    }
};