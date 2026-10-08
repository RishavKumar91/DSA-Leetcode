class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();

        int j = 1;
        int i = 0;
        int ans = -1;
        bool flag = 1;

        while(j < n){
            if(nums[j] == nums[j-1] + (flag == 1 ? 1 : -1)){
                flag = !flag;
                ans = max(ans, j-i+1);
            }
            else {
                if(nums[j] == nums[j-1] + 1) {
                    i = j - 1;
                    flag = 0;
                    ans = max(ans, 2);
                }
                else {
                    i = j;
                    flag = 1;
                }
            }
            j++;
        }

        return ans;
    }
};