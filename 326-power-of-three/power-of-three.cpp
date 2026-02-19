class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return 0;
        for(long long i =1;i<=n;i*=3){
            if(n==i) return 1;
        }
    return 0;
    }
};