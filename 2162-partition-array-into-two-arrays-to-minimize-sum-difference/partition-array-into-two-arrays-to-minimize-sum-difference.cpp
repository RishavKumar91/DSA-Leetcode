class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N / 2;
        int SUM = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> left(n + 1), right(n + 1);

        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = 0, sum1 = 0 , sum2 = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sum1 += nums[i];
                    sum2 += nums[i+n];
                }
            }
            left[cnt].push_back(sum1);
            right[cnt].push_back(sum2);
        }

        for (int i = 0; i <= n; i++)
            sort(right[i].begin(), right[i].end());

        int ans = INT_MAX;

        for (int cnt = 0; cnt <= n; cnt++) {
            auto &A = left[cnt];
            auto &B = right[n - cnt];

            for (int s1 : A) {
                int target = SUM / 2 - s1;

                auto it = lower_bound(B.begin(), B.end(), target);

                if (it != B.end()) {
                    int total = s1 + *it;
                    ans = min(ans, abs(SUM - 2 * total));
                }

                if (it != B.begin()) {
                    --it;
                    int total = s1 + *it;
                    ans = min(ans, abs(SUM - 2 * total));
                }

                if (ans == 0) return 0;
            }
        }

        return ans;
    }
};