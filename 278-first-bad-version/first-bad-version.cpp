// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i =1;
        int ans = 0;
        while(i<=n){
            int mi = i + (n-i)/2;
            if(isBadVersion(mi)){
                ans = mi;
                n = mi-1;
            }
            else {
                i = mi +1;
            }
        }
    return ans;
    }
};