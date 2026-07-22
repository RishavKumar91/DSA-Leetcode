class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0 ;
        int last = n-1;
        while(start <= last){
            int m = start + (last-start)/2;
            if(nums[m] == target) return m;
            else if(nums[m] > target ) last = m -1;
            else start = m+1;
        }
    return -1;
    }
};