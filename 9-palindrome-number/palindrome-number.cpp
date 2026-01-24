class Solution {
public:
    bool isPalindrome(long long x) {
        if(x<0) return 0;
        long long  n =x,sum=0;
        while(n!=0){
            long long r = n%10;
            sum = sum*10 + r;
            n=n/10;
        }
        return (x==sum);
    }
};