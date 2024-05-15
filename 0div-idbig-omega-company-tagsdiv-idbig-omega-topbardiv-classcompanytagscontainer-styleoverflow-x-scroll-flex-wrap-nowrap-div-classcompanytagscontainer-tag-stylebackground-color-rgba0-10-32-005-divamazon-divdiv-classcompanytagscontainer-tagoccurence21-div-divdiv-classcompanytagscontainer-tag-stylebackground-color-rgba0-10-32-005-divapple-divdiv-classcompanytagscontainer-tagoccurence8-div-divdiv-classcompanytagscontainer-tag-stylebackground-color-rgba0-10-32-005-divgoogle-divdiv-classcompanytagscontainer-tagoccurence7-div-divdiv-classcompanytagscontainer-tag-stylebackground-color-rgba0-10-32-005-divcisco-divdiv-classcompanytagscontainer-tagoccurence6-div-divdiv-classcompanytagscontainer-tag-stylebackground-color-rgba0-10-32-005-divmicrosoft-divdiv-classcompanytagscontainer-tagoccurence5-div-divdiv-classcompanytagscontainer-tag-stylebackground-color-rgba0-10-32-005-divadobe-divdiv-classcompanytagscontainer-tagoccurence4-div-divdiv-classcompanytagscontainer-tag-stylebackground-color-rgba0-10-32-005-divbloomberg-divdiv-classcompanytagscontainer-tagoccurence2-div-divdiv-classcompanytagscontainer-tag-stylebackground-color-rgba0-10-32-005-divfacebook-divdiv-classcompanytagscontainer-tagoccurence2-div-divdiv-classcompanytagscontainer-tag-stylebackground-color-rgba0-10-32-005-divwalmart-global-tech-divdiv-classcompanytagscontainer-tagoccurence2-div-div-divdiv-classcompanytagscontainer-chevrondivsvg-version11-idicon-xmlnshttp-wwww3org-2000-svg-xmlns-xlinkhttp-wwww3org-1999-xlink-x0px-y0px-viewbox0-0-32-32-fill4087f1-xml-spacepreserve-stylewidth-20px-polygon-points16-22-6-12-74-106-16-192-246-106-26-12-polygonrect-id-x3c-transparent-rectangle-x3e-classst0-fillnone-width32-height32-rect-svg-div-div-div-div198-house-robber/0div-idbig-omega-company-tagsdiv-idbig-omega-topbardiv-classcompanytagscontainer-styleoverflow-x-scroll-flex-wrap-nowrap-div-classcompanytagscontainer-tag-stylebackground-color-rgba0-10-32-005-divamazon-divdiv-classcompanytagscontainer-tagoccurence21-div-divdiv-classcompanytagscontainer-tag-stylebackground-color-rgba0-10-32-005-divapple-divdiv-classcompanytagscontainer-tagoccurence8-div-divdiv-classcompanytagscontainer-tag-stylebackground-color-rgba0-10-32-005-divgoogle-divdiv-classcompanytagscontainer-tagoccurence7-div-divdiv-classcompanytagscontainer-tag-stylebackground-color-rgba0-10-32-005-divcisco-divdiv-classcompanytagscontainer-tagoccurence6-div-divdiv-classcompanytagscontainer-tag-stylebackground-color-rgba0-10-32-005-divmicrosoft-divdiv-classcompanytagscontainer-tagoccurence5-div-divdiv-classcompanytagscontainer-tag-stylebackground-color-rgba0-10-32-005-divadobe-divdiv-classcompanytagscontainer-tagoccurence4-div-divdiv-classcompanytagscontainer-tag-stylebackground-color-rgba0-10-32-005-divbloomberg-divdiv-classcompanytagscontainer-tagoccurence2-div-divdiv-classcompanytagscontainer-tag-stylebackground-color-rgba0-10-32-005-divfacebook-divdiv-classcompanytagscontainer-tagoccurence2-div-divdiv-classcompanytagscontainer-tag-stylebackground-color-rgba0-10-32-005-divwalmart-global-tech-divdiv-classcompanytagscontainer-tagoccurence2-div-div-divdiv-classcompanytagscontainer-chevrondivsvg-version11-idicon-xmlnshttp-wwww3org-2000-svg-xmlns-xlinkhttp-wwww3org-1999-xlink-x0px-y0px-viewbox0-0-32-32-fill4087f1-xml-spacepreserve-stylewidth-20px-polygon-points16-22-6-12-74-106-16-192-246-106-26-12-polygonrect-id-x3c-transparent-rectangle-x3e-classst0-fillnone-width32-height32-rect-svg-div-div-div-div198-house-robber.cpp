class Solution {
public:
    long rec(vector<int>&nums, vector<int>&dp, int ind){
        if(ind==0) return nums[0];
        if(ind<0) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int pick = nums[ind] + rec(nums, dp, ind-2);
        int notpick = rec(nums, dp, ind-1);
        
        return dp[ind] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return rec(nums, dp, n-1);
    }
};