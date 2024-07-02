class Solution {
public:
    int memoization(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 100000;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int  up = grid[i][j] + memoization(i-1, j, grid, dp);
        int left = grid[i][j] + memoization(i, j-1, grid, dp);
        
        return dp[i][j] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        long long m = grid.size();
        long long n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return memoization(m-1, n-1, grid, dp);
    }
};