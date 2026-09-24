class Solution {
public:
    int n, total;
    int* dp;

    int solve(vector<int>& rods, int i, int diff) {

        if (i == n)
            return diff == 0 ? 0 : -1000000000;

        int idx = i * (2 * total + 1) + (diff + total);

        if (dp[idx] != -1)
            return dp[idx];

        int skip = solve(rods, i + 1, diff);

        int take1 = rods[i] +
                    solve(rods, i + 1, diff + rods[i]);

        int take2 =
                    solve(rods, i + 1, diff - rods[i]);

        return dp[idx] = max({skip, take1, take2});
    }

    int tallestBillboard(vector<int>& rods) {

        n = rods.size();

        total = accumulate(rods.begin(), rods.end(), 0);

        int cols = 2 * total + 1;

        dp = new int[n * cols];

        fill(dp, dp + n * cols, -1);

        int ans = solve(rods, 0, 0);

        delete[] dp;

        return ans;
    }
};