class Solution {
    int m , n ;
    int M = 1000000000 + 7 ;
    int dp[][][];
    public int uniquePaths(int[][] grid) {
        m = grid.length ; n = grid[0].length ;
        dp = new int[m+1][n+1][2];
        for(int tmp[][] : dp){
            for(int tm[] : tmp){
            Arrays.fill(tm,-1);
            }
        }
        return (hlpr(0,1, true,grid ) + hlpr(1,0,false,grid))%M;
    }
    int hlpr(int i , int j , boolean dxn,int[][] grid){   // true -> R
        if(i>=m || j >= n) return 0 ;
        int d = dxn == false ? 1 : 0 ;
        if(i==m-1 && j == n-1) return dp[i][j][d] =  1;
        if(dp[i][j][d]  != -1) return dp[i][j][d]  ;
        if(grid[i][j] == 1){
            if(dxn == true) return dp[i][j][d]  =  hlpr(i+1,j,false,grid);
            else return dp[i][j][d]  =  hlpr(i,j+1,true,grid) ; 
        }
        return dp[i][j][d]  =  (hlpr(i,j+1,true,grid) + hlpr(i+1,j,false,grid))%M;
    }
}