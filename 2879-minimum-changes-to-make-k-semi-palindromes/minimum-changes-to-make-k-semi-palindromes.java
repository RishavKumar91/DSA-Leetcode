class Solution {
    int dp[][];
    int cost[][];
    public int minimumChanges(String s, int k) {
        int n = s.length();
        dp = new int[n+1][k+1]; cost = new int[n+1][n+1];
        for(int tmp[] : dp)  Arrays.fill(tmp,-1);
        for(int tmp[] : cost)  Arrays.fill(tmp,-1);
        return hlpr(0,k,s);
    }

    int hlpr(int start ,int k,String s){
        int n = s.length();
        if( n - start < k*2 )  return 1000000000; 
        if(k == 0 ){
            if(start == n) return dp[start][k] =  0 ;
            return dp[start][k] =  1000000000; 
        }
        if(start == n) return 1000000000; 
        if(dp[start][k] != -1) return dp[start][k];
        int ans = 1000000000 ; 
        for(int i = start + 1 ; i < n ; i++){
            int currmin = minimumcost(start,i,s);
            ans = Math.min(ans , currmin + hlpr(i+1,k-1,s));
        }
    return dp[start][k] =  ans ;
    }
    public int minimumcost(int i , int j , String s ){
        if(cost[i][j] != -1) return cost[i][j];
        int len = j - i + 1 ;
        int mincost = 1000000000 ; 
        for(int d = 1 ; d <= len/2 ; d++){
            if(len % d != 0) continue ;
            int currcost = 0 ; 
            for(int group = 0 ; group < d ; group++){
                int l = i + group ; 
                int r = l + ( len/d - 1 ) * d ; 
                while(l < r){
                    if(s.charAt(l) != s.charAt(r)) currcost++;
                    l+=d ; r-=d ; 
                }
            }
            mincost = Math.min(mincost,currcost); 
        }
    return cost[i][j] = mincost ; 
    }
}