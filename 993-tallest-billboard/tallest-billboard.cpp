class Solution {
public:
    int n;
    int total;
    vector<vector<int>> dp;

    int solve(vector<int>& rods, int i, int diff) {

        // All rods processed
        if (i == n) {
            return diff == 0 ? 0 : -1e9;
        }

        // Shift negative diff into valid index
        int idx = diff + total;

        if (dp[i][idx] != -1)
            return dp[i][idx];

        // 1. Don't take the rod
        int skip = solve(rods, i + 1, diff);

        // 2. Put rod on first billboard
        int take1 = rods[i] +
                    solve(rods, i + 1, diff + rods[i]);

        // 3. Put rod on second billboard
        int take2 = solve(rods, i + 1, diff - rods[i]);

        return dp[i][idx] = max({skip, take1, take2});
    }

    int tallestBillboard(vector<int>& rods) {

        n = rods.size();

        total = accumulate(rods.begin(), rods.end(), 0);

        // diff ranges from -total to +total
        dp = vector<vector<int>>(
            n,
            vector<int>(2 * total + 1, -1)
        );

        return solve(rods, 0, 0);
    }
};