class Solution {
public:
    int trailingZeroes(int n) {
        int r = 0;
        int k = 5;
        while( k <= n){
            r = r + n/k;
            k = k*5;
        }
    return r;
    }
};