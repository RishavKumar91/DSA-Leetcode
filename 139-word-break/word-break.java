class Solution {
    int n ;
    HashSet<String> mp;
    int dp[][] ; 
    public boolean wordBreak(String s, List<String> wordDict) {
        n = s.length();
        mp = new HashSet<>();
        dp = new int[n+1][n+1];
        for(int d[] : dp){
            Arrays.fill(d,-1);
        }
        for(String word : wordDict) mp.add(word);
    return hlpr(0,0,s);
    }
    boolean hlpr(int ix , int ixl, String s){
        if(ix == n) return true ;
        if(ixl == n) return false ;
        if(dp[ix][ixl] != -1) return dp[ix][ixl] == 1;
        if(mp.contains(s.substring(ix,ixl+1)) == true ) {
            dp[ix][ixl] = ( hlpr(ix,ixl+1,s) == true || hlpr(ixl+1,ixl+1,s) == true) == true ? 1 : 0 ; 
            return dp[ix][ixl] == 1 ;
        }
            dp[ix][ixl] =  hlpr(ix,ixl+1,s) == true ? 1 : 0 ;
        return dp[ix][ixl] == 1 ;
    }
}