class Solution {
public:
    void findPermutations(vector<int>&nums, vector<int>&ds, map<int, int>&map, vector<vector<int>>&ans){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(map[i] == 0){
                ds.push_back(nums[i]);
                map[i] = 1;
                findPermutations(nums, ds, map, ans);
                ds.pop_back();
                map[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        map<int, int>map;
        for(int i=0; i<nums.size(); i++){
            map[i] = 0;
        }
        findPermutations(nums, ds, map, ans);
        return ans;
    }
};