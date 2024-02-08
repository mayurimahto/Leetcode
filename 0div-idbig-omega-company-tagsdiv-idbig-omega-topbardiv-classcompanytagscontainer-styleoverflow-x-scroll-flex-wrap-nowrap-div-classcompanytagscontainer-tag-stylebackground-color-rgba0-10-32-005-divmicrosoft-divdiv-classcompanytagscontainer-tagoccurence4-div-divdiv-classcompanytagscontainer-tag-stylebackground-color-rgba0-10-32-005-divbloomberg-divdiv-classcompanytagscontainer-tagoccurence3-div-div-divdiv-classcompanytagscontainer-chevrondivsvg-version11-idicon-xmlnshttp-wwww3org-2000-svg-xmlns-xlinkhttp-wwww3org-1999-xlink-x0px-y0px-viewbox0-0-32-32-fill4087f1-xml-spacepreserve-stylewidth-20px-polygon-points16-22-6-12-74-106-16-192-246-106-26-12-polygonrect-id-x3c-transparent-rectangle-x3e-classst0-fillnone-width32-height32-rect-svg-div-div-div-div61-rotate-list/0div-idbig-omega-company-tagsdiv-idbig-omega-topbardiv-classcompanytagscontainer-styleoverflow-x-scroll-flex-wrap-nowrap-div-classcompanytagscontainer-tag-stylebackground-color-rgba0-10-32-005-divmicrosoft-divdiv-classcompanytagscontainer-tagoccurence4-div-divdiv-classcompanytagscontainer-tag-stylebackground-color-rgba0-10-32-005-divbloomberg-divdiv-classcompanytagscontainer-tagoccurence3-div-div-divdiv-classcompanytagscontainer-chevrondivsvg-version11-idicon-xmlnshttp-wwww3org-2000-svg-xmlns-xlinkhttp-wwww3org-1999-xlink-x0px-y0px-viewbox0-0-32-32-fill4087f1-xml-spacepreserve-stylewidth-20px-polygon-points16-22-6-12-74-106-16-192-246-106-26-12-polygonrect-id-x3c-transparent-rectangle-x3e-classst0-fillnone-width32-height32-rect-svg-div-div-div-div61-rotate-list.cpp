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
    ListNode* findNthNode(ListNode* head, int m){
        int count=1;
        ListNode* temp=head;
        while(temp!=NULL){
            if(count==m) return temp;
            count++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0) return head;
        
        int len=1;
        ListNode* tail = head;
        while(tail->next!=NULL){
            len++;
            tail = tail->next;
        }
        if(k%len==0) return head;
        k = k%len;
        tail->next = head;
        ListNode* newtail = findNthNode(head, len-k);
        head = newtail->next;
        newtail->next = NULL;
        return head;
    }
};