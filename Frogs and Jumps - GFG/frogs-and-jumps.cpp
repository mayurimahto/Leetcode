//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        unordered_map<int, int> mp;
        for(int i=0; i<N; i++){
            int a = frogs[i];
            int b = a;
            if(!mp[a]){
                while(a <= leaves){
                    mp[a]++;
                    a+=b;
                }
            }
            
        }
        
        int count=0;
        for(int i=1;i<=leaves;i++){
            if(mp[i]==0) count++;
        }
        return count++;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends