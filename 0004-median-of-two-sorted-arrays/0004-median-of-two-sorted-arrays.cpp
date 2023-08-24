class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans;
        for(int i=0; i<nums1.size();i++){
            ans.push_back(nums1[i]);
        }

        for(int i=0; i<nums2.size();i++){
            ans.push_back(nums2[i]);
        }

        sort(ans.begin(), ans.end());

        int n= ans.size();

        if(n%2!=0){
            int m = (n+1)/2;
            return ans[m-1];
        }
        else{
            float m = n/2;
            float u = ans[m-1]+ans[m];
            return u/2;
        }
    }
};