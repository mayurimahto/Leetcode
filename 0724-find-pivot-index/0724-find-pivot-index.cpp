class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum=0;
        int rightsum=0;
        for(int i=0; i<nums.size(); i++){
            rightsum+=nums[i];
        }
        
        for(int i=0; i<nums.size(); i++){
            rightsum-=nums[i];
            
            if(rightsum == leftsum){
                return i;
            }
            leftsum+=nums[i];
        }
        return -1;
    }
};