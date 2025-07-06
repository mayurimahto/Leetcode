//1043. Partition Array for Maximum Sum

//Optimal(Tabulation)
class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n=arr.length;
        int[]dp=new int[n+1];
        Arrays.fill(dp,0);
        for(int ind=n-1;ind>=0;ind--){
            int maxAns=Integer.MIN_VALUE;
            int len=0;
            int maxElement=Integer.MIN_VALUE;
            for(int j=ind;j<Math.min(ind+k,n);j++){
                len++;
                maxElement=Math.max(arr[j],maxElement);
                int sum=(maxElement*len)+dp[j+1];
                maxAns=Math.max(maxAns,sum);
            }
            dp[ind]=maxAns;
        }
        return dp[0];
    }
}

//Memoization
class Solution {
    public int f(int ind, int n, int[]arr, int k, int[]dp){
        if(ind==n) return 0;
        if(dp[ind]!=-1)return dp[ind];
        int maxAns=Integer.MIN_VALUE;
        int len=0;
        int maxElement=Integer.MIN_VALUE;
        for(int j=ind;j<Math.min(ind+k,n);j++){
            len++;
            maxElement=Math.max(arr[j],maxElement);
            int sum=(maxElement*len)+f(j+1,n,arr,k,dp);
            maxAns=Math.max(maxAns,sum);
        }
        return dp[ind]=maxAns;
    }
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n=arr.length;
        int[]dp=new int[n];
        Arrays.fill(dp,-1);
        return f(0,n,arr,k,dp);
    }
}

//Recursion
class Solution {
    public int f(int ind, int n, int[]arr, int k){
        if(ind==n) return 0;
        int maxAns=Integer.MIN_VALUE;
        int len=0;
        int maxElement=Integer.MIN_VALUE;
        for(int j=ind;j<Math.min(ind+k,n);j++){
            len++;
            maxElement=Math.max(arr[j],maxElement);
            int sum=(maxElement*len)+f(j+1,n,arr,k);
            maxAns=Math.max(maxAns,sum);
        }
        return maxAns;
    }
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n=arr.length;
        return f(0,n,arr,k);
    }
}
