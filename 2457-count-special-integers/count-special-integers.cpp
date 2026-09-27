class Solution {
public:
int sz ;
string num;
vector<vector<vector<vector<int>>>> dp ; 
    int hlpr(int ix , bool LZ , bool tight , int mask ){
        if(ix == sz) return 1;
        // if( dp[ix][LZ][tight] == -1 ) return dp[ix][LZ][tight] ;
        int limit = tight ? num[ix]-'0' : 9 ; 
        int ans = 0 ;
        for(int i = 0 ; i <= limit ; i++ ){
            bool nLZ = LZ && i == 0 ; 
            bool ntight = tight && i == limit ; 
            if(nLZ ) ans += hlpr(ix+1,nLZ , ntight , mask );
            else if(mask & (1<<i)) continue;
            else ans += hlpr(ix+1,nLZ , ntight , mask | (1<<i));
        }
    return dp[ix][LZ][tight][mask] =  ans;
    }
    int countSpecialNumbers(int n) {
        num = to_string(n);
        sz = num.size();
        dp.resize(sz+1,vector<vector<vector<int>>> (2,vector<vector<int>> (2,vector<int> (1025,-1)))) ; 
        return hlpr(0,1,1,0) - 1;
    }
};