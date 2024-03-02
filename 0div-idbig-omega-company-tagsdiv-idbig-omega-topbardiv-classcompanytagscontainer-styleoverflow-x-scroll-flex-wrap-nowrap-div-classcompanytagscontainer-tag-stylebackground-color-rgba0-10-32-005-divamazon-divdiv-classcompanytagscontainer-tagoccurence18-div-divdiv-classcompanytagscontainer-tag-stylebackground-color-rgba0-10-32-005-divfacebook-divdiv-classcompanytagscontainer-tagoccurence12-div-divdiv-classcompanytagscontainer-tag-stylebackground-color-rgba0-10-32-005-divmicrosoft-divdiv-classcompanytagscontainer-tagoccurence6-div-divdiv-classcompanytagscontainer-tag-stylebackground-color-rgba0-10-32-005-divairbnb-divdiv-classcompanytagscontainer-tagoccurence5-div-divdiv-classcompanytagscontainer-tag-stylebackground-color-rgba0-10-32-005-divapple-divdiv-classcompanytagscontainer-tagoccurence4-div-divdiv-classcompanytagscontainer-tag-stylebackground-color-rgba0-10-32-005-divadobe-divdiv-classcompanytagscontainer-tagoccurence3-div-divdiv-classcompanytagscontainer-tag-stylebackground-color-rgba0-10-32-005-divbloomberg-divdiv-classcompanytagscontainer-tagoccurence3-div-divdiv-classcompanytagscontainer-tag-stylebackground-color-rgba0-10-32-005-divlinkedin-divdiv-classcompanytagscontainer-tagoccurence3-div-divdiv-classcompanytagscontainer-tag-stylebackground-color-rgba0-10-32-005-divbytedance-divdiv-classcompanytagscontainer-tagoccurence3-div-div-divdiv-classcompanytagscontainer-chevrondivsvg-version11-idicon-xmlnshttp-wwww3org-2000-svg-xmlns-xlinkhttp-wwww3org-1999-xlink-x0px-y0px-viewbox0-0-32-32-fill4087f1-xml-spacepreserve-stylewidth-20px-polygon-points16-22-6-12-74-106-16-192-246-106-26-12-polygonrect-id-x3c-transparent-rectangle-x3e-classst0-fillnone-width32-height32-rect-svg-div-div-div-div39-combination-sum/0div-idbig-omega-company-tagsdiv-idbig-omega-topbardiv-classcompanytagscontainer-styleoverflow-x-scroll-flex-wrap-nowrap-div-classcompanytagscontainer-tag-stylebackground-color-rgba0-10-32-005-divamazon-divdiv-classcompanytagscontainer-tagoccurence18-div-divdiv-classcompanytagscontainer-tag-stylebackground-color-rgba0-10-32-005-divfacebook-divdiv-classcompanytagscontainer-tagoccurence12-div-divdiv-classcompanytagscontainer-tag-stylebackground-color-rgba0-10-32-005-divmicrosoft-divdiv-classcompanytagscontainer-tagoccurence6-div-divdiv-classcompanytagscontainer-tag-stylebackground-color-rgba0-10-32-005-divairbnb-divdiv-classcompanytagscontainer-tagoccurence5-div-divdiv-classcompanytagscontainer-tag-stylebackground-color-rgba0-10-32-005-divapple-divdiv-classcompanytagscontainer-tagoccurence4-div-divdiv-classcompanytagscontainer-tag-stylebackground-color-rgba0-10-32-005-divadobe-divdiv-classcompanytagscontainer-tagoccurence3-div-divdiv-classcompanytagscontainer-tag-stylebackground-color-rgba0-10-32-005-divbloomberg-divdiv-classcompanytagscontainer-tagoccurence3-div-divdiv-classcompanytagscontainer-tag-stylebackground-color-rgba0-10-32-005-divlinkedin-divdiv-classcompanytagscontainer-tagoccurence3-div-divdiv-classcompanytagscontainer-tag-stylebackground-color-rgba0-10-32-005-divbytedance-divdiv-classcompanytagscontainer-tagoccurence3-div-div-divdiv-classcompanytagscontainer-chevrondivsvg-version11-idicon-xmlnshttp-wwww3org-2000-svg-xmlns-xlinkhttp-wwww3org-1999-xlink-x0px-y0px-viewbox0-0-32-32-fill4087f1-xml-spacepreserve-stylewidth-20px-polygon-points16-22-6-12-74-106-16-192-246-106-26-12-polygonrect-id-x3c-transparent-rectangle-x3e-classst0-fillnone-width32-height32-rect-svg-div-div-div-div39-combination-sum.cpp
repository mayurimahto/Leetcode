class Solution {
public:
    void rec(int indx, int target, vector<int>&arr, vector<int>&currComb, vector<vector<int>>&ans){
        //base case
        if(indx==arr.size()){
            if(target==0){
                ans.push_back(currComb);
            }
            return;
        }
        //picking
        if(arr[indx]<=target){
            currComb.push_back(arr[indx]);
            rec(indx, target-arr[indx], arr, currComb, ans);
            currComb.pop_back();
        }
        
        //not picking
        rec(indx+1, target, arr, currComb, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>currComb;
        rec(0, target, candidates, currComb, ans);
        return ans;
    }
};