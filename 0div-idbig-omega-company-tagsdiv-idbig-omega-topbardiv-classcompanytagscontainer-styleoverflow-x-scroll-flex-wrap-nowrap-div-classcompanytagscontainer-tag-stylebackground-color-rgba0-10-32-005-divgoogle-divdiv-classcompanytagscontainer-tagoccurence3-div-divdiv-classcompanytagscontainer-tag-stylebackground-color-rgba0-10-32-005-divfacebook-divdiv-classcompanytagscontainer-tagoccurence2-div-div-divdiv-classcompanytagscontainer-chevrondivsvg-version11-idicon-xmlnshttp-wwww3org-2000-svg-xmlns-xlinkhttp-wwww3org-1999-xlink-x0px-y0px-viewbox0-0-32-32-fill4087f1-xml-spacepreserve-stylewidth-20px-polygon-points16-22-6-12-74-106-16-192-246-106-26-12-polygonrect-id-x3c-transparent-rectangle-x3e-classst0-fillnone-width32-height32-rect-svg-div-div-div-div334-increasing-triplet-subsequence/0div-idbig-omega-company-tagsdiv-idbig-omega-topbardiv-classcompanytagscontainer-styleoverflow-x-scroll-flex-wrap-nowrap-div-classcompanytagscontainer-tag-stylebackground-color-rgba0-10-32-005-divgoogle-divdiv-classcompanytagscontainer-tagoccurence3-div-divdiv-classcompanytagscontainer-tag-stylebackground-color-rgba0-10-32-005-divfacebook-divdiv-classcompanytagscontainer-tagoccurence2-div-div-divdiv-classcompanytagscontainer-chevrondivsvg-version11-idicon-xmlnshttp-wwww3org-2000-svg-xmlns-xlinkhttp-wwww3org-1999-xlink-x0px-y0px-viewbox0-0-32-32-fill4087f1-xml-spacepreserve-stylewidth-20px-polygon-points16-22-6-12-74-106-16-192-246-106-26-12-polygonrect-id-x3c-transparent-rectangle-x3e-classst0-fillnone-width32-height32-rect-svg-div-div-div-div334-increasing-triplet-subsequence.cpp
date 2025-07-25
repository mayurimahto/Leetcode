class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstMin=INT_MAX,secondMin=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=firstMin)
            {
                firstMin=nums[i];
            }
            else if(nums[i]>firstMin && nums[i]<=secondMin)
            {
                secondMin=nums[i];
            }
            else return true;
        }
        return false;
    }
};