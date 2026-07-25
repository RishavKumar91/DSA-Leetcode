class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0 , last = n-1;
        int ans = 0;
        while(start <= last){
            while(start < last  && nums[start] == nums[start+1]) start++;
            while(start < last && nums[last] == nums[last-1]) last--;
            int mi = start + (last-start)/2;
            if(nums[mi] < nums[ans]) ans = mi;
            if(nums[mi] > nums[last]) {
                start = mi + 1;
            }
            else{
                last = mi - 1;
            }
        }
    return nums[ans];
    }
};