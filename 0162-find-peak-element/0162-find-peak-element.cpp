class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        
        int low=1, high=n-2;
        
        while(low<=high){
            int mid = (low+high)/2;
            
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            //on increasing curve peak on righ 
            else if(nums[mid]>nums[mid-1]){
                low = mid+1;
            }
            //on decreasing curve peak on left
            else if(nums[mid]>nums[mid-1]){
                high = mid-1;
            }
            // on bottom we can eighter move high or left both will work
            else{
                high = mid-1;
            }
        }
        return -1;
    }
};