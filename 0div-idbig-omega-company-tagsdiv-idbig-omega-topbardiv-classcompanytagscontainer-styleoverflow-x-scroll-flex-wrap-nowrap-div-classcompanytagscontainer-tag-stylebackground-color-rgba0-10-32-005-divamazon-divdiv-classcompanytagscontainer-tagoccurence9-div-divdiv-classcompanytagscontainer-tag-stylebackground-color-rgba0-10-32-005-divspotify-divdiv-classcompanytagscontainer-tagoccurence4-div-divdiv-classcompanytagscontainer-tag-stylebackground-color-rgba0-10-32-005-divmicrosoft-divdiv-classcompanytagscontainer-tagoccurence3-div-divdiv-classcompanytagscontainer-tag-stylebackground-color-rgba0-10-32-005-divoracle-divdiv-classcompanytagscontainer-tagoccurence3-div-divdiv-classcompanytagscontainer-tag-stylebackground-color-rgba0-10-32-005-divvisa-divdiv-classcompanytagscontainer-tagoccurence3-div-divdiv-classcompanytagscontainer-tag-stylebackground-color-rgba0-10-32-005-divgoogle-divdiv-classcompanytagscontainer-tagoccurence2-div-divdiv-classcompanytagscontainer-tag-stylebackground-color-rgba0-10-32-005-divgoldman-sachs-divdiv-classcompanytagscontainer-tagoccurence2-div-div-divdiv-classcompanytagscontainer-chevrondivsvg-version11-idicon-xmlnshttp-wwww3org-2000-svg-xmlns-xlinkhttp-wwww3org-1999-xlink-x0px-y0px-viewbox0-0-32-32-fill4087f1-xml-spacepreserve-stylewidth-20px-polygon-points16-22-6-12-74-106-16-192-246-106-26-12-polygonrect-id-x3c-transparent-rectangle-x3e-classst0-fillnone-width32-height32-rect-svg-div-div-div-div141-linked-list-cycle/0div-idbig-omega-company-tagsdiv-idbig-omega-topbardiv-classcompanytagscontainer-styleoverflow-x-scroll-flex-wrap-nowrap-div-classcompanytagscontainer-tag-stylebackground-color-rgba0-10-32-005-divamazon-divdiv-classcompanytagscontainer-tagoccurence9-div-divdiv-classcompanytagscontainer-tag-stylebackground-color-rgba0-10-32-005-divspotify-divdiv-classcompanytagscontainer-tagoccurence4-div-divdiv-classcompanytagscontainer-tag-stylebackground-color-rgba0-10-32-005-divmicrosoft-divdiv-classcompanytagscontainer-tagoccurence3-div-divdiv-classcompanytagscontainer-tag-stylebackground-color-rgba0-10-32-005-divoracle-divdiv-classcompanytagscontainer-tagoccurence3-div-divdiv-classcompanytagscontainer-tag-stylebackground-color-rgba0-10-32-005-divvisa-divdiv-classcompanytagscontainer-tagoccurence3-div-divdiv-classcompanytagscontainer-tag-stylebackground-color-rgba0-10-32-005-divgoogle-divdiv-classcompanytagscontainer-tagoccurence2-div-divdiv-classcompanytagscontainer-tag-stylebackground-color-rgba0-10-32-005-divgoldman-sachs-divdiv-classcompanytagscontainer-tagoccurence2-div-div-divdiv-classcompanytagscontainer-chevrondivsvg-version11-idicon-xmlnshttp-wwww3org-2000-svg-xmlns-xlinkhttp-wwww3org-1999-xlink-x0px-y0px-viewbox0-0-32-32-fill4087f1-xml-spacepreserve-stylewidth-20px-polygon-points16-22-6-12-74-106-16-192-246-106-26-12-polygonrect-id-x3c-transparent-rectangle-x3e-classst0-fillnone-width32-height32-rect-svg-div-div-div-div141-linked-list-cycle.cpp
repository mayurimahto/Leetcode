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
    //brute
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        map<ListNode*, int>memo;
        while(temp!=NULL){
            if(memo.find(temp)!=memo.end()) return true;
            memo[temp] = 1;
            temp = temp->next;
        }
        return false;
    }
};