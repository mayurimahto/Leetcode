class Solution {
public:
    int positive(vector<int>& nums){
       int s=0;
       int e=nums.size()-1;
       while(s<=e){
           int mid=s+(e-s)/2;
           if(nums[mid]>0){
               e=mid-1;
           }
           else{
               s=mid+1;
           }
       }
       return e+1;
   }
    int negative(vector<int>& nums){
       int s=0;
       int e=nums.size()-1;
       while(s<=e){
           int mid=s+(e-s)/2;
           if(nums[mid]<0){
               s=mid+1;
           }
           else{
               e=mid-1;
           }
       }
       return s-1;
   }
    int maximumCount(vector<int>& nums) {
       int n=negative(nums)+1;
       int p=nums.size()-positive(nums);
       if(p>=n){
           return p;
       }
       else{
           return n;
       }
    }
};