class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        for (int x : nums) total += x;

        int rightSum = total;
        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            rightSum -= nums[i];   // sum of elements to the right
            int len = n - i - 1;

            // nums[i] > rightSum / len
            // multiply both sides
            if ((long long)nums[i] * len > rightSum)
                count++;
        }

        return count;
    }
};
