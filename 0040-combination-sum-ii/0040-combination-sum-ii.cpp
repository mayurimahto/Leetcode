class Solution {
public:
    void rec(int ind, int target, vector<int>&arr, vector<int>&currComb, vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(currComb);
            return;
        }
        for(int i=ind; i<arr.size(); i++){
            if(i>ind && arr[i]==arr[i-1]) continue; // avoiding picking up duplicate values
            if(arr[i]>target)break;
            currComb.push_back(arr[i]);
            rec(i+1, target-arr[i], arr, currComb, ans);
            currComb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>currComb;
        vector<vector<int>>ans;
        rec(0, target, candidates, currComb, ans);
        return ans;
    }
};