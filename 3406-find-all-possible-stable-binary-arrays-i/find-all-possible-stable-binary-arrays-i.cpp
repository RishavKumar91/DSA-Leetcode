class Solution {
public:
int M  = 1e9 + 7;
    int dp[201][201][2];
    int hlpr(int zeroleft,int oneleft,int limit,bool lastwas){
        if(zeroleft==0 && oneleft == 0) return 1;
        if(dp[zeroleft][oneleft][lastwas] != -1) return dp[zeroleft][oneleft][lastwas];
        int ans = 0;
        if(lastwas){
            for(int i = 1;i<=min(limit,zeroleft);i++){
            ans = (ans +  hlpr(zeroleft-i,oneleft,limit,0)) %M;
            }
        }
        else{
            for(int i = 1;i<=min(limit,oneleft);i++){
            ans  =  (ans+ hlpr(zeroleft,oneleft-i,limit,1)) % M;
            }
        }
    return dp[zeroleft][oneleft][lastwas] = ans%M;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        int x = hlpr(zero,one,limit,0);
        int y = hlpr(zero,one,limit,1);
        return (x+y )%M;
    }
};