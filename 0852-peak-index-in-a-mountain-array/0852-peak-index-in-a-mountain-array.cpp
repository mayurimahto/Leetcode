class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=1; 
        int high=arr.size()-2;
        
        while(low<=high){
            int mid = (low+high)/2;
            
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }
            //on increasing slope
            else if(arr[mid]>arr[mid-1]){
                low = mid+1;
            }
            //on decreasin slope
            else if(arr[mid]<arr[mid-1]){
                high = mid-1;
            }
        }
        return -1;
    }
};