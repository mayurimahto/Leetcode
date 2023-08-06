class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>ans;
        int n=nums1.size();
        int m=nums2.size();
        int i=0, j=0;
        while(i<n && j<m){
            int left = max(nums1[i][0], nums2[j][0]);
            int right = min(nums1[i][1], nums2[j][1]);
            if(left<=right){
                ans.push_back({left, right});
            }
            if(nums1[i][1]>nums2[j][1]) j++;
            else i++;
        }
        return ans;
    }
};