//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void rec(int row, int col, string path, vector<vector<int>>&visited, vector<string>&ans, int di[], int dj[], vector<vector<int>>&m, int n){
        if(row==n-1 && col==n-1){
            ans.push_back(path);
            return;
        }
        
        string direction = "DLRU";
        for(int ind=0; ind<4; ind++){
            int nextrow = row + di[ind];
            int nextcol = col + dj[ind];
            if(nextrow>=0 && nextcol>=0 && nextrow<n && nextcol<n && !visited[nextrow][nextcol] && m[nextrow][nextcol]==1){
                visited[row][col]=1;
                rec(nextrow, nextcol, path+direction[ind], visited, ans, di, dj, m, n);
                visited[row][col]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<int>>visited(n,vector<int>(n,0));
        int di[] = {+1, 0, 0, -1};
        int dj[] = {0,0-1, +1, 0};
        if(m[0][0]==1){
            rec(0,0,"", visited, ans, di, dj, m, n);
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