class Solution {
public:
    int n;
    unordered_map<string, int> dp;

    int hlpr(int i, int diff, vector<int>& rods) {

        if(i == n)
            return diff == 0 ? 0 : -1e9;

        string key = to_string(i) + "," + to_string(diff);

        if(dp.count(key))
            return dp[key];

        int take1 = rods[i] + hlpr(i + 1,
                                    diff + rods[i],
                                    rods);

        int take2 = hlpr(i + 1,
                         diff - rods[i],
                         rods);

        int skip = hlpr(i + 1,
                        diff,
                        rods);

        return dp[key] = max({take1, take2, skip});
    }

    int tallestBillboard(vector<int>& rods) {

        n = rods.size();

        return hlpr(0, 0, rods);
    }
};