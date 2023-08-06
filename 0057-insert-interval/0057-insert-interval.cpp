class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& nums1) {
        nums.push_back(nums1);
        sort(nums.begin(), nums.end());
        int j=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[j][1]>=nums[i][0]){
                nums[j][1] = max(nums[j][1], nums[i][1]);
            }
            else{
                j++;
                nums[j] = nums[i];
            }
        }
        nums.resize(j+1);
        return nums;
    }
};