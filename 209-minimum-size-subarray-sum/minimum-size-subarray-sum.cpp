class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int j =0,i=0;
        int maxln = INT_MAX;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                maxln = min(maxln,j-i+1);
                sum-=nums[i];
                i++;
            }
        j++;
        }
    return maxln==INT_MAX ? 0:maxln;
    }
};