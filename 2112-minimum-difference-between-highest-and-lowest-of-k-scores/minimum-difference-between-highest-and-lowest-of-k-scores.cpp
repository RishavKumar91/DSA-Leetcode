class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int j = 0,minn=INT_MAX;
        while(j<n-k+1){
            minn  = min(minn,nums[j+k-1] - nums[j]) ;
        j++;
        }
    return minn;
    }
};