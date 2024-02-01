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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return NULL;
        ListNode* temp = head;
        int N=0;
        while(temp!=NULL){
            N++;
            temp = temp->next;
        }
        int res = N/2;
        temp = head;
        while(temp!=NULL){
            res--;
            if(res==0){
                ListNode* middle = temp->next;
                temp->next = temp->next->next;
                delete (middle);
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};