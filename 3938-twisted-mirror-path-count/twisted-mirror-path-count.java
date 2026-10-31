class Solution {
    int m, n;
    int M = 1000000007;
    int[][][] dp;

    public int uniquePaths(int[][] grid) {
        m = grid.length;
        n = grid[0].length;

        dp = new int[m][n][2];

        for (int[][] a : dp)
            for (int[] b : a)
                Arrays.fill(b, -1);

        return (int)((hlpr(0, 1, true, grid) +
                (long)hlpr(1, 0, false, grid)) % M);
    }

    int hlpr(int i, int j, boolean dxn, int[][] grid) {
        if (i >= m || j >= n) return 0;

        if (i == m-1 && j == n-1) return 1;

        int d = dxn ? 0 : 1;

        if (dp[i][j][d] != -1) return dp[i][j][d];

        if (grid[i][j] == 1) {
            if (dxn)
                return dp[i][j][d] = hlpr(i+1, j, false, grid);
            else
                return dp[i][j][d] = hlpr(i, j+1, true, grid);
        }

        return dp[i][j][d] = (int)(
            ((long)hlpr(i, j+1, true, grid) +
             hlpr(i+1, j, false, grid)) % M
        );
    }
}