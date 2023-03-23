class Solution {
public:
    void rec(int ind, vector<int>&ds, vector<vector<int>>&ans, vector<int>&nums){
        ans.push_back(ds);
        for(int i=ind; i<nums.size(); i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            rec(i+1, ds, ans, nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(), nums.end());
        rec(0, ds, ans, nums);
        return ans;
    }
};