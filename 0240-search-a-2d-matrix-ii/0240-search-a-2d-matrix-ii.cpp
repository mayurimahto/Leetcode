class Solution {
public:
    bool bs(vector<int>&mat, int target){
        int low=0; 
        int high=mat.size()-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(mat[mid]==target) return true;
            else if(mat[mid]<target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++){
            bool flag = bs(matrix[i], target);
            if(flag == true) return true;
        }
        return false;
    }
};