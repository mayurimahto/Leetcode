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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2, -1);
        if(!head || !head->next || !head->next->next) return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nextp = head->next->next;
        vector<int> arr;

        int idx = 1;
        while(nextp) {
            if((curr->val > prev->val && curr->val > nextp->val) ||
               (curr->val < prev->val && curr->val < nextp->val)) {
                arr.push_back(idx);
            }
            prev = curr;
            curr = nextp;
            nextp = nextp->next;
            idx++;
        }

        if(arr.size() < 2) return ans;

        int maxi = arr[arr.size() - 1] - arr[0];
        int mini = INT_MAX;

        for(int i = 0; i < arr.size() - 1; i++) {
            mini = min(mini, arr[i+1] - arr[i]);
        }

        ans[0] = mini;
        ans[1] = maxi;
        return ans;
    }
};