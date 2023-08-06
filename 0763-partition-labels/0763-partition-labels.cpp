class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        unordered_map<char, int>map;
        int pre = -1;
        int maxi = 0;
        for(int i=0; i<s.size(); i++){
            char character = s[i];
            map[character] = i;
        }
        
        for(int i=0; i<s.size(); i++){
            maxi = max(maxi, map[s[i]]);
            if(maxi == i){
                ans.push_back(maxi-pre);
                pre = maxi;
            }
        }
        return ans;
    }
};