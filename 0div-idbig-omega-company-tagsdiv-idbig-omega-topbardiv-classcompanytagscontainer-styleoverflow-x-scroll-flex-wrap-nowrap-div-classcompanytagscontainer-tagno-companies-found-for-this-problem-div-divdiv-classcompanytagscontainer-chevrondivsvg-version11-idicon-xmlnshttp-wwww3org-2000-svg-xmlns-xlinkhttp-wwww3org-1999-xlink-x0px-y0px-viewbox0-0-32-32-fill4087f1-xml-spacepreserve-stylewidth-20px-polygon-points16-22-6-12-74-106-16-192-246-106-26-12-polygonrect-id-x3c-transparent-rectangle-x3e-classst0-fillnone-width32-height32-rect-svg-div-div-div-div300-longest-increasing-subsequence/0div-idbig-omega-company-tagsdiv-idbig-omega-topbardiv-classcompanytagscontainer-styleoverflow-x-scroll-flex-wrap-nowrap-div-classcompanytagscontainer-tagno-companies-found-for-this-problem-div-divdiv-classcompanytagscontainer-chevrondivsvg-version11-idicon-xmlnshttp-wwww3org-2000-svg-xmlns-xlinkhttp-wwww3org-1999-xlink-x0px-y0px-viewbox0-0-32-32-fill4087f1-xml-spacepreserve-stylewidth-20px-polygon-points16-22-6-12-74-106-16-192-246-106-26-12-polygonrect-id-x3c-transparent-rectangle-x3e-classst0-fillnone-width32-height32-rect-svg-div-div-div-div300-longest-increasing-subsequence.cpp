class Solution {
public:
    //Mmemoization
    int find(int ind, int prevInd, vector<int>&nums, vector<vector<int>>&dp, int n){
        if(ind == n) return 0;
    
        if(dp[ind][prevInd+1]!=-1) return dp[ind][prevInd+1];
        
        int len = 0 + find(ind+1, prevInd, nums, dp, n);
        
        if(prevInd == -1 || nums[ind]>nums[prevInd]){
            len = max(len, 1 + find(ind+1, ind, nums, dp, n));
        }
        
        return dp[ind][prevInd+1] = len;
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return find(0, -1, nums, dp, n);
    }
};