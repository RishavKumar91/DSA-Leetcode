class Solution {
public:
    int maxProduct(int n) {
        int mx = INT_MIN , smx = INT_MIN;
        while(n){
            int   r = n%10;
            if( r > mx ) { smx = mx ; mx = r ; }
            else if( r > smx) smx = r;
            n/=10;
        }
    return mx * smx ; 

    }
};