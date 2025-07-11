class Solution {
public:
    void findComb(int ind, int target, vector<int>&arr, vector<int>&ds, vector<vector<int>>&ans){
        //base case
        if(target==0){
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind; i<arr.size(); i++){
            if(i>ind && arr[i] == arr[i-1]) continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            findComb(i+1, target-arr[i], arr, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        findComb(0, target, candidates, ds, ans);
        return ans;
    }
};