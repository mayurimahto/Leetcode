class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count=0;
        map<int, int>map;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                map[nums1[i]+nums2[j]]++;
            }
        }
        for(int i=0; i<nums3.size(); i++){
            for(int j=0; j<nums4.size(); j++){
                int sum=nums3[i]+nums4[j];
                if(map.find(-(sum))!=map.end()){
                    count+=map[-(sum)];
                }
            }
        }
        
        return count;
    }
};