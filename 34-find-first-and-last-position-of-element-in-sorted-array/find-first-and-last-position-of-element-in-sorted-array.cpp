class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int last = nums.size()-1;
        int low = -1,high = -1;
        while(start<=last){
            int mi = start + (last-start)/2;
            if(nums[mi]==target) {last = mi-1; low = mi;}
            else if(nums[mi] > target) last = mi-1;
            else start = mi + 1;
        }
        start = 0;
        last = nums.size()-1;
        while(start<=last){
            int mi = start + (last-start)/2;
            if(nums[mi]==target) {start = mi+1; high = mi;}
            else if(nums[mi] > target) last = mi-1;
            else start = mi + 1;
        }
    return {low,high};
    }
};