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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, int>memo;
        ListNode* temp = head;
        while(temp!=NULL){
            if(memo.find(temp)!=memo.end()){
                return temp;
            }
            memo[temp] = 1;
            temp = temp->next;
        }
        return NULL;
    }
};