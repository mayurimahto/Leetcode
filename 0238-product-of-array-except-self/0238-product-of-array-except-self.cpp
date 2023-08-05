class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n, 1);
        vector<int>suff(n, 1);
        
        int prepro=1;
        for(int i=0; i<n; i++){
            pre[i] = prepro;
            prepro*=nums[i];
        }
        int suffpro=1;
        for(int i=n-1; i>=0; i--){
            suff[i] = suffpro;
            suffpro*=nums[i];
        }
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            ans[i] = pre[i]*suff[i];
        }
        return ans;
    }
};