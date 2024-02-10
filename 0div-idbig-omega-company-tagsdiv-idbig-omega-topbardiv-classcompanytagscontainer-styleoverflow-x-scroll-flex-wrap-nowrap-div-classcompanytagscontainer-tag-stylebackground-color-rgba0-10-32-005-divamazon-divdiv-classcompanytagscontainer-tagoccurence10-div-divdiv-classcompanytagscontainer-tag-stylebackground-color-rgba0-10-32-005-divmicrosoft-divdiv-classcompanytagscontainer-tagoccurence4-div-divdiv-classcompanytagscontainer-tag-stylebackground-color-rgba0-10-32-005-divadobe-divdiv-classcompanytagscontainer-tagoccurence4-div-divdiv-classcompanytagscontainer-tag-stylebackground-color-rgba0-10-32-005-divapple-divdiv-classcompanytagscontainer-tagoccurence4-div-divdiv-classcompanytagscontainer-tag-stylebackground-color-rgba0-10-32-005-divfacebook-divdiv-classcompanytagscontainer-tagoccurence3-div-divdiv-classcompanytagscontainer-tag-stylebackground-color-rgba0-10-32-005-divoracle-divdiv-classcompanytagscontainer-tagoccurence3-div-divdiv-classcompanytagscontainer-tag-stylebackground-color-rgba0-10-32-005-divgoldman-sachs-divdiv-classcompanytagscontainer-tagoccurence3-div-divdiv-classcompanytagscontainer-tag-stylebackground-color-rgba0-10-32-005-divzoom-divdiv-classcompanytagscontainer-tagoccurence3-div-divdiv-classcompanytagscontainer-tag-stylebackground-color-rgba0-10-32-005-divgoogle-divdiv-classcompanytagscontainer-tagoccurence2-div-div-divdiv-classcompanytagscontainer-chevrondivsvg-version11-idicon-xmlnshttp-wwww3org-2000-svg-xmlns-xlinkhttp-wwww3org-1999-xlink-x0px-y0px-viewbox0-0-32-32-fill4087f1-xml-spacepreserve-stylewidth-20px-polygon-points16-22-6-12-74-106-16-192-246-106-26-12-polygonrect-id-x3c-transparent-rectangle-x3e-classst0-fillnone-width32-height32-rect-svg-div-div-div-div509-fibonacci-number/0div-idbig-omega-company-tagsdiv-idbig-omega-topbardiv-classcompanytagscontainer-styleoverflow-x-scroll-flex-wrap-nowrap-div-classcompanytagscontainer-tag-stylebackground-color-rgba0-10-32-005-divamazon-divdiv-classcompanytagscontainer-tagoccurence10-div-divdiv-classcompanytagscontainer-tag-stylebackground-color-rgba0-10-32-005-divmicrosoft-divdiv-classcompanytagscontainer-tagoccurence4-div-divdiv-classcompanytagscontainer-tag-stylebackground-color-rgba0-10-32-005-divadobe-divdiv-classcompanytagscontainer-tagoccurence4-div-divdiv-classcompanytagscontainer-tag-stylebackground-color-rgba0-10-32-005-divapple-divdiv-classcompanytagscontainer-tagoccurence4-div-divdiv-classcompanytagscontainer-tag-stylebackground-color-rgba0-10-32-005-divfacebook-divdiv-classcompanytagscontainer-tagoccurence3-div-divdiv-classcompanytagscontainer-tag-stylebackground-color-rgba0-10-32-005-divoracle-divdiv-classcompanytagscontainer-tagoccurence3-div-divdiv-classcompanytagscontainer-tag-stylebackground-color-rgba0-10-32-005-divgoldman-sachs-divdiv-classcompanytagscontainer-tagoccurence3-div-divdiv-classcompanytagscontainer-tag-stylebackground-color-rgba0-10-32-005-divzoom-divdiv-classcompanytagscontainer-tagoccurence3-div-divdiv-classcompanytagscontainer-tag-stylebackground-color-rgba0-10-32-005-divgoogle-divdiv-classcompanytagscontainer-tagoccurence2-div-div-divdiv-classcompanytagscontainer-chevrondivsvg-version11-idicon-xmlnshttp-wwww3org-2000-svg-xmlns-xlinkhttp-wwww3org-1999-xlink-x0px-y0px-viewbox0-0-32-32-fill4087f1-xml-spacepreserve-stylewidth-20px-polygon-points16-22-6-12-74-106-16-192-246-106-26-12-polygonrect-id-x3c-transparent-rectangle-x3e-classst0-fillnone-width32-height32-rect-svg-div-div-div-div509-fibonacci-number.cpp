class Solution {
public:
    //dp optimized
    int fib(int n) {
        int prev1 = 1;
        int prev2 = 0;
        int curri=0;
        if(n<=1) return n;
        for(int i=2; i<=n; i++){
            curri = prev1 + prev2;
            prev2 = prev1;
            prev1 = curri;
        }
        return curri;
    }
};