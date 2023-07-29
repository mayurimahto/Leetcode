class Solution {
public:
    void rotate(vector<vector<int>>&mat){
        int n=mat.size();
        int m=mat[0].size();
        
        //transposing
        for(int i=0; i<=n-2; i++){
            for(int j=i+1; j<=n-1; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        for(int i=0; i<n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        if(mat==target)return true;
        for(int i=0;i<3;i++){
            rotate(mat);
            if(mat==target){
                return true;
            }
        }
        return false;
    }
};