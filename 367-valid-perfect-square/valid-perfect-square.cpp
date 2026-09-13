class Solution {
public:
    bool isPerfectSquare(int num) {
        long long n = 1;
        while( 1LL * n * n < num){
            n++;
        }
    return n*n == num ;
    }
};