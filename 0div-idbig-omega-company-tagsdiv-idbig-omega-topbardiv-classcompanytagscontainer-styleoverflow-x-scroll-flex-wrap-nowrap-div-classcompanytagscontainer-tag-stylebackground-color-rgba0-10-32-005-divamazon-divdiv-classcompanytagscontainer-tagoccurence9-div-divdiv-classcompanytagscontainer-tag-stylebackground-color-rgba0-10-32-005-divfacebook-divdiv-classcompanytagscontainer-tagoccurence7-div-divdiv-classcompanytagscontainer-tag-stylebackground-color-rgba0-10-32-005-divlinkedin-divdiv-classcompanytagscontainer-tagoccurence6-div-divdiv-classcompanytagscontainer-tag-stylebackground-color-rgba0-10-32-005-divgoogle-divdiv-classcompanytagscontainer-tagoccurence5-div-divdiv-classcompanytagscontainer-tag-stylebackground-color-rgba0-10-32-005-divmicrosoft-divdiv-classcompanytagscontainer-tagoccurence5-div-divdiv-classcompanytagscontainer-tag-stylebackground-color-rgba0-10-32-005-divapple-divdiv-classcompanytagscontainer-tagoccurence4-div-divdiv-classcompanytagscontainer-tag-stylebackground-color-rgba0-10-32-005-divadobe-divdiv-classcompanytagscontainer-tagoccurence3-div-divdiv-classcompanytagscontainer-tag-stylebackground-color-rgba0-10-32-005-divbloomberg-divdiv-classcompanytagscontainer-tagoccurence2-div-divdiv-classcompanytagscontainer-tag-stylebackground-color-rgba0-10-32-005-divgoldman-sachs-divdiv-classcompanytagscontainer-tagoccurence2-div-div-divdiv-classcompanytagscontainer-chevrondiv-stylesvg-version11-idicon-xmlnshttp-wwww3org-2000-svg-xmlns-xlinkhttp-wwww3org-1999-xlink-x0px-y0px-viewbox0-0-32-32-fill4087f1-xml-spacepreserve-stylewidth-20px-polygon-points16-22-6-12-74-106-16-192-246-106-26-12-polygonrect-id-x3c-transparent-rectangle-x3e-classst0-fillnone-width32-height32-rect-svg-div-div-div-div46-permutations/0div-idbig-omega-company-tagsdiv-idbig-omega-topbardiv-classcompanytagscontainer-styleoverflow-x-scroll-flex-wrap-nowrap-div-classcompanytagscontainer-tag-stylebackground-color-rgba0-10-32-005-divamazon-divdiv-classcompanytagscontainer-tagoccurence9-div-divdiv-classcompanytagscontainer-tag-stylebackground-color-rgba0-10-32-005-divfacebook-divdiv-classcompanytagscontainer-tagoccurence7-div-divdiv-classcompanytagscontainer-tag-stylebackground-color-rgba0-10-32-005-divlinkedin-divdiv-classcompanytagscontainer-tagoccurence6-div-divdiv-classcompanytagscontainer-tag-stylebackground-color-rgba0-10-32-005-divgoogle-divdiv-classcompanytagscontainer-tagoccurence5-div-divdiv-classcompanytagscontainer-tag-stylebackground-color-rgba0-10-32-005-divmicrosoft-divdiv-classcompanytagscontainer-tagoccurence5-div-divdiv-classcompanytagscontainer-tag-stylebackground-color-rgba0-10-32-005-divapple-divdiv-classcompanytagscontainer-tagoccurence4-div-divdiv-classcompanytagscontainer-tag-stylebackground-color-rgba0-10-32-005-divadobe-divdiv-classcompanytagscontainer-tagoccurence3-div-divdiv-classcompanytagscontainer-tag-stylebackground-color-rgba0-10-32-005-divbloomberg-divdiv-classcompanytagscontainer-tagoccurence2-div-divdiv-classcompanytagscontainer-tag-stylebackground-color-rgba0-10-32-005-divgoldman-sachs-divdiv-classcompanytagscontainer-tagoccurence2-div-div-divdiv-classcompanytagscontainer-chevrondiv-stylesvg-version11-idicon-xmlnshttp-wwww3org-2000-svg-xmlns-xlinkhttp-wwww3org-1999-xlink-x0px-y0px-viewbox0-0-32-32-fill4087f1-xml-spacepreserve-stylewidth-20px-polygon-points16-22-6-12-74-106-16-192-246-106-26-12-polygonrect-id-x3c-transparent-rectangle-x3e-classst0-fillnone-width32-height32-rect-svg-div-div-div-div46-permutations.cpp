class Solution {
public:
    void findPermutations(int ind, vector<int>&nums, vector<vector<int>>&ans){
        if(ind == nums.size()){
            ans.push_back(nums);
        }
        
        for(int i=ind; i<nums.size(); i++){
            swap(nums[ind], nums[i]);
            findPermutations(ind+1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        findPermutations(0, nums, ans);
        return ans;
    }
};