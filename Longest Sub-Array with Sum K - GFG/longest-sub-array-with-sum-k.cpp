//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int K) 
    { 
        // Complete the function
        map<int, int>Map;
        int sum=0;
        int maxlen=0;
        
        for(int i=0; i<n; i++){
            sum+=a[i];
            if(sum == K){
            maxlen = max(maxlen, i+1);
            }
            
            int rem = sum - K;
            
            if(Map.find(rem)!=Map.end()){
                int len = i - Map[rem];
                maxlen = max(maxlen, len);
            }
            if (Map.find(sum) == Map.end()) {
                Map[sum] = i;
            }
        }
        return maxlen;

    } 
};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends