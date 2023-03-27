//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void rec(int row, int col, string path, vector<vector<int>>&visited, vector<string>&ans, vector<vector<int>>&m, int n){
        if(row==n-1 && col==n-1){
            ans.push_back(path);
            return;
        }
        
        //down
        if(row+1<n && !visited[row+1][col] && m[row+1][col]==1){
            visited[row][col]=1;
            rec(row+1, col, path+"D", visited, ans, m, n);
            visited[row][col]=0;
        }
        
        //left
        if(col-1>=0 && !visited[row][col-1] && m[row][col-1]==1){
            visited[row][col]=1;
            rec(row, col-1, path+"L", visited, ans, m, n);
            visited[row][col]=0;
        }
        
        //right
        if(col+1<n && !visited[row][col+1] && m[row][col+1]==1){
            visited[row][col]=1;
            rec(row, col+1, path+"R", visited, ans, m, n);
            visited[row][col]=0;
        }
        
        //up
        if(row-1>=0 && !visited[row-1][col] && m[row-1][col]==1){
            visited[row][col]=1;
            rec(row-1, col, path+"U", visited, ans, m, n);
            visited[row][col]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<int>>visited(n,vector<int>(n,0));
        if(m[0][0]==1){
            rec(0,0,"", visited, ans, m, n);
        }
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends