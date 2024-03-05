class Solution {
public:
    void findComb(int ind, int n, vector<int>&nums, vector<int>&ds, vector<vector<int>>&ans){
        if(ind == n){
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(nums[ind]);
        findComb(ind+1, n, nums, ds, ans);
        ds.pop_back();
        findComb(ind+1, n, nums, ds, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n = nums.size();
        findComb(0, n, nums, ds, ans);
        return ans;
    }
};