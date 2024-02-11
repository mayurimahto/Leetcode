class Solution {
public:
    //dp tabulation
    int climbStairs(int n) {
        int prev1 = 1;
        int prev2 = 1;
        int curri = 0;
        if(n==0) return 0;
        if(n==1) return 1;
        for(int i=2; i<=n; i++){
            curri = prev1+prev2;
            prev2 = prev1;
            prev1 = curri;
        }
        return curri;
    }
};