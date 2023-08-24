class Solution {
public:
    int countsubarray(vector<int>&nums, int maxsum){
        int subarrays = 1;
        int subarraysum = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(subarraysum+nums[i]<=maxsum){
                subarraysum+=nums[i];
            }
            else{
                subarrays++;
                subarraysum = nums[i];
            }
        }
        return subarrays;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans;
        while(low<=high){
            int mid = (low+high)/2;
            int partition = countsubarray(nums, mid);
            
            if (partition > k) {
            low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};