class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0 , last = n-1;
        int ans = INT_MAX;
        while(start<=last){
            int mi = start + (last - start)/2;
            if(nums[start] <= nums[mi]){
                ans = min(ans,nums[start]);
                start = mi+1;
            }
            else {
                ans = min(ans,nums[mi]) ;
                last = mi-1;
            }
        }
    return ans;
    }
};