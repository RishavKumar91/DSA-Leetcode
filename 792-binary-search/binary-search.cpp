class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int last = nums.size()-1;
        while(start<=last){
            int mi = start + (last-start)/2;
            if(nums[mi]==target) return mi;
            else if(nums[mi]<target) start = mi+1;
            else last = mi-1;
        }
    return -1;
    }
};