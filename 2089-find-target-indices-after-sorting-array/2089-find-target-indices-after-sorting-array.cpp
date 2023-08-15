class Solution {
public:
    int leftpoint(vector<int>&nums, int target, int n){
        int low=0;
        int high=n-1;
        int res=-1;
        
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                res = mid;
                high = mid-1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return res;
    }
    int rightpoint(vector<int>&nums, int target, int n){
        int low=0;
        int high=n-1;
        int res=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                res = mid;
                low = mid+1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return res;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int left = leftpoint(nums, target, n);
        if(left == -1) return {};
        int right = rightpoint(nums, target, n);
        vector<int>ans;
        
        for(int i=left; i<=right; i++){
            ans.push_back(i);
        }
        return ans;
    }
};