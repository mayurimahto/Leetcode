class Solution {
public:
    //dp optimal
    int tribonacci(int n) {
        int prev1 = 1;
        int prev2 = 1;
        int prev3 = 0;
        int curri = 0;
        
        if(n<=1) return n;
        if(n==2) return 1;
        for(int i=3; i<=n; i++){
            curri = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curri;
        }
        return curri;
    }
};