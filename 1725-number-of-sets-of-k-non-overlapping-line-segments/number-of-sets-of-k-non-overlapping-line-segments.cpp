class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<int>> dp;
    vector<vector<int>> suf;

    int hlpr(int ix, int n, int k) {
        if(k == 0) return 1;
        if(ix >= n) return 0;

        if(dp[ix][k] != -1)
            return dp[ix][k];

        int skip = hlpr(ix + 1, n, k);

        // original:
        // for(int i = ix + 1; i < n; i++)
        //     take += hlpr(i,n,k-1);

        int take = suf[ix + 1][k - 1];

        return dp[ix][k] = (skip + take) % M;
    }

    int numberOfSets(int n, int k) {
        dp.assign(n + 1, vector<int>(k + 1, -1));
        suf.assign(n + 1, vector<int>(k + 1, 0));

        // k = 0 -> every ix has exactly 1 way
        for(int i = n - 1; i >= 0; i--) {
            suf[i][0] = (suf[i + 1][0] + 1) % M;
        }

        // Build suffix sums for all k
        for(int j = 1; j <= k; j++) {
            for(int i = n - 1; i >= 0; i--) {
                suf[i][j] = (suf[i + 1][j] + hlpr(i, n, j)) % M;
            }
        }

        return hlpr(0, n, k);
    }
};