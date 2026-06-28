class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        const int MAX = 100000;
        int freq[MAX + 1] = {};

        for (int x : nums)
            freq[x]++;

        long long ans = 0;

        for (int val = MAX; val >= 1 && k > 0; val--) {
            while (freq[val] > 0 && k > 0) {
                if (mul >= 2)
                    ans += 1LL * val * mul--;
                else
                    ans += val;

                freq[val]--;
                k--;
            }
        }

        return ans;
    }
};