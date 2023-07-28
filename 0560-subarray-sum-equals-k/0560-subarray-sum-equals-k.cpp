class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int>map;
        map[0] = 1;
        int presum = 0, count=0;
        
        for(int i=0; i<n; i++){
            presum+=nums[i];
            
            //x-k
            int remove = presum-k;
            
            count+=map[remove];
            
            map[presum]+=1;
        }
        return count;
    }
};