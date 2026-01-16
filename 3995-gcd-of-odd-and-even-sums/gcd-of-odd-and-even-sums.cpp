class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int o = n*n;
        int e = n * (n-1);
        int ans;
        for(int i = min(o,e);i>=1;i--){
            if(o%i==0 && e%i==0) {ans = i; break;}
        }
        return ans= n==1? 1:ans;
    }
};