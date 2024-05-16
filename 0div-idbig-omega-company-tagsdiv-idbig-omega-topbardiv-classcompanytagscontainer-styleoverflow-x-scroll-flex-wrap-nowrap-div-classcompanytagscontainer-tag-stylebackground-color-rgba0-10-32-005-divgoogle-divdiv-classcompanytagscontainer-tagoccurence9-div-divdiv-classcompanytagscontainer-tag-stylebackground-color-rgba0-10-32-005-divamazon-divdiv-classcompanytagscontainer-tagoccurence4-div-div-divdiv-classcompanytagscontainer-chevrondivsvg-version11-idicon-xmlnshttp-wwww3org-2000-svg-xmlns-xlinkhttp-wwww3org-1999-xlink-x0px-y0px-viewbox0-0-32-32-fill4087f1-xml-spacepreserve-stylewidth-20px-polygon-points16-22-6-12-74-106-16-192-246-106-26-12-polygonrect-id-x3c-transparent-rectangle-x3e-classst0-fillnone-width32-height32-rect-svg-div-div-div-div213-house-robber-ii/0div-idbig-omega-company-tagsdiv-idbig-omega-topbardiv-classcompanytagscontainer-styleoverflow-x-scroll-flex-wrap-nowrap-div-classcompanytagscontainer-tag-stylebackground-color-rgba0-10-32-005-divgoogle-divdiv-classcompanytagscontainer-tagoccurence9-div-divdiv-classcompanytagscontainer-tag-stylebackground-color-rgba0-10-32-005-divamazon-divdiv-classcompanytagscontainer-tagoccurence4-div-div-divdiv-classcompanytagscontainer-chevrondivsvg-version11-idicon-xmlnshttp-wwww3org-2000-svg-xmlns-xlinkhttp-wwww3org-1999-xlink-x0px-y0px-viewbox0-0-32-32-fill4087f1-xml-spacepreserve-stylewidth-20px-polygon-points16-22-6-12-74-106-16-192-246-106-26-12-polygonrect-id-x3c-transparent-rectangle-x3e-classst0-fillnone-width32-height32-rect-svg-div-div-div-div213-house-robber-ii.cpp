class Solution {
public:
    int solve(int ind, vector<int>& arr, vector<int>& dp) {
        if (ind < 0) 
            return 0;
        
        if (dp[ind] != -1) 
            return dp[ind];

        if (ind == 0)  
            return arr[ind];

        int pick = arr[ind] + solve(ind - 2, arr, dp);
        int nonPick = 0 + solve(ind - 1, arr, dp);

        return dp[ind] = max(pick, nonPick);
    }

    int rob(vector<int>& arr) {
        int n = arr.size();

        if (n == 1) 
            return arr[0];

        vector<int> arr1(arr.begin() + 1, arr.end());
        vector<int> arr2(arr.begin(), arr.end() - 1);

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int ans1 = solve(arr1.size() - 1, arr1, dp1);
        int ans2 = solve(arr2.size() - 1, arr2, dp2);

        return max(ans1, ans2);
    }
};