class Solution {
public:
int pro(int n ){
    int ans = 1 ;
    while(n != 0 ){
        ans *= n%10;
        n/=10;
    }
return ans ;
}
    int smallestNumber(int n, int t) {
        for(int start = n ; start < n+10 ; start++){
            int p = pro(start)  ;
            if(p%t ==0 ) return start;
        }
    return -1;
    }
};