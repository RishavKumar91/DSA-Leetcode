class Solution {
public:
    int sz;
    string nums;

    vector<vector<vector<vector<vector<int>>>>> dp;

    int hlpr(int ix, bool LZ, bool tight, bool rpt, int mask) {

        if(ix == sz)
            return rpt;

        if(dp[ix][LZ][tight][rpt][mask] != -1)
            return dp[ix][LZ][tight][rpt][mask];

        int limit = tight ? nums[ix] - '0' : 9;
        int ans = 0;

        for(int i = 0; i <= limit; i++) {

            ans += hlpr(
                ix + 1,
                LZ && i == 0,
                tight && (i == nums[ix] - '0'),
                LZ ? rpt : (rpt || (mask & (1 << i))),
                (LZ && i == 0) ? mask : (mask | (1 << i))
            );
        }

        return dp[ix][LZ][tight][rpt][mask] = ans;
    }

    int numDupDigitsAtMostN(int n) {

        nums = to_string(n);
        sz = nums.size();

        dp.assign(sz,
            vector<vector<vector<vector<int>>>>(
                2,
                vector<vector<vector<int>>>(
                    2,
                    vector<vector<int>>(
                        2,
                        vector<int>(1 << 10, -1)
                    )
                )
            )
        );

        return hlpr(0, true, true, false, 0);
    }
};