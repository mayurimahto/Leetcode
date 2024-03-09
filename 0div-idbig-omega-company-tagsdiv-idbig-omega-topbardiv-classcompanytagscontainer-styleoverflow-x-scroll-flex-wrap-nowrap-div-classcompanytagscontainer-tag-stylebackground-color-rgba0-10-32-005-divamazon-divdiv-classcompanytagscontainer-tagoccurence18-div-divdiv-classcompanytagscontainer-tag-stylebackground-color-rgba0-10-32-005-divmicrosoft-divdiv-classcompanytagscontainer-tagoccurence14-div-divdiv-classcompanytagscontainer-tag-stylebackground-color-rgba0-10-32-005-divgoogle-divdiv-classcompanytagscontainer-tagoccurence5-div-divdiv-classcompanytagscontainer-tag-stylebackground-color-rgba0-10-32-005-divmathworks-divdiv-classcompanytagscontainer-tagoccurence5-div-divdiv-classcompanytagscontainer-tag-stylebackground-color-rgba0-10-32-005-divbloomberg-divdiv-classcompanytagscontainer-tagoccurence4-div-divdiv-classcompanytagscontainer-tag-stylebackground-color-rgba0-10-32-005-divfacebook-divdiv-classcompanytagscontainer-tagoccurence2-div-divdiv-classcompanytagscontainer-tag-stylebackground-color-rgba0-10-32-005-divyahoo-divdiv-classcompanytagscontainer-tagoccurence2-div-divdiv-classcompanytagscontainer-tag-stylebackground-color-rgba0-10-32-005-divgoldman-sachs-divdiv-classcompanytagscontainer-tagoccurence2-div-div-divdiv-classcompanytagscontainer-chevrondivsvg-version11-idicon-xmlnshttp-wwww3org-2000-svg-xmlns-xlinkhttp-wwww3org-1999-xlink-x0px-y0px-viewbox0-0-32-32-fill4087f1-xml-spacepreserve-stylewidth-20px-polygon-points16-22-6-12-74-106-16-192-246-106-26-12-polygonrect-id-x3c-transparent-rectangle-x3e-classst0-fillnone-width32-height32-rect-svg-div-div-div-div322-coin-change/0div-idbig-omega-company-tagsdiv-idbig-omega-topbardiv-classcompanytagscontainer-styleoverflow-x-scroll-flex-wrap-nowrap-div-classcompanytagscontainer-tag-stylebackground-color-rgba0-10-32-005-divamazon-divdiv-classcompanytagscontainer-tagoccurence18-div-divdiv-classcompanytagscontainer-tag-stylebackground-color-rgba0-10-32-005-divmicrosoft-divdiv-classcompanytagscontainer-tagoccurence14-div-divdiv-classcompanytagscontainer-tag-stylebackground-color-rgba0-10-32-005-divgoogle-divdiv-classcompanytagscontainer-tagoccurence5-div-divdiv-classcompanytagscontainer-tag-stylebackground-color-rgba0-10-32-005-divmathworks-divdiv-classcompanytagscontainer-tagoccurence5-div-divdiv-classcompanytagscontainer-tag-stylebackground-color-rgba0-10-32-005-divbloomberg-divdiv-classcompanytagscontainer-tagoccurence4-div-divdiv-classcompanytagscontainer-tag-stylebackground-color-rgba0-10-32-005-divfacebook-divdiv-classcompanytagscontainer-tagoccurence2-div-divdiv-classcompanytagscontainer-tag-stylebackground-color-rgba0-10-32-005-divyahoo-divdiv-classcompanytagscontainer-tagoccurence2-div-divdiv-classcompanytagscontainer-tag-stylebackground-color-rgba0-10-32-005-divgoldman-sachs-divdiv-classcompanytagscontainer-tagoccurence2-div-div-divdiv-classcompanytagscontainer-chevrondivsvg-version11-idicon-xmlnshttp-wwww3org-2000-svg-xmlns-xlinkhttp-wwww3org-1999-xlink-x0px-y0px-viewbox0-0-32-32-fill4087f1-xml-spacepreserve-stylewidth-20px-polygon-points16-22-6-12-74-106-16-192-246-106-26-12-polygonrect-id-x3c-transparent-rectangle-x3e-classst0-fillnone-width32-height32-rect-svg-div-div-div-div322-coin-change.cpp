class Solution {
public:
    int minCoins(int ind, vector<vector<int>>&dp, vector<int>&coins, int target){
        if(ind == 0){
            if(target % coins[ind] == 0){
                return target/coins[ind];
            }
            else return 1e9;
        }
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        int nottake = 0 + minCoins(ind-1, dp, coins, target);
        int take = INT_MAX;
        if(coins[ind]<=target){
            take = 1 + minCoins(ind, dp, coins, target-coins[ind]);
        }
        return dp[ind][target] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = minCoins(n-1, dp, coins, amount);
        if(ans>=1e9) return -1;
        else return ans;
    }
};