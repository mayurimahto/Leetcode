class Solution {
public:
    int findMin(vector<int>& nums) {
       int n=nums.size();
        int low=0; 
        int high=n-1;
        int ans = INT_MAX;
        
        while(low<=high) {
            int mid = (low+high)/2;

            if(nums[mid]==nums[low] && nums[high]==nums[mid]){
                ans = min(ans,nums[low]);
                high = high-1;
                low = low+1;
                continue;
            }
            if(nums[low]<=nums[mid]){
                ans = min(ans,nums[low]);
                low = mid+1;
            }
            else{
                ans = min(ans,nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};