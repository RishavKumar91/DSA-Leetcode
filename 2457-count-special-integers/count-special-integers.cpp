class Solution {
public:
string s;
    int hlpr(int ix , bool tight , bool LZ , int mask ){
        if(ix == s.size()) return 1 ;
        int limit = tight ? s[ix]-'0' : 9 ;
        int ans = 0;
        for(int d = 0 ; d <= limit ; d++){
            int ntight = tight && d == s[ix]-'0';
            if(LZ && d==0){
                ans += hlpr(ix+1 , ntight , 1 , mask );
                continue;
            }
            if( mask & (1<<d) ) continue;
            ans += hlpr(ix+1,ntight , 0  , mask | (1<<d) );
        }
    return ans;
    }
    int countSpecialNumbers(int n) {
        s = to_string(n);
        return hlpr(0,1,1,0)-1;
    }
};