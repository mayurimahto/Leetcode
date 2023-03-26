class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void rec(int ind, vector<string>&ds, vector<vector<string>>&ans, string s){
        if(ind==s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=ind; i<s.size(); i++){
            if(isPalindrome(s, ind, i)){
                ds.push_back(s.substr(ind, i-ind+1));
                rec(i+1, ds, ans, s);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        rec(0, ds, ans, s);
        return ans;
    }
};