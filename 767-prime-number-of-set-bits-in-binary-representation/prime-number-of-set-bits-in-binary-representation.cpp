class Solution {
public:
    bool isprime(int n ){
        if(n==0 || n==1) return 0;
        //if(n==2) return 1;
        for(int i =2;i<=sqrt(n);i++){
            if(n%i==0) return 0;
        }
    return 1;
    }
    int countPrimeSetBits(int left, int right) {
        int count =0;
        for(int i =right;i>=left;i--){
            if(isprime(__builtin_popcount(i))) count++;
        }
    return count;
    }
};