class Solution {
public:
    double myPow(double x, long long n) {
        long long N = n;
        if(x==1.0) return 1.0;
        if(N==0) return 1.0;
        if(N<0) return myPow(1/x,-N);
        double h= myPow(x,N/2);
        if(N%2==0) return h*h;
        else       return h*h * x;
    }
};