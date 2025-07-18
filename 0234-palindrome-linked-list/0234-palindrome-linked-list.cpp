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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        
        ListNode* temp = head;
        stack<int>st;
        while(temp!=NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        
        temp=head;
        while(temp!=NULL){
            if(temp->val!=st.top()) return false;
            else{
                temp = temp->next;
                st.pop();
            }
        }
        return true;
    }
};