class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0, emptyBottles = 0;
        while(numBottles) {
            ans += numBottles;
            emptyBottles += numBottles;
            numBottles = emptyBottles / numExchange;
            emptyBottles %= numExchange;
        } 
        return ans;
    }
};