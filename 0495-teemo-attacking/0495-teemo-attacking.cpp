class Solution {
public:
    int findPoisonedDuration(vector<int>& timeseries, int duration) {
        int ans = 0;
        for(int i = 0; i< timeseries.size()-1; i++)
        {
            if(timeseries[i]+duration<timeseries[i+1])
            {
                ans+=duration;
            }
            else
            ans+=timeseries[i+1]-timeseries[i];
        }
        return ans+duration;
    }
};