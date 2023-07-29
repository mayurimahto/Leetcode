class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int>map;
        int count=0;
        int prefix=0;
        map[prefix] = 1;
        for(int i=0; i<nums.size(); i++){
            prefix+=nums[i];
            int remainder = ((prefix%k)+k)%k;
            
            if(map.find(remainder)!=map.end()){
                count = count + map[remainder];
                map[remainder]++;
            }
            else{
                map[remainder]++;
            }
        }
        return count;
    }
};