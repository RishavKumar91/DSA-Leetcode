class Solution {
public:
    int n, rqsum;
    vector<int> dp;

    bool hlpr(vector<int>& nums, int k, int currsum, int mask) {
        if (k == 0) return 1;

        if (dp[mask] != -1) return dp[mask];

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue;

            if (currsum + nums[i] > rqsum) break;

            else if (currsum + nums[i] == rqsum) {
                if (hlpr(nums, k - 1, 0, mask | (1 << i)))
                    return dp[mask] = 1;
            }
            else {
                if (hlpr(nums, k, currsum + nums[i],
                         mask | (1 << i)))
                    return dp[mask] = 1;
            }
        }

        return dp[mask] = 0;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % k != 0) return 0;

        rqsum = sum / k;

        sort(nums.begin(), nums.end());

        if (nums[n - 1] > rqsum) return 0;

        dp.assign(1 << n, -1);

        return hlpr(nums, k, 0, 0);
    }
};