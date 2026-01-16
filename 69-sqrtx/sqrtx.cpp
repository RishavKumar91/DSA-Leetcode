class Solution {
public:
    int mySqrt(int x) {
        // int y = sqrt(x);
        // return y;
        int f =1,l=x;
        while(f<=l){
            long long m=f+(l-f)/2;
            if(m*m==x) return m;
            if(m*m<x)  f=m+1;
            else l = m-1;
        }
        return l;
    }
};