class Solution {
public:
    void findComb(int ind, int k, int target, vector<int>&integers, vector<int>&ds, vector<vector<int>>&ans){
        if(k==0){
            if(target==0){
                ans.push_back(ds);
                return;
            }
        }
        
        for(int i=ind; i<integers.size(); i++){
            ds.push_back(integers[i]);
            findComb(i+1, k-1, target-integers[i], integers, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<int>integers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        findComb(0, k, n, integers, ds, ans);
        return ans;
    }
};