class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0 ;
        long long sum = 0 ;
        while(n){
            sum += n%10;
            if(n%10 != 0) ans = ans*10 + n%10;
            n/=10;
        }
        while(ans){
            n = 1LL * n*10 + ans%10;
            ans/=10;
        }
    return n * sum;
    }
};