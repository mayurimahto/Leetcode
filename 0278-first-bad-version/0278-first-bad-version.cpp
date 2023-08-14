// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int s = 0, e = n;

        long long int minBadVersion = n;

        while(s <= e){
            long long int mid = s + (e-s) / 2;
            if(isBadVersion(mid)){
                minBadVersion = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }

        return minBadVersion;
    }
};