class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int start=0; 
        int end=n-1;
        int index=n-1;
        
        while(start<=end){
            if(abs(nums[start])>abs(nums[end])){
                ans[index] = nums[start]*nums[start];
                index--;
                start++;
            }
            else{
                ans[index] = nums[end]*nums[end];
                index--;
                end--;
            }
        }
        return ans;
        
    }
};