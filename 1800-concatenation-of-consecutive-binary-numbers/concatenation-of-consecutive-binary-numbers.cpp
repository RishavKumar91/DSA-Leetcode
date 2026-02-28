class Solution {
public:
int M = 1000000007;
    int concatenatedBinary(int n) {
        long ans = 0;
        for(int i =1;i<=n;i++){
            int bit = log2(i) + 1;
            ans = ((ans<<bit)%M + i%M)%M ;
        }
    return ans;
    }
};